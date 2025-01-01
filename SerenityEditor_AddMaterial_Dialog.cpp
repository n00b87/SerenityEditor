#include <wx/wx.h>
#include <wx/dir.h>
#include "SerenityEditor_AddMaterial_Dialog.h"

SerenityEditor_AddMaterial_Dialog::SerenityEditor_AddMaterial_Dialog( wxWindow* parent )
:
AddMaterial_Dialog( parent )
{
	bool show_duplicates = false;
	refresh_list();
}

bool SerenityEditor_AddMaterial_Dialog::isDuplicate(wxString filename)
{
	for(int i = 0; i < project_files.size(); i++)
	{
		if(project_files[i].compare(filename)==0)
			return true;
	}
	return false;
}

void SerenityEditor_AddMaterial_Dialog::refresh_list()
{
	m_files_checkList->Clear();

	wxDir dir;
	wxString filename;
	wxString filespec = _T("*.*");
	wxArrayString files_list;

	if ( dir.Open( material_path.GetAbsolutePath() ) )
	{
		bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES);
		while ( cont )
		{
			files_list.Add( filename );
			cont = dir.GetNext(&filename);
		}
	}

	files_list.Sort();

	for(int i = 0; i < files_list.size(); i++)
	{
		if(!show_duplicates)
		{
			if(isDuplicate(files_list.Item(i)))
				continue;
		}

		m_files_checkList->AppendAndEnsureVisible(files_list.Item(i));
	}
}

void SerenityEditor_AddMaterial_Dialog::OnSelectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		m_files_checkList->Check(i, true);
	}
}

void SerenityEditor_AddMaterial_Dialog::OnDeselectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		m_files_checkList->Check(i, false);
	}
}

void SerenityEditor_AddMaterial_Dialog::OnShowDuplicates( wxCommandEvent& event )
{
	show_duplicates = true;
	refresh_list();
}

void SerenityEditor_AddMaterial_Dialog::OnHideDuplicates( wxCommandEvent& event )
{
	show_duplicates = false;
	refresh_list();
}

void SerenityEditor_AddMaterial_Dialog::OnLoad( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		if(m_files_checkList->IsChecked(i))
			selected_files.push_back(m_files_checkList->GetString(i));
	}

	Close();
}

void SerenityEditor_AddMaterial_Dialog::OnCancel( wxCommandEvent& event )
{
	selected_files.clear();
	Close();
}
