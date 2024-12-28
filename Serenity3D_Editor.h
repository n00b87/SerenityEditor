///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6-dirty)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/panel.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/splitter.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/statbmp.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Serenity3D_Frame
///////////////////////////////////////////////////////////////////////////////
class Serenity3D_Frame : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_project_menu;
		wxMenu* m_menu3;
		wxAuiNotebook* m_auinotebook2;
		wxPanel* m_stage_panel;
		wxAuiToolBar* m_auiToolBar52;
		wxAuiToolBarItem* m_s3d_select_tool;
		wxAuiToolBarItem* m_s3d_boxSelect_tool;
		wxAuiToolBarItem* m_s3d_move_tool;
		wxAuiToolBarItem* m_s3d_rotate_tool;
		wxAuiToolBarItem* m_s3d_scale_tool;
		wxAuiToolBarItem* m_s3d_octreeActor_tool;
		wxAuiToolBarItem* m_s3d_animatedActor_tool;
		wxAuiToolBarItem* m_s3d_billboardActor_tool;
		wxAuiToolBarItem* m_s3d_lightActor_tool;
		wxAuiToolBarItem* m_s3d_terrainActor_tool;
		wxAuiToolBarItem* m_s3d_waterActor_tool;
		wxAuiToolBarItem* m_s3d_particleActor_tool;
		wxAuiToolBarItem* m_s3d_plane_tool;
		wxAuiToolBarItem* m_s3d_cube_tool;
		wxAuiToolBarItem* m_s3d_sphere_tool;
		wxAuiToolBarItem* m_s3d_path_tool;
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel71;
		wxPanel* m_panel15;
		wxPanel* m_panel45;
		wxPanel* m_panel47;
		wxStaticText* m_staticText12;
		wxComboBox* m_stagePOV_comboBox;
		wxPanel* m_stageViewport_panel;
		wxPanel* m_panel40;
		wxPanel* m_panel8;
		wxAuiNotebook* m_auinotebook3;
		wxPanel* m_project_stages_panel;
		wxSplitterWindow* m_splitter6;
		wxPanel* m_panel305;
		wxNotebook* m_notebook1;
		wxPanel* m_panel44;
		wxTreeCtrl* m_project_treeCtrl;
		wxPanel* m_panel452;
		wxTreeCtrl* m_treeCtrl2;
		wxPanel* m_panel311;
		wxPropertyGrid* m_project_propertyGrid;
		wxScrolledWindow* m_scrolledWindow2;
		wxPanel* m_panel422;
		wxStaticText* m_staticText28;
		wxCheckBox* m_checkBox1;
		wxStaticText* m_staticText30;
		wxSpinCtrl* m_spinCtrl1;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_spinCtrl2;
		wxStaticText* m_staticText322;
		wxColourPickerCtrl* m_colourPicker1;
		wxPanel* m_meshDB_panel;
		wxSplitterWindow* m_splitter51;
		wxPanel* m_panel28;
		wxButton* m_mesh_importMesh_button;
		wxButton* m_mesh_removeMesh_button;
		wxListBox* m_mesh_mesh_listBox;
		wxPanel* m_panel291;
		wxPanel* m_panel41;
		wxPanel* m_panel33;
		wxStaticText* m_staticText321;
		wxTextCtrl* m_mesh_meshID_textCtrl;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_mesh_meshFile_textCtrl;
		wxPanel* m_panel34;
		wxStaticText* m_staticText323;
		wxPanel* m_panel35;
		wxScrolledWindow* m_setMaterial_scrolledWindow;
		wxPropertyGrid* m_mesh_material_propertyGrid;
		wxPGProperty* m_propertyGridItem25;
		wxPGProperty* m_propertyGridItem26;
		wxPanel* m_mesh_animationPreview_panel;
		wxToolBar* m_toolBar2;
		wxToolBarToolBase* m_mesh_meshAnimation_play_tool;
		wxToolBarToolBase* m_mesh_meshAnimation_stop_tool;
		wxPanel* m_panel43;
		wxPanel* m_panel46;
		wxStaticText* m_staticText33;
		wxButton* m_mesh_newAnimation_button;
		wxButton* m_mesh_deleteAnimation_button;
		wxListBox* m_mesh_meshAnimation_listBox;
		wxPanel* m_panel451;
		wxStaticText* m_staticText27;
		wxTextCtrl* m_mesh_animationID_textCtrl;
		wxStaticText* m_staticText271;
		wxTextCtrl* m_mesh_animationStartFrame_textCtrl;
		wxStaticText* m_staticText2711;
		wxTextCtrl* m_mesh_animationEndFrame_textCtrl;
		wxStaticText* m_staticText2712;
		wxTextCtrl* m_mesh_animationSpeed_textCtrl;
		wxPanel* m_panel36;
		wxSplitterWindow* m_splitter4;
		wxPanel* m_panel37;
		wxButton* m_material_newMaterial_button;
		wxButton* m_button231;
		wxButton* m_material_saveMaterial_button;
		wxButton* m_button24;
		wxListBox* m_material_material_listBox;
		wxPanel* m_panel38;
		wxPanel* m_panel391;
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_material_id_textCtrl;
		wxStaticText* m_staticText35;
		wxComboBox* m_material_type_comboBox;
		wxStaticText* m_staticText36;
		wxColourPickerCtrl* m_material_ambient_colourPicker;
		wxStaticText* m_staticText361;
		wxColourPickerCtrl* m_material_diffuse_colourPicker;
		wxStaticText* m_staticText362;
		wxColourPickerCtrl* m_material_emissive_colourPicker;
		wxStaticText* m_staticText363;
		wxColourPickerCtrl* m_material_specular_colourPicker;
		wxStaticText* m_staticText351;
		wxComboBox* m_material_antiAlias_comboBox;
		wxStaticText* m_staticText43;
		wxCheckBox* m_material_backFaceCulling_checkBox;
		wxStaticText* m_staticText431;
		wxCheckBox* m_material_frontFaceCulling_checkBox;
		wxStaticText* m_staticText46;
		wxSpinCtrlDouble* m_material_blendFactor_spinCtrlDouble;
		wxStaticText* m_staticText47;
		wxComboBox* m_material_blendMode_comboBox;
		wxStaticText* m_staticText48;
		wxComboBox* m_material_colorMask_comboBox;
		wxStaticText* m_staticText49;
		wxComboBox* m_material_colorMode_comboBox;
		wxStaticText* m_staticText50;
		wxCheckBox* m_material_fog_checkBox;
		wxStaticText* m_staticText51;
		wxCheckBox* m_material_gouradShading_checkBox;
		wxStaticText* m_staticText52;
		wxCheckBox* m_material_lighting_checkBox;
		wxStaticText* m_staticText521;
		wxCheckBox* m_material_normalize_checkBox;
		wxStaticText* m_staticText522;
		wxCheckBox* m_material_pointCloud_checkBox;
		wxStaticText* m_staticText56;
		wxSpinCtrl* m_material_shineness_spinCtrl;
		wxPanel* m_panel401;
		wxPanel* m_panel411;
		wxPanel* m_material_materialPreview_panel;
		wxAuiToolBar* m_auiToolBar2;
		wxAuiToolBarItem* m_material_previewSpotLight_tool;
		wxAuiToolBarItem* m_material_previewPointLight_tool;
		wxPanel* m_panel42;
		wxStaticText* m_staticText57;
		wxButton* m_material_addTextureLevel_button;
		wxButton* m_material_removeTextureLevel_button;
		wxPropertyGrid* m_material_textureLevel_propertyGrid;
		wxPGProperty* m_propertyGridItem23;
		wxPanel* m_panel441;
		wxStaticBitmap* m_material_texturePreview_bitmap;
		wxStatusBar* m_statusBar1;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_tool1;
		wxToolBarToolBase* m_tool2;
		wxToolBarToolBase* m_tool3;
		wxToolBarToolBase* m_tbar_play_tool;
		wxToolBarToolBase* m_tool7;

		// Virtual event handlers, override them in your derived class
		virtual void OnNewProjectMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DSelectClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DBoxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DMoveClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DRotateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DScaleClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DDumpClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DWizClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DBillboardClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DLightClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DTerrainClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DWaterClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DEffectClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DPlaneClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DCubeClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DSphereClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DPathClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewComboSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMeshImportButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAnimationPreviewSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnAnimationStopClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlayClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		Serenity3D_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Serenity Engine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1368,758 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Serenity3D_Frame();

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 1400 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter3OnIdle ), NULL, this );
		}

		void m_splitter6OnIdle( wxIdleEvent& )
		{
			m_splitter6->SetSashPosition( 0 );
			m_splitter6->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter6OnIdle ), NULL, this );
		}

		void m_splitter51OnIdle( wxIdleEvent& )
		{
			m_splitter51->SetSashPosition( 300 );
			m_splitter51->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
		}

		void m_splitter4OnIdle( wxIdleEvent& )
		{
			m_splitter4->SetSashPosition( 300 );
			m_splitter4->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class StageCanvasSettings_Frame
///////////////////////////////////////////////////////////////////////////////
class StageCanvasSettings_Frame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel33;
		wxScrolledWindow* m_scrolledWindow1;
		wxPanel* m_panel34;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrl1;
		wxComboBox* m_comboBox4;
		wxButton* m_button3;
		wxButton* m_button2;
		wxPanel* m_panel341;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText101;
		wxTextCtrl* m_textCtrl11;
		wxComboBox* m_comboBox41;
		wxButton* m_button31;
		wxButton* m_button21;
		wxPanel* m_panel342;
		wxStaticText* m_staticText92;
		wxStaticText* m_staticText102;
		wxTextCtrl* m_textCtrl12;
		wxComboBox* m_comboBox42;
		wxButton* m_button32;
		wxButton* m_button22;
		wxPanel* m_panel343;
		wxStaticText* m_staticText93;
		wxStaticText* m_staticText103;
		wxTextCtrl* m_textCtrl13;
		wxComboBox* m_comboBox43;
		wxButton* m_button33;
		wxButton* m_button23;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

	public:

		StageCanvasSettings_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Canvas Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 682,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~StageCanvasSettings_Frame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame3
///////////////////////////////////////////////////////////////////////////////
class MyFrame3 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_textCtrl12;
		wxButton* m_button17;
		wxListBox* m_listBox3;
		wxButton* m_button18;
		wxButton* m_button19;

	public:

		MyFrame3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create Octree Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame3();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame31
///////////////////////////////////////////////////////////////////////////////
class MyFrame31 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_textCtrl12;
		wxButton* m_button17;
		wxListBox* m_listBox3;
		wxButton* m_button18;
		wxButton* m_button19;

	public:

		MyFrame31( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create Octree Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame31();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame5
///////////////////////////////////////////////////////////////////////////////
class MyFrame5 : public wxFrame
{
	private:

	protected:
		wxPanel* m_setMaterial_panel;
		wxPanel* m_materialLabel_panel;
		wxStaticText* m_materialNumber_staticText;
		wxPanel* m_materialID_panel;
		wxComboBox* m_materialID_comboBox;
		wxPanel* m_setMaterial_panel1;
		wxPanel* m_materialLabel_panel1;
		wxStaticText* m_materialNumber_staticText1;
		wxPanel* m_materialID_panel1;
		wxComboBox* m_materialID_comboBox1;
		wxPropertyGrid* m_propertyGrid2;
		wxPGProperty* m_propertyGridItem1;
		wxPGProperty* m_propertyGridItem2;
		wxPGProperty* m_propertyGridItem3;

	public:

		MyFrame5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 733,653 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame5();

};

