#include <wx/dir.h>
#include "SerenityEditor_AddMesh_Dialog.h"

SerenityEditor_AddMesh_Dialog::SerenityEditor_AddMesh_Dialog( wxWindow* parent )
:
AddMesh_Dialog( parent )
{
	bool show_duplicates = false;
	refresh_list();
}

void SerenityEditor_AddMesh_Dialog::refresh_list()
{
	m_files_checkList->Clear();

	wxDir dir;
	wxString filename;
	wxString filespec = _T("*.*");
	wxArrayString files_list;

	wxArrayString mesh_ext;

	mesh_ext.Add(_("obj"));
	mesh_ext.Add(_("an8"));
	mesh_ext.Add(_("b3d"));
	mesh_ext.Add(_("x"));
	mesh_ext.Add(_("ms3d"));
	mesh_ext.Add(_("md2"));
	mesh_ext.Add(_("md3"));
	mesh_ext.Add(_("irr"));
	mesh_ext.Add(_("irrmesh"));
	mesh_ext.Add(_("3ds"));
	mesh_ext.Add(_("lwo"));
	mesh_ext.Add(_("xml"));
	mesh_ext.Add(_("dae"));
	mesh_ext.Add(_("my3d"));
	mesh_ext.Add(_("lmts"));
	mesh_ext.Add(_("bsp"));
	mesh_ext.Add(_("dmf"));
	mesh_ext.Add(_("oct"));
	mesh_ext.Add(_("csm"));
	mesh_ext.Add(_("stl"));
	mesh_ext.Add(_("ply"));


	for(int i = 0; i < mesh_ext.size(); i++)
	{
	    filespec = _("*.") + mesh_ext.Item(i);

	    if ( dir.Open( model_path.GetAbsolutePath() ) )
        {
            bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES);
            while ( cont )
            {
                files_list.Add( filename );
                cont = dir.GetNext(&filename);
            }
        }

        dir.Close();
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

bool SerenityEditor_AddMesh_Dialog::isDuplicate(wxString filename)
{
	for(int i = 0; i < project_files.size(); i++)
	{
		if(project_files[i].compare(filename)==0)
			return true;
	}
	return false;
}

void SerenityEditor_AddMesh_Dialog::OnSelectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		m_files_checkList->Check(i, true);
	}
}

void SerenityEditor_AddMesh_Dialog::OnDeselectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		m_files_checkList->Check(i, false);
	}
}

void SerenityEditor_AddMesh_Dialog::OnShowDuplicates( wxCommandEvent& event )
{
	show_duplicates = true;
	refresh_list();
}

void SerenityEditor_AddMesh_Dialog::OnHideDuplicates( wxCommandEvent& event )
{
	show_duplicates = false;
	refresh_list();
}

void SerenityEditor_AddMesh_Dialog::OnLoad( wxCommandEvent& event )
{
	for(int i = 0; i < m_files_checkList->GetCount(); i++)
	{
		if(m_files_checkList->IsChecked(i))
			selected_files.push_back(m_files_checkList->GetString(i));
	}

	Close();
}

void SerenityEditor_AddMesh_Dialog::OnCancel( wxCommandEvent& event )
{
	selected_files.clear();
	Close();
}
