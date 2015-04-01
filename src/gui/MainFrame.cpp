///////////////////////////////////////////////////////////////////////////////
// Name               : MainFrame.cpp
// Purpose            : Main window
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 21.02.2010
// Copyright          : (C) 2010 Tobias Schaefer <tobiassch@users.sourceforge.net>
// Licence            : GNU General Public License version 3.0 (GPLv3)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

#include <unistd.h>

#include "DialogAbout.h"
#include "DialogSetup6DOFController.h"
#include "DialogSetupUnits.h"

#include "../languages.h"
#include "../command/CommandProjectRename.h"
#include "../command/CommandObjectLoad.h"
#include "../command/CommandObjectDelete.h"
#include "../command/CommandObjectRename.h"
#include "../command/CommandObjectTransform.h"
#include "../command/CommandWorkpieceRename.h"
#include "../command/CommandWorkpieceDelete.h"
#include "../command/CommandRunAdd.h"
#include "../command/CommandRunRename.h"
#include "../command/CommandRunRemove.h"

#include "IDs.h"
#include <wx/icon.h>
#include <wx/filename.h>
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include <wx/progdlg.h>
#include <wx/dir.h>

#include "../generator/ToolpathGeneratorThread.h"

#ifndef __WIN32__
#include "../icon/logo32.xpm"
#include "../icon/logo48.xpm"
#include "../icon/logo64.xpm"
#include "../icon/logo128.xpm"
#endif

MainFrame::MainFrame(wxWindow* parent, wxLocale* locale, wxConfig* config) :
		GUIMainFrame(parent)
{

	selectedTargetPosition = 0;

#ifndef __WIN32__
	//TODO: Check, why the icon is not working under Windows / Code::Blocks.
	wxIconBundle logo;
	logo.AddIcon(wxIcon(logo32_xpm));
	logo.AddIcon(wxIcon(logo48_xpm));
	logo.AddIcon(wxIcon(logo64_xpm));
	logo.AddIcon(wxIcon(logo128_xpm));
	SetIcons(logo);
#endif

	logWindow = new wxLogWindow(this, _("Generic CAM - log window"), false,
			true);

// Setup configuration
	this->config = config;
	this->locale = locale;

	settings.GetConfigFrom(config);
	// Set the window size according to the config file
	int w, h;
	w = config->Read(_T("MainFrameWidth"), 600);
	h = config->Read(_T("MainFrameHeight"), 400);
	SetClientSize(w, h);
	control.GetConfigFrom(config);

	m_canvas->SetController(control);

	this->Connect(ID_UPDATE, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::Update));
	this->Connect(ID_REFRESHTREE, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::UpdateTree));
	this->Connect(ID_REFRESHDISPLAY, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::UpdateCanvas));

	//TODO: Why is the KeyDown event connected to the canvas?
	m_canvas->Connect(wxID_ANY, wxEVT_KEY_DOWN,
			wxKeyEventHandler(MainFrame::OnKeyDown), NULL, this);

	commandProcessor.SetEditMenu(m_menuEdit);
	commandProcessor.Initialize();
	commandProcessor.MarkAsSaved();

	dialogObjectTransformation = new DialogObjectTransformation(this, &project,
			&commandProcessor, &settings);
	dialogStockMaterial = new DialogStockMaterial(this, &project,
			&commandProcessor, &settings);
	dialogWorkpiece = new DialogWorkpiece(this, &project, &commandProcessor);
	dialogPlacement = new DialogPlacement(this, &project, &commandProcessor,
			&settings);
	dialogRun = new DialogRun(this, &project, &commandProcessor, &settings);
	dialogDebugger = new DialogMachineDebugger(this, &settings);
	dialogSetupStereo3D = new DialogSetupStereo3D(this, &settings);
	dialogToolbox = new DialogToolbox(this, &project, &settings);
	dialogToolpathGenerator = new DialogToolpathGenerator(this, &project,
			&commandProcessor, &settings);
	dialogAnimation = new DialogAnimation(this, &project);

	// Connect the project to the 3D canvas
	m_canvas->InsertProject(&project);
	settings.WriteToCanvas(m_canvas);
	tree = new TreeSetup(m_tree, &project);

	timer.SetOwner(this);
	this->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimer), NULL,
			this);
	timer.Start(1000); // ms
	dt = 1.0;

	TransferDataToWindow();
}

