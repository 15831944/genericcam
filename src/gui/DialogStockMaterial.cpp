///////////////////////////////////////////////////////////////////////////////
// Name               : DialogStockMaterial.cpp
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 15.06.2011
// Copyright          : (C) 2011 Tobias Schaefer <tobiassch@users.sourceforge.net>
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

#include "DialogStockMaterial.h"
#include "IDs.h"

DialogStockMaterial::DialogStockMaterial(wxWindow* parent, Project * project,
		wxCommandProcessor * commandProcessor, DisplaySettings * settings) :
		GUIStockMaterial(parent)
{
	this->project = project;
	this->settings = settings;
	this->commandProcessor = commandProcessor;

	selectedLine = -1;
	isInitialized = false;

	name = _T("");
	sx = 0.1;
	sy = 0.1;
	sz = 0.1;
	feedrate = 1.0;
	toolSpeed = 10000.0 / 60.0;
	available = true;
}

void DialogStockMaterial::Initialize(void)
{
	wxSize sz = m_listCtrl->GetClientSize();
	unsigned int w = sz.x / 11;
	m_listCtrl->ClearAll();

	m_listCtrl->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 3 * w);
	m_listCtrl->InsertColumn(2, _("X"), wxLIST_FORMAT_RIGHT, 1 * w);
	m_listCtrl->InsertColumn(3, _("Y"), wxLIST_FORMAT_RIGHT, 1 * w);
	m_listCtrl->InsertColumn(4, _("Z"), wxLIST_FORMAT_RIGHT, 1 * w);
	m_listCtrl->InsertColumn(5, _("max. Speed"), wxLIST_FORMAT_RIGHT, 2 * w);
	m_listCtrl->InsertColumn(6, _("max. Feedrate"), wxLIST_FORMAT_RIGHT, 2 * w);
	m_listCtrl->InsertColumn(7, _("available"), wxLIST_FORMAT_CENTER, w);
	isInitialized = true;
}

bool DialogStockMaterial::TransferDataToWindow(void)
{
	if(!this->IsShown()) return false;
	if(project == NULL) return false;

	if(!isInitialized) Initialize();

	ArrayOfStockMaterial* temp = &(project->stock.stockMaterials);
	size_t N = m_listCtrl->GetItemCount();
	size_t i;
	for(i = 0; i < temp->GetCount(); i++){
		if(i >= N){
			m_listCtrl->InsertItem(i, temp->Item(i).name);
		}else{
			m_listCtrl->SetItem(i, 0, temp->Item(i).name);
		}
		m_listCtrl->SetItem(i, 1,
				settings->Distance.TextFromSIWithUnit(temp->Item(i).sx, 1));
		m_listCtrl->SetItem(i, 2,
				settings->Distance.TextFromSIWithUnit(temp->Item(i).sy, 1));
		m_listCtrl->SetItem(i, 3,
				settings->Distance.TextFromSIWithUnit(temp->Item(i).sz, 1));
		m_listCtrl->SetItem(i, 4,
				settings->RotationalSpeed.TextFromSIWithUnit(
						temp->Item(i).maxToolSpeed, 0));
		m_listCtrl->SetItem(i, 5,
				settings->LinearSpeed.TextFromSIWithUnit(
						temp->Item(i).maxFeedrate, 1));
		if(temp->Item(i).available)
			m_listCtrl->SetItem(i, 6, _T("x"));
		else
			m_listCtrl->SetItem(i, 6, _T(""));
	}
	for(i = N; i > temp->GetCount(); i--)
		m_listCtrl->DeleteItem(i - 1);

	m_staticTextUnitX->SetLabel(settings->Distance.GetOtherName());
	m_staticTextUnitY->SetLabel(settings->Distance.GetOtherName());
	m_staticTextUnitZ->SetLabel(settings->Distance.GetOtherName());

	m_staticTextUnitRotationalSpeed->SetLabel(
			settings->RotationalSpeed.GetOtherName());
	m_staticTextUnitLinearSpeed->SetLabel(settings->LinearSpeed.GetOtherName());

	m_textCtrlName->SetValue(name);
	m_textCtrlX->SetValue(settings->Distance.TextFromSI(sx));
	m_textCtrlY->SetValue(settings->Distance.TextFromSI(sy));
	m_textCtrlZ->SetValue(settings->Distance.TextFromSI(sz));
	m_textCtrlMaxSpeed->SetValue(
			settings->RotationalSpeed.TextFromSI(toolSpeed, 0));
	m_textCtrlMaxFeedrate->SetValue(
			settings->LinearSpeed.TextFromSI(feedrate, 1));
	m_checkBoxAvailable->SetValue(available);

	return true;
}
bool DialogStockMaterial::TransferDataFromWindow(void)
{
	name = m_textCtrlName->GetValue();

	m_textCtrlX->GetValue().ToDouble(&sx);
	m_textCtrlY->GetValue().ToDouble(&sy);
	m_textCtrlZ->GetValue().ToDouble(&sz);

	m_textCtrlMaxSpeed->GetValue().ToDouble(&toolSpeed);
	m_textCtrlMaxFeedrate->GetValue().ToDouble(&feedrate);

	available = m_checkBoxAvailable->GetValue();

	sx = settings->Distance.ToSI(sx);
	sy = settings->Distance.ToSI(sy);
	sz = settings->Distance.ToSI(sz);

	toolSpeed = settings->RotationalSpeed.ToSI(toolSpeed);
	feedrate = settings->LinearSpeed.ToSI(feedrate);

	return true;
}

