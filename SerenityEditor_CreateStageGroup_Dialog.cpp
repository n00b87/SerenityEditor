#include "SerenityEditor_CreateStageGroup_Dialog.h"

SerenityEditor_CreateStageGroup_Dialog::SerenityEditor_CreateStageGroup_Dialog( wxWindow* parent )
:
CreateStageGroup_Dialog( parent )
{
	set_flag = false;
}

void SerenityEditor_CreateStageGroup_Dialog::OnCreate( wxCommandEvent& event )
{
	set_flag = true;
	group_name = m_groupName_textCtrl->GetValue();

	if(m_stage_comboBox->GetSelection() >= 0 && m_stage_comboBox->GetSelection() < m_stage_comboBox->GetCount())
		selected_stage = m_stage_comboBox->GetString(m_stage_comboBox->GetSelection());
	else
		selected_stage = _("");

	Close();
}

void SerenityEditor_CreateStageGroup_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_CreateStageGroup_Dialog::refresh_list()
{
	stages.Sort();

	for(int i = 0; i < stages.size(); i++)
	{
		if(stages.Item(i).compare(_(""))!=0)
		{
			m_stage_comboBox->Insert(stages.Item(i), i);
		}
	}

	for(int i = 0; i < stages.size(); i++)
	{
		if(stages.Item(i).compare(selected_stage)==0)
		{
			m_stage_comboBox->SetSelection(i);
			break;
		}
	}
}
