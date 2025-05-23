#ifndef __SerenityEditor_CreateMesh_Dialog__
#define __SerenityEditor_CreateMesh_Dialog__

/**
@file
Subclass of CreateMesh_Dialog, which is generated by wxFormBuilder.
*/

#include "Serenity3D_Editor.h"

//// end generated include

#define CREATE_MESH_SHAPE_PLANE			0
#define CREATE_MESH_SHAPE_CONE			1
#define CREATE_MESH_SHAPE_CYLINDERER	2

/** Implementing CreateMesh_Dialog */
class SerenityEditor_CreateMesh_Dialog : public CreateMesh_Dialog
{
	protected:
		// Handlers for CreateMesh_Dialog events.
		void OnShapeSelected( wxCommandEvent& event );
		void OnCancel( wxCommandEvent& event );
		void OnCreate( wxCommandEvent& event );
	public:
		bool create_flag;

		wxString mesh_id;
		int shape_type;

		//Plane Properties
		int tile_width;
		int tile_height;
		int tile_x_count;
		int tile_y_count;
		int tile_txRepeat_x;
		int tile_txRepeat_y;

		//Cone Properties
		double radius;
		double length;
		int tesselation;
		wxColour cone_top_color;
		wxColour cone_bottom_color;

		//Cylinder Properties  --  Note: Reuses radius, length, and tesselation from cone
		wxColour cylinder_color;
		bool cylinder_close_top;

		/** Constructor */
		SerenityEditor_CreateMesh_Dialog( wxWindow* parent );
	//// end generated class members

};

#endif // __SerenityEditor_CreateMesh_Dialog__
