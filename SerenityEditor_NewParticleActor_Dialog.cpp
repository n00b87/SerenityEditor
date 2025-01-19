#include "SerenityEditor_NewParticleActor_Dialog.h"

SerenityEditor_NewParticleActor_Dialog::SerenityEditor_NewParticleActor_Dialog( wxWindow* parent )
:
NewParticleActor_Dialog( parent )
{
	create_flag = false;
}

void SerenityEditor_NewParticleActor_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_NewParticleActor_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
	id_name = m_actorID_textCtrl->GetValue();
	particle_type = m_type_comboBox->GetStringSelection();
	create_flag = true;
	Close();
}

void SerenityEditor_NewParticleActor_Dialog::refresh_list()
{
	m_type_comboBox->Clear();

	m_type_comboBox->Insert(_("NONE"), 0);

	for(int i = 0; i < particle_type_list.size(); i++)
	{
		m_type_comboBox->Insert(particle_type_list.Item(i), i+1);
	}
}
