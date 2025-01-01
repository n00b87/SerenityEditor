#include <wx/wx.h>
#include "SerenityEditor_NewProject_Dialog.h"

SerenityEditor_NewProject_Dialog::SerenityEditor_NewProject_Dialog( wxWindow* parent )
:
NewProject_Dialog( parent )
{
	m_projectName_textCtrl->SetValue(_("Untitled Project"));
	createFlag = false;
}

void SerenityEditor_NewProject_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewProject_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	project_name = m_projectName_textCtrl->GetValue();

	wxString pf_name = project_name;
	pf_name.Replace(_("\t"), _(" "));
	pf_name.Replace(_("\r"), _(""));
	pf_name.Replace(_("\n"), _(""));
	pf_name.Replace(_("\\"), _(""));
	pf_name.Replace(_("/"), _(""));
	pf_name.Replace(_(" "), _("_"));

	project_file = m_projectLocation_dirPicker->GetDirName();

	if(!wxDirExists(project_file.GetAbsolutePath()))
	{
		wxMessageBox(_("Could not create project at this location. The directory does not exists."));
		return;
	}

	project_file.AppendDir(pf_name);
	project_file.SetName(pf_name);
	project_file.SetExt(_("snprj"));

	if(wxDirExists(project_file.GetPath()))
	{
		wxMessageBox(_("Can't create project at this location. Project path already exists."));
		return; //Don't try to overwrite existing folder
	}

	project_file.Mkdir();

	createFlag = true;

	Close();
}
