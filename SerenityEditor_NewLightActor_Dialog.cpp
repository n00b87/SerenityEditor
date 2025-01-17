#include "SerenityEditor_NewLightActor_Dialog.h"

SerenityEditor_NewLightActor_Dialog::SerenityEditor_NewLightActor_Dialog( wxWindow* parent )
:
NewLightActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewLightActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewLightActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	id_name = m_actorID_textCtrl->GetValue();
	light_type = m_type_comboBox->GetStringSelection();
	create_flag = true;
	Close();
}

void SerenityEditor_NewLightActor_Dialog::refresh_list()
{
	m_type_comboBox->Clear();

	m_type_comboBox->Insert(_("NONE"), 0);

	for(int i = 0; i < light_type_list.size(); i++)
	{
		m_type_comboBox->Insert(light_type_list.Item(i), i+1);
	}
}
