#include <wx/wx.h>
#include "SerenityEditor_DeleteStageAlert_Dialog.h"

SerenityEditor_DeleteStageAlert_Dialog::SerenityEditor_DeleteStageAlert_Dialog( wxWindow* parent )
:
DeleteStageAlert_Dialog( parent )
{
	delete_flag = false;
}

void SerenityEditor_DeleteStageAlert_Dialog::OnDelete( wxCommandEvent& event )
{
	delete_flag = true;
	Close();
}

void SerenityEditor_DeleteStageAlert_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_DeleteStageAlert_Dialog::setStageID(wxString stage_id)
{
	wxString label = m_deleteGroupName_staticText->GetLabel();
	label.Replace(_("[STAGE_NAME]"), stage_id);
	//wxMessageBox(_("NEW LBL: ") + label);
	m_deleteGroupName_staticText->SetLabel(label);
}
