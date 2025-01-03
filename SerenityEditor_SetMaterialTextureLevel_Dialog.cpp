#include "SerenityEditor_SetMaterialTextureLevel_Dialog.h"

SerenityEditor_SetMaterialTextureLevel_Dialog::SerenityEditor_SetMaterialTextureLevel_Dialog( wxWindow* parent )
:
SetMaterialTextureLevel_Dialog( parent )
{
	selected_texture_id = _("");
	id_list.Clear();
}

void SerenityEditor_SetMaterialTextureLevel_Dialog::OnSearch( wxCommandEvent& event )
{
	wxString search_string = event.GetString().Lower();

	if(search_string.compare(_(""))==0)
	{
		refresh_list();
		return;
	}

	m_textureList_listBox->Clear();

	for(int i = 0; i < id_list.size(); i++)
	{
		wxString id_name = id_list.Item(i);
		id_name = id_name.Lower();

		if(id_name.substr(0, search_string.length()).compare(search_string)==0)
			m_textureList_listBox->AppendAndEnsureVisible(id_list.Item(i));
	}
}

void SerenityEditor_SetMaterialTextureLevel_Dialog::OnSetTexture( wxCommandEvent& event )
{
	if(m_textureList_listBox->GetSelection() >= 0 && m_textureList_listBox->GetSelection() < m_textureList_listBox->GetCount() )
		selected_texture_id = m_textureList_listBox->GetString( m_textureList_listBox->GetSelection() );
	Close();
}

void SerenityEditor_SetMaterialTextureLevel_Dialog::refresh_list()
{
	m_textureList_listBox->Clear();

	for(int i = 0; i < id_list.size(); i++)
	{
		m_textureList_listBox->AppendAndEnsureVisible(id_list.Item(i));
	}
}

void SerenityEditor_SetMaterialTextureLevel_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}
