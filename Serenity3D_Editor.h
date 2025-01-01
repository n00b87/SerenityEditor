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
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include <wx/checklst.h>
#include <wx/srchctrl.h>
#include <wx/statline.h>

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
		wxAuiNotebook* m_editorMain_auinotebook;
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
		wxNotebook* m_project_abstraction_notebook;
		wxPanel* m_panel44;
		wxTreeCtrl* m_project_stage_treeCtrl;
		wxPanel* m_panel452;
		wxTreeCtrl* m_project_object_treeCtrl;
		wxPanel* m_panel311;
		wxPropertyGrid* m_project_propertyGrid;
		wxScrolledWindow* m_scrolledWindow2;
		wxPanel* m_panel422;
		wxStaticText* m_staticText28;
		wxCheckBox* m_viewportSettings_showGrid_checkBox;
		wxStaticText* m_staticText30;
		wxSpinCtrl* m_viewportSettings_gridSize_spinCtrl;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_viewportSettings_gridSpacing_spinCtrl;
		wxStaticText* m_staticText322;
		wxColourPickerCtrl* m_viewportSettings_gridColor_colourPicker;
		wxPanel* m_meshDB_panel;
		wxSplitterWindow* m_splitter51;
		wxPanel* m_panel28;
		wxButton* m_mesh_importMesh_button;
		wxButton* m_mesh_removeMesh_button;
		wxButton* m_mesh_saveMesh_button;
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
		wxButton* m_button51;
		wxButton* m_button52;
		wxButton* m_button53;
		wxListBox* m_mesh_materialList_listBox;
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
		wxPanel* m_materialDB_panel;
		wxSplitterWindow* m_splitter4;
		wxPanel* m_panel37;
		wxButton* m_material_newMaterial_button;
		wxButton* m_material_loadMaterial_button;
		wxButton* m_material_saveMaterial_button;
		wxButton* m_material_removeMaterial_button;
		wxListBox* m_material_material_listBox;
		wxPanel* m_panel38;
		wxPanel* m_panel391;
		wxScrolledWindow* m_scrolledWindow3;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_material_id_textCtrl;
		wxStaticText* m_staticText421;
		wxTextCtrl* m_material_materialFile_textCtrl;
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
		wxAuiToolBarItem* m_material_previewNoLight_tool;
		wxAuiToolBarItem* m_material_previewDirectionLight_tool;
		wxAuiToolBarItem* m_material_previewPointLight_tool;
		wxAuiToolBarItem* m_materialPreviewMesh_tool;
		wxAuiToolBarItem* m_materialPreviewSettings_tool;
		wxPanel* m_panel42;
		wxStaticText* m_staticText57;
		wxButton* m_material_addTextureLevel_button;
		wxButton* m_material_removeTextureLevel_button;
		wxButton* m_material_setTextureLevel_button;
		wxListBox* m_material_textureLevel_listBox;
		wxPanel* m_textureDB_panel;
		wxSplitterWindow* m_splitter5;
		wxPanel* m_panel39;
		wxButton* m_texture_addTexture_button;
		wxButton* m_texture_removeTexture_button;
		wxListBox* m_texture_textureList_listBox;
		wxPanel* m_panel402;
		wxStaticText* m_staticText40;
		wxTextCtrl* m_texture_textureID_textCtrl;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_texture_textureFile_textCtrl;
		wxStaticText* m_staticText432;
		wxCheckBox* m_texture_useColorKey_checkBox;
		wxStaticText* m_staticText41;
		wxColourPickerCtrl* m_texture_colorKey_colourPicker;
		wxPanel* m_texture_texturePreview_panel;
		wxStatusBar* m_statusBar1;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_tool1;
		wxToolBarToolBase* m_tool2;
		wxToolBarToolBase* m_tool3;
		wxToolBarToolBase* m_tbar_play_tool;
		wxToolBarToolBase* m_tool7;

		// Virtual event handlers, override them in your derived class
		virtual void OnNewProjectMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadProjectMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMainEditorNotebookPageChanged( wxAuiNotebookEvent& event ) { event.Skip(); }
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
		virtual void OnProjectPropertiesNotebookChanged( wxAuiNotebookEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Load_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Remove_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Save_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_MeshList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_AddMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_RemoveMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_SetMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAnimationPreviewSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void On_Mesh_previewPlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_previewStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_NewAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_DeleteAnimation( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_AnimationList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Animation_AnimationID( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Animation_StartFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Animation_EndFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Animation_Speed( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_NewMaterial_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_LoadMaterial_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_SaveMaterial_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_RemoveMaterial_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_MaterialList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_MaterialID_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_MaterialType_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_Ambient_Update( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_Material_Diffuse_Update( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_Material_Emissive_Update( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_Material_Specular_Update( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_Material_AntiAlias_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_BackfaceCulling_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_FrontfaceCulling_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_BlendFactor_Update( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void On_Material_BlendMode_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_ColorMask_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_ColorMode_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_Fog_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_GouradShading_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_Lighting_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_Normalize_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_PointCloud_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_Shineness_Update( wxSpinEvent& event ) { event.Skip(); }
		virtual void On_Material_previewNoLight_Selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_previewDirectionlight_Selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_previewPointlight_Selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetMaterialPreviewMesh( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_previewSettings_Selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_AddTextureLevel_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_RemoveTextureLevel_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Material_SetTextureLevel_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_AddTexture_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_RemoveTexture_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_TextureList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_TextureID_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_UseColorkey_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_Colorkey_Update( wxColourPickerEvent& event ) { event.Skip(); }
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
			m_splitter51->SetSashPosition( 176 );
			m_splitter51->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter51OnIdle ), NULL, this );
		}

		void m_splitter4OnIdle( wxIdleEvent& )
		{
			m_splitter4->SetSashPosition( 300 );
			m_splitter4->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter4OnIdle ), NULL, this );
		}

		void m_splitter5OnIdle( wxIdleEvent& )
		{
			m_splitter5->SetSashPosition( 291 );
			m_splitter5->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewProject_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewProject_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel61;
		wxStaticText* m_staticText65;
		wxTextCtrl* m_projectName_textCtrl;
		wxStaticText* m_staticText66;
		wxDirPickerCtrl* m_projectLocation_dirPicker;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewProject_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 390,178 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewProject_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewOctree_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewOctree_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_selectedMesh_textCtrl;
		wxButton* m_find_button;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewOctree_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Octree Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 534,346 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewOctree_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddTexture_Dialog
///////////////////////////////////////////////////////////////////////////////
class AddTexture_Dialog : public wxDialog
{
	private:

	protected:
		wxCheckListBox* m_files_checkList;
		wxButton* m_button19;
		wxButton* m_button20;
		wxButton* m_button23;
		wxButton* m_button24;
		wxButton* m_button21;
		wxButton* m_button22;

		// Virtual event handlers, override them in your derived class
		virtual void OnSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeselectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowDuplicates( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHideDuplicates( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		AddTexture_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add Textures"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 549,374 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AddTexture_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SetMaterialTextureLevel_Dialog
///////////////////////////////////////////////////////////////////////////////
class SetMaterialTextureLevel_Dialog : public wxDialog
{
	private:

	protected:
		wxSearchCtrl* m_findTexture_searchCtrl;
		wxListBox* m_textureList_listBox;
		wxButton* m_setTexture_button;
		wxButton* m_cancel_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetTexture( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		SetMaterialTextureLevel_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Set Texture Level"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 513,304 ), long style = wxDEFAULT_DIALOG_STYLE );

		~SetMaterialTextureLevel_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SetMaterialPreviewMesh_Dialog
///////////////////////////////////////////////////////////////////////////////
class SetMaterialPreviewMesh_Dialog : public wxDialog
{
	private:

	protected:
		wxSearchCtrl* m_findMesh_searchCtrl;
		wxListBox* m_meshList_listBox;
		wxButton* m_setMesh_button;
		wxButton* m_cube_button;
		wxButton* m_sphere_button;
		wxButton* m_cancel_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetMesh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDefaultCube( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDefaultSphere( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		SetMaterialPreviewMesh_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Set Material Preview Mesh"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 475,273 ), long style = wxDEFAULT_DIALOG_STYLE );

		~SetMaterialPreviewMesh_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MaterialPreviewSettings_Dialog
///////////////////////////////////////////////////////////////////////////////
class MaterialPreviewSettings_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText50;
		wxTextCtrl* m_cameraSpeed_textCtrl;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_cameraDistance_textCtrl;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText52;
		wxTextCtrl* m_lightRadius_textCtrl;
		wxButton* m_apply_button;
		wxButton* m_cancel_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		MaterialPreviewSettings_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Material Preview Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 497,223 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MaterialPreviewSettings_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddMaterial_Dialog
///////////////////////////////////////////////////////////////////////////////
class AddMaterial_Dialog : public wxDialog
{
	private:

	protected:
		wxCheckListBox* m_files_checkList;
		wxButton* m_button19;
		wxButton* m_button20;
		wxButton* m_button23;
		wxButton* m_button24;
		wxButton* m_button21;
		wxButton* m_button22;

		// Virtual event handlers, override them in your derived class
		virtual void OnSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeselectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowDuplicates( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHideDuplicates( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		AddMaterial_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Load Materials"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 505,372 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AddMaterial_Dialog();

};

