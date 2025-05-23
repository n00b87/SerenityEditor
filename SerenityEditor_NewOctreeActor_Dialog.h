#ifndef __SerenityEditor_NewOctreeActor_Dialog__
#define __SerenityEditor_NewOctreeActor_Dialog__

/**
@file
Subclass of NewOctreeActor_Dialog, which is generated by wxFormBuilder.
*/
#include <wx/wx.h>
#include "Serenity3D_Editor.h"

//// end generated include

/** Implementing NewOctreeActor_Dialog */
class SerenityEditor_NewOctreeActor_Dialog : public NewOctreeActor_Dialog
{
	protected:
		// Handlers for NewOctreeActor_Dialog events.
		void OnSearchText( wxCommandEvent& event );
		void OnCancelButtonClicked( wxCommandEvent& event );
		void OnCreateButtonClicked( wxCommandEvent& event );
	public:
		wxString id_name;
		wxString mesh_id_name;
		wxArrayString meshes;
		bool create_flag;

		void refresh_list();

		/** Constructor */
		SerenityEditor_NewOctreeActor_Dialog( wxWindow* parent );
	//// end generated class members

};

#endif // __SerenityEditor_NewOctreeActor_Dialog__
