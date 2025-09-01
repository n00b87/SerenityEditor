#include <wx/wx.h>
#include "SerenityEditor_NewTerrainActor_Dialog.h"

SerenityEditor_NewTerrainActor_Dialog::SerenityEditor_NewTerrainActor_Dialog( wxWindow* parent )
:
NewTerrainActor_Dialog( parent )
{
	create_flag = false;
	m_terrainSize_spinCtrl->SetValue(512);
}

void SerenityEditor_NewTerrainActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewTerrainActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	terrain_size = m_terrainSize_spinCtrl->GetValue();

	Close();
}

