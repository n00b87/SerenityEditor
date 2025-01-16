#include <wx/wx.h>
#include "SerenityEditor_NewAnimatedActor_Dialog.h"

SerenityEditor_NewAnimatedActor_Dialog::SerenityEditor_NewAnimatedActor_Dialog( wxWindow* parent )
:
NewAnimatedActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewAnimatedActor_Dialog::OnSearchText( wxCommandEvent& event )
{
	refresh_list();
}

void SerenityEditor_NewAnimatedActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewAnimatedActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	if(m_mesh_listBox->GetSelection() >= 0 && m_mesh_listBox->GetSelection() < m_mesh_listBox->GetCount())
		mesh_id_name = m_mesh_listBox->GetString( m_mesh_listBox->GetSelection() );
	else
		mesh_id_name = _("");

	Close();
}

void SerenityEditor_NewAnimatedActor_Dialog::refresh_list()
{
	meshes.Sort();

	wxString search_string = m_meshSearch_searchCtrl->GetValue();
	search_string = search_string.Lower();

	m_mesh_listBox->Clear();

	for(int i = 0; i < meshes.size(); i++)
	{
		if(search_string.Length() == 0)
		{
			m_mesh_listBox->AppendAndEnsureVisible(meshes.Item(i));
		}
		else if( meshes.Item(i).Lower().substr(0, search_string.length()).compare(search_string) == 0 )
		{
			m_mesh_listBox->AppendAndEnsureVisible(meshes.Item(i));
		}
	}
}