MainFrame::~MainFrame()
{
	// Disconnect events
	m_canvas->Disconnect(wxID_ANY, wxEVT_KEY_DOWN,
			wxKeyEventHandler(MainFrame::OnKeyDown), NULL, this);
	this->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimer), NULL,
			this);
	this->Disconnect(ID_REFRESHTREE, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::UpdateTree));
	this->Disconnect(ID_UPDATE, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::Update));
	this->Disconnect(ID_REFRESHDISPLAY, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::UpdateCanvas));

	// Save the configuration of the 6DOF controller
	control.WriteConfigTo(config);

	// Save the size of the mainframe
	int w, h;
	GetClientSize(&w, &h);
	config->Write(_T("MainFrameWidth"), (long) w);
	config->Write(_T("MainFrameHeight"), (long) h);

	settings.WriteConfigTo(config);

	delete config; // config is written back on deletion of object
}

bool MainFrame::TransferDataToWindow(void)
{
	// Populate the treeview
	tree->Update();

	m_menuToolpath->Check(ID_GENERATORAUTOMATIC, project.processToolpath);
	m_menuView->Check(ID_VIEWSTEREO3D, m_canvas->stereoMode != stereoOff);
	m_toolBar->ToggleTool(ID_DISPLAYMACHINE, project.displayMachine);
	m_toolBar->ToggleTool(ID_DISPLAYMATERIAL, project.displayGeometry);

	wxString temp = _T("Generic CAM - ");
	if(commandProcessor.IsDirty()) temp += _T("* ");
	temp += project.name;
	this->SetTitle(temp);

	dialogObjectTransformation->TransferDataToWindow();
	dialogStockMaterial->TransferDataToWindow();
	dialogWorkpiece->TransferDataToWindow();
	dialogPlacement->TransferDataToWindow();
	dialogToolbox->TransferDataToWindow();
	dialogRun->TransferDataToWindow();
	dialogDebugger->TransferDataToWindow();
	dialogToolpathGenerator->TransferDataToWindow();
	dialogSetupStereo3D->TransferDataToWindow();

	Refresh();
	return true;
}

bool MainFrame::TransferDataFromWindow(void)
{
//	m_canvas->stereoMode =
//			m_menuView->IsChecked(ID_VIEWSTEREO3D)? stereoAnaglyph : stereoOff;
	project.displayMachine = m_toolBar->GetToolState(ID_DISPLAYMACHINE);
	project.displayGeometry = m_toolBar->GetToolState(ID_DISPLAYMATERIAL);

	return true;
}

void MainFrame::Update(wxCommandEvent& event)
{
	TransferDataToWindow();
}

void MainFrame::UpdateTree(wxCommandEvent& event)
{
	tree->UpdateSelection();
	m_tree->Refresh();
}

void MainFrame::UpdateCanvas(wxCommandEvent& event)
{
	settings.WriteToCanvas(m_canvas);
	m_canvas->Refresh();
}

size_t MainFrame::GetFreeSystemMemory()
{
#ifdef __UNIX__
	long pages = sysconf(_SC_AVPHYS_PAGES);
	long page_size = sysconf(_SC_PAGE_SIZE);
	return pages * page_size;
#endif
#ifdef __WIN__
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	//TODO: Change this to available memory.
	return status.ullTotalPhys;
#endif
}

void MainFrame::OnTimer(wxTimerEvent& event)
{
	t += dt;

	wxString temp;
	temp = wxString::Format(_T("Free RAM: %lu MB"),
			GetFreeSystemMemory() / 1024 / 1024);
	m_statusBar->SetStatusText(temp, 1);

	if(project.processToolpath){
		if(project.GenerateToolpaths()) TransferDataToWindow();
	}
}

