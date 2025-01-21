#include "SerenityEditor_CreateMesh_Dialog.h"

SerenityEditor_CreateMesh_Dialog::SerenityEditor_CreateMesh_Dialog( wxWindow* parent )
:
CreateMesh_Dialog( parent )
{
	m_shape_comboBox->Insert(_("Plane"), 0);
	m_shape_comboBox->Insert(_("Cone"), 1);
	m_shape_comboBox->Insert(_("Cylinder"), 2);

	m_shape_comboBox->SetSelection(0);

	create_flag = false;

	m_coneTopColor_colourPicker->SetColour(wxColour(0,0,0,255));
	m_coneBottomColor_colourPicker->SetColour(wxColour(0,0,0,255));
	m_cylinderColor_colourPicker->SetColour(wxColour(0,0,0,255));
}

void SerenityEditor_CreateMesh_Dialog::OnShapeSelected( wxCommandEvent& event )
{
	wxString selected_shape = m_shape_comboBox->GetStringSelection();

	if(selected_shape.Trim().compare(_("Plane"))==0)
	{
		m_shape_simplebook->ShowNewPage(m_plane_panel);
	}
	else if(selected_shape.Trim().compare(_("Cone"))==0)
	{
		m_shape_simplebook->ShowNewPage(m_cone_panel);
	}
	else if(selected_shape.Trim().compare(_("Cylinder"))==0)
	{
		m_shape_simplebook->ShowNewPage(m_cylinder_panel);
	}
}

void SerenityEditor_CreateMesh_Dialog::OnCancel( wxCommandEvent& event )
{
	Close();
}

void SerenityEditor_CreateMesh_Dialog::OnCreate( wxCommandEvent& event )
{
	mesh_id = m_meshID_textCtrl->GetValue();
	wxString selected_shape = m_shape_comboBox->GetStringSelection();

	cone_top_color = wxColour(0,0,0,255);
	cone_bottom_color = wxColour(0,0,0,255);
	cylinder_color = wxColour(0,0,0,255);

	if(selected_shape.Trim().compare(_("Plane"))==0)
	{
		shape_type = CREATE_MESH_SHAPE_PLANE;

		tile_width = m_planeTileWidth_spinCtrl->GetValue();
		tile_height = m_planeTileHeight_spinCtrl->GetValue();

		tile_x_count = m_planeCountX_spinCtrl->GetValue();
		tile_y_count = m_planeCountY_spinCtrl->GetValue();

		tile_txRepeat_x = m_planeTxRepeatX_spinCtrl->GetValue();
		tile_txRepeat_y = m_planeTxRepeatY_spinCtrl->GetValue();
	}
	else if(selected_shape.Trim().compare(_("Cone"))==0)
	{
		shape_type = CREATE_MESH_SHAPE_CONE;

		radius = m_coneRadius_spinCtrlDouble->GetValue();
		length = m_coneLength_spinCtrlDouble->GetValue();
		tesselation = m_coneTesselation_spinCtrl->GetValue();
		cone_top_color = m_coneTopColor_colourPicker->GetColour();
		cone_bottom_color = m_coneBottomColor_colourPicker->GetColour();
	}
	else if(selected_shape.Trim().compare(_("Cylinder"))==0)
	{
		shape_type = CREATE_MESH_SHAPE_CYLINDERER;

		radius = m_cylinderRadius_spinCtrlDouble->GetValue();
		length = m_cylinderLength_spinCtrlDouble->GetValue();
		tesselation = m_cylinderTesselation_spinCtrl->GetValue();
		cylinder_color = m_cylinderColor_colourPicker->GetColour();
		cylinder_close_top = m_cylinderCloseTop_checkBox->GetValue();
	}

	create_flag = true;
	Close();
}
