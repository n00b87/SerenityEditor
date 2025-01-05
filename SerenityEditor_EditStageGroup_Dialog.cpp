#include "SerenityEditor_EditStageGroup_Dialog.h"

SerenityEditor_EditStageGroup_Dialog::SerenityEditor_EditStageGroup_Dialog( wxWindow* parent )
:
EditStageGroup_Dialog( parent )
{
	applyFlag = false;
}

void SerenityEditor_EditStageGroup_Dialog::OnStageSelectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_stageList_checkList->GetCount(); i++)
	{
		m_stageList_checkList->Check(i, true);
	}
}

void SerenityEditor_EditStageGroup_Dialog::OnStageDeselectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_stageList_checkList->GetCount(); i++)
	{
		m_stageList_checkList->Check(i, false);
	}
}

void SerenityEditor_EditStageGroup_Dialog::OnAdd( wxCommandEvent& event )
{
	for(int i = 0; i < m_stageList_checkList->GetCount(); i++)
	{
		if(m_stageList_checkList->IsChecked(i))
		{
			dst_actors.push_back(src_actors.Item(i));
		}
	}

	for(int i = m_stageList_checkList->GetCount()-1; i >= 0; i--)
	{
		if(m_stageList_checkList->IsChecked(i))
		{
			src_actors.RemoveAt(i);
		}
	}

	refresh_list();
}

void SerenityEditor_EditStageGroup_Dialog::OnRemove( wxCommandEvent& event )
{
	for(int i = 0; i < m_groupList_checkList->GetCount(); i++)
	{
		if(m_groupList_checkList->IsChecked(i))
		{
			src_actors.push_back(dst_actors.Item(i));
		}
	}

	for(int i = m_groupList_checkList->GetCount()-1; i >= 0; i--)
	{
		if(m_groupList_checkList->IsChecked(i))
		{
			dst_actors.RemoveAt(i);
		}
	}

	refresh_list();
}

void SerenityEditor_EditStageGroup_Dialog::OnGroupSelectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_groupList_checkList->GetCount(); i++)
	{
		m_groupList_checkList->Check(i, true);
	}
}

void SerenityEditor_EditStageGroup_Dialog::OnGroupDeselectAll( wxCommandEvent& event )
{
	for(int i = 0; i < m_groupList_checkList->GetCount(); i++)
	{
		m_groupList_checkList->Check(i, false);
	}
}

void SerenityEditor_EditStageGroup_Dialog::OnApply( wxCommandEvent& event )
{
	group_name = m_groupLabel_textCtrl->GetValue();
	applyFlag = true;
	Close();
}

void SerenityEditor_EditStageGroup_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_EditStageGroup_Dialog::refresh_list()
{
	m_stageList_checkList->Clear();
	m_groupList_checkList->Clear();

	for(int i = 0; i < src_actors.size(); i++)
	{
		m_stageList_checkList->AppendAndEnsureVisible(src_actors.Item(i));
	}

	for(int i = 0; i < dst_actors.size(); i++)
	{
		m_groupList_checkList->AppendAndEnsureVisible(dst_actors.Item(i));
	}
}

void SerenityEditor_EditStageGroup_Dialog::refresh_groupName()
{
	m_groupLabel_textCtrl->SetValue(group_name);
}
