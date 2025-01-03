#include "SerenityEditor_SetMeshMaterialLevel_Dialog.h"

SerenityEditor_SetMeshMaterialLevel_Dialog::SerenityEditor_SetMeshMaterialLevel_Dialog( wxWindow* parent )
:
SetMeshMaterialLevel_Dialog( parent )
{
	selected_material_id = _("");
	id_list.Clear();
}

void SerenityEditor_SetMeshMaterialLevel_Dialog::OnSearch( wxCommandEvent& event )
{
	wxString search_string = event.GetString().Lower();

	if(search_string.compare(_(""))==0)
	{
		refresh_list();
		return;
	}

	m_materialList_listBox->Clear();

	for(int i = 0; i < id_list.size(); i++)
	{
		wxString id_name = id_list.Item(i);
		id_name = id_name.Lower();

		if(id_name.substr(0, search_string.length()).compare(search_string)==0)
			m_materialList_listBox->AppendAndEnsureVisible(id_list.Item(i));
	}
}

void SerenityEditor_SetMeshMaterialLevel_Dialog::OnSetMaterial( wxCommandEvent& event )
{
	if(m_materialList_listBox->GetSelection() >= 0 && m_materialList_listBox->GetSelection() < m_materialList_listBox->GetCount() )
		selected_material_id = m_materialList_listBox->GetString( m_materialList_listBox->GetSelection() );
	Close();
}

void SerenityEditor_SetMeshMaterialLevel_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}


void SerenityEditor_SetMeshMaterialLevel_Dialog::refresh_list()
{
	m_materialList_listBox->Clear();

	for(int i = 0; i < id_list.size(); i++)
	{
		m_materialList_listBox->AppendAndEnsureVisible(id_list.Item(i));
	}
}
