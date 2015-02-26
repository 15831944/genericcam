///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

#include "../icon/arrowxn.xpm"
#include "../icon/arrowxp.xpm"
#include "../icon/arrowyd.xpm"
#include "../icon/arrowyn.xpm"
#include "../icon/arrowyp.xpm"
#include "../icon/arrowyu.xpm"
#include "../icon/arrowzn.xpm"
#include "../icon/arrowzp.xpm"
#include "../icon/first.xpm"
#include "../icon/last.xpm"
#include "../icon/machine.xpm"
#include "../icon/material.xpm"
#include "../icon/next.xpm"
#include "../icon/play.xpm"
#include "../icon/prev.xpm"
#include "../icon/redo.xpm"
#include "../icon/tool_drilling.xpm"
#include "../icon/undo.xpm"

///////////////////////////////////////////////////////////////////////////

GUIMainFrame::GUIMainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuProject = new wxMenu();
	wxMenuItem* m_menuItemProjectCreate;
	m_menuItemProjectCreate = new wxMenuItem( m_menuProject, wxID_NEW, wxString( _("&Create new project") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemProjectCreate );
	
	wxMenuItem* m_menuItemProjectRename;
	m_menuItemProjectRename = new wxMenuItem( m_menuProject, ID_PROJECTRENAME, wxString( _("&Rename Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemProjectRename );
	
	wxMenuItem* m_menuItemProjectLoad;
	m_menuItemProjectLoad = new wxMenuItem( m_menuProject, wxID_OPEN, wxString( _("&Load Project...") ) + wxT('\t') + wxT("CTRL+L"), wxEmptyString, wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemProjectLoad );
	
	wxMenuItem* m_menuItemProjectSave;
	m_menuItemProjectSave = new wxMenuItem( m_menuProject, wxID_SAVE, wxString( _("&Save Project") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemProjectSave );
	
	wxMenuItem* m_menuItemProjectSaveAs;
	m_menuItemProjectSaveAs = new wxMenuItem( m_menuProject, wxID_SAVEAS, wxString( _("Save Project &as...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemProjectSaveAs );
	
	wxMenuItem* m_separator4;
	m_separator4 = m_menuProject->AppendSeparator();
	
	wxMenuItem* m_menuItemQuit;
	m_menuItemQuit = new wxMenuItem( m_menuProject, wxID_EXIT, wxString( _("&Quit") ) + wxT('\t') + wxT("CTRL+Q"), _("Exit the program"), wxITEM_NORMAL );
	m_menuProject->Append( m_menuItemQuit );
	
	m_menubar->Append( m_menuProject, _("&Project") );
	
	m_menuEdit = new wxMenu();
	wxMenuItem* m_menuItemUndo;
	m_menuItemUndo = new wxMenuItem( m_menuEdit, wxID_UNDO, wxString( _("&Undo") ) + wxT('\t') + wxT("CTRL+Z"), _("Undo last command"), wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemUndo );
	
	wxMenuItem* m_menuItemRedo;
	m_menuItemRedo = new wxMenuItem( m_menuEdit, wxID_REDO, wxString( _("&Redo") ) + wxT('\t') + wxT("CTRL+Y"), _("Redo last undone command"), wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemRedo );
	
	m_menubar->Append( m_menuEdit, _("&Edit") );
	
	m_menuObject = new wxMenu();
	wxMenuItem* m_menuItemObjectModify;
	m_menuItemObjectModify = new wxMenuItem( m_menuObject, ID_OBJECTMODIFY, wxString( _("&Modify Object") ) + wxT('\t') + wxT("CTRL+M"), wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectModify );
	
	wxMenuItem* m_menuItemObjectFlipNormals;
	m_menuItemObjectFlipNormals = new wxMenuItem( m_menuObject, ID_OBJECTFLIPNORMALS, wxString( _("&Flip Normals") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectFlipNormals );
	
	wxMenuItem* m_separator8;
	m_separator8 = m_menuObject->AppendSeparator();
	
	wxMenuItem* m_menuItemObjectLoad;
	m_menuItemObjectLoad = new wxMenuItem( m_menuObject, ID_OBJECTLOAD, wxString( _("&Load Object File...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectLoad );
	
	wxMenuItem* m_menuItemObjectRename;
	m_menuItemObjectRename = new wxMenuItem( m_menuObject, ID_OBJECTRENAME, wxString( _("&Rename Object") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectRename );
	
	wxMenuItem* m_menuItemObjectDelete;
	m_menuItemObjectDelete = new wxMenuItem( m_menuObject, ID_OBJECTDELETE, wxString( _("&Delete Object") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectDelete );
	
	m_menubar->Append( m_menuObject, _("&Object") );
	
	m_menuStock = new wxMenu();
	wxMenuItem* m_menuItemStockOrganize;
	m_menuItemStockOrganize = new wxMenuItem( m_menuStock, ID_STOCKORGANIZE, wxString( _("&Organize Stock") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemStockOrganize );
	
	wxMenuItem* m_menuItemStockToWorkpiece;
	m_menuItemStockToWorkpiece = new wxMenuItem( m_menuStock, ID_WORKPIECEADD, wxString( _("&Add Stock to Project") ) , _("Add stock material to project as workpiece."), wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemStockToWorkpiece );
	
	wxMenuItem* m_separator16;
	m_separator16 = m_menuStock->AppendSeparator();
	
	wxMenuItem* m_menuItemStockLoad;
	m_menuItemStockLoad = new wxMenuItem( m_menuStock, ID_STOCKLOAD, wxString( _("&Load Stock...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemStockLoad );
	
	wxMenuItem* m_menuItemStockSave;
	m_menuItemStockSave = new wxMenuItem( m_menuStock, ID_STOCKSAVE, wxString( _("&Save Stock...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemStockSave );
	
	m_menubar->Append( m_menuStock, _("&Stock") );
	
	m_menuWorkpiece = new wxMenu();
	wxMenuItem* m_menuItemWorkpieceSetup;
	m_menuItemWorkpieceSetup = new wxMenuItem( m_menuWorkpiece, ID_WORKPIECESETUP, wxString( _("&Setup Workpiece") ) + wxT('\t') + wxT("CTRL+W"), wxEmptyString, wxITEM_NORMAL );
	m_menuWorkpiece->Append( m_menuItemWorkpieceSetup );
	
	wxMenuItem* m_menuItemWorkpieceDelete;
	m_menuItemWorkpieceDelete = new wxMenuItem( m_menuWorkpiece, ID_WORKPIECEDELETE, wxString( _("&Delete Workpiece") ) , _("Remove the selected workpiece or workpieces."), wxITEM_NORMAL );
	m_menuWorkpiece->Append( m_menuItemWorkpieceDelete );
	
	wxMenuItem* m_menuItemWorkpieceDeleteUnused;
	m_menuItemWorkpieceDeleteUnused = new wxMenuItem( m_menuWorkpiece, ID_WORKPIECEDELETEUNUSED, wxString( _("Delete &unused Workpieces") ) , _("Remove all workpieces, that have no objects linked to them."), wxITEM_NORMAL );
	m_menuWorkpiece->Append( m_menuItemWorkpieceDeleteUnused );
	
	m_menubar->Append( m_menuWorkpiece, _("&Workpiece") );
	
	m_menuRun = new wxMenu();
	wxMenuItem* m_menuItemRunSetup;
	m_menuItemRunSetup = new wxMenuItem( m_menuRun, ID_RUNEDIT, wxString( _("&Setup Run") ) + wxT('\t') + wxT("CTRL+R"), wxEmptyString, wxITEM_NORMAL );
	m_menuRun->Append( m_menuItemRunSetup );
	
	wxMenuItem* m_menuItemRunAdd;
	m_menuItemRunAdd = new wxMenuItem( m_menuRun, ID_RUNADD, wxString( _("&Add Run") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuRun->Append( m_menuItemRunAdd );
	
	wxMenuItem* m_menuItemRunDelete;
	m_menuItemRunDelete = new wxMenuItem( m_menuRun, ID_RUNDELETE, wxString( _("&Delete Run") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuRun->Append( m_menuItemRunDelete );
	
	m_menubar->Append( m_menuRun, _("&Run") );
	
	m_menuMachine = new wxMenu();
	wxMenuItem* m_menuItemMachineLoad;
	m_menuItemMachineLoad = new wxMenuItem( m_menuMachine, ID_MACHINELOAD, wxString( _("&Load Machine...") ) , _("Load a machine for the selected run"), wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemMachineLoad );
	
	wxMenuItem* m_menuItemMachineReload;
	m_menuItemMachineReload = new wxMenuItem( m_menuMachine, ID_MACHINERELOAD, wxString( _("&Reload Machine") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemMachineReload );
	
	wxMenuItem* m_separator10;
	m_separator10 = m_menuMachine->AppendSeparator();
	
	wxMenuItem* m_menuItemMachineDebugger;
	m_menuItemMachineDebugger = new wxMenuItem( m_menuMachine, ID_MACHINEDEBUGGER, wxString( _("&Open Machine Debugger") ) + wxT('\t') + wxT("CTRL+D"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemMachineDebugger );
	
	wxMenuItem* m_menuItemFlipDrill;
	m_menuItemFlipDrill = new wxMenuItem( m_menuMachine, wxID_ANY, wxString( _("Setup &Filp Drills") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemFlipDrill );
	
	m_menubar->Append( m_menuMachine, _("&Machine") );
	
	m_menuToolbox = new wxMenu();
	wxMenuItem* m_menuItemToolboxEdit;
	m_menuItemToolboxEdit = new wxMenuItem( m_menuToolbox, ID_TOOLBOXEDIT, wxString( _("&Edit Toolbox") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolbox->Append( m_menuItemToolboxEdit );
	
	wxMenuItem* m_menuItemToolboxLoad;
	m_menuItemToolboxLoad = new wxMenuItem( m_menuToolbox, ID_TOOLBOXLOAD, wxString( _("&Load Toolbox...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolbox->Append( m_menuItemToolboxLoad );
	
	wxMenuItem* m_menuItemToolboxSave;
	m_menuItemToolboxSave = new wxMenuItem( m_menuToolbox, wxID_ANY, wxString( _("&Save Toolbox...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolbox->Append( m_menuItemToolboxSave );
	
	m_menubar->Append( m_menuToolbox, _("&Toolbox") );
	
	m_menuToolpath = new wxMenu();
	wxMenuItem* m_menuItemGeneratorSetup;
	m_menuItemGeneratorSetup = new wxMenuItem( m_menuToolpath, ID_GENERATORSETUP, wxString( _("&Setup Generators") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolpath->Append( m_menuItemGeneratorSetup );
	
	wxMenuItem* m_separator18;
	m_separator18 = m_menuToolpath->AppendSeparator();
	
	wxMenuItem* m_menuItemGeneratorAutomatic;
	m_menuItemGeneratorAutomatic = new wxMenuItem( m_menuToolpath, ID_GENERATORAUTOMATIC, wxString( _("&Automatic Generation") ) , wxEmptyString, wxITEM_CHECK );
	m_menuToolpath->Append( m_menuItemGeneratorAutomatic );
	m_menuItemGeneratorAutomatic->Check( true );
	
	wxMenuItem* m_menuItemGeneratorRestart;
	m_menuItemGeneratorRestart = new wxMenuItem( m_menuToolpath, ID_GENERATORRESTART, wxString( _("&Restart Generation") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolpath->Append( m_menuItemGeneratorRestart );
	
	wxMenuItem* m_separator19;
	m_separator19 = m_menuToolpath->AppendSeparator();
	
	wxMenuItem* m_menuItemGeneratorSaveToolpath;
	m_menuItemGeneratorSaveToolpath = new wxMenuItem( m_menuToolpath, wxID_ANY, wxString( _("Save &Toolpath") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolpath->Append( m_menuItemGeneratorSaveToolpath );
	
	wxMenuItem* m_separator5;
	m_separator5 = m_menuToolpath->AppendSeparator();
	
	wxMenuItem* m_menuItemShowAnimationControl;
	m_menuItemShowAnimationControl = new wxMenuItem( m_menuToolpath, wxID_ANY, wxString( _("Show Animation &Control") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolpath->Append( m_menuItemShowAnimationControl );
	
	m_menubar->Append( m_menuToolpath, _("Tool&path") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItemSetupLanguage;
	m_menuItemSetupLanguage = new wxMenuItem( m_menuSettings, wxID_ANY, wxString( _("Change Language") ) , _("Change the programs language."), wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupLanguage );
	
	wxMenuItem* m_menuItemActivateStereo3D;
	m_menuItemActivateStereo3D = new wxMenuItem( m_menuSettings, ID_VIEWSTEREO3D, wxString( _("Stereo &3D") ) + wxT('\t') + wxT("CTRL+3"), wxEmptyString, wxITEM_CHECK );
	m_menuSettings->Append( m_menuItemActivateStereo3D );
	
	wxMenuItem* m_separator71;
	m_separator71 = m_menuSettings->AppendSeparator();
	
	wxMenuItem* m_menuItemSetupController;
	m_menuItemSetupController = new wxMenuItem( m_menuSettings, ID_SETUPCONTROLLER, wxString( _("Setup 6DOF &Controller") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupController );
	
	wxMenuItem* m_menuItemSetupStereo3D;
	m_menuItemSetupStereo3D = new wxMenuItem( m_menuSettings, wxID_ANY, wxString( _("Setup &Stereo 3D") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupStereo3D );
	
	wxMenuItem* m_menuItemSetupUnits;
	m_menuItemSetupUnits = new wxMenuItem( m_menuSettings, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupUnits );
	
	m_menubar->Append( m_menuSettings, _("S&ettings") );
	
	m_menuView = new wxMenu();
	wxMenuItem* m_menuItemCloseAdditionalWindows;
	m_menuItemCloseAdditionalWindows = new wxMenuItem( m_menuView, ID_CLOSEEXTRAWINDOWS, wxString( _("&Close all Extra Windows") ) + wxT('\t') + wxT("CTRL+SHIFT+W"), _("Close all the dialogs. No data is lost."), wxITEM_NORMAL );
	m_menuView->Append( m_menuItemCloseAdditionalWindows );
	
	wxMenuItem* m_menuItemLogShow;
	m_menuItemLogShow = new wxMenuItem( m_menuView, ID_LOGSHOW, wxString( _("Show &Log Window") ) + wxT('\t') + wxT("CTRL+L"), wxEmptyString, wxITEM_CHECK );
	m_menuView->Append( m_menuItemLogShow );
	
	wxMenuItem* m_separator11;
	m_separator11 = m_menuView->AppendSeparator();
	
	wxMenuItem* m_menuItemTop;
	m_menuItemTop = new wxMenuItem( m_menuView, ID_VIEWTOP, wxString( _("View from Top") ) + wxT('\t') + wxT("CTRL+8"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemTop );
	
	wxMenuItem* m_menuItemBottom;
	m_menuItemBottom = new wxMenuItem( m_menuView, ID_VIEWBOTTOM, wxString( _("View from Bottom") ) + wxT('\t') + wxT("CTRL+2"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemBottom );
	
	wxMenuItem* m_menuItemFront;
	m_menuItemFront = new wxMenuItem( m_menuView, ID_VIEWFRONT, wxString( _("View from Front") ) + wxT('\t') + wxT("CTRL+5"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemFront );
	
	wxMenuItem* m_menuItemBack;
	m_menuItemBack = new wxMenuItem( m_menuView, ID_VIEWBACK, wxString( _("View from Back") ) + wxT('\t') + wxT("CTRL+0"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemBack );
	
	wxMenuItem* m_menuItemLeft;
	m_menuItemLeft = new wxMenuItem( m_menuView, ID_VIEWLEFT, wxString( _("View from Left") ) + wxT('\t') + wxT("CTRL+4"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemLeft );
	
	wxMenuItem* m_menuItemRight;
	m_menuItemRight = new wxMenuItem( m_menuView, ID_VIEWRIGHT, wxString( _("View from Right") ) + wxT('\t') + wxT("CTRL+6"), wxEmptyString, wxITEM_NORMAL );
	m_menuView->Append( m_menuItemRight );
	
	m_menubar->Append( m_menuView, _("&View") );
	
	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuAbout;
	m_menuAbout = new wxMenuItem( m_menuHelp, wxID_ABOUT, wxString( _("&About") ) , _("About the program"), wxITEM_NORMAL );
	m_menuHelp->Append( m_menuAbout );
	
	m_menubar->Append( m_menuHelp, _("&Help") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );
	
	m_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH|wxSP_LIVE_UPDATE );
	m_splitter->SetMinimumPaneSize( 100 );
	m_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( GUIMainFrame::m_splitterOnIdle ), NULL, this );
	m_panelTree = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerTree;
	bSizerTree = new wxBoxSizer( wxVERTICAL );
	
	m_tree = new wxTreeCtrl( m_panelTree, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_EDIT_LABELS|wxTR_EXTENDED|wxTR_FULL_ROW_HIGHLIGHT|wxTR_HAS_BUTTONS|wxTR_MULTIPLE|wxTR_NO_LINES|wxTR_SINGLE );
	bSizerTree->Add( m_tree, 1, wxALL|wxEXPAND, 5 );
	
	m_panelTree->SetSizer( bSizerTree );
	m_panelTree->Layout();
	bSizerTree->Fit( m_panelTree );
	m_panelMainCanvas = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerMainCanvas;
	bSizerMainCanvas = new wxBoxSizer( wxVERTICAL );
	
	m_canvas = new MainCanvas(m_panelMainCanvas);
	bSizerMainCanvas->Add( m_canvas, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelMainCanvas->SetSizer( bSizerMainCanvas );
	m_panelMainCanvas->Layout();
	bSizerMainCanvas->Fit( m_panelMainCanvas );
	m_splitter->SplitVertically( m_panelTree, m_panelMainCanvas, 144 );
	bSizer->Add( m_splitter, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	m_toolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar->SetBackgroundColour( wxColour( 240, 240, 240 ) );
	
	m_toolBar->AddTool( wxID_UNDO, _("tool"), wxBitmap( undo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Undo"), _("Undo") );
	m_toolBar->AddTool( wxID_REDO, _("tool"), wxBitmap( redo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Redo"), _("Redo") );
	m_toolBar->AddSeparator();
	m_toolBar->AddTool( ID_DISPLAYMACHINE, _("tool"), wxBitmap( machine_xpm ), wxNullBitmap, wxITEM_CHECK, _("Display machine"), _("Display machine") );
	m_toolBar->AddTool( ID_DISPLAYMATERIAL, _("tool"), wxBitmap( material_xpm ), wxNullBitmap, wxITEM_CHECK, _("Display material"), _("Display material") );
	m_toolBar->AddSeparator();
	m_toolBar->AddTool( ID_GENERATORSETUP, _("tool"), wxBitmap( tool_drilling_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Show the dialog to add, update and remove toolpath generators."), _("Add / setup toolpath generators") );
	m_toolBar->Realize();
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItemProjectCreate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectNew ) );
	this->Connect( m_menuItemProjectRename->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectRename ) );
	this->Connect( m_menuItemProjectLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectLoad ) );
	this->Connect( m_menuItemProjectSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectSave ) );
	this->Connect( m_menuItemProjectSaveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectSaveAs ) );
	this->Connect( m_menuItemQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnQuit ) );
	this->Connect( m_menuItemUndo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnUndo ) );
	this->Connect( m_menuItemRedo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRedo ) );
	this->Connect( m_menuItemObjectModify->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectModify ) );
	this->Connect( m_menuItemObjectFlipNormals->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectFlipNormals ) );
	this->Connect( m_menuItemObjectLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectLoad ) );
	this->Connect( m_menuItemObjectRename->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectRename ) );
	this->Connect( m_menuItemObjectDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectDelete ) );
	this->Connect( m_menuItemStockOrganize->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnStockEdit ) );
	this->Connect( m_menuItemStockToWorkpiece->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceAdd ) );
	this->Connect( m_menuItemWorkpieceSetup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceSetup ) );
	this->Connect( m_menuItemWorkpieceDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceDelete ) );
	this->Connect( m_menuItemWorkpieceDeleteUnused->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceDeleteUnused ) );
	this->Connect( m_menuItemRunSetup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunEdit ) );
	this->Connect( m_menuItemRunAdd->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunAdd ) );
	this->Connect( m_menuItemRunDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunDelete ) );
	this->Connect( m_menuItemMachineLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineLoad ) );
	this->Connect( m_menuItemMachineReload->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineReload ) );
	this->Connect( m_menuItemMachineDebugger->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineDebugger ) );
	this->Connect( m_menuItemFlipDrill->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnFlipDrillSetup ) );
	this->Connect( m_menuItemToolboxEdit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxEdit ) );
	this->Connect( m_menuItemToolboxLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxLoad ) );
	this->Connect( m_menuItemToolboxSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxSave ) );
	this->Connect( m_menuItemGeneratorSetup->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSetup ) );
	this->Connect( m_menuItemGeneratorAutomatic->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorAutomatic ) );
	this->Connect( m_menuItemGeneratorRestart->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorRestart ) );
	this->Connect( m_menuItemGeneratorSaveToolpath->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSaveToolpath ) );
	this->Connect( m_menuItemShowAnimationControl->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnShowAnimationControl ) );
	this->Connect( m_menuItemSetupLanguage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnChangeLanguage ) );
	this->Connect( m_menuItemActivateStereo3D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnActivateStereo3D ) );
	this->Connect( m_menuItemSetupController->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupController ) );
	this->Connect( m_menuItemSetupStereo3D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupStereo3D ) );
	this->Connect( m_menuItemSetupUnits->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupUnits ) );
	this->Connect( m_menuItemCloseAdditionalWindows->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnExtraWindowClose ) );
	this->Connect( m_menuItemLogShow->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnShowLogWindow ) );
	this->Connect( m_menuItemTop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuItemBottom->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuItemFront->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuItemBack->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuItemLeft->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuItemRight->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Connect( m_menuAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnAbout ) );
	m_tree->Connect( wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, wxTreeEventHandler( GUIMainFrame::OnBeginLabelEdit ), NULL, this );
	m_tree->Connect( wxEVT_COMMAND_TREE_END_LABEL_EDIT, wxTreeEventHandler( GUIMainFrame::OnEndLabelEdit ), NULL, this );
	m_tree->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( GUIMainFrame::OnActivate ), NULL, this );
	m_tree->Connect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( GUIMainFrame::OnActivateRightClickMenu ), NULL, this );
	m_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( GUIMainFrame::OnSelectionChanged ), NULL, this );
	m_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( GUIMainFrame::OnSelectionChanging ), NULL, this );
	m_canvas->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIMainFrame::On3DSelect ), NULL, this );
	this->Connect( wxID_UNDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnUndo ) );
	this->Connect( wxID_REDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnRedo ) );
	this->Connect( ID_DISPLAYMACHINE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnToolbarButton ) );
	this->Connect( ID_DISPLAYMATERIAL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnToolbarButton ) );
	this->Connect( ID_GENERATORSETUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSetup ) );
}

GUIMainFrame::~GUIMainFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectNew ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectRename ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnProjectSaveAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnUndo ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRedo ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectModify ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectFlipNormals ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectRename ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnObjectDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnStockEdit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceAdd ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceSetup ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnWorkpieceDeleteUnused ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunEdit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunAdd ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnRunDelete ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineReload ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnMachineDebugger ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnFlipDrillSetup ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxEdit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnToolboxSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSetup ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorAutomatic ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorRestart ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSaveToolpath ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnShowAnimationControl ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnChangeLanguage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnActivateStereo3D ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupController ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupStereo3D ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnSetupUnits ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnExtraWindowClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnShowLogWindow ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnViewSet ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMainFrame::OnAbout ) );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, wxTreeEventHandler( GUIMainFrame::OnBeginLabelEdit ), NULL, this );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_END_LABEL_EDIT, wxTreeEventHandler( GUIMainFrame::OnEndLabelEdit ), NULL, this );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( GUIMainFrame::OnActivate ), NULL, this );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( GUIMainFrame::OnActivateRightClickMenu ), NULL, this );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( GUIMainFrame::OnSelectionChanged ), NULL, this );
	m_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGING, wxTreeEventHandler( GUIMainFrame::OnSelectionChanging ), NULL, this );
	m_canvas->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GUIMainFrame::On3DSelect ), NULL, this );
	this->Disconnect( wxID_UNDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnUndo ) );
	this->Disconnect( wxID_REDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnRedo ) );
	this->Disconnect( ID_DISPLAYMACHINE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnToolbarButton ) );
	this->Disconnect( ID_DISPLAYMATERIAL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnToolbarButton ) );
	this->Disconnect( ID_GENERATORSETUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIMainFrame::OnGeneratorSetup ) );
}

