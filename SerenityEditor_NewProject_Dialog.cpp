#include <wx/wx.h>
#include "SerenityEditor_NewProject_Dialog.h"
#include "rc_defines.h"

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

	//Make sub folders
	wxFileName tx_dir = project_file;
	tx_dir.AppendDir(_("textures"));
	tx_dir.Mkdir();

	wxFileName mat_dir = project_file;
	mat_dir.AppendDir(_("materials"));
	mat_dir.Mkdir();

	wxFileName model_dir = project_file;
	model_dir.AppendDir(_("models"));
	model_dir.Mkdir();

	wxFileName stage_dir = project_file;
	stage_dir.AppendDir(_("stages"));
	stage_dir.Mkdir();

	wxFileName data_dir = project_file;
	data_dir.AppendDir(_("data"));
	data_dir.Mkdir();

	wxFile p_file(project_file.GetAbsolutePath(), wxFile::write);

	if(!p_file.IsOpened())
	{
		wxMessageBox(_("Error: Could not write to project file"));
		return;
	}

	p_file.Write(_("Serenity version=") + _(SERENITY_VERSION_STRING) + _(";\n"));
	p_file.Write(_("Project name=\"") + project_name + _("\"") + _(";\n"));
	p_file.Close();

	createFlag = true;

	Close();
}
