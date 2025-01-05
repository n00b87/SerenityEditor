#include "SerenityEditor_DeleteGroupAlert_Dialog.h"

SerenityEditor_DeleteGroupAlert_Dialog::SerenityEditor_DeleteGroupAlert_Dialog( wxWindow* parent )
:
DeleteGroupAlert_Dialog( parent )
{
	deleteFlag = false;
}

void SerenityEditor_DeleteGroupAlert_Dialog::OnDelete( wxCommandEvent& event )
{
	deleteFlag = true;
	Close();
}

void SerenityEditor_DeleteGroupAlert_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_DeleteGroupAlert_Dialog::setGroupName(wxString group_name)
{
	wxString label = m_deleteGroupName_staticText->GetLabel();
	label.Replace(_("[GROUP_NAME]"), group_name);
	m_deleteGroupName_staticText->SetLabel( label );
}
