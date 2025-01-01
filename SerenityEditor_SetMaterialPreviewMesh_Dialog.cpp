#include "SerenityEditor_SetMaterialPreviewMesh_Dialog.h"

SerenityEditor_SetMaterialPreviewMesh_Dialog::SerenityEditor_SetMaterialPreviewMesh_Dialog( wxWindow* parent )
:
SetMaterialPreviewMesh_Dialog( parent )
{
	selected_mesh_id = _("");
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::refresh_list()
{
	m_meshList_listBox->Clear();

	mesh_list.Sort();

	for(int i = 0; i < mesh_list.size(); i++)
	{
		m_meshList_listBox->AppendAndEnsureVisible(mesh_list.Item(i));
	}
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::OnSearch( wxCommandEvent& event )
{
	wxString search_string = event.GetString().Lower();

	if(search_string.compare(_(""))==0)
	{
		refresh_list();
		return;
	}

	m_meshList_listBox->Clear();

	for(int i = 0; i < mesh_list.size(); i++)
	{
		wxString id_name = mesh_list.Item(i);
		id_name = id_name.Lower();

		if(id_name.substr(0, search_string.length()).compare(search_string)==0)
			m_meshList_listBox->AppendAndEnsureVisible(mesh_list.Item(i));
	}
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::OnSetMesh( wxCommandEvent& event )
{
	selected_mesh_id = m_meshList_listBox->GetString( m_meshList_listBox->GetSelection() );
	Close();
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::OnDefaultCube( wxCommandEvent& event )
{
	selected_mesh_id = _("[DEFAULT_CUBE]");
	Close();
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::OnDefaultSphere( wxCommandEvent& event )
{
	selected_mesh_id = _("[DEFAULT_SPHERE]");
	Close();
}

void SerenityEditor_SetMaterialPreviewMesh_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}