void DialogStockMaterial::OnClose(wxCommandEvent& event)
{
	TransferDataFromWindow();
	this->Show(false);
}
void DialogStockMaterial::OnXClose(wxCloseEvent& event)
{
	TransferDataFromWindow();
	this->Show(false);
}

void DialogStockMaterial::OnAddUpdate(wxCommandEvent& event)
{
	TransferDataFromWindow();

	size_t i;
	for(i = 0; i < project->stock.stockMaterials.GetCount(); i++){
		if(project->stock.stockMaterials[i].name.CmpNoCase(name) == 0) break;
	}
	if(i >= project->stock.stockMaterials.GetCount()){
		project->stock.stockMaterials.Add(new StockMaterial);
		i = project->stock.stockMaterials.GetCount() - 1;
	}

	project->stock.stockMaterials[i].name = name;
	project->stock.stockMaterials[i].sx = sx;
	project->stock.stockMaterials[i].sy = sy;
	project->stock.stockMaterials[i].sz = sz;
	project->stock.stockMaterials[i].maxToolSpeed = toolSpeed;
	project->stock.stockMaterials[i].maxFeedrate = feedrate;
	project->stock.stockMaterials[i].available = available;

	wxCommandEvent selectEvent(wxEVT_COMMAND_MENU_SELECTED, ID_UPDATE);
	ProcessEvent(selectEvent);
}

void DialogStockMaterial::OnDelete(wxCommandEvent& event)
{
	TransferDataFromWindow();
	size_t i;
	for(i = 0; i < project->stock.stockMaterials.GetCount(); i++){
		if(project->stock.stockMaterials[i].name.Cmp(name) == 0) break;
	}
	if(i < project->stock.stockMaterials.GetCount()){
		project->stock.stockMaterials.RemoveAt(i);
	}
	TransferDataToWindow();
}

void DialogStockMaterial::OnActivate(wxListEvent& event)
{
	TransferDataFromWindow();
	int i = event.GetIndex();
	project->stock.stockMaterials[i].available ^= true;
	available = project->stock.stockMaterials[i].available;
	TransferDataToWindow();
}

void DialogStockMaterial::OnSize(wxSizeEvent& event)
{
//	wxSize sz = m_listCtrl->GetClientSize();
//	unsigned int w = sz.x / 10;

	event.Skip();
}

void DialogStockMaterial::OnSelected(wxListEvent& event)
{
	int i = event.GetIndex();

	sx = project->stock.stockMaterials[i].sx;
	sy = project->stock.stockMaterials[i].sy;
	sz = project->stock.stockMaterials[i].sz;
	name = project->stock.stockMaterials[i].name;
	feedrate = project->stock.stockMaterials[i].maxFeedrate;
	toolSpeed = project->stock.stockMaterials[i].maxToolSpeed;
	available = project->stock.stockMaterials[i].available;

	TransferDataToWindow();
}
