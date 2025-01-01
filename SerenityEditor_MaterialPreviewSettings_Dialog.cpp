#include "SerenityEditor_MaterialPreviewSettings_Dialog.h"

SerenityEditor_MaterialPreviewSettings_Dialog::SerenityEditor_MaterialPreviewSettings_Dialog( wxWindow* parent )
:
MaterialPreviewSettings_Dialog( parent )
{
	apply_changes = false;
}

void SerenityEditor_MaterialPreviewSettings_Dialog::setFields(double speed, double distance, double radius)
{
	m_cameraSpeed_textCtrl->SetValue(wxString::FromDouble(speed));
	m_cameraDistance_textCtrl->SetValue(wxString::FromDouble(distance));
	m_lightRadius_textCtrl->SetValue(wxString::FromDouble(radius));
}

void SerenityEditor_MaterialPreviewSettings_Dialog::OnApply( wxCommandEvent& event )
{
	apply_changes = true;

	m_cameraSpeed_textCtrl->GetValue().ToDouble(&camera_speed);
	m_cameraDistance_textCtrl->GetValue().ToDouble(&camera_distance);
	m_lightRadius_textCtrl->GetValue().ToDouble(&light_radius);

	Close();
}

void SerenityEditor_MaterialPreviewSettings_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}
