#include "SerenityEditor_ExitEditorAlert_Dialog.h"

SerenityEditor_ExitEditorAlert_Dialog::SerenityEditor_ExitEditorAlert_Dialog( wxWindow* parent )
:
ExitEditorAlert_Dialog( parent )
{
	save_flag = false;
	exit_flag = false;
}

void SerenityEditor_ExitEditorAlert_Dialog::OnSave( wxCommandEvent& event )
{
	save_flag = true;
	exit_flag = true;

	Close();
}

void SerenityEditor_ExitEditorAlert_Dialog::OnDiscard( wxCommandEvent& event )
{
	exit_flag = true;
	Close();
}

void SerenityEditor_ExitEditorAlert_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}