void MainFrame::OnKeyDown(wxKeyEvent& event)
{
	int k = event.GetKeyCode();

//	if(k == WXK_ESCAPE){
//		this->Close();
//	}

// Select placement
//	if(k == WXK_NUMPAD_ADD
//			&& selectedTargetPosition
//					< project.run[0].placements.GetCount() - 1) selectedTargetPosition++;
//	if(k == WXK_NUMPAD_SUBTRACT && selectedTargetPosition > 0) selectedTargetPosition--;

//	if(selectedTargetPosition
//			< project.run[0].placements.GetCount()
//			&& project.run[0].placements[selectedTargetPosition].isMovable){
//
//		if(k == WXK_UP) project.run[0].placements[selectedTargetPosition].matrix.TranslateGlobal(
//				0.0, 0.001, 0.0);
//		if(k == WXK_DOWN) project.run[0].placements[selectedTargetPosition].matrix.TranslateGlobal(
//				0.0, -0.001, 0.0);
//		if(k == WXK_RIGHT) project.run[0].placements[selectedTargetPosition].matrix.TranslateGlobal(
//				0.001, 0.0, 0.0);
//		if(k == WXK_LEFT) project.run[0].placements[selectedTargetPosition].matrix.TranslateGlobal(
//				-0.001, 0.0, 0.0);
//
//		if(k == WXK_PAGEUP){
//			AffineTransformMatrix temp;
//			temp = AffineTransformMatrix::RotateXYZ(0.0, 0.0, M_PI / 16);
//			project.run[0].placements[selectedTargetPosition].matrix =
//					project.run[0].placements[selectedTargetPosition].matrix
//							* temp;
//		}
//		if(k == WXK_PAGEDOWN){
//			AffineTransformMatrix temp;
//			temp = AffineTransformMatrix::RotateXYZ(0.0, 0.0, -M_PI / 16);
//			project.run[0].placements[selectedTargetPosition].matrix =
//					project.run[0].placements[selectedTargetPosition].matrix
//							* temp;
//		}
//
//		m_statusBar->SetStatusText(_T("Dummy text..."));
//
//		this->Refresh();
//	}

	event.Skip();
}

void MainFrame::On3DSelect(wxMouseEvent& event)
{
	int x = event.GetX();
	int y = event.GetY();

	OpenGLPick result;
	m_canvas->OnPick(result, x, y);

	size_t n;
	if(result.HasHits()){
		result.SortByNear();
		if(result.Get(0, 0) == 1 && result.Get(0, 1) > 0){
			size_t id = result.Get(0, 1) - 1;
			for(n = 0; n < project.objects.GetCount(); n++)
				project.objects[n].selected = (n == id);
			tree->UpdateSelection();
			Refresh();
		}
	}
}

void MainFrame::OnBeginLabelEdit(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);

	if(data->dataType == itemProject) return;
	if(data->dataType == itemObject) return;
	if(data->dataType == itemWorkpiece) return;
	if(data->dataType == itemRun) return;

// Stop editing, if it cannot be changed.
	event.Veto();
}

void MainFrame::OnEndLabelEdit(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);
	wxString newName = event.GetLabel();
	if(newName.IsEmpty()){
		event.Veto();
		return;
	}

	if(data->dataType == itemProject){
		if(newName == project.name) return;
		commandProcessor.Submit(
				new CommandProjectRename(_("Project renamed to ") + newName,
						&project, newName));
		TransferDataToWindow();
		return;
	};

	if(data->dataType == itemObject){
		if(newName == project.objects[data->nr].name) return;
		commandProcessor.Submit(
				new CommandObjectRename(_("Object renamed to ") + newName,
						&project, data->nr, newName));
		TransferDataToWindow();
		return;
	};

	if(data->dataType == itemWorkpiece){
		if(newName == project.workpieces[data->nr].name) return;
		commandProcessor.Submit(
				new CommandWorkpieceRename(_("Workpiece renamed to ") + newName,
						&project, data->nr, newName));
		TransferDataToWindow();
		return;
	};

	if(data->dataType == itemRun){
		if(newName == project.run[data->nr].name) return;
		commandProcessor.Submit(
				new CommandRunRename(_("Run renamed to ") + newName, &project,
						data->nr, newName));
		TransferDataToWindow();
		return;
	};

	event.Veto();
}

