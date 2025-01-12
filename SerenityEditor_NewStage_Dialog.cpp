#include "SerenityEditor_NewStage_Dialog.h"

SerenityEditor_NewStage_Dialog::SerenityEditor_NewStage_Dialog( wxWindow* parent )
:
NewStage_Dialog( parent )
{
	create_flag = false;
	stage_id = _("");
}

void SerenityEditor_NewStage_Dialog::OnCreate( wxCommandEvent& event )
{
	stage_id = m_stageID_textCtrl->GetValue();
	create_flag = true;
	Close();
}

void SerenityEditor_NewStage_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}
