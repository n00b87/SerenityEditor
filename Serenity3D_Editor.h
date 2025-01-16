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
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/treectrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/advprops.h>
#include <wx/splitter.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/clrpicker.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/srchctrl.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/checklst.h>
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
		wxAuiNotebook* m_editorMain_auinotebook;
		wxPanel* m_stage_panel;
		wxAuiToolBar* m_auiToolBar52;
		wxAuiToolBarItem* m_s3d_select_tool;
		wxAuiToolBarItem* m_s3d_boxSelect_tool;
		wxAuiToolBarItem* m_s3d_move_tool;
		wxAuiToolBarItem* m_s3d_rotate_tool;
		wxAuiToolBarItem* m_s3d_scale_tool;
		wxAuiToolBarItem* m_s3d_animatedActor_tool;
		wxAuiToolBarItem* m_s3d_octreeActor_tool;
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
		wxPanel* m_panel44;
		wxBitmapButton* m_bpButton41;
		wxBitmapButton* m_bpButton51;
		wxBitmapButton* m_bpButton4;
		wxBitmapButton* m_bpButton5;
		wxBitmapButton* m_bpButton6;
		wxBitmapButton* m_bpButton61;
		wxTreeCtrl* m_project_stage_treeCtrl;
		wxPanel* m_panel311;
		wxPropertyGridManager* m_stage_propertyGridManager;
		wxPropertyGridPage* m_group_propertyGridPage;
		wxPropertyGridPage* m_lightActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem11111;
		wxPGProperty* m_aniActorID_propertyGridItem11111;
		wxPGProperty* m_propertyGridItem268;
		wxPGProperty* m_propertyGridItem272;
		wxPGProperty* m_propertyGridItem443;
		wxPGProperty* m_propertyGridItem444;
		wxPGProperty* m_propertyGridItem445;
		wxPGProperty* m_propertyGridItem269;
		wxPGProperty* m_propertyGridItem271;
		wxPGProperty* m_propertyGridItem435;
		wxPGProperty* m_propertyGridItem436;
		wxPGProperty* m_propertyGridItem437;
		wxPGProperty* m_propertyGridItem438;
		wxPGProperty* m_propertyGridItem439;
		wxPGProperty* m_propertyGridItem440;
		wxPGProperty* m_propertyGridItem441;
		wxPGProperty* m_propertyGridItem442;
		wxPGProperty* m_propertyGridItem4611111;
		wxPGProperty* m_propertyGridItem4711111;
		wxPGProperty* m_propertyGridItem4811111;
		wxPGProperty* m_propertyGridItem4911111;
		wxPGProperty* m_propertyGridItem5011111;
		wxPGProperty* m_propertyGridItem5111111;
		wxPGProperty* m_propertyGridItem5211111;
		wxPGProperty* m_propertyGridItem5311111;
		wxPGProperty* m_propertyGridItem5411111;
		wxPGProperty* m_propertyGridItem5511111;
		wxPGProperty* m_propertyGridItem5611111;
		wxPGProperty* m_propertyGridItem5711111;
		wxPGProperty* m_propertyGridItem5811111;
		wxPGProperty* m_propertyGridItem453;
		wxPGProperty* m_propertyGridItem6011111;
		wxPGProperty* m_propertyGridItem6111111;
		wxPGProperty* m_propertyGridItem6211111;
		wxPropertyGridPage* m_animatedActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem;
		wxPGProperty* m_aniActorID_propertyGridItem;
		wxPGProperty* m_propertyGridItem41;
		wxPGProperty* m_propertyGridItem42;
		wxPGProperty* m_propertyGridItem43;
		wxPGProperty* m_propertyGridItem44;
		wxPGProperty* m_propertyGridItem46;
		wxPGProperty* m_propertyGridItem47;
		wxPGProperty* m_propertyGridItem48;
		wxPGProperty* m_propertyGridItem49;
		wxPGProperty* m_propertyGridItem50;
		wxPGProperty* m_propertyGridItem51;
		wxPGProperty* m_propertyGridItem52;
		wxPGProperty* m_propertyGridItem53;
		wxPGProperty* m_propertyGridItem54;
		wxPGProperty* m_propertyGridItem55;
		wxPGProperty* m_propertyGridItem56;
		wxPGProperty* m_propertyGridItem57;
		wxPGProperty* m_propertyGridItem58;
		wxPGProperty* m_propertyGridItem452;
		wxPGProperty* m_propertyGridItem60;
		wxPGProperty* m_propertyGridItem61;
		wxPGProperty* m_propertyGridItem62;
		wxPropertyGridPage* m_projectProperties_propertyGridPage;
		wxPGProperty* m_propertyGridItem432;
		wxPGProperty* m_propertyGridItem433;
		wxPropertyGridPage* m_particleActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem111111;
		wxPGProperty* m_aniActorID_propertyGridItem111111;
		wxPGProperty* m_propertyGridItem2681;
		wxPGProperty* m_propertyGridItem333;
		wxPGProperty* m_propertyGridItem334;
		wxPGProperty* m_propertyGridItem335;
		wxPGProperty* m_propertyGridItem336;
		wxPGProperty* m_propertyGridItem337;
		wxPGProperty* m_propertyGridItem338;
		wxPGProperty* m_propertyGridItem322;
		wxPGProperty* m_propertyGridItem323;
		wxPGProperty* m_propertyGridItem324;
		wxPGProperty* m_propertyGridItem325;
		wxPGProperty* m_propertyGridItem326;
		wxPGProperty* m_propertyGridItem327;
		wxPGProperty* m_propertyGridItem328;
		wxPGProperty* m_propertyGridItem329;
		wxPGProperty* m_propertyGridItem330;
		wxPGProperty* m_propertyGridItem364;
		wxPGProperty* m_propertyGridItem365;
		wxPGProperty* m_propertyGridItem366;
		wxPGProperty* m_propertyGridItem367;
		wxPGProperty* m_propertyGridItem339;
		wxPGProperty* m_propertyGridItem340;
		wxPGProperty* m_propertyGridItem341;
		wxPGProperty* m_propertyGridItem342;
		wxPGProperty* m_propertyGridItem331;
		wxPGProperty* m_propertyGridItem332;
		wxPGProperty* m_propertyGridItem347;
		wxPGProperty* m_propertyGridItem348;
		wxPGProperty* m_propertyGridItem349;
		wxPGProperty* m_propertyGridItem350;
		wxPGProperty* m_propertyGridItem2691;
		wxPGProperty* m_propertyGridItem343;
		wxPGProperty* m_propertyGridItem321;
		wxPGProperty* m_propertyGridItem2701;
		wxPGProperty* m_propertyGridItem2721;
		wxPGProperty* m_propertyGridItem344;
		wxPGProperty* m_propertyGridItem345;
		wxPGProperty* m_propertyGridItem346;
		wxPGProperty* m_propertyGridItem2711;
		wxPGProperty* m_propertyGridItem354;
		wxPGProperty* m_propertyGridItem355;
		wxPGProperty* m_propertyGridItem356;
		wxPGProperty* m_propertyGridItem357;
		wxPGProperty* m_propertyGridItem358;
		wxPGProperty* m_propertyGridItem359;
		wxPGProperty* m_propertyGridItem360;
		wxPGProperty* m_propertyGridItem361;
		wxPGProperty* m_propertyGridItem362;
		wxPGProperty* m_propertyGridItem363;
		wxPGProperty* m_propertyGridItem46111111;
		wxPGProperty* m_propertyGridItem47111111;
		wxPGProperty* m_propertyGridItem48111111;
		wxPGProperty* m_propertyGridItem49111111;
		wxPGProperty* m_propertyGridItem50111111;
		wxPGProperty* m_propertyGridItem51111111;
		wxPGProperty* m_propertyGridItem52111111;
		wxPGProperty* m_propertyGridItem53111111;
		wxPGProperty* m_propertyGridItem54111111;
		wxPGProperty* m_propertyGridItem55111111;
		wxPGProperty* m_propertyGridItem56111111;
		wxPGProperty* m_propertyGridItem57111111;
		wxPGProperty* m_propertyGridItem58111111;
		wxPGProperty* m_propertyGridItem451;
		wxPGProperty* m_propertyGridItem60111111;
		wxPGProperty* m_propertyGridItem61111111;
		wxPGProperty* m_propertyGridItem62111111;
		wxPropertyGridPage* m_stageProperties_propertyGridPage;
		wxPGProperty* m_propertyGridItem15;
		wxPGProperty* m_stageID_propertyGridItem;
		wxPGProperty* m_skyShape_propertyGridItem;
		wxPGProperty* m_propertyGridItem21;
		wxPGProperty* m_propertyGridItem14;
		wxPGProperty* m_skyDome_hRes_propertyGridItem;
		wxPGProperty* m_skyDome_vRes_propertyGridItem;
		wxPGProperty* m_skyDomeTxPct_propertyGridItem;
		wxPGProperty* m_skyDomeSpherePct_propertyGridItem;
		wxPGProperty* m_skyDomeRadius_propertyGridItem;
		wxPGProperty* m_skyBoxCat_propertyGridItem;
		wxPGProperty* m_skyBoxTopImage_propertyGridItem;
		wxPGProperty* m_skyBoxBottomImage_propertyGridItem;
		wxPGProperty* m_skyBoxLeftImage_propertyGridItem;
		wxPGProperty* m_skyBoxRightImage_propertyGridItem;
		wxPGProperty* m_skyBoxFrontImage_propertyGridItem;
		wxPGProperty* m_skyBoxBackImage_propertyGridItem;
		wxPropertyGridPage* m_octreeActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem1;
		wxPGProperty* m_aniActorID_propertyGridItem1;
		wxPGProperty* m_propertyGridItem411;
		wxPGProperty* m_propertyGridItem461;
		wxPGProperty* m_propertyGridItem471;
		wxPGProperty* m_propertyGridItem481;
		wxPGProperty* m_propertyGridItem491;
		wxPGProperty* m_propertyGridItem501;
		wxPGProperty* m_propertyGridItem511;
		wxPGProperty* m_propertyGridItem521;
		wxPGProperty* m_propertyGridItem531;
		wxPGProperty* m_propertyGridItem541;
		wxPGProperty* m_propertyGridItem551;
		wxPGProperty* m_propertyGridItem561;
		wxPGProperty* m_propertyGridItem571;
		wxPGProperty* m_propertyGridItem581;
		wxPGProperty* m_propertyGridItem450;
		wxPGProperty* m_propertyGridItem601;
		wxPGProperty* m_propertyGridItem611;
		wxPGProperty* m_propertyGridItem621;
		wxPropertyGridPage* m_cubeActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem11;
		wxPGProperty* m_aniActorID_propertyGridItem11;
		wxPGProperty* m_propertyGridItem149;
		wxPGProperty* m_propertyGridItem4611;
		wxPGProperty* m_propertyGridItem4711;
		wxPGProperty* m_propertyGridItem4811;
		wxPGProperty* m_propertyGridItem4911;
		wxPGProperty* m_propertyGridItem5011;
		wxPGProperty* m_propertyGridItem5111;
		wxPGProperty* m_propertyGridItem5211;
		wxPGProperty* m_propertyGridItem5311;
		wxPGProperty* m_propertyGridItem5411;
		wxPGProperty* m_propertyGridItem5511;
		wxPGProperty* m_propertyGridItem5611;
		wxPGProperty* m_propertyGridItem5711;
		wxPGProperty* m_propertyGridItem5811;
		wxPGProperty* m_propertyGridItem449;
		wxPGProperty* m_propertyGridItem6011;
		wxPGProperty* m_propertyGridItem6111;
		wxPGProperty* m_propertyGridItem6211;
		wxPropertyGridPage* m_sphereActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem111;
		wxPGProperty* m_aniActorID_propertyGridItem111;
		wxPGProperty* m_propertyGridItem1491;
		wxPGProperty* m_propertyGridItem46111;
		wxPGProperty* m_propertyGridItem47111;
		wxPGProperty* m_propertyGridItem48111;
		wxPGProperty* m_propertyGridItem49111;
		wxPGProperty* m_propertyGridItem50111;
		wxPGProperty* m_propertyGridItem51111;
		wxPGProperty* m_propertyGridItem52111;
		wxPGProperty* m_propertyGridItem53111;
		wxPGProperty* m_propertyGridItem54111;
		wxPGProperty* m_propertyGridItem55111;
		wxPGProperty* m_propertyGridItem56111;
		wxPGProperty* m_propertyGridItem57111;
		wxPGProperty* m_propertyGridItem58111;
		wxPGProperty* m_propertyGridItem448;
		wxPGProperty* m_propertyGridItem60111;
		wxPGProperty* m_propertyGridItem61111;
		wxPGProperty* m_propertyGridItem62111;
		wxPropertyGridPage* m_billboardActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem1111;
		wxPGProperty* m_aniActorID_propertyGridItem1111;
		wxPGProperty* m_propertyGridItem461111;
		wxPGProperty* m_propertyGridItem471111;
		wxPGProperty* m_propertyGridItem481111;
		wxPGProperty* m_propertyGridItem491111;
		wxPGProperty* m_propertyGridItem501111;
		wxPGProperty* m_propertyGridItem511111;
		wxPGProperty* m_propertyGridItem521111;
		wxPGProperty* m_propertyGridItem531111;
		wxPGProperty* m_propertyGridItem541111;
		wxPGProperty* m_propertyGridItem551111;
		wxPGProperty* m_propertyGridItem561111;
		wxPGProperty* m_propertyGridItem571111;
		wxPGProperty* m_propertyGridItem581111;
		wxPGProperty* m_propertyGridItem434;
		wxPGProperty* m_propertyGridItem601111;
		wxPGProperty* m_propertyGridItem611111;
		wxPGProperty* m_propertyGridItem621111;
		wxPropertyGridPage* m_terrainActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem112;
		wxPGProperty* m_aniActorID_propertyGridItem112;
		wxPGProperty* m_propertyGridItem1492;
		wxPGProperty* m_propertyGridItem46112;
		wxPGProperty* m_propertyGridItem47112;
		wxPGProperty* m_propertyGridItem48112;
		wxPGProperty* m_propertyGridItem49112;
		wxPGProperty* m_propertyGridItem50112;
		wxPGProperty* m_propertyGridItem51112;
		wxPGProperty* m_propertyGridItem52112;
		wxPGProperty* m_propertyGridItem53112;
		wxPGProperty* m_propertyGridItem54112;
		wxPGProperty* m_propertyGridItem55112;
		wxPGProperty* m_propertyGridItem56112;
		wxPGProperty* m_propertyGridItem57112;
		wxPGProperty* m_propertyGridItem58112;
		wxPGProperty* m_propertyGridItem447;
		wxPGProperty* m_propertyGridItem60112;
		wxPGProperty* m_propertyGridItem61112;
		wxPGProperty* m_propertyGridItem62112;
		wxPropertyGridPage* m_waterActorProperties_propertyGridPage;
		wxPGProperty* m_animatedActorPropertiesCat_propertyGridItem113;
		wxPGProperty* m_aniActorID_propertyGridItem113;
		wxPGProperty* m_propertyGridItem1493;
		wxPGProperty* m_propertyGridItem428;
		wxPGProperty* m_propertyGridItem429;
		wxPGProperty* m_propertyGridItem430;
		wxPGProperty* m_propertyGridItem431;
		wxPGProperty* m_propertyGridItem46113;
		wxPGProperty* m_propertyGridItem47113;
		wxPGProperty* m_propertyGridItem48113;
		wxPGProperty* m_propertyGridItem49113;
		wxPGProperty* m_propertyGridItem50113;
		wxPGProperty* m_propertyGridItem51113;
		wxPGProperty* m_propertyGridItem52113;
		wxPGProperty* m_propertyGridItem53113;
		wxPGProperty* m_propertyGridItem54113;
		wxPGProperty* m_propertyGridItem55113;
		wxPGProperty* m_propertyGridItem56113;
		wxPGProperty* m_propertyGridItem57113;
		wxPGProperty* m_propertyGridItem58113;
		wxPGProperty* m_propertyGridItem446;
		wxPGProperty* m_propertyGridItem60113;
		wxPGProperty* m_propertyGridItem61113;
		wxPGProperty* m_propertyGridItem62113;
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
		wxPanel* m_panel392;
		wxStaticText* m_staticText58;
		wxCheckBox* m_toolSettings_showAxisLines_checkBox;
		wxCheckBox* m_toolSettings_showAxisRings_checkBox;
		wxPanel* m_panel403;
		wxStaticText* m_staticText59;
		wxCheckBox* m_cameraSettings_showPosition_checkBox;
		wxCheckBox* m_cameraSettings_showRotation_checkBox;
		wxStaticText* m_staticText60;
		wxSpinCtrlDouble* m_cameraSettings_moveSpeed_spinCtrlDouble;
		wxPanel* m_panel412;
		wxStaticText* m_staticText61;
		wxStaticText* m_staticText62;
		wxColourPickerCtrl* m_viewHUD_color_colourPicker;
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
		wxButton* m_clear_button;
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
		wxButton* m_material_clearTextureLevel_button;
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
		wxToolBar* m_toolBar3;
		wxToolBarToolBase* m_tool33;
		wxToolBarToolBase* m_tool34;
		wxToolBarToolBase* m_tool35;
		wxToolBarToolBase* m_tool36;

		// Virtual event handlers, override them in your derived class
		virtual void OnNewProjectMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadProjectMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMainEditorNotebookPageChanged( wxAuiNotebookEvent& event ) { event.Skip(); }
		virtual void OnS3DSelectClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DBoxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DMoveClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DRotateClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DScaleClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DWizClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnS3DDumpClicked( wxCommandEvent& event ) { event.Skip(); }
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
		virtual void OnStageUpdate( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnProjectPropertiesNotebookChanged( wxAuiNotebookEvent& event ) { event.Skip(); }
		virtual void On_Stage_NewStage( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_DeleteStage( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_NewGroup( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_DeleteGroup( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_EditGroup( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_DeleteActor( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Stage_StageNodeActivated( wxTreeEvent& event ) { event.Skip(); }
		virtual void On_Stage_StageNodeSelected( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnStagePropertyGridChanged( wxPropertyGridEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ShowGrid( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_SetGridSize( wxSpinEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_SetGridSpacing( wxSpinEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_SetGridColor( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ShowAxisLines( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ShowAxisRings( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ShowViewCameraPosition( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ShowViewCameraRotation( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ViewCameraSpeed( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void On_StageSettings_ViewHUDColor( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Load_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Remove_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Save_ButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_MeshList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_MeshID( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_AddMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_RemoveMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_SetMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Mesh_Material_Clear( wxCommandEvent& event ) { event.Skip(); }
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
		virtual void On_Material_ClearTextureLevel_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_AddTexture_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_RemoveTexture_ButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_TextureList_Select( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_TextureID_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_UseColorkey_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void On_Texture_Colorkey_Update( wxColourPickerEvent& event ) { event.Skip(); }


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

		void m_splitter5OnIdle( wxIdleEvent& )
		{
			m_splitter5->SetSashPosition( 291 );
			m_splitter5->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Serenity3D_Frame::m_splitter5OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class SetMeshMaterialLevel_Dialog
///////////////////////////////////////////////////////////////////////////////
class SetMeshMaterialLevel_Dialog : public wxDialog
{
	private:

	protected:
		wxSearchCtrl* m_findMaterial_searchCtrl;
		wxListBox* m_materialList_listBox;
		wxButton* m_setMaterial_button;
		wxButton* m_cancel_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSetMaterial( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		SetMeshMaterialLevel_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Set Material Level"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 513,304 ), long style = wxDEFAULT_DIALOG_STYLE );

		~SetMeshMaterialLevel_Dialog();

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

///////////////////////////////////////////////////////////////////////////////
/// Class AddMesh_Dialog
///////////////////////////////////////////////////////////////////////////////
class AddMesh_Dialog : public wxDialog
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

		AddMesh_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add Meshes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 549,374 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AddMesh_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddArchiveSource_Dialog
///////////////////////////////////////////////////////////////////////////////
class AddArchiveSource_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText49;
		wxListBox* m_listBox12;
		wxStaticText* m_staticText50;
		wxTextCtrl* m_textCtrl19;
		wxButton* m_button72;
		wxButton* m_button73;

	public:

		AddArchiveSource_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Load From Archive"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 498,239 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AddArchiveSource_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class CreateStageGroup_Dialog
///////////////////////////////////////////////////////////////////////////////
class CreateStageGroup_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText54;
		wxComboBox* m_stage_comboBox;
		wxStaticText* m_staticText48;
		wxTextCtrl* m_groupName_textCtrl;
		wxButton* m_button54;
		wxButton* m_button55;

		// Virtual event handlers, override them in your derived class
		virtual void OnCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		CreateStageGroup_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Group"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 476,172 ), long style = wxDEFAULT_DIALOG_STYLE );

		~CreateStageGroup_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DeleteGroupAlert_Dialog
///////////////////////////////////////////////////////////////////////////////
class DeleteGroupAlert_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_deleteGroupName_staticText;
		wxStaticText* m_staticText50;
		wxButton* m_button56;
		wxButton* m_button57;

		// Virtual event handlers, override them in your derived class
		virtual void OnDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		DeleteGroupAlert_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Delete Group"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~DeleteGroupAlert_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class EditStageGroup_Dialog
///////////////////////////////////////////////////////////////////////////////
class EditStageGroup_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText53;
		wxTextCtrl* m_groupLabel_textCtrl;
		wxStaticText* m_stageLabel_staticText;
		wxCheckListBox* m_stageList_checkList;
		wxButton* m_button58;
		wxButton* m_button59;
		wxButton* m_button62;
		wxButton* m_button63;
		wxStaticText* m_groupLabel_staticText;
		wxCheckListBox* m_groupList_checkList;
		wxButton* m_button60;
		wxButton* m_button61;
		wxButton* m_button64;
		wxButton* m_button65;

		// Virtual event handlers, override them in your derived class
		virtual void OnStageSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStageDeselectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGroupSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGroupDeselectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		EditStageGroup_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Edit Group"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 659,488 ), long style = wxDEFAULT_DIALOG_STYLE );

		~EditStageGroup_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewStage_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewStage_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText55;
		wxTextCtrl* m_stageID_textCtrl;
		wxButton* m_button67;
		wxButton* m_button68;

		// Virtual event handlers, override them in your derived class
		virtual void OnCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewStage_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create New Stage"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 440,120 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewStage_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DeleteStageAlert_Dialog
///////////////////////////////////////////////////////////////////////////////
class DeleteStageAlert_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_deleteGroupName_staticText;
		wxStaticText* m_alert_staticText;
		wxButton* m_button56;
		wxButton* m_button57;

		// Virtual event handlers, override them in your derived class
		virtual void OnDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		DeleteStageAlert_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Delete Stage"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~DeleteStageAlert_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DeleteActorAlert_Dialog
///////////////////////////////////////////////////////////////////////////////
class DeleteActorAlert_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_deleteGroupName_staticText;
		wxStaticText* m_alert_staticText;
		wxButton* m_button56;
		wxButton* m_button57;

		// Virtual event handlers, override them in your derived class
		virtual void OnDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		DeleteActorAlert_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Delete Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~DeleteActorAlert_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewAnimatedActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewAnimatedActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText34;
		wxSearchCtrl* m_meshSearch_searchCtrl;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearchText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewAnimatedActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Animated Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 638,346 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewAnimatedActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewOctreeActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewOctreeActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText34;
		wxSearchCtrl* m_meshSearch_searchCtrl;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearchText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewOctreeActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Octree Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 654,346 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewOctreeActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewBillboardActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewBillboardActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText34;
		wxSearchCtrl* m_materialSearch_searchCtrl;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearchText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewBillboardActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Billboard Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 564,346 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewBillboardActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewLightActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewLightActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText85;
		wxComboBox* m_type_comboBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewLightActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Light Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 534,175 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewLightActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewParticleActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewParticleActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText85;
		wxComboBox* m_type_comboBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewParticleActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Particle Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 534,171 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewParticleActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewTerrainActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewTerrainActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText34;
		wxSearchCtrl* m_materialSearch_searchCtrl;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearchText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewTerrainActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Terrain Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 564,346 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewTerrainActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewWaterActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewWaterActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText101;
		wxSpinCtrlDouble* m_waveHeight_spinCtrlDouble;
		wxStaticText* m_staticText1011;
		wxSpinCtrlDouble* m_waveLength_spinCtrlDouble;
		wxStaticText* m_staticText1012;
		wxSpinCtrlDouble* m_waveSpeed_spinCtrlDouble;
		wxStaticText* m_staticText34;
		wxSearchCtrl* m_meshSearch_searchCtrl;
		wxListBox* m_mesh_listBox;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearchText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewWaterActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Water Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 654,502 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewWaterActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewCubeActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewCubeActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText101;
		wxSpinCtrlDouble* m_size_spinCtrlDouble;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewCubeActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Cube Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 382,176 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewCubeActor_Dialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NewSphereActor_Dialog
///////////////////////////////////////////////////////////////////////////////
class NewSphereActor_Dialog : public wxDialog
{
	private:

	protected:
		wxPanel* m_panel38;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_actorID_textCtrl;
		wxStaticText* m_staticText101;
		wxSpinCtrlDouble* m_radius_spinCtrlDouble;
		wxButton* m_cancel_button;
		wxButton* m_create_button;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancelButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreateButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		NewSphereActor_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("New Sphere Actor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 382,177 ), long style = wxDEFAULT_DIALOG_STYLE );

		~NewSphereActor_Dialog();

};

