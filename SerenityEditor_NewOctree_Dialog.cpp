#include "SerenityEditor_NewOctree_Dialog.h"

SerenityEditor_NewOctree_Dialog::SerenityEditor_NewOctree_Dialog( wxWindow* parent, serenity_project* prj )
:
NewOctree_Dialog( parent )
{
	project = prj;


}

void SerenityEditor_NewOctree_Dialog::OnCancelButtonClicked( wxCommandEvent& event )
{
// TODO: Implement OnCancelButtonClicked
	Close();
}

void SerenityEditor_NewOctree_Dialog::OnCreateButtonClicked( wxCommandEvent& event )
{
// TODO: Implement OnCreateButtonClicked
}