GUIObjectTransformation::GUIObjectTransformation( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuObject = new wxMenu();
	wxMenuItem* m_menuItemOpen;
	m_menuItemOpen = new wxMenuItem( m_menuObject, ID_OBJECTLOAD, wxString( _("&Load Object") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemOpen );
	
	wxMenuItem* m_menuItemObjectRename;
	m_menuItemObjectRename = new wxMenuItem( m_menuObject, ID_OBJECTRENAME, wxString( _("&Rename Object") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemObjectRename );
	
	wxMenuItem* m_menuItemFlipNormals;
	m_menuItemFlipNormals = new wxMenuItem( m_menuObject, ID_OBJECTFLIPNORMALS, wxString( _("Flip normal vectors") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemFlipNormals );
	
	wxMenuItem* m_separator;
	m_separator = m_menuObject->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuObject, wxID_CLOSE, wxString( _("&Close Window") ) + wxT('\t') + wxT("Ctrl+M"), wxEmptyString, wxITEM_NORMAL );
	m_menuObject->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuObject, _("&Object") );
	
	m_menuEdit = new wxMenu();
	wxMenuItem* m_menuItemUndo;
	m_menuItemUndo = new wxMenuItem( m_menuEdit, wxID_UNDO, wxString( _("Undo") ) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemUndo );
	
	wxMenuItem* m_menuItemRedo;
	m_menuItemRedo = new wxMenuItem( m_menuEdit, wxID_REDO, wxString( _("Redo") ) + wxT('\t') + wxT("CTRL+Y"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemRedo );
	
	m_menubar->Append( m_menuEdit, _("&Edit") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItemSetupUnits;
	m_menuItemSetupUnits = new wxMenuItem( m_menuSettings, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupUnits );
	
	m_menubar->Append( m_menuSettings, _("&Settings") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_choiceObjectSelectionChoices;
	m_choiceObjectSelection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceObjectSelectionChoices, 0 );
	m_choiceObjectSelection->SetSelection( 0 );
	bSizer22->Add( m_choiceObjectSelection, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer21->Add( bSizer22, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Current size of object") ), wxHORIZONTAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	sbSizer3->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSizeX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT );
	sbSizer3->Add( m_textCtrlSizeX, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitX = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX->Wrap( -1 );
	sbSizer3->Add( m_staticTextUnitX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText38 = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	sbSizer3->Add( m_staticText38, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSizeY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT );
	sbSizer3->Add( m_textCtrlSizeY, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitY = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY->Wrap( -1 );
	sbSizer3->Add( m_staticTextUnitY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, _("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	sbSizer3->Add( m_staticText39, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSizeZ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT );
	sbSizer3->Add( m_textCtrlSizeZ, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitZ = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ->Wrap( -1 );
	sbSizer3->Add( m_staticTextUnitZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer21->Add( sbSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelScale = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panelScale, wxID_ANY, _("Quick scale:") ), wxHORIZONTAL );
	
	m_buttonMultTen = new wxButton( m_panelScale, ID_MULTTEN, _("XYZ * 10"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_buttonMultTen, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonDivTen = new wxButton( m_panelScale, ID_DIVTEN, _("XYZ / 10"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_buttonDivTen, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer29->Add( sbSizer11, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer101;
	sbSizer101 = new wxStaticBoxSizer( new wxStaticBox( m_panelScale, wxID_ANY, _("Calculate scaling factors") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer91;
	fgSizer91 = new wxFlexGridSizer( 3, 4, 0, 0 );
	fgSizer91->SetFlexibleDirection( wxBOTH );
	fgSizer91->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText44 = new wxStaticText( m_panelScale, wxID_ANY, _("X ="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	fgSizer91->Add( m_staticText44, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlScaleUnitX = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer91->Add( m_textCtrlScaleUnitX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitX2 = new wxStaticText( m_panelScale, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX2->Wrap( -1 );
	fgSizer91->Add( m_staticTextUnitX2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button19 = new wxButton( m_panelScale, ID_SCALEUNITX, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer91->Add( m_button19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText46 = new wxStaticText( m_panelScale, wxID_ANY, _("Y ="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	fgSizer91->Add( m_staticText46, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlScaleUnitY = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer91->Add( m_textCtrlScaleUnitY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitY2 = new wxStaticText( m_panelScale, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY2->Wrap( -1 );
	fgSizer91->Add( m_staticTextUnitY2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button21 = new wxButton( m_panelScale, ID_SCALEUNITY, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer91->Add( m_button21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText52 = new wxStaticText( m_panelScale, wxID_ANY, _("Z ="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	fgSizer91->Add( m_staticText52, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlScaleUnitZ = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer91->Add( m_textCtrlScaleUnitZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitZ2 = new wxStaticText( m_panelScale, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ2->Wrap( -1 );
	fgSizer91->Add( m_staticTextUnitZ2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button23 = new wxButton( m_panelScale, ID_SCALEUNITZ, _("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer91->Add( m_button23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer101->Add( fgSizer91, 0, wxEXPAND, 5 );
	
	m_checkBoxScaleProportionally = new wxCheckBox( m_panelScale, wxID_ANY, _("Scale proportionally"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxScaleProportionally->SetValue(true); 
	sbSizer101->Add( m_checkBoxScaleProportionally, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	bSizer24->Add( sbSizer101, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panelScale, wxID_ANY, _("Rescale") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 4, 4, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText50 = new wxStaticText( m_panelScale, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	fgSizer6->Add( m_staticText50, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlScalePercentX = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer6->Add( m_textCtrlScalePercentX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText51 = new wxStaticText( m_panelScale, wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer6->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button20 = new wxButton( m_panelScale, ID_SCALEPERCENTX, _("Scale"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_button20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText48 = new wxStaticText( m_panelScale, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	fgSizer6->Add( m_staticText48, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlScalePercentY = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer6->Add( m_textCtrlScalePercentY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText55 = new wxStaticText( m_panelScale, wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	fgSizer6->Add( m_staticText55, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button22 = new wxButton( m_panelScale, ID_SCALEPERCENTY, _("Scale"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_button22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText54 = new wxStaticText( m_panelScale, wxID_ANY, _("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	fgSizer6->Add( m_staticText54, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlScalePercentZ = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer6->Add( m_textCtrlScalePercentZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText43 = new wxStaticText( m_panelScale, wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	fgSizer6->Add( m_staticText43, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button24 = new wxButton( m_panelScale, ID_SCALEPERCENTZ, _("Scale"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_button24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText68 = new wxStaticText( m_panelScale, wxID_ANY, _("Proportional:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText68->Wrap( -1 );
	fgSizer6->Add( m_staticText68, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlScalePercent = new wxTextCtrl( m_panelScale, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer6->Add( m_textCtrlScalePercent, 0, wxALL, 5 );
	
	m_staticText49 = new wxStaticText( m_panelScale, wxID_ANY, _("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	fgSizer6->Add( m_staticText49, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button15 = new wxButton( m_panelScale, ID_SCALEPERCENT, _("Scale"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_button15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer4->Add( fgSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer24->Add( sbSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer29->Add( bSizer24, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelScale->SetSizer( bSizer29 );
	m_panelScale->Layout();
	bSizer29->Fit( m_panelScale );
	m_notebook->AddPage( m_panelScale, _("Scale"), true );
	m_panelMove = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer34->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panelMove, wxID_ANY, _("Move") ), wxVERTICAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText62 = new wxStaticText( m_panelMove, wxID_ANY, _("Step:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	bSizer37->Add( m_staticText62, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlMoveStep = new wxTextCtrl( m_panelMove, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer37->Add( m_textCtrlMoveStep, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitMove = new wxStaticText( m_panelMove, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitMove->Wrap( -1 );
	bSizer37->Add( m_staticTextUnitMove, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer9->Add( bSizer37, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer8->Add( 0, 0, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_bpButton6 = new wxBitmapButton( m_panelMove, ID_MOVEZP, wxBitmap( arrowzp_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton6, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton7 = new wxBitmapButton( m_panelMove, ID_MOVEYP, wxBitmap( arrowyp_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton7, 0, wxTOP|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton8 = new wxBitmapButton( m_panelMove, ID_MOVEXN, wxBitmap( arrowxn_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton8, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer8->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton9 = new wxBitmapButton( m_panelMove, ID_MOVEXP, wxBitmap( arrowxp_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton9, 0, wxRIGHT|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bpButton10 = new wxBitmapButton( m_panelMove, ID_MOVEYN, wxBitmap( arrowyn_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton10, 0, wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bpButton11 = new wxBitmapButton( m_panelMove, ID_MOVEZN, wxBitmap( arrowzn_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer8->Add( m_bpButton11, 0, wxBOTTOM|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer8->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	sbSizer9->Add( fgSizer8, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer34->Add( sbSizer9, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer34->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panelMove, wxID_ANY, _("Align") ), wxVERTICAL );
	
	m_button18 = new wxButton( m_panelMove, ID_ALIGNTOP, _("Align with top"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_button18, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_button17 = new wxButton( m_panelMove, ID_ALIGNMIDDLE, _("Align with middle"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_button17, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_button16 = new wxButton( m_panelMove, ID_ALIGNBOTTOM, _("Align with bottom"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_button16, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer34->Add( sbSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer34->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panelMove->SetSizer( bSizer34 );
	m_panelMove->Layout();
	bSizer34->Fit( m_panelMove );
	m_notebook->AddPage( m_panelMove, _("Move"), false );
	m_panelRotate = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer291;
	bSizer291 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer291->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panelRotate, wxID_ANY, _("Rotate stepwise") ), wxVERTICAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText76 = new wxStaticText( m_panelRotate, wxID_ANY, _("Step:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText76->Wrap( -1 );
	bSizer40->Add( m_staticText76, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlRotateStep = new wxTextCtrl( m_panelRotate, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer40->Add( m_textCtrlRotateStep, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitAngle = new wxStaticText( m_panelRotate, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitAngle->Wrap( -1 );
	bSizer40->Add( m_staticTextUnitAngle, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer8->Add( bSizer40, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_button32 = new wxButton( m_panelRotate, ID_ROTATEYN, _("Y -"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button32, 0, wxALL, 5 );
	
	m_button33 = new wxButton( m_panelRotate, ID_ROTATEXN, _("X -"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button33, 0, wxALL, 5 );
	
	m_button28 = new wxButton( m_panelRotate, ID_ROTATEYP, _("Y +"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button28, 0, wxALL, 5 );
	
	m_button29 = new wxButton( m_panelRotate, ID_ROTATEZN, _("Z -"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button29, 0, wxALL, 5 );
	
	
	fgSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button30 = new wxButton( m_panelRotate, ID_ROTATEZP, _("Z +"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button30, 0, wxALL, 5 );
	
	
	fgSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button31 = new wxButton( m_panelRotate, ID_ROTATEXP, _("X +"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_button31, 0, wxALL, 5 );
	
	
	fgSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	sbSizer8->Add( fgSizer9, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer291->Add( sbSizer8, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer291->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelRotate->SetSizer( bSizer291 );
	m_panelRotate->Layout();
	bSizer291->Fit( m_panelRotate );
	m_notebook->AddPage( m_panelRotate, _("Rotate"), false );
	m_panelMirror = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer36->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panelMirror, wxID_ANY, _("Mirror on") ), wxVERTICAL );
	
	m_button39 = new wxButton( m_panelMirror, ID_FLIPX, _("X axis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer10->Add( m_button39, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_button40 = new wxButton( m_panelMirror, ID_FLIPY, _("Y axis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer10->Add( m_button40, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_button41 = new wxButton( m_panelMirror, ID_FLIPZ, _("Z axis"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer10->Add( m_button41, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer36->Add( sbSizer10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer36->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonFlipNormalVectors = new wxButton( m_panelMirror, ID_OBJECTFLIPNORMALS, _("Flip normal vectors"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( m_buttonFlipNormalVectors, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer36->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelMirror->SetSizer( bSizer36 );
	m_panelMirror->Layout();
	bSizer36->Fit( m_panelMirror );
	m_notebook->AddPage( m_panelMirror, _("Mirror"), false );
	
	bSizer21->Add( m_notebook, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer21 );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIObjectTransformation::OnClose ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIObjectTransformation::OnClose ) );
	m_choiceObjectSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIObjectTransformation::OnSelectObject ), NULL, this );
	m_buttonMultTen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_buttonDivTen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button32->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button33->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button39->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button40->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button41->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_buttonFlipNormalVectors->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnFlipNormals ), NULL, this );
}

GUIObjectTransformation::~GUIObjectTransformation()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIObjectTransformation::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIObjectTransformation::OnClose ) );
	m_choiceObjectSelection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIObjectTransformation::OnSelectObject ), NULL, this );
	m_buttonMultTen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_buttonDivTen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnSetFactors ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_bpButton11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button32->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button33->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button39->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button40->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_button41->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnTransform ), NULL, this );
	m_buttonFlipNormalVectors->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIObjectTransformation::OnFlipNormals ), NULL, this );
}

GUIStockMaterial::GUIStockMaterial( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuStock = new wxMenu();
	wxMenuItem* m_menuItem43;
	m_menuItem43 = new wxMenuItem( m_menuStock, wxID_ANY, wxString( _("&Load Stocklist...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItem43 );
	
	wxMenuItem* m_menuItem42;
	m_menuItem42 = new wxMenuItem( m_menuStock, wxID_ANY, wxString( _("&Save Stocklist...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItem42 );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menuStock->AppendSeparator();
	
	wxMenuItem* m_menuItem34;
	m_menuItem34 = new wxMenuItem( m_menuStock, wxID_CLOSE, wxString( _("&Close Window") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItem34 );
	
	m_menubar->Append( m_menuStock, _("&Stock") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItem23;
	m_menuItem23 = new wxMenuItem( m_menuSettings, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItem23 );
	
	m_menubar->Append( m_menuSettings, _("S&ettings") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer55->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText96 = new wxStaticText( this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	bSizer55->Add( m_staticText96, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_textCtrlName, 3, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer55->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer20->Add( bSizer55, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Length (in X):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer4->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer4->Add( m_textCtrlX, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitX = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX->Wrap( -1 );
	fgSizer4->Add( m_staticTextUnitX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, _("Width (in Y):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer4->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer4->Add( m_textCtrlY, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitY = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY->Wrap( -1 );
	fgSizer4->Add( m_staticTextUnitY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Height (in Z):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer4->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlZ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer4->Add( m_textCtrlZ, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitZ = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ->Wrap( -1 );
	fgSizer4->Add( m_staticTextUnitZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer52->Add( fgSizer4, 0, wxALIGN_BOTTOM, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, _("Max speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer13->Add( m_staticText33, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlMaxSpeed = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer13->Add( m_textCtrlMaxSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitRotationalSpeed = new wxStaticText( this, wxID_ANY, _("rpm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitRotationalSpeed->Wrap( -1 );
	fgSizer13->Add( m_staticTextUnitRotationalSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText35 = new wxStaticText( this, wxID_ANY, _("Max feedrate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer13->Add( m_staticText35, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlMaxFeedrate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizer13->Add( m_textCtrlMaxFeedrate, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitLinearSpeed = new wxStaticText( this, wxID_ANY, _("mm/s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitLinearSpeed->Wrap( -1 );
	fgSizer13->Add( m_staticTextUnitLinearSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer53->Add( fgSizer13, 0, 0, 5 );
	
	bSizer52->Add( bSizer53, 0, wxALIGN_BOTTOM, 5 );
	
	bSizer20->Add( bSizer52, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_checkBoxAvailable = new wxCheckBox( this, wxID_ANY, _("available in workshop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxAvailable->SetToolTip( _("Pieces of stock material can be set to \"available\". This allows the (not yet written) autosetup function to know what is really available in the workshop. Thus stock that is not available needs not to be deleted.") );
	
	bSizer20->Add( m_checkBoxAvailable, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonStockAdd = new wxButton( this, wxID_ANY, _("Add / Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_buttonStockAdd, 0, wxALL, 5 );
	
	m_buttonStockDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_buttonStockDelete, 0, wxALL, 5 );
	
	bSizer20->Add( bSizer54, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_listCtrl = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer20->Add( m_listCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIStockMaterial::OnClose ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( GUIStockMaterial::OnSize ) );
	this->Connect( m_menuItem34->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIStockMaterial::OnClose ) );
	m_buttonStockAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIStockMaterial::OnAddUpdate ), NULL, this );
	m_buttonStockDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIStockMaterial::OnDelete ), NULL, this );
	m_listCtrl->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( GUIStockMaterial::OnActivate ), NULL, this );
	m_listCtrl->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIStockMaterial::OnSelected ), NULL, this );
}

GUIStockMaterial::~GUIStockMaterial()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIStockMaterial::OnClose ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GUIStockMaterial::OnSize ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIStockMaterial::OnClose ) );
	m_buttonStockAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIStockMaterial::OnAddUpdate ), NULL, this );
	m_buttonStockDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIStockMaterial::OnDelete ), NULL, this );
	m_listCtrl->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( GUIStockMaterial::OnActivate ), NULL, this );
	m_listCtrl->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIStockMaterial::OnSelected ), NULL, this );
}

GUIWorkpiece::GUIWorkpiece( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuStock = new wxMenu();
	wxMenuItem* m_menuItemManageStock;
	m_menuItemManageStock = new wxMenuItem( m_menuStock, ID_STOCKORGANIZE, wxString( _("&Manage Stock") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemManageStock );
	
	wxMenuItem* m_separator13;
	m_separator13 = m_menuStock->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuStock, wxID_CLOSE, wxString( _("&Close") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuStock->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuStock, _("&Stock") );
	
	m_menuEdit = new wxMenu();
	wxMenuItem* m_menuItemUndo;
	m_menuItemUndo = new wxMenuItem( m_menuEdit, wxID_UNDO, wxString( _("&Undo") ) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemUndo );
	
	wxMenuItem* m_menuItemRedo;
	m_menuItemRedo = new wxMenuItem( m_menuEdit, wxID_REDO, wxString( _("&Redo") ) + wxT('\t') + wxT("CTRL+Y"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemRedo );
	
	m_menubar->Append( m_menuEdit, _("&Edit") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText97 = new wxStaticText( this, wxID_ANY, _("Stock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	bSizer57->Add( m_staticText97, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceStockChoices;
	m_choiceStock = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceStockChoices, 0 );
	m_choiceStock->SetSelection( 0 );
	bSizer57->Add( m_choiceStock, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_buttonAdd, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer57->Add( bSizer58, 0, 0, 5 );
	
	bSizer56->Add( bSizer57, 0, wxEXPAND, 5 );
	
	m_grid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid->CreateGrid( 2, 2 );
	m_grid->EnableEditing( false );
	m_grid->EnableGridLines( true );
	m_grid->EnableDragGridSize( false );
	m_grid->SetMargins( 0, 0 );
	
	// Columns
	m_grid->EnableDragColMove( false );
	m_grid->EnableDragColSize( true );
	m_grid->SetColLabelSize( 30 );
	m_grid->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Rows
	m_grid->EnableDragRowSize( true );
	m_grid->SetRowLabelSize( 60 );
	m_grid->SetRowLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer56->Add( m_grid, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer56 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIWorkpiece::OnClose ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( GUIWorkpiece::OnSize ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIWorkpiece::OnClose ) );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIWorkpiece::OnAddStock ), NULL, this );
	m_grid->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUIWorkpiece::OnDBLClick ), NULL, this );
	m_grid->Connect( wxEVT_SIZE, wxSizeEventHandler( GUIWorkpiece::OnSize ), NULL, this );
}

GUIWorkpiece::~GUIWorkpiece()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIWorkpiece::OnClose ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GUIWorkpiece::OnSize ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIWorkpiece::OnClose ) );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIWorkpiece::OnAddStock ), NULL, this );
	m_grid->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( GUIWorkpiece::OnDBLClick ), NULL, this );
	m_grid->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GUIWorkpiece::OnSize ), NULL, this );
}

GUIPlacement::GUIPlacement( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuEdit = new wxMenu();
	wxMenuItem* m_menuItemUndo;
	m_menuItemUndo = new wxMenuItem( m_menuEdit, wxID_UNDO, wxString( _("&Undo") ) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemUndo );
	
	wxMenuItem* m_menuItemRedo;
	m_menuItemRedo = new wxMenuItem( m_menuEdit, wxID_REDO, wxString( _("&Redo") ) + wxT('\t') + wxT("CTRL+Y"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemRedo );
	
	wxMenuItem* m_separator14;
	m_separator14 = m_menuEdit->AppendSeparator();
	
	wxMenuItem* m_menuItemSetupUnits;
	m_menuItemSetupUnits = new wxMenuItem( m_menuEdit, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemSetupUnits );
	
	wxMenuItem* m_separator16;
	m_separator16 = m_menuEdit->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuEdit, wxID_CLOSE, wxString( _("&Close") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuEdit, _("&Edit") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString m_choiceWorkpieceChoices;
	m_choiceWorkpiece = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceWorkpieceChoices, 0 );
	m_choiceWorkpiece->SetSelection( 0 );
	bSizer68->Add( m_choiceWorkpiece, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString m_choicePlacementChoices;
	m_choicePlacement = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePlacementChoices, 0 );
	m_choicePlacement->SetSelection( 0 );
	bSizer68->Add( m_choicePlacement, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizer68->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText100 = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	bSizer69->Add( m_staticText100, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlX = new wxTextCtrl( this, ID_POSX, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer69->Add( m_textCtrlX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitX = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX->Wrap( -1 );
	bSizer69->Add( m_staticTextUnitX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText102 = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer69->Add( m_staticText102, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlY = new wxTextCtrl( this, ID_POSY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer69->Add( m_textCtrlY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitY = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY->Wrap( -1 );
	bSizer69->Add( m_staticTextUnitY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText104 = new wxStaticText( this, wxID_ANY, _("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText104->Wrap( -1 );
	bSizer69->Add( m_staticText104, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlZ = new wxTextCtrl( this, ID_POSZ, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer69->Add( m_textCtrlZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitZ = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ->Wrap( -1 );
	bSizer69->Add( m_staticTextUnitZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer68->Add( bSizer69, 0, 0, 5 );
	
	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText106 = new wxStaticText( this, wxID_ANY, _("Angle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	bSizer70->Add( m_staticText106, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAngle = new wxTextCtrl( this, ID_ANGLE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer70->Add( m_textCtrlAngle, 0, wxALL, 5 );
	
	m_staticTextunitAngle = new wxStaticText( this, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextunitAngle->Wrap( -1 );
	bSizer70->Add( m_staticTextunitAngle, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderAngle = new wxSlider( this, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer70->Add( m_sliderAngle, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer68->Add( bSizer70, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );
	
	m_radioBtnBox = new wxRadioButton( this, ID_FORMBOX, _("Box"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer71->Add( m_radioBtnBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_radioBtnContour = new wxRadioButton( this, ID_FORMCONTOUR, _("Contour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnContour->Enable( false );
	
	bSizer71->Add( m_radioBtnContour, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer71->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText108 = new wxStaticText( this, wxID_ANY, _("Distance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	bSizer71->Add( m_staticText108, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDistance = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer71->Add( m_textCtrlDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitDistance = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitDistance->Wrap( -1 );
	bSizer71->Add( m_staticTextUnitDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer68->Add( bSizer71, 0, wxEXPAND, 5 );
	
	bSizer66->Add( bSizer68, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 3, 3, 0, 0 );
	
	
	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButtonYP = new wxBitmapButton( this, ID_MOVEYP, wxBitmap( arrowyu_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButtonYP, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButtonXN = new wxBitmapButton( this, ID_MOVEXN, wxBitmap( arrowxn_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButtonXN, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButtonXP = new wxBitmapButton( this, ID_MOVEXP, wxBitmap( arrowxp_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButtonXP, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpButtonYM = new wxBitmapButton( this, ID_MOVEYN, wxBitmap( arrowyd_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButtonYM, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer66->Add( gSizer1, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAlignTop = new wxButton( this, ID_ALIGNTOP, _("Align with Top"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer67->Add( m_buttonAlignTop, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonAlignMiddle = new wxButton( this, ID_ALIGNMIDDLE, _("Align with Middle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer67->Add( m_buttonAlignMiddle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonAlignBottom = new wxButton( this, ID_ALIGNBOTTOM, _("Align with Bottom"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer67->Add( m_buttonAlignBottom, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer66->Add( bSizer67, 0, wxALIGN_BOTTOM, 5 );
	
	bSizerMain->Add( bSizer66, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_topview = new PanelTopView(this);
	bSizerMain->Add( m_topview, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIPlacement::OnClose ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( GUIPlacement::OnSize ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIPlacement::OnClose ) );
	m_choiceWorkpiece->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectWorkpiece ), NULL, this );
	m_choicePlacement->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectObject ), NULL, this );
	m_textCtrlX->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlY->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlZ->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlAngle->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_sliderAngle->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIPlacement::OnChangeSlider ), NULL, this );
	m_radioBtnBox->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_radioBtnContour->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_textCtrlDistance->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_bpButtonYP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonXN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonXP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonYM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignTop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignMiddle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignBottom->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
}

GUIPlacement::~GUIPlacement()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIPlacement::OnClose ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GUIPlacement::OnSize ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIPlacement::OnClose ) );
	m_choiceWorkpiece->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectWorkpiece ), NULL, this );
	m_choicePlacement->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectObject ), NULL, this );
	m_textCtrlX->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlY->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlZ->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_textCtrlAngle->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnChangePosition ), NULL, this );
	m_sliderAngle->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIPlacement::OnChangeSlider ), NULL, this );
	m_radioBtnBox->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_radioBtnContour->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_textCtrlDistance->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIPlacement::OnSelectForm ), NULL, this );
	m_bpButtonYP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonXN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonXP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_bpButtonYM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignTop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignMiddle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
	m_buttonAlignBottom->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIPlacement::OnTransform ), NULL, this );
}

GUIRun::GUIRun( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuEdit = new wxMenu();
	wxMenuItem* m_menuItemUndo;
	m_menuItemUndo = new wxMenuItem( m_menuEdit, wxID_UNDO, wxString( _("&Undo") ) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemUndo );
	
	wxMenuItem* m_menuItemRedo;
	m_menuItemRedo = new wxMenuItem( m_menuEdit, wxID_REDO, wxString( _("&Redo") ) + wxT('\t') + wxT("CTRL+Y"), wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemRedo );
	
	wxMenuItem* m_separator9;
	m_separator9 = m_menuEdit->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuEdit, wxID_CLOSE, wxString( _("&Close Window") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuEdit->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuEdit, _("Edit") );
	
	m_menuToolbox = new wxMenu();
	wxMenuItem* m_menuItemToolboxLoad;
	m_menuItemToolboxLoad = new wxMenuItem( m_menuToolbox, ID_TOOLBOXLOAD, wxString( _("&Load Toolbox") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuToolbox->Append( m_menuItemToolboxLoad );
	
	m_menubar->Append( m_menuToolbox, _("&Toolbox") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItemSetupUnits;
	m_menuItemSetupUnits = new wxMenuItem( m_menuSettings, ID_SETUPUNITS, wxString( _("Setup &Units") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemSetupUnits );
	
	m_menubar->Append( m_menuSettings, _("&Settings") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString m_choiceRunChoices;
	m_choiceRun = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRunChoices, 0 );
	m_choiceRun->SetSelection( 0 );
	bSizer51->Add( m_choiceRun, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerStock;
	sbSizerStock = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Workpiece") ), wxVERTICAL );
	
	wxArrayString m_choiceWorkpieceChoices;
	m_choiceWorkpiece = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceWorkpieceChoices, 0 );
	m_choiceWorkpiece->SetSelection( 0 );
	sbSizerStock->Add( m_choiceWorkpiece, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonRotX90 = new wxButton( this, ID_WORKPIECEROTATEX, _("rotate X"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_buttonRotX90, 0, wxALL, 5 );
	
	m_buttonRotY90 = new wxButton( this, ID_WORKPIECEROTATEY, _("rotate Y"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_buttonRotY90, 0, wxALL, 5 );
	
	m_buttonRotZ90 = new wxButton( this, ID_WORKPIECEROTATEZ, _("rotate Z"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_buttonRotZ90, 0, wxALL, 5 );
	
	sbSizerStock->Add( bSizer15, 0, wxALIGN_RIGHT, 5 );
	
	bSizer51->Add( sbSizerStock, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizerMachine;
	sbSizerMachine = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Machine") ), wxVERTICAL );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrlMachineName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer61->Add( m_textCtrlMachineName, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonLoadMachine = new wxButton( this, wxID_ANY, _("Load Machine"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_buttonLoadMachine, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	sbSizerMachine->Add( bSizer61, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText99 = new wxStaticText( this, wxID_ANY, _("Tools"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	sbSizerMachine->Add( m_staticText99, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrlTools = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer65->Add( m_listCtrlTools, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonToolDelete = new wxButton( this, wxID_ANY, _("Remove from Machine"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer65->Add( m_buttonToolDelete, 0, wxALL, 5 );
	
	bSizer62->Add( bSizer65, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString m_choiceToolChoices;
	m_choiceTool = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceToolChoices, 0 );
	m_choiceTool->SetSelection( 0 );
	bSizer63->Add( m_choiceTool, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText100 = new wxStaticText( this, wxID_ANY, _("Toolslot:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	bSizer64->Add( m_staticText100, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinCtrlToolSlot = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 1 );
	bSizer64->Add( m_spinCtrlToolSlot, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonToolAdd = new wxButton( this, wxID_ANY, _("Add to Machine"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer64->Add( m_buttonToolAdd, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer63->Add( bSizer64, 0, wxALIGN_RIGHT, 5 );
	
	bSizer62->Add( bSizer63, 1, wxEXPAND, 5 );
	
	sbSizerMachine->Add( bSizer62, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer51->Add( sbSizerMachine, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer51 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIRun::OnClose ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIRun::OnClose ) );
	m_choiceRun->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIRun::OnRunSelect ), NULL, this );
	m_choiceWorkpiece->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIRun::OnWorkpieceSelect ), NULL, this );
	m_buttonRotX90->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonRotY90->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonRotZ90->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonLoadMachine->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnMachineLoad ), NULL, this );
	m_buttonToolDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnToolRemove ), NULL, this );
	m_buttonToolAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnToolAdd ), NULL, this );
}

GUIRun::~GUIRun()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIRun::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIRun::OnClose ) );
	m_choiceRun->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIRun::OnRunSelect ), NULL, this );
	m_choiceWorkpiece->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIRun::OnWorkpieceSelect ), NULL, this );
	m_buttonRotX90->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonRotY90->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonRotZ90->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnRotate ), NULL, this );
	m_buttonLoadMachine->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnMachineLoad ), NULL, this );
	m_buttonToolDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnToolRemove ), NULL, this );
	m_buttonToolAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIRun::OnToolAdd ), NULL, this );
}

GUIMachineDebugger::GUIMachineDebugger( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuMachine = new wxMenu();
	wxMenuItem* m_menuItemLoad;
	m_menuItemLoad = new wxMenuItem( m_menuMachine, wxID_LOAD, wxString( _("&Load Machine Description") ) + wxT('\t') + wxT("CTRL+L"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemLoad );
	
	wxMenuItem* m_menuItemSave;
	m_menuItemSave = new wxMenuItem( m_menuMachine, wxID_SAVE, wxString( _("&Save Machine Description") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemSave );
	
	wxMenuItem* m_separator18;
	m_separator18 = m_menuMachine->AppendSeparator();
	
	wxMenuItem* m_menuItemMachineReevaluateScript;
	m_menuItemMachineReevaluateScript = new wxMenuItem( m_menuMachine, wxID_ANY, wxString( _("&Evaluate Script") ) + wxT('\t') + wxT("CTRL+E"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemMachineReevaluateScript );
	
	wxMenuItem* m_menuItemShowControl;
	m_menuItemShowControl = new wxMenuItem( m_menuMachine, wxID_ANY, wxString( _("&Show Controller") ) + wxT('\t') + wxT("CTRL+SHIFT+C"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemShowControl );
	
	wxMenuItem* m_separator12;
	m_separator12 = m_menuMachine->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuMachine, wxID_CLOSE, wxString( _("Close Window") ) + wxT('\t') + wxT("CTRL+D"), wxEmptyString, wxITEM_NORMAL );
	m_menuMachine->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuMachine, _("&Machine") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItemEnable3D;
	m_menuItemEnable3D = new wxMenuItem( m_menuSettings, wxID_ANY, wxString( _("Enable &3D") ) + wxT('\t') + wxT("CTRL+3"), wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemEnable3D );
	
	m_menubar->Append( m_menuSettings, _("&Settings") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->SetMinimumPaneSize( 200 );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( GUIMachineDebugger::m_splitter2OnIdle ), NULL, this );
	m_panel = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter3 = new wxSplitterWindow( m_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter3->SetSashGravity( 200 );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( GUIMachineDebugger::m_splitter3OnIdle ), NULL, this );
	m_panelEditor = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrlScript = new wxTextCtrl( m_panelEditor, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_RICH );
	bSizer40->Add( m_textCtrlScript, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_buttonRestart = new wxButton( m_panelEditor, wxID_ANY, _("Evaluate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_buttonRestart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_panelEditor->SetSizer( bSizer40 );
	m_panelEditor->Layout();
	bSizer40->Fit( m_panelEditor );
	m_panelOutput = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrlOutput = new wxTextCtrl( m_panelOutput, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer41->Add( m_textCtrlOutput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_panelOutput->SetSizer( bSizer41 );
	m_panelOutput->Layout();
	bSizer41->Fit( m_panelOutput );
	m_splitter3->SplitHorizontally( m_panelEditor, m_panelOutput, 222 );
	bSizer39->Add( m_splitter3, 1, wxEXPAND, 5 );
	
	m_panel->SetSizer( bSizer39 );
	m_panel->Layout();
	bSizer39->Fit( m_panel );
	m_panelMachineView = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	m_canvas = new MainCanvas(m_panelMachineView);
	bSizer38->Add( m_canvas, 1, wxALL|wxEXPAND, 5 );
	
	m_panelMachineView->SetSizer( bSizer38 );
	m_panelMachineView->Layout();
	bSizer38->Fit( m_panelMachineView );
	m_splitter2->SplitVertically( m_panel, m_panelMachineView, 325 );
	bSizer37->Add( m_splitter2, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer37 );
	this->Layout();
	m_statusBar3 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIMachineDebugger::OnClose ) );
	this->Connect( m_menuItemLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnMachineLoad ) );
	this->Connect( m_menuItemSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnMachineSave ) );
	this->Connect( m_menuItemMachineReevaluateScript->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnScriptEvaluate ) );
	this->Connect( m_menuItemShowControl->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnShowController ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnClose ) );
	m_buttonRestart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIMachineDebugger::OnScriptEvaluate ), NULL, this );
}

GUIMachineDebugger::~GUIMachineDebugger()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIMachineDebugger::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnMachineLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnMachineSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnScriptEvaluate ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnShowController ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineDebugger::OnClose ) );
	m_buttonRestart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIMachineDebugger::OnScriptEvaluate ), NULL, this );
}

GUIMachineControl::GUIMachineControl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar9 = new wxMenuBar( 0 );
	m_menuDialog = new wxMenu();
	wxMenuItem* m_menuItemSetupUnits;
	m_menuItemSetupUnits = new wxMenuItem( m_menuDialog, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuDialog->Append( m_menuItemSetupUnits );
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuDialog, wxID_CLOSE, wxString( _("&Close") ) + wxT('\t') + wxT("CTRL+SHIFT+C"), wxEmptyString, wxITEM_NORMAL );
	m_menuDialog->Append( m_menuItemClose );
	
	m_menubar9->Append( m_menuDialog, _("&Dialog") );
	
	this->SetMenuBar( m_menubar9 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Main Axis") ), wxVERTICAL );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText69 = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText69->Wrap( -1 );
	bSizer42->Add( m_staticText69, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderX = new wxSlider( this, ID_AXISX, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer42->Add( m_sliderX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( bSizer42, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText70 = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText70->Wrap( -1 );
	bSizer43->Add( m_staticText70, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderY = new wxSlider( this, ID_AXISY, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer43->Add( m_sliderY, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( bSizer43, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText71 = new wxStaticText( this, wxID_ANY, _("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	bSizer44->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderZ = new wxSlider( this, ID_AXISZ, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer44->Add( m_sliderZ, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer41->Add( bSizer44, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer12->Add( bSizer41, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText73 = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText73->Wrap( -1 );
	fgSizer10->Add( m_staticText73, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlX = new wxTextCtrl( this, ID_TEXTX, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer10->Add( m_textCtrlX, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitX = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX->Wrap( -1 );
	fgSizer10->Add( m_staticTextUnitX, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText75 = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText75->Wrap( -1 );
	fgSizer10->Add( m_staticText75, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlY = new wxTextCtrl( this, ID_TEXTY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer10->Add( m_textCtrlY, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitY = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY->Wrap( -1 );
	fgSizer10->Add( m_staticTextUnitY, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText77 = new wxStaticText( this, wxID_ANY, _("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77->Wrap( -1 );
	fgSizer10->Add( m_staticText77, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlZ = new wxTextCtrl( this, ID_TEXTZ, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer10->Add( m_textCtrlZ, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitZ = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ->Wrap( -1 );
	fgSizer10->Add( m_staticTextUnitZ, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer12->Add( fgSizer10, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer38->Add( sbSizer12, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer14;
	sbSizer14 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Main Angles") ), wxVERTICAL );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText78 = new wxStaticText( this, wxID_ANY, _("A:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	bSizer46->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderA = new wxSlider( this, ID_AXISA, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer46->Add( m_sliderA, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer45->Add( bSizer46, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText79 = new wxStaticText( this, wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText79->Wrap( -1 );
	bSizer47->Add( m_staticText79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderB = new wxSlider( this, ID_AXISB, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer47->Add( m_sliderB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer45->Add( bSizer47, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText80 = new wxStaticText( this, wxID_ANY, _("C:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText80->Wrap( -1 );
	bSizer48->Add( m_staticText80, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderC = new wxSlider( this, ID_AXISC, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer48->Add( m_sliderC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer45->Add( bSizer48, 0, wxEXPAND, 5 );
	
	sbSizer14->Add( bSizer45, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer101;
	fgSizer101 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer101->SetFlexibleDirection( wxBOTH );
	fgSizer101->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText731 = new wxStaticText( this, wxID_ANY, _("A:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText731->Wrap( -1 );
	fgSizer101->Add( m_staticText731, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlA = new wxTextCtrl( this, ID_TEXTA, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer101->Add( m_textCtrlA, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitA = new wxStaticText( this, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitA->Wrap( -1 );
	fgSizer101->Add( m_staticTextUnitA, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText751 = new wxStaticText( this, wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText751->Wrap( -1 );
	fgSizer101->Add( m_staticText751, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlB = new wxTextCtrl( this, ID_TEXTB, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer101->Add( m_textCtrlB, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitB = new wxStaticText( this, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitB->Wrap( -1 );
	fgSizer101->Add( m_staticTextUnitB, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText771 = new wxStaticText( this, wxID_ANY, _("C:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText771->Wrap( -1 );
	fgSizer101->Add( m_staticText771, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlC = new wxTextCtrl( this, ID_TEXTC, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer101->Add( m_textCtrlC, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitC = new wxStaticText( this, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitC->Wrap( -1 );
	fgSizer101->Add( m_staticTextUnitC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer14->Add( fgSizer101, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer38->Add( sbSizer14, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Additional Axis") ), wxVERTICAL );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText81 = new wxStaticText( this, wxID_ANY, _("U:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer50->Add( m_staticText81, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderU = new wxSlider( this, ID_AXISU, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer50->Add( m_sliderU, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer49->Add( bSizer50, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText82 = new wxStaticText( this, wxID_ANY, _("V:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	bSizer51->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderV = new wxSlider( this, ID_AXISV, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer51->Add( m_sliderV, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer49->Add( bSizer51, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, _("W:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	bSizer52->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderW = new wxSlider( this, ID_AXISW, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer52->Add( m_sliderW, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer49->Add( bSizer52, 0, wxEXPAND, 5 );
	
	sbSizer13->Add( bSizer49, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer102;
	fgSizer102 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer102->SetFlexibleDirection( wxBOTH );
	fgSizer102->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText732 = new wxStaticText( this, wxID_ANY, _("U:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText732->Wrap( -1 );
	fgSizer102->Add( m_staticText732, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlU = new wxTextCtrl( this, ID_TEXTU, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer102->Add( m_textCtrlU, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitU = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitU->Wrap( -1 );
	fgSizer102->Add( m_staticTextUnitU, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText752 = new wxStaticText( this, wxID_ANY, _("V:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText752->Wrap( -1 );
	fgSizer102->Add( m_staticText752, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlV = new wxTextCtrl( this, ID_TEXTV, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer102->Add( m_textCtrlV, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitV = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitV->Wrap( -1 );
	fgSizer102->Add( m_staticTextUnitV, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText772 = new wxStaticText( this, wxID_ANY, _("W:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText772->Wrap( -1 );
	fgSizer102->Add( m_staticText772, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlW = new wxTextCtrl( this, ID_TEXTW, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizer102->Add( m_textCtrlW, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitW = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitW->Wrap( -1 );
	fgSizer102->Add( m_staticTextUnitW, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer13->Add( fgSizer102, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer38->Add( sbSizer13, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer38 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIMachineControl::OnClose ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineControl::OnClose ) );
	m_sliderX->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderY->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderZ->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlX->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlY->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlZ->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_sliderA->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderB->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderC->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlA->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlC->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_sliderU->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderV->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderW->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlU->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlV->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlW->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
}

GUIMachineControl::~GUIMachineControl()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIMachineControl::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIMachineControl::OnClose ) );
	m_sliderX->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderY->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlX->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlY->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlZ->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_sliderA->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderA->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderB->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderC->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderC->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlA->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlC->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_sliderU->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderU->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderV->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderV->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_sliderW->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GUIMachineControl::OnZero ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIMachineControl::OnScroll ), NULL, this );
	m_sliderW->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIMachineControl::OnTrack ), NULL, this );
	m_textCtrlU->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlV->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
	m_textCtrlW->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIMachineControl::OnTextChanged ), NULL, this );
}

GUIToolbox::GUIToolbox( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuTools = new wxMenu();
	wxMenuItem* m_menuItemToolboxLoad;
	m_menuItemToolboxLoad = new wxMenuItem( m_menuTools, wxID_ANY, wxString( _("&Load Toolbox") ) + wxT('\t') + wxT("CTRL+L"), wxEmptyString, wxITEM_NORMAL );
	m_menuTools->Append( m_menuItemToolboxLoad );
	m_menuItemToolboxLoad->Enable( false );
	
	wxMenuItem* m_menuItemToolboxSave;
	m_menuItemToolboxSave = new wxMenuItem( m_menuTools, wxID_ANY, wxString( _("&Save Toolbox") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	m_menuTools->Append( m_menuItemToolboxSave );
	m_menuItemToolboxSave->Enable( false );
	
	wxMenuItem* m_separator1;
	m_separator1 = m_menuTools->AppendSeparator();
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuTools, wxID_CLOSE, wxString( _("&Close Window") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuTools->Append( m_menuItemClose );
	
	m_menubar->Append( m_menuTools, _("&Tools") );
	
	m_menuSettings = new wxMenu();
	wxMenuItem* m_menuItemUnitsSetup;
	m_menuItemUnitsSetup = new wxMenuItem( m_menuSettings, ID_SETUPUNITS, wxString( _("Setup &Units") ) + wxT('\t') + wxT("CTRL+U"), wxEmptyString, wxITEM_NORMAL );
	m_menuSettings->Append( m_menuItemUnitsSetup );
	
	wxMenuItem* m_menuItemStereo3D;
	m_menuItemStereo3D = new wxMenuItem( m_menuSettings, ID_VIEWSTEREO3D, wxString( _("&Stereo 3D") ) + wxT('\t') + wxT("CTRL+3"), wxEmptyString, wxITEM_CHECK );
	m_menuSettings->Append( m_menuItemStereo3D );
	
	m_menubar->Append( m_menuSettings, _("&Settings") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxHORIZONTAL );
	
	m_comboBoxToolSelector = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizerTop->Add( m_comboBoxToolSelector, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonToolNew = new wxButton( this, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTop->Add( m_buttonToolNew, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_buttonToolUpdate = new wxButton( this, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTop->Add( m_buttonToolUpdate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonToolDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTop->Add( m_buttonToolDelete, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer->Add( bSizerTop, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizerMain;
	fgSizerMain = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerMain->AddGrowableCol( 1 );
	fgSizerMain->AddGrowableRow( 0 );
	fgSizerMain->AddGrowableRow( 1 );
	fgSizerMain->SetFlexibleDirection( wxBOTH );
	fgSizerMain->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tool definition") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 5, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("Shaft diameter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlShaftDiameter = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlShaftDiameter->SetToolTip( _("Diameter of the part that disappears inside the chuck.") );
	
	fgSizer1->Add( m_textCtrlShaftDiameter, 0, wxALL, 5 );
	
	m_staticTextUnitShaftDiameter = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitShaftDiameter->Wrap( -1 );
	fgSizer1->Add( m_staticTextUnitShaftDiameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("Shaft length:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlShaftLength = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlShaftLength->SetToolTip( _("This is the length of the that disappears inside the chuck.") );
	
	fgSizer1->Add( m_textCtrlShaftLength, 0, wxALL, 5 );
	
	m_staticTextUnitShaftLength = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitShaftLength->Wrap( -1 );
	fgSizer1->Add( m_staticTextUnitShaftLength, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Maximum speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer1->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlMaxSpeed = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlMaxSpeed->SetToolTip( _("Max. speed: Look at label on box you got the tools shipped in.") );
	
	fgSizer1->Add( m_textCtrlMaxSpeed, 0, wxALL, 5 );
	
	m_staticTextUnitMaxSpeed = new wxStaticText( this, wxID_ANY, _("rpm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitMaxSpeed->Wrap( -1 );
	fgSizer1->Add( m_staticTextUnitMaxSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Feed coefficient:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer1->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlFeedCoefficient = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlFeedCoefficient->SetToolTip( _("Feed per tooth: How deep can a tooth cut per revolution. Usually in the range of 0.02 mm to 0.05 mm.") );
	
	fgSizer1->Add( m_textCtrlFeedCoefficient, 0, wxALL, 5 );
	
	m_staticTextUnitFeedCoefficient = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitFeedCoefficient->Wrap( -1 );
	fgSizer1->Add( m_staticTextUnitFeedCoefficient, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextFlutes = new wxStaticText( this, wxID_ANY, _("Number of flutes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFlutes->Wrap( -1 );
	fgSizer1->Add( m_staticTextFlutes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlNrOfTeeth = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlNrOfTeeth->SetToolTip( _("Number of teeth around the cutter.") );
	
	fgSizer1->Add( m_textCtrlNrOfTeeth, 0, wxALL, 5 );
	
	
	fgSizer1->Add( 0, 0, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	sbSizer1->Add( fgSizer1, 0, 0, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	sbSizer1->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textCtrlComment = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	sbSizer1->Add( m_textCtrlComment, 1, wxALL|wxEXPAND, 5 );
	
	fgSizerMain->Add( sbSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_panel=new PanelTool(this);
	fgSizerMain->Add( m_panel, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tool shape") ), wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonShapeNew = new wxButton( this, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_buttonShapeNew, 0, wxALL, 5 );
	
	m_buttonShapeUpdate = new wxButton( this, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_buttonShapeUpdate, 0, wxALL, 5 );
	
	m_buttonShapeDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_buttonShapeDelete, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer4, 0, 0, 5 );
	
	wxString m_choiceTypeChoices[] = { _("Linear or bend line"), _("Corner: first diameter change, then height change"), _("Corner: first height change, then diameter change"), _("Sphere: radius at upper limit, calculate height"), _("Sphere: radius at lower limit, calculate height") };
	int m_choiceTypeNChoices = sizeof( m_choiceTypeChoices ) / sizeof( wxString );
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeNChoices, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 0 );
	bSizer3->Add( m_choiceType, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Diameter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer2->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDiameter = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlDiameter->SetToolTip( _("Diameter of the tool at the end of this segment.") );
	
	fgSizer2->Add( m_textCtrlDiameter, 0, wxALL|wxEXPAND, 5 );
	
	m_staticTextUnitDiameter = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitDiameter->Wrap( -1 );
	fgSizer2->Add( m_staticTextUnitDiameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	fgSizer2->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlHeight = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlHeight->SetToolTip( _("Height of this segment.") );
	
	fgSizer2->Add( m_textCtrlHeight, 0, wxALL|wxEXPAND, 5 );
	
	m_staticTextUnitHeight = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitHeight->Wrap( -1 );
	fgSizer2->Add( m_staticTextUnitHeight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer2->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlRadius = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlRadius->SetToolTip( _("Radius of curvature:\nPositive radius = convex surface = bulged to the outside.\nNegative radius = concave surface = bulged to the inside.\nRadius of 0 = straight line. ") );
	
	fgSizer2->Add( m_textCtrlRadius, 0, wxALL|wxEXPAND, 5 );
	
	m_staticTextUnitRadius = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitRadius->Wrap( -1 );
	fgSizer2->Add( m_staticTextUnitRadius, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer2->Add( 0, 0, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_checkBoxCutting = new wxCheckBox( this, wxID_ANY, _("surface is cutting"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_checkBoxCutting, 0, wxALL, 5 );
	
	
	fgSizer2->Add( 0, 0, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer3->Add( fgSizer2, 0, 0, 5 );
	
	bSizer2->Add( bSizer3, 0, 0, 5 );
	
	m_listCtrl = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer2->Add( m_listCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	sbSizer2->Add( bSizer2, 1, wxEXPAND, 5 );
	
	fgSizerMain->Add( sbSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_canvas = new ToolCanvas(this);
	fgSizerMain->Add( m_canvas, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer->Add( fgSizerMain, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIToolbox::OnClose ) );
	this->Connect( m_menuItemToolboxLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolboxLoad ) );
	this->Connect( m_menuItemToolboxSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolboxSave ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnClose ) );
	this->Connect( m_menuItemStereo3D->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnChangeStereo3D ) );
	m_comboBoxToolSelector->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolSelect ), NULL, this );
	m_comboBoxToolSelector->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolbox::OnToolRename ), NULL, this );
	m_buttonToolNew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolNew ), NULL, this );
	m_buttonToolUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolUpdate ), NULL, this );
	m_buttonToolDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolDelete ), NULL, this );
	m_buttonShapeNew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeNew ), NULL, this );
	m_buttonShapeUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeUpdate ), NULL, this );
	m_buttonShapeDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeDelete ), NULL, this );
	m_listCtrl->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIToolbox::OnShapeSelect ), NULL, this );
}

GUIToolbox::~GUIToolbox()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIToolbox::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolboxLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolboxSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIToolbox::OnChangeStereo3D ) );
	m_comboBoxToolSelector->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIToolbox::OnToolSelect ), NULL, this );
	m_comboBoxToolSelector->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolbox::OnToolRename ), NULL, this );
	m_buttonToolNew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolNew ), NULL, this );
	m_buttonToolUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolUpdate ), NULL, this );
	m_buttonToolDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnToolDelete ), NULL, this );
	m_buttonShapeNew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeNew ), NULL, this );
	m_buttonShapeUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeUpdate ), NULL, this );
	m_buttonShapeDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolbox::OnShapeDelete ), NULL, this );
	m_listCtrl->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( GUIToolbox::OnShapeSelect ), NULL, this );
}

GUIToolpathGenerator::GUIToolpathGenerator( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerRun;
	bSizerRun = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText125 = new wxStaticText( this, wxID_ANY, _("Run:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText125->Wrap( -1 );
	bSizerRun->Add( m_staticText125, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceRunChoices;
	m_choiceRun = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRunChoices, 0 );
	m_choiceRun->SetSelection( 0 );
	bSizerRun->Add( m_choiceRun, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerRun, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerGenerator;
	bSizerGenerator = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText145 = new wxStaticText( this, wxID_ANY, _("Generator:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText145->Wrap( -1 );
	bSizerGenerator->Add( m_staticText145, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceToolpathChoices;
	m_choiceToolpath = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceToolpathChoices, 0 );
	m_choiceToolpath->SetSelection( 0 );
	bSizerGenerator->Add( m_choiceToolpath, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonAddNew = new wxButton( this, wxID_ANY, _("Add New"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddNew->SetToolTip( _("Add a new empty generator below the current one.") );
	
	bSizerGenerator->Add( m_buttonAddNew, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerGenerator, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer851;
	bSizer851 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerArea;
	sbSizerArea = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Area:") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerAreaCorrdinates;
	fgSizerAreaCorrdinates = new wxFlexGridSizer( 3, 6, 0, 0 );
	fgSizerAreaCorrdinates->AddGrowableCol( 1 );
	fgSizerAreaCorrdinates->AddGrowableCol( 4 );
	fgSizerAreaCorrdinates->SetFlexibleDirection( wxBOTH );
	fgSizerAreaCorrdinates->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextX = new wxStaticText( this, wxID_ANY, _("X start:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextX->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextX, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlX1 = new wxTextCtrl( this, ID_XSTART, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlX1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitX1 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX1->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitX1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText130 = new wxStaticText( this, wxID_ANY, _("end:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText130->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticText130, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlX2 = new wxTextCtrl( this, ID_XEND, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlX2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitX2 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitX2->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitX2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextY = new wxStaticText( this, wxID_ANY, _("Y start:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextY->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextY, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlY1 = new wxTextCtrl( this, ID_YSTART, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlY1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitY1 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY1->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitY1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText132 = new wxStaticText( this, wxID_ANY, _("end:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText132->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticText132, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlY2 = new wxTextCtrl( this, ID_YEND, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlY2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitY2 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitY2->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitY2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextZ = new wxStaticText( this, wxID_ANY, _("Z start:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextZ->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextZ, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlZ1 = new wxTextCtrl( this, ID_ZSTART, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlZ1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticTextUnitZ1 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ1->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitZ1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText1312 = new wxStaticText( this, wxID_ANY, _("end:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1312->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticText1312, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlZ2 = new wxTextCtrl( this, ID_ZEND, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	fgSizerAreaCorrdinates->Add( m_textCtrlZ2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticTextUnitZ2 = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitZ2->Wrap( -1 );
	fgSizerAreaCorrdinates->Add( m_staticTextUnitZ2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerArea->Add( fgSizerAreaCorrdinates, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerAreaSelect;
	bSizerAreaSelect = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonSelectAreaFromObject = new wxButton( this, ID_SELECTAREAOBJECT, _("from Object ..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerAreaSelect->Add( m_buttonSelectAreaFromObject, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerArea->Add( bSizerAreaSelect, 0, 0, 5 );
	
	bSizer851->Add( sbSizerArea, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerMargin;
	sbSizerMargin = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Margin:") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextSide = new wxStaticText( this, wxID_ANY, _("Side:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSide->Wrap( -1 );
	fgSizer18->Add( m_staticTextSide, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlMarginSide = new wxTextCtrl( this, ID_MARGINSIDE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_textCtrlMarginSide, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitMarginSide = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitMarginSide->Wrap( -1 );
	fgSizer18->Add( m_staticTextUnitMarginSide, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextBelow = new wxStaticText( this, wxID_ANY, _("Below:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBelow->Wrap( -1 );
	fgSizer18->Add( m_staticTextBelow, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlMarginBelow = new wxTextCtrl( this, ID_MARGINBELOW, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_textCtrlMarginBelow, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTextUnitMarginBelow = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitMarginBelow->Wrap( -1 );
	fgSizer18->Add( m_staticTextUnitMarginBelow, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerMargin->Add( fgSizer18, 1, wxEXPAND, 5 );
	
	bSizer87->Add( sbSizerMargin, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTool;
	sbSizerTool = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tool") ), wxVERTICAL );
	
	wxArrayString m_choiceToolChoices;
	m_choiceTool = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceToolChoices, 0 );
	m_choiceTool->SetSelection( 0 );
	sbSizerTool->Add( m_choiceTool, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextDiameter = new wxStaticText( this, wxID_ANY, _("Diameter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDiameter->Wrap( -1 );
	bSizer86->Add( m_staticTextDiameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlToolDiameter = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer86->Add( m_textCtrlToolDiameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitDiameter = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitDiameter->Wrap( -1 );
	bSizer86->Add( m_staticTextUnitDiameter, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerTool->Add( bSizer86, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer87->Add( sbSizerTool, 0, wxEXPAND, 5 );
	
	bSizer88->Add( bSizer87, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizerFreeLevel;
	sbSizerFreeLevel = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Safety distance:") ), wxVERTICAL );
	
	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextFreeHeight = new wxStaticText( this, wxID_ANY, _("Free Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFreeHeight->Wrap( -1 );
	bSizer89->Add( m_staticTextFreeHeight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlFreeHeight = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer89->Add( m_textCtrlFreeHeight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitFreeHeight = new wxStaticText( this, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitFreeHeight->Wrap( -1 );
	bSizer89->Add( m_staticTextUnitFreeHeight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerFreeLevel->Add( bSizer89, 0, 0, 5 );
	
	bSizer88->Add( sbSizerFreeLevel, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer851->Add( bSizer88, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizerMain->Add( bSizer851, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxStaticBoxSizer* sbSizer18;
	sbSizer18 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Generator Type:") ), wxVERTICAL );
	
	m_choicebookGenerator = new wxChoicebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	sbSizer18->Add( m_choicebookGenerator, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizerMain->Add( sbSizer18, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrlInfo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizerMain->Add( m_textCtrlInfo, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonUpdate = new wxButton( this, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonUpdate->SetToolTip( _("Update changes for the current generator.") );
	
	bSizerButtons->Add( m_buttonUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonReset = new wxButton( this, wxID_ANY, _("Reset changes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonReset->SetToolTip( _("Reset the changes for this generator to the state of the last update.") );
	
	bSizerButtons->Add( m_buttonReset, 0, wxALL, 5 );
	
	m_buttonDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonDelete->SetToolTip( _("Delete the current generator.") );
	
	bSizerButtons->Add( m_buttonDelete, 0, wxALL, 5 );
	
	m_buttonClose = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonClose->SetToolTip( _("Close window.") );
	
	bSizerButtons->Add( m_buttonClose, 0, wxALL, 5 );
	
	bSizerMain->Add( bSizerButtons, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIToolpathGenerator::OnClose ) );
	m_choiceRun->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectRun ), NULL, this );
	m_choiceToolpath->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectToolpath ), NULL, this );
	m_buttonAddNew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnAdd ), NULL, this );
	m_textCtrlX1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlX2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlY1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlY2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlZ1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlZ2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_buttonSelectAreaFromObject->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectArea ), NULL, this );
	m_textCtrlMarginSide->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlMarginBelow->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_choiceTool->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectTool ), NULL, this );
	m_choicebookGenerator->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( GUIToolpathGenerator::OnPageChanged ), NULL, this );
	m_buttonUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnUpdate ), NULL, this );
	m_buttonReset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnResetChanges ), NULL, this );
	m_buttonDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnDelete ), NULL, this );
	m_buttonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnClose ), NULL, this );
}

GUIToolpathGenerator::~GUIToolpathGenerator()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIToolpathGenerator::OnClose ) );
	m_choiceRun->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectRun ), NULL, this );
	m_choiceToolpath->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectToolpath ), NULL, this );
	m_buttonAddNew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnAdd ), NULL, this );
	m_textCtrlX1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlX2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlY1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlY2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlZ1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlZ2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_buttonSelectAreaFromObject->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectArea ), NULL, this );
	m_textCtrlMarginSide->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_textCtrlMarginBelow->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIToolpathGenerator::OnChangeText ), NULL, this );
	m_choiceTool->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIToolpathGenerator::OnSelectTool ), NULL, this );
	m_choicebookGenerator->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( GUIToolpathGenerator::OnPageChanged ), NULL, this );
	m_buttonUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnUpdate ), NULL, this );
	m_buttonReset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnResetChanges ), NULL, this );
	m_buttonDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnDelete ), NULL, this );
	m_buttonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIToolpathGenerator::OnClose ), NULL, this );
}

GUIAnimation::GUIAnimation( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText70 = new wxStaticText( this, wxID_ANY, _("Toolpath:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText70->Wrap( -1 );
	bSizer30->Add( m_staticText70, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceToolpathChoices[] = { _("No toolpath available.") };
	int m_choiceToolpathNChoices = sizeof( m_choiceToolpathChoices ) / sizeof( wxString );
	m_choiceToolpath = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceToolpathNChoices, m_choiceToolpathChoices, 0 );
	m_choiceToolpath->SetSelection( 0 );
	bSizer30->Add( m_choiceToolpath, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer29->Add( bSizer30, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText71 = new wxStaticText( this, wxID_ANY, _("Time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	bSizer31->Add( m_staticText71, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlTime = new wxTextCtrl( this, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_textCtrlTime, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText72 = new wxStaticText( this, wxID_ANY, _("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	bSizer31->Add( m_staticText72, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlMaxTime = new wxTextCtrl( this, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer31->Add( m_textCtrlMaxTime, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer29->Add( bSizer31, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderTime = new wxSlider( this, wxID_ANY, 0, 0, 2000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer29->Add( m_sliderTime, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButtonFirst = new wxBitmapButton( this, wxID_ANY, wxBitmap( first_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonFirst->SetToolTip( _("First") );
	
	m_bpButtonFirst->SetToolTip( _("First") );
	
	bSizer32->Add( m_bpButtonFirst, 0, wxALL, 5 );
	
	m_bpButtonPrev = new wxBitmapButton( this, wxID_ANY, wxBitmap( prev_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonPrev->SetToolTip( _("Step back") );
	
	m_bpButtonPrev->SetToolTip( _("Step back") );
	
	bSizer32->Add( m_bpButtonPrev, 0, wxALL, 5 );
	
	m_bpButtonPlayStop = new wxBitmapButton( this, wxID_ANY, wxBitmap( play_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonPlayStop->SetToolTip( _("Play / Stop") );
	
	m_bpButtonPlayStop->SetToolTip( _("Play / Stop") );
	
	bSizer32->Add( m_bpButtonPlayStop, 0, wxALL, 5 );
	
	m_bpButtonNext = new wxBitmapButton( this, wxID_ANY, wxBitmap( next_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonNext->SetToolTip( _("Step forward") );
	
	m_bpButtonNext->SetToolTip( _("Step forward") );
	
	bSizer32->Add( m_bpButtonNext, 0, wxALL, 5 );
	
	m_bpButtonLast = new wxBitmapButton( this, wxID_ANY, wxBitmap( last_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButtonLast->SetToolTip( _("Last") );
	
	m_bpButtonLast->SetToolTip( _("Last") );
	
	bSizer32->Add( m_bpButtonLast, 0, wxALL, 5 );
	
	bSizer29->Add( bSizer32, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer29 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIAnimation::OnClose ) );
	m_choiceToolpath->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIAnimation::OnSelectToolpath ), NULL, this );
	m_textCtrlTime->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIAnimation::OnChangeTime ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_bpButtonFirst->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnFirst ), NULL, this );
	m_bpButtonPrev->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnPrev ), NULL, this );
	m_bpButtonPlayStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnPlayStop ), NULL, this );
	m_bpButtonNext->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnNext ), NULL, this );
	m_bpButtonLast->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnLast ), NULL, this );
}

GUIAnimation::~GUIAnimation()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIAnimation::OnClose ) );
	m_choiceToolpath->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIAnimation::OnSelectToolpath ), NULL, this );
	m_textCtrlTime->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIAnimation::OnChangeTime ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_sliderTime->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIAnimation::OnScroll ), NULL, this );
	m_bpButtonFirst->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnFirst ), NULL, this );
	m_bpButtonPrev->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnPrev ), NULL, this );
	m_bpButtonPlayStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnPlayStop ), NULL, this );
	m_bpButtonNext->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnNext ), NULL, this );
	m_bpButtonLast->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAnimation::OnLast ), NULL, this );
}

GUISetup6DOFController::GUISetup6DOFController( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText = new wxStaticText( this, wxID_ANY, _("Serial port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText->Wrap( -1 );
	bSizer1->Add( m_staticText, 0, wxALL, 5 );
	
	textPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( textPort, 0, wxALL|wxEXPAND, 5 );
	
	wxString radioDeviceSelectChoices[] = { _("SpaceBall"), _("SpaceOrb"), _("SpaceMouse") };
	int radioDeviceSelectNChoices = sizeof( radioDeviceSelectChoices ) / sizeof( wxString );
	radioDeviceSelect = new wxRadioBox( this, wxID_ANY, _("Type of controller"), wxDefaultPosition, wxDefaultSize, radioDeviceSelectNChoices, radioDeviceSelectChoices, 1, wxRA_SPECIFY_COLS );
	radioDeviceSelect->SetSelection( 2 );
	bSizer1->Add( radioDeviceSelect, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTx;
	bSizerTx = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTx = new wxStaticText( this, wxID_ANY, _("Tx"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTx->Wrap( -1 );
	bSizerTx->Add( m_staticTextTx, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_sliderTx = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderTx->Enable( false );
	
	bSizerTx->Add( m_sliderTx, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizer1->Add( bSizerTx, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTy;
	bSizerTy = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTy = new wxStaticText( this, wxID_ANY, _("Ty"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTy->Wrap( -1 );
	bSizerTy->Add( m_staticTextTy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderTy = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderTy->Enable( false );
	
	bSizerTy->Add( m_sliderTy, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizerTy, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTz;
	bSizerTz = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextTz = new wxStaticText( this, wxID_ANY, _("Tz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTz->Wrap( -1 );
	bSizerTz->Add( m_staticTextTz, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderTz = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderTz->Enable( false );
	
	bSizerTz->Add( m_sliderTz, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizerTz, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerRx;
	bSizerRx = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextRx = new wxStaticText( this, wxID_ANY, _("Rx"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRx->Wrap( -1 );
	bSizerRx->Add( m_staticTextRx, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderRx = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderRx->Enable( false );
	
	bSizerRx->Add( m_sliderRx, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizerRx, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerRy;
	bSizerRy = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextRy = new wxStaticText( this, wxID_ANY, _("Ry"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRy->Wrap( -1 );
	bSizerRy->Add( m_staticTextRy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderRy = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderRy->Enable( false );
	
	bSizerRy->Add( m_sliderRy, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizerRy, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerRz;
	bSizerRz = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextRz = new wxStaticText( this, wxID_ANY, _("Rz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRz->Wrap( -1 );
	bSizerRz->Add( m_staticTextRz, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderRz = new wxSlider( this, wxID_ANY, 0, -1024, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderRz->Enable( false );
	
	bSizerRz->Add( m_sliderRz, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizerRz, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	buttonConnect = new wxButton( this, ID_BUTTONCONNECT, _("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( buttonConnect, 1, wxALL|wxEXPAND, 5 );
	
	buttonDisconnect = new wxButton( this, ID_BUTTONDISCONNECT, _("Disconnect"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonDisconnect->Enable( false );
	
	bSizer2->Add( buttonDisconnect, 1, wxALL|wxEXPAND, 5 );
	
	buttonClose = new wxButton( this, wxID_CLOSE, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( buttonClose, 1, wxALL|wxEXPAND, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	buttonConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnConnect ), NULL, this );
	buttonDisconnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnDisconnect ), NULL, this );
	buttonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnClose ), NULL, this );
}

GUISetup6DOFController::~GUISetup6DOFController()
{
	// Disconnect Events
	buttonConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnConnect ), NULL, this );
	buttonDisconnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnDisconnect ), NULL, this );
	buttonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetup6DOFController::OnClose ), NULL, this );
}

GUISetupUnits::GUISetupUnits( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Units ") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, _("Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	fgSizer6->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitLengthChoices;
	m_choiceUnitLength = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitLengthChoices, 0 );
	m_choiceUnitLength->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitLength, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText58 = new wxStaticText( this, wxID_ANY, _("Linear Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText58->Wrap( -1 );
	fgSizer6->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitSpeedLinearChoices;
	m_choiceUnitSpeedLinear = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitSpeedLinearChoices, 0 );
	m_choiceUnitSpeedLinear->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitSpeedLinear, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText59 = new wxStaticText( this, wxID_ANY, _("Rotational Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText59->Wrap( -1 );
	fgSizer6->Add( m_staticText59, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitSpeedRotationalChoices;
	m_choiceUnitSpeedRotational = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitSpeedRotationalChoices, 0 );
	m_choiceUnitSpeedRotational->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitSpeedRotational, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText65 = new wxStaticText( this, wxID_ANY, _("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	fgSizer6->Add( m_staticText65, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitTimeChoices;
	m_choiceUnitTime = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitTimeChoices, 0 );
	m_choiceUnitTime->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitTime, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticText110 = new wxStaticText( this, wxID_ANY, _("Small Distance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	fgSizer6->Add( m_staticText110, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitSmallDistanceChoices;
	m_choiceUnitSmallDistance = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitSmallDistanceChoices, 0 );
	m_choiceUnitSmallDistance->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitSmallDistance, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText111 = new wxStaticText( this, wxID_ANY, _("Tolerance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer6->Add( m_staticText111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitToleranceChoices;
	m_choiceUnitTolerance = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitToleranceChoices, 0 );
	m_choiceUnitTolerance->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitTolerance, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText112 = new wxStaticText( this, wxID_ANY, _("Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	fgSizer6->Add( m_staticText112, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceUnitAngleChoices;
	m_choiceUnitAngle = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceUnitAngleChoices, 0 );
	m_choiceUnitAngle->SetSelection( 0 );
	fgSizer6->Add( m_choiceUnitAngle, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	sbSizer6->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	bSizer25->Add( sbSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonClose = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_buttonClose, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText64 = new wxStaticText( this, wxID_ANY, _("Unit conversion is only used for displaying.\nInternally everything is stored in SI base units.\nPlease use Object->Modify to change object sizes."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	bSizer25->Add( m_staticText64, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
	bSizer25->Fit( this );
	
	// Connect Events
	m_choiceUnitLength->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSpeedLinear->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSpeedRotational->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitTime->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSmallDistance->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitTolerance->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitAngle->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_buttonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetupUnits::OnClose ), NULL, this );
}

GUISetupUnits::~GUISetupUnits()
{
	// Disconnect Events
	m_choiceUnitLength->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSpeedLinear->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSpeedRotational->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitTime->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitSmallDistance->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitTolerance->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_choiceUnitAngle->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUISetupUnits::OnChangeUnit ), NULL, this );
	m_buttonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetupUnits::OnClose ), NULL, this );
}

GUISetupStereo3D::GUISetupStereo3D( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizerMain;
	fgSizerMain = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizerMain->AddGrowableCol( 1 );
	fgSizerMain->AddGrowableRow( 0 );
	fgSizerMain->SetFlexibleDirection( wxBOTH );
	fgSizerMain->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizerLeftSilders;
	bSizerLeftSilders = new wxBoxSizer( wxVERTICAL );
	
	m_staticText120 = new wxStaticText( this, wxID_ANY, _("Left Eye"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText120->Wrap( -1 );
	bSizerLeftSilders->Add( m_staticText120, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sliderLR = new wxSlider( this, ID_COLORLR, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer76->Add( m_sliderLR, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderLG = new wxSlider( this, ID_COLORLG, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer76->Add( m_sliderLG, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderLB = new wxSlider( this, ID_COLORLB, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer76->Add( m_sliderLB, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizerLeftSilders->Add( bSizer76, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizerMain->Add( bSizerLeftSilders, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_canvas = new CanvasStereoTest(this);
	fgSizerMain->Add( m_canvas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizerRightSliders;
	bSizerRightSliders = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1201 = new wxStaticText( this, wxID_ANY, _("Right Eye"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1201->Wrap( -1 );
	bSizerRightSliders->Add( m_staticText1201, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer761;
	bSizer761 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sliderRR = new wxSlider( this, ID_COLORRR, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer761->Add( m_sliderRR, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderRG = new wxSlider( this, ID_COLORRG, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer761->Add( m_sliderRG, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderRB = new wxSlider( this, ID_COLORRB, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE|wxSL_VERTICAL );
	bSizer761->Add( m_sliderRB, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizerRightSliders->Add( bSizer761, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizerMain->Add( bSizerRightSliders, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_colourPickerLeft = new wxColourPickerCtrl( this, ID_COLORLEFT, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizerMain->Add( m_colourPickerLeft, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonSwapColors = new wxButton( this, wxID_ANY, _("<-   Swap Colors   ->"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerMain->Add( m_buttonSwapColors, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_colourPickerRight = new wxColourPickerCtrl( this, ID_COLORRIGHT, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizerMain->Add( m_colourPickerRight, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizerLeftText;
	fgSizerLeftText = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizerLeftText->SetFlexibleDirection( wxBOTH );
	fgSizerLeftText->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText113 = new wxStaticText( this, wxID_ANY, _("R:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	fgSizerLeftText->Add( m_staticText113, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlLR = new wxTextCtrl( this, ID_TEXTLR, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerLeftText->Add( m_textCtrlLR, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText1131 = new wxStaticText( this, wxID_ANY, _("G:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1131->Wrap( -1 );
	fgSizerLeftText->Add( m_staticText1131, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlLG = new wxTextCtrl( this, ID_TEXTLG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerLeftText->Add( m_textCtrlLG, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText11311 = new wxStaticText( this, wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11311->Wrap( -1 );
	fgSizerLeftText->Add( m_staticText11311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlLB = new wxTextCtrl( this, ID_TEXTLB, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerLeftText->Add( m_textCtrlLB, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizerMain->Add( fgSizerLeftText, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer( wxVERTICAL );
	
	m_sliderEyeDistance = new wxSlider( this, ID_EYEDISTANCE, 100, 0, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizerMiddle->Add( m_sliderEyeDistance, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText125 = new wxStaticText( this, wxID_ANY, _("Eye Distance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText125->Wrap( -1 );
	bSizer82->Add( m_staticText125, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlEyeDistance = new wxTextCtrl( this, ID_TEXTEYEDISTANCE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer82->Add( m_textCtrlEyeDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitEyeDistance = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitEyeDistance->Wrap( -1 );
	bSizer82->Add( m_staticTextUnitEyeDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMiddle->Add( bSizer82, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_sliderFocalDistance = new wxSlider( this, ID_FOCALDISTANCE, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizerMiddle->Add( m_sliderFocalDistance, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText127 = new wxStaticText( this, wxID_ANY, _("Focal Distance:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText127->Wrap( -1 );
	bSizer83->Add( m_staticText127, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlFocalDistance = new wxTextCtrl( this, ID_TEXTFOCALDISTANCE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer83->Add( m_textCtrlFocalDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextUnitFocalDistance = new wxStaticText( this, wxID_ANY, _("cm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextUnitFocalDistance->Wrap( -1 );
	bSizer83->Add( m_staticTextUnitFocalDistance, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMiddle->Add( bSizer83, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizerMain->Add( bSizerMiddle, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizerRightText;
	fgSizerRightText = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizerRightText->SetFlexibleDirection( wxBOTH );
	fgSizerRightText->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1132 = new wxStaticText( this, wxID_ANY, _("R:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1132->Wrap( -1 );
	fgSizerRightText->Add( m_staticText1132, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlRR = new wxTextCtrl( this, ID_TEXTRR, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerRightText->Add( m_textCtrlRR, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText11312 = new wxStaticText( this, wxID_ANY, _("G:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11312->Wrap( -1 );
	fgSizerRightText->Add( m_staticText11312, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlRG = new wxTextCtrl( this, ID_TEXTRG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerRightText->Add( m_textCtrlRG, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText113111 = new wxStaticText( this, wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113111->Wrap( -1 );
	fgSizerRightText->Add( m_staticText113111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlRB = new wxTextCtrl( this, ID_TEXTRB, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	fgSizerRightText->Add( m_textCtrlRB, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizerMain->Add( fgSizerRightText, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer80->Add( fgSizerMain, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	this->SetSizer( bSizer80 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUISetupStereo3D::OnClose ) );
	m_sliderLR->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_colourPickerLeft->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUISetupStereo3D::OnColorChanged ), NULL, this );
	m_buttonSwapColors->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetupStereo3D::OnSwap ), NULL, this );
	m_colourPickerRight->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUISetupStereo3D::OnColorChanged ), NULL, this );
	m_textCtrlLR->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlLG->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlLB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_textCtrlEyeDistance->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_textCtrlFocalDistance->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRR->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRG->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
}

GUISetupStereo3D::~GUISetupStereo3D()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUISetupStereo3D::OnClose ) );
	m_sliderLR->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLR->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLG->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderLB->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRR->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRG->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderRB->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_colourPickerLeft->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUISetupStereo3D::OnColorChanged ), NULL, this );
	m_buttonSwapColors->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUISetupStereo3D::OnSwap ), NULL, this );
	m_colourPickerRight->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( GUISetupStereo3D::OnColorChanged ), NULL, this );
	m_textCtrlLR->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlLG->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlLB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderEyeDistance->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_textCtrlEyeDistance->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_sliderFocalDistance->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUISetupStereo3D::OnScroll ), NULL, this );
	m_textCtrlFocalDistance->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRR->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRG->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
	m_textCtrlRB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUISetupStereo3D::OnTextChange ), NULL, this );
}

GUIAbout::GUIAbout( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, _("Generic CAM  Copyright (C) 2010 - 2015 Tobias Schaefer\n\nFrench translation & additional debugging: Jacques-Louis Tartarin\nItalian Translation: Sandro Dalle Nogare\n\nLicence for Generic CAM:\nGNU General Public License version 3.0 (GPLv3)\n\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it under certain conditions.\n\nYou should have received a copy of the GNU General Public License along with this program.\nIf not, see <http://www.gnu.org/licenses/>."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	bSizer3->Add( m_textCtrl12, 1, wxALL|wxEXPAND, 5 );
	
	m_button1 = new wxButton( this, wxID_CLOSE, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAbout::OnClose ), NULL, this );
}

GUIAbout::~GUIAbout()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIAbout::OnClose ), NULL, this );
}

StartupText::StartupText( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );
	
	m_richText = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer->Add( m_richText, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
}

StartupText::~StartupText()
{
}
