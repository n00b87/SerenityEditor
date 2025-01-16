#include "SerenityEditor_DeleteActorAlert_Dialog.h"

SerenityEditor_DeleteActorAlert_Dialog::SerenityEditor_DeleteActorAlert_Dialog( wxWindow* parent )
:
DeleteActorAlert_Dialog( parent )
{
	delete_flag = false;
}

void SerenityEditor_DeleteActorAlert_Dialog::OnDelete( wxCommandEvent& event )
{
	delete_flag = true;
	Close();
}

void SerenityEditor_DeleteActorAlert_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_DeleteActorAlert_Dialog::setActorID(wxString actor_id)
{
	wxString label = m_deleteGroupName_staticText->GetLabel();
	label.Replace(_("[ACTOR_NAME]"), actor_id);
	//wxMessageBox(_("NEW LBL: ") + label);
	m_deleteGroupName_staticText->SetLabel(label);
}
