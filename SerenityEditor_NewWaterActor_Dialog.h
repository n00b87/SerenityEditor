#ifndef __SerenityEditor_NewWaterActor_Dialog__
#define __SerenityEditor_NewWaterActor_Dialog__

/**
@file
Subclass of NewWaterActor_Dialog, which is generated by wxFormBuilder.
*/

#include "Serenity3D_Editor.h"

//// end generated include

/** Implementing NewWaterActor_Dialog */
class SerenityEditor_NewWaterActor_Dialog : public NewWaterActor_Dialog
{
	protected:
		// Handlers for NewWaterActor_Dialog events.
		void OnSearchText( wxCommandEvent& event );
		void OnCancelButtonClicked( wxCommandEvent& event );
		void OnCreateButtonClicked( wxCommandEvent& event );
	public:
		wxString id_name;
		wxString mesh_id_name;
		wxArrayString meshes;
		bool create_flag;

		double wave_height;
		double wave_length;
		double wave_speed;

		void refresh_list();

		/** Constructor */
		SerenityEditor_NewWaterActor_Dialog( wxWindow* parent );
	//// end generated class members

};

#endif // __SerenityEditor_NewWaterActor_Dialog__
