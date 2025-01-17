#include <wx/wx.h>
#include "SerenityEditor_NewBillboardActor_Dialog.h"

SerenityEditor_NewBillboardActor_Dialog::SerenityEditor_NewBillboardActor_Dialog( wxWindow* parent )
:
NewBillboardActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewBillboardActor_Dialog::OnSearchText( wxCommandEvent& event )
{
	refresh_list();
}

void SerenityEditor_NewBillboardActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewBillboardActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	create_flag = true;
	id_name = m_actorID_textCtrl->GetValue();

	if(m_material_listBox->GetSelection() >= 0 && m_material_listBox->GetSelection() < m_material_listBox->GetCount())
		material_id_name = m_material_listBox->GetString( m_material_listBox->GetSelection() );
	else
		material_id_name = _("");

	Close();
}


void SerenityEditor_NewBillboardActor_Dialog::refresh_list()
{
	materials.Sort();

	wxString search_string = m_materialSearch_searchCtrl->GetValue();
	search_string = search_string.Lower();

	m_material_listBox->Clear();

	for(int i = 0; i < materials.size(); i++)
	{
		if(search_string.Length() == 0)
		{
			m_material_listBox->AppendAndEnsureVisible(materials.Item(i));
		}
		else if( materials.Item(i).Lower().substr(0, search_string.length()).compare(search_string) == 0 )
		{
			m_material_listBox->AppendAndEnsureVisible(materials.Item(i));
		}
	}
}