void MainFrame::OnActivateRightClickMenu(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);

	wxLogMessage(_T("RKMenu: %u - %u"), data->dataType, data->nr);

	wxMenu menu(_T(""));

	if(data->dataType == itemProject){

		menu.Append(wxID_OPEN, wxT("&Load Project"));
		menu.Append(wxID_SAVE, wxT("&Save Project"));
		menu.Append(wxID_SAVEAS, wxT("Save Project &As ..."));
		menu.Append(ID_PROJECTRENAME, wxT("&Rename Project"));
	}

	if(data->dataType == itemGroupObject){
		menu.Append(ID_OBJECTLOAD, wxT("&Load Object"));
		menu.AppendSeparator();
		menu.Append(ID_OBJECTMODIFY, wxT("&Modify Object"));
	}

	if(data->dataType == itemObject){
		menu.Append(ID_OBJECTMODIFY, wxT("&Modify Object"));
		menu.AppendSeparator();
		menu.Append(ID_OBJECTFLIPNORMALS, wxT("&Flip Normals"));
		menu.Append(ID_OBJECTRENAME, wxT("&Rename Object"));
		menu.Append(ID_OBJECTDELETE, wxT("&Delete Object"));
		menu.Append(ID_OBJECTLOAD, wxT("&Load Object"));
	}

	if(data->dataType == itemGroupWorkpiece){
		menu.Append(ID_WORKPIECEADD, wxT("&Add Workpiece (and Objects)"));
		menu.AppendSeparator();
		menu.Append(ID_STOCKORGANIZE, wxT("&Organize Stock"));
		menu.Append(ID_WORKPIECEDELETEUNUSED, wxT("Delete &unused Workpieces"));
	}
	if(data->dataType == itemWorkpiece){
		menu.Append(ID_WORKPIECESETUP, wxT("&Setup Workpiece"));
		menu.AppendSeparator();
		menu.Append(ID_WORKPIECEADD, wxT("&Add Objects to Workpiece"));
		menu.Append(ID_WORKPIECEDELETE, wxT("&Delete Workpiece"));
		menu.Append(ID_WORKPIECEDELETEUNUSED, wxT("Delete &unused Workpieces"));
	}

	if(data->dataType == itemGroupRun){
		menu.Append(ID_RUNADD, wxT("&Add Run"));
		menu.AppendSeparator();
		menu.Append(ID_RUNEDIT, wxT("&Setup Run"));
	}

	if(data->dataType == itemMachine){
		menu.Append(ID_MACHINELOAD, wxT("Load &Machine"));
		menu.Append(ID_GENERATORSETUP, wxT("Setup &Generators"));
		menu.AppendSeparator();
		menu.Append(ID_MACHINERELOAD, wxT("&Reload Machine"));
	}

	if(data->dataType == itemRun){
		menu.Append(ID_RUNEDIT, wxT("&Setup Run"));
		menu.Append(ID_GENERATORSETUP, wxT("Setup &Generator"));
		menu.AppendSeparator();
		menu.Append(ID_TOOLPATHSAVE, wxT("Save &Toolpath"));
		menu.AppendSeparator();
		menu.Append(ID_RUNADD, wxT("&Add Run"));
		menu.Append(ID_RUNDELETE, wxT("&Delete Run"));
	}

	if(menu.GetMenuItemCount() > 0) PopupMenu(&menu, event.GetPoint());
}

void MainFrame::OnActivate(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);

	if(data->dataType == itemGroupObject){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED, ID_OBJECTLOAD);
		ProcessEvent(menuEvent);
	}
	if(data->dataType == itemObject){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED,
		ID_OBJECTMODIFY);
		ProcessEvent(menuEvent);
	}
	if(data->dataType == itemGroupWorkpiece){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED, ID_WORKPIECEADD);
		ProcessEvent(menuEvent);
	}
	if(data->dataType == itemWorkpiece){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED,
		ID_WORKPIECESETUP);
		ProcessEvent(menuEvent);
	}
	if(data->dataType == itemGroupRun){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED, ID_RUNADD);
		ProcessEvent(menuEvent);
	}
	if(data->dataType == itemRun){
		wxCommandEvent menuEvent(wxEVT_COMMAND_MENU_SELECTED, ID_RUNEDIT);
		ProcessEvent(menuEvent);
	}
}

void MainFrame::OnSelectionChanged(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);

	tree->UpdateVariables();

	if(data->dataType == itemRun){
		if(m_tree->IsSelected(id)){
			// Only allow one item selected at a time
			size_t n;
			for(n = 0; n < project.run.GetCount(); n++)
				project.run[n].selected = (n == data->nr);
			tree->UpdateSelection();
		}
	}

	switch(data->dataType){
	case itemGroupObject:
	case itemObject:
		project.displayType = displayObjects;
		break;
	case itemGroupWorkpiece:
	case itemWorkpiece:
		project.displayType = displayWorkpieces;
		break;
	case itemGroupRun:
	case itemRun:
		project.displayType = displayRun;
		break;
	}

	TransferDataToWindow();
}

void MainFrame::OnSelectionChanging(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	TreeItem * data = (TreeItem*) m_tree->GetItemData(id);
	if(data->dataType == itemProject) return;
	if(data->dataType == itemObject) return;
	if(data->dataType == itemWorkpiece) return;
	if(data->dataType == itemPlacement) return;
	if(data->dataType == itemRun) return;

	event.Veto();
}

