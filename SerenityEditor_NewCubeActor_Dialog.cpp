#include "SerenityEditor_NewCubeActor_Dialog.h"

SerenityEditor_NewCubeActor_Dialog::SerenityEditor_NewCubeActor_Dialog( wxWindow* parent )
:
NewCubeActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewCubeActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewCubeActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	cube_size = m_size_spinCtrlDouble->GetValue();

	Close();
}
