#include "SerenityEditor_SetCamera_Dialog.h"

SerenityEditor_SetCamera_Dialog::SerenityEditor_SetCamera_Dialog( wxWindow* parent )
:
SetCamera_Dialog( parent )
{
	set_flag = false;
}

void SerenityEditor_SetCamera_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_SetCamera_Dialog::OnSet( wxCommandEvent& event )
{
	m_posX_textCtrl->GetValue().ToDouble(&px);
	m_posY_textCtrl->GetValue().ToDouble(&py);
	m_posZ_textCtrl->GetValue().ToDouble(&pz);

	m_rotX_textCtrl->GetValue().ToDouble(&rx);
	m_rotY_textCtrl->GetValue().ToDouble(&ry);
	m_rotZ_textCtrl->GetValue().ToDouble(&rz);

	set_flag = true;

	Close();
}

void SerenityEditor_SetCamera_Dialog::refresh_values()
{
	m_posX_textCtrl->SetValue(wxString::FromDouble(px));
	m_posY_textCtrl->SetValue(wxString::FromDouble(py));
	m_posZ_textCtrl->SetValue(wxString::FromDouble(pz));

	m_rotX_textCtrl->SetValue(wxString::FromDouble(rx));
	m_rotY_textCtrl->SetValue(wxString::FromDouble(ry));
	m_rotZ_textCtrl->SetValue(wxString::FromDouble(rz));
}