void MainFrame::OnToolbarButton(wxCommandEvent& event)
{
	TransferDataFromWindow();
	TransferDataToWindow();
}

void MainFrame::OnProjectNew(wxCommandEvent& event)
{
//	Project temp;
//	project.Add(temp);
	project.Clear();
	commandProcessor.ClearCommands();
	commandProcessor.MarkAsSaved();
	commandProcessor.SetMenuStrings();
	TransferDataToWindow();
}

void MainFrame::OnProjectRename(wxCommandEvent& event)
{
	wxTextEntryDialog dialog(this, _("Enter new project name:"),
			_T("Rename Project"), project.name);
	if(dialog.ShowModal() == wxID_OK){
		if(dialog.GetValue().IsEmpty()) return;
		if(dialog.GetValue() == project.name) return;

		CommandProjectRename * command = new CommandProjectRename(
		_("Project renamed to ") + dialog.GetValue(), &project,
				dialog.GetValue());
		commandProcessor.Submit(command);
		TransferDataToWindow();
	}
}

void MainFrame::ProjectLoad(wxString fileName)
{
	project.Load(fileName);
	commandProcessor.ClearCommands();
	commandProcessor.MarkAsSaved();
	TransferDataToWindow();
}

void MainFrame::OnProjectLoad(wxCommandEvent& event)
{
	wxFileName fileName;
	wxFileDialog dialog(this, _("Open Project..."), _T(""), _T(""),
			_("Generic CAM Project (*.prj; *.zip)|*.prj;*.zip|All Files|*.*"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if(wxDir::Exists(settings.lastProjectDirectory)){
		dialog.SetDirectory(settings.lastProjectDirectory);
	}

	if(dialog.ShowModal() == wxID_OK){
		fileName = dialog.GetPath();
		if(project.Load(fileName)){
			settings.lastProjectDirectory = fileName.GetPath();
			TransferDataToWindow();
		}
	}
}

void MainFrame::OnProjectSave(wxCommandEvent& event)
{
	if(!project.fileName.IsOk()) OnProjectSaveAs(event);
	project.Save(project.fileName);
	commandProcessor.MarkAsSaved();
	TransferDataToWindow();
}

void MainFrame::OnProjectSaveAs(wxCommandEvent &event)
{
	wxFileName fileName;
	wxFileDialog dialog(this, _("Save Project As..."), _T(""), _T(""),
			_(
					"Generic CAM Project (*.prj)|*.prj|Zip File (*.zip)|*.zip|All Files|*.*"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if(wxDir::Exists(settings.lastProjectDirectory)){
		dialog.SetDirectory(settings.lastProjectDirectory);
	}

	if(project.fileName.IsOk()) dialog.SetFilename(
			project.fileName.GetFullPath());

	if(dialog.ShowModal() == wxID_OK){
		fileName = dialog.GetPath();
		if(project.Save(fileName)){
			commandProcessor.MarkAsSaved();
			settings.lastProjectDirectory = project.fileName.GetPath();
			TransferDataToWindow();
		}
	}
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

void MainFrame::OnUndo(wxCommandEvent& event)
{
	commandProcessor.Undo();
	TransferDataToWindow();
}

void MainFrame::OnRedo(wxCommandEvent& event)
{
	commandProcessor.Redo();
	TransferDataToWindow();
}

void MainFrame::OnObjectLoad(wxCommandEvent& event)
{
	wxFileName fileName;
	wxFileDialog dialog(this, _("Open Object..."), _T(""), _T(""),
			_(
					"All supported files (*.dxf; *.stl; *.gts)|*.dxf;*.stl;*.gts|DXF Files (*.dxf)|*.dxf|Stereolithography files (STL files) (*.stl)|*.stl|GTS files (*.gts)|*.gts|All files|*.*"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE);

	if(wxDir::Exists(settings.lastObjectDirectory)){
		dialog.SetDirectory(settings.lastObjectDirectory);
	}else{
		if(wxDir::Exists(settings.lastProjectDirectory)){
			dialog.SetDirectory(settings.lastProjectDirectory);
		}
	}

	if(dialog.ShowModal() == wxID_OK){
		wxArrayString paths;
		dialog.GetPaths(paths);

		size_t n;
		for(n = 0; n < paths.GetCount(); n++){
			fileName = paths[n];
			commandProcessor.Submit(
					new CommandObjectLoad(
							(_("Load Object: ") + fileName.GetName()),
							&project, paths[n]));
			if(n == 0) settings.lastObjectDirectory = fileName.GetPath();
		}
		TransferDataToWindow();
	}
}

void MainFrame::OnObjectModify(wxCommandEvent& event)
{
	dialogObjectTransformation->Show(true);
	dialogObjectTransformation->Raise();
	TransferDataToWindow();
}

void MainFrame::OnObjectRename(wxCommandEvent& event)
{
	TransferDataFromWindow();
	int i = tree->GetFirstSelectedObject();
	if(i < 0 || i >= project.objects.GetCount()) return;
	wxTextEntryDialog dialog(this, _("Enter new name:"),
	_T("Rename Object ") + project.objects[i].name,
			project.objects[i].name);
	if(dialog.ShowModal() == wxID_OK){
		if(dialog.GetValue().IsEmpty()) return;
		if(dialog.GetValue() == project.objects[i].name) return;
		commandProcessor.Submit(
				new CommandObjectRename(
				_("Object renamed to ") + dialog.GetValue(), &project, i,
						dialog.GetValue()));
		TransferDataToWindow();
	}
}

void MainFrame::OnObjectDelete(wxCommandEvent& event)
{
	TransferDataFromWindow();
	tree->UpdateVariables();
	int i = tree->GetFirstSelectedObject();
	if(i < 0 || i >= project.objects.GetCount()) return;
	commandProcessor.Submit(
			new CommandObjectDelete(
			_("Object ") + project.objects[i].name + _(" deleted."),
					&project, i));
	TransferDataToWindow();
}

void MainFrame::OnObjectFlipNormals(wxCommandEvent& event)
{
	size_t n;
	for(n = 0; n < project.objects.GetCount(); n++){
		if(project.objects[n].selected){
			AffineTransformMatrix matrix = project.objects[n].matrix;
			CommandObjectTransform * command = new CommandObjectTransform(
					project.objects[n].name + _(": Flipped normal vectors"),
					&project, n, false, false, false, true, matrix);
			commandProcessor.Submit(command);
		}
	}
	TransferDataToWindow();
}

void MainFrame::OnStockEdit(wxCommandEvent& event)
{
	dialogStockMaterial->Show(true);
	dialogStockMaterial->Raise();
	dialogStockMaterial->Initialize();
	TransferDataToWindow();
}

void MainFrame::OnWorkpieceSetup(wxCommandEvent& event)
{
	dialogPlacement->Show(true);
	dialogPlacement->Raise();
	TransferDataToWindow();
}

void MainFrame::OnWorkpieceAdd(wxCommandEvent& event)
{
	dialogWorkpiece->Show(true);
	dialogWorkpiece->Raise();
	TransferDataToWindow();
}

void MainFrame::OnWorkpieceDelete(wxCommandEvent& event)
{
	TransferDataFromWindow();
	tree->UpdateVariables();
	size_t i;
	for(i = project.workpieces.GetCount(); i > 0; i--){
		if(project.workpieces[i - 1].selected){
			commandProcessor.Submit(
					new CommandWorkpieceDelete(
							_("Remove workpiece ")
									+ project.workpieces[i - 1].name, &project,
							i - 1));
		}
	}
	TransferDataToWindow();
}

void MainFrame::OnWorkpieceDeleteUnused(wxCommandEvent& event)
{
	TransferDataFromWindow();
	size_t i;
	for(i = project.workpieces.GetCount(); i > 0; i--){
		if(project.workpieces[i - 1].placements.GetCount() == 0){
			commandProcessor.Submit(
					new CommandWorkpieceDelete(
							_("Remove workpiece ")
									+ project.workpieces[i - 1].name, &project,
							i - 1));
		}
	}
	TransferDataToWindow();
}

void MainFrame::OnRunAdd(wxCommandEvent& event)
{
	unsigned int i = project.run.GetCount() + 1;
	commandProcessor.Submit(
			new CommandRunAdd(_("Add run"), &project,
					wxString::Format(_("Run #%u"), i)));
	TransferDataToWindow();
}

void MainFrame::OnRunEdit(wxCommandEvent& event)
{
	dialogRun->Show(true);
	dialogRun->Raise();
	TransferDataToWindow();
}

void MainFrame::OnRunDelete(wxCommandEvent& event)
{
	TransferDataFromWindow();
	tree->UpdateVariables();
	size_t i;
	for(i = project.run.GetCount(); i > 0; i--){
		if(project.run[i - 1].selected){
			commandProcessor.Submit(new CommandRunRemove(
			_("Remove run ") + project.run[i - 1].name, &project, i - 1));
		}
	}
	TransferDataToWindow();
}
void MainFrame::OnMachineLoad(wxCommandEvent& event)
{
	int selected = tree->GetFirstSelectedRun();
	if(selected < 0) return;

	wxFileDialog dialog(this, _("Open machine description..."), _T(""), _T(""),
			_(
					"All machine descriptions  (*.lua;*.zip)|*.lua;*.zip|Machine descriptions (LUA Files)  (*.lua)|*.lua|Packed Machine descriptions  (*.zip)|*.zip|Text files  (*.txt)|*.txt|All files|*.*"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if(wxDir::Exists(settings.lastMachineDirectory)){
		dialog.SetDirectory(settings.lastMachineDirectory);
	}else{
		if(wxDir::Exists(settings.lastProjectDirectory)){
			dialog.SetDirectory(settings.lastProjectDirectory);
		}
	}

	if(dialog.ShowModal() == wxID_OK){
		wxFileName fileName(dialog.GetPath());
		if(project.run[selected].machine.Load(fileName)){
			settings.lastMachineDirectory = fileName.GetPath();
		}else{
			wxLogError(project.run[selected].machine.textOut);
		}
		TransferDataToWindow();
	}
}

void MainFrame::OnMachineReload(wxCommandEvent& event)
{
	int selected = tree->GetFirstSelectedRun();
	if(selected < 0) return;

	if(!project.run[selected].machine.ReLoad()){

		wxLogError(project.run[selected].machine.textOut);
	}
	TransferDataToWindow();
}

void MainFrame::OnMachineDebugger(wxCommandEvent& event)
{
	dialogDebugger->Show(true);
	dialogDebugger->Raise();
}

void MainFrame::OnFlipDrillSetup(wxCommandEvent& event)
{
}

void MainFrame::OnToolboxEdit(wxCommandEvent& event)
{
	dialogToolbox->Show(true);
	dialogToolbox->Raise();
	TransferDataToWindow();
}

void MainFrame::OnToolboxLoad(wxCommandEvent& event)
{
	wxFileDialog dialog(this, _("Open toolbox..."), _T(""), _T(""),
			_("Toolbox (*.xml)|*.xml|All files|*.*"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(wxDir::Exists(settings.lastToolboxDirectory)){
		dialog.SetDirectory(settings.lastToolboxDirectory);
	}else{
		if(wxDir::Exists(settings.lastProjectDirectory)){
			dialog.SetDirectory(settings.lastProjectDirectory);
		}
	}
	if(dialog.ShowModal() == wxID_OK){
		wxFileName fileName(dialog.GetPath());
		if(project.toolbox.LoadToolbox(fileName)){
			settings.lastToolboxDirectory = fileName.GetPath();
			TransferDataToWindow();
		}
	}
}

void MainFrame::OnToolboxSave(wxCommandEvent &event)
{
	wxFileDialog dialog(this, _("Save toolbox..."), _T(""), _T(""),
			_("Toolbox (*.xml)|*.xml|All files|*.*"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if(project.toolbox.fileName.IsOk()){
		dialog.SetFilename(project.toolbox.fileName.GetFullPath());
	}else{
		if(wxDir::Exists(settings.lastToolboxDirectory)){
			dialog.SetDirectory(settings.lastToolboxDirectory);
		}
	}
	if(dialog.ShowModal() == wxID_OK){
		wxFileName fileName;
		fileName = dialog.GetPath();
		if(project.toolbox.LoadToolbox(fileName)){
			TransferDataToWindow();
		}
	}
}

void MainFrame::OnGeneratorSetup(wxCommandEvent& event)
{
	dialogToolpathGenerator->Show();
	dialogToolpathGenerator->Raise();
	TransferDataToWindow();

}

void MainFrame::OnGeneratorStart(wxCommandEvent& event)
{

	project.PropagateChanges();

	size_t maxNr = 0;
	size_t count = 0;
	for(size_t workpieceNr = 0; workpieceNr < project.workpieces.GetCount();
			workpieceNr++){
		if(project.workpieces[workpieceNr].hasRunningGenerator) continue;
		for(size_t runNr = 0; runNr < project.run.GetCount(); runNr++){
			if(project.run[runNr].workpieceNr != workpieceNr) continue;
			maxNr += project.run[runNr].toolpaths.GetCount();
		}
	}

	wxProgressDialog dialog(_T("Generating Toolpaths"), _T(""), maxNr, this);
	dialog.Show();

	for(size_t workpieceNr = 0; workpieceNr < project.workpieces.GetCount();
			workpieceNr++){
		if(project.workpieces[workpieceNr].hasRunningGenerator) continue;
		for(size_t runNr = 0; runNr < project.run.GetCount(); runNr++){
			if(project.run[runNr].workpieceNr != workpieceNr) continue;
			for(size_t toolpathNr = 0;
					toolpathNr < project.run[runNr].toolpaths.GetCount();
					toolpathNr++){
				count++;
				dialog.Update(count,
						project.workpieces[workpieceNr].name + _T(" - ")
								+ project.run[runNr].toolpaths[toolpathNr].generator->GetName());
				if(project.run[runNr].toolpaths[toolpathNr].generator->toolpathGenerated) continue;
				// Generate a detached thread. on exit it signals the workpiece to be free for
				// other generators.
				project.run[runNr].toolpaths[toolpathNr].generator->GenerateToolpath();
				project.workpieces[workpieceNr].hasRunningGenerator = false;
			}
		}
	}

}

void MainFrame::OnGeneratorAutomatic(wxCommandEvent& event)
{
	project.processToolpath = event.IsChecked();
	TransferDataToWindow();
}

void MainFrame::OnGeneratorRestart(wxCommandEvent& event)
{
}

void MainFrame::OnGeneratorSaveToolpath(wxCommandEvent& event)
{


}

void MainFrame::OnChangeLanguage(wxCommandEvent& event)
{
	long lng =
			wxGetSingleChoiceIndex(
					_T(
							"Please choose language:\nChanges will take place after restart!"),
					_T("Language"), WXSIZEOF(langNames), langNames);
	config->Write(_T("Language"), langNames[lng]);
	TransferDataToWindow();
}

void MainFrame::OnActivateStereo3D(wxCommandEvent& event)
{
	if(m_canvas->stereoMode == stereoOff){
		m_canvas->stereoMode = stereoAnaglyph;
	}else{
		m_canvas->stereoMode = stereoOff;
	}
	m_menuView->Check(ID_VIEWSTEREO3D, m_canvas->stereoMode != stereoOff);
	TransferDataToWindow();
}

void MainFrame::OnSetupController(wxCommandEvent& event)
{
	DialogSetup6DOFController temp(this);
	temp.InsertController(control);
	temp.ShowModal();
}

void MainFrame::OnSetupStereo3D(wxCommandEvent& event)
{
	dialogSetupStereo3D->Show(true);
	dialogSetupStereo3D->Raise();
}

void MainFrame::OnSetupUnits(wxCommandEvent& event)
{
	DialogSetupUnits * temp = new DialogSetupUnits(this, &settings);
	temp->Show();
	temp->Raise();
}

void MainFrame::OnShowAnimationControl(wxCommandEvent& event)
{
	dialogAnimation->Show(true);
	dialogAnimation->Raise();
	TransferDataToWindow();
}

void MainFrame::OnExtraWindowClose(wxCommandEvent& event)
{
	dialogObjectTransformation->Show(false);
	dialogStockMaterial->Show(false);
	dialogWorkpiece->Show(false);
	dialogPlacement->Show(false);
	dialogRun->Show(false);
	dialogDebugger->Show(false);
	dialogToolbox->Show(false);
	dialogToolpathGenerator->Show(false);
	dialogAnimation->Show(false);
	dialogSetupStereo3D->Show(false);

	TransferDataToWindow();
}

void MainFrame::OnShowLogWindow(wxCommandEvent& event)
{
	logWindow->Show();
	logWindow->GetFrame()->Raise();
	TransferDataToWindow();
}

void MainFrame::OnViewSet(wxCommandEvent& event)
{
//TODO: Canvas rotation from the outside.
	switch(event.GetId()){
	case ID_VIEWFRONT:

		break;
	case ID_VIEWBACK:
		break;
	case ID_VIEWLEFT:
		break;
	case ID_VIEWRIGHT:
		break;
	case ID_VIEWTOP:
		break;
	case ID_VIEWBOTTOM:
		break;
	}
	TransferDataToWindow();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	DialogAbout * dialog = new DialogAbout(this);
	dialog->Show();
	dialog->Raise();
}

