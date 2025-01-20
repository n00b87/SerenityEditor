#include "SerenityEditor_NewSphereActor_Dialog.h"

SerenityEditor_NewSphereActor_Dialog::SerenityEditor_NewSphereActor_Dialog( wxWindow* parent )
:
NewSphereActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewSphereActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewSphereActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	radius = m_radius_spinCtrlDouble->GetValue();

	Close();
}
