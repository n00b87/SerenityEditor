#include <wx/wx.h>
#include "SerenityEditor_NewTerrainActor_Dialog.h"

SerenityEditor_NewTerrainActor_Dialog::SerenityEditor_NewTerrainActor_Dialog( wxWindow* parent )
:
NewTerrainActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewTerrainActor_Dialog::OnSearchText( wxCommandEvent& event )
{
	refresh_list();
}

void SerenityEditor_NewTerrainActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewTerrainActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	if(m_texture_listBox->GetSelection() >= 0 && m_texture_listBox->GetSelection() < m_texture_listBox->GetCount())
		texture_id_name = m_texture_listBox->GetString( m_texture_listBox->GetSelection() );
	else
		texture_id_name = _("");

	Close();
}


void SerenityEditor_NewTerrainActor_Dialog::refresh_list()
{
	textures.Sort();

	wxString search_string = m_textureSearch_searchCtrl->GetValue();
	search_string = search_string.Lower();

	m_texture_listBox->Clear();

	for(int i = 0; i < textures.size(); i++)
	{
		if(search_string.Length() == 0)
		{
			m_texture_listBox->AppendAndEnsureVisible(textures.Item(i));
		}
		else if( textures.Item(i).Lower().substr(0, search_string.length()).compare(search_string) == 0 )
		{
			m_texture_listBox->AppendAndEnsureVisible(textures.Item(i));
		}
	}
}

