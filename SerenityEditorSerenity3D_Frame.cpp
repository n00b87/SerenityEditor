#include <wx/stdpaths.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/propgridpagestate.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <irrlicht.h>
#include "wxIrrlicht.h"
#include "SerenityEditorSerenity3D_Frame.h"
#include "CGridSceneNode.h"
#include "engine_base.h"
#include "rc_stage.h"
#include "rc_defines.h"
#include "SerenityEditor_NewProject_Dialog.h"
#include "SerenityEditor_NewOctree_Dialog.h"
#include "SerenityEditor_AddTexture_Dialog.h"
#include "SerenityEditor_SetMaterialTextureLevel_Dialog.h"
#include "SerenityEditor_MaterialPreviewSettings_Dialog.h"
#include "SerenityEditor_SetMaterialPreviewMesh_Dialog.h"
#include "SerenityEditor_AddMaterial_Dialog.h"
#include "SerenityEditor_SetMeshMaterialLevel_Dialog.h"
#include "SerenityEditor_AddMesh_Dialog.h"
#include "SerenityEditor_CreateStageGroup_Dialog.h"
#include "SerenityEditor_DeleteGroupAlert_Dialog.h"
#include "SerenityEditor_EditStageGroup_Dialog.h"
#include "SerenityEditor_NewStage_Dialog.h"
#include "SerenityEditor_DeleteStageAlert_Dialog.h"

SerenityEditorSerenity3D_Frame::SerenityEditorSerenity3D_Frame( wxWindow* parent )
:
Serenity3D_Frame( parent )
{
	m_stagePOV_comboBox->Insert(_("Front"),0);
	m_stagePOV_comboBox->Insert(_("Right"),1);
	m_stagePOV_comboBox->Insert(_("Top"),2);
	m_stagePOV_comboBox->Insert(_("Perspective"),3);
	m_stagePOV_comboBox->Insert(_("All"),4);
	m_stagePOV_comboBox->SetSelection(0);

	stage_tools.push_back(m_s3d_select_tool);
	stage_tools.push_back(m_s3d_boxSelect_tool);
	stage_tools.push_back(m_s3d_move_tool);
	stage_tools.push_back(m_s3d_rotate_tool);
	stage_tools.push_back(m_s3d_scale_tool);

	stage_tools.push_back(m_s3d_plane_tool);
	stage_tools.push_back(m_s3d_cube_tool);
	stage_tools.push_back(m_s3d_sphere_tool);
	//stage_tools.push_back(m_prim3d_cylinder_tool);

	stage_tools.push_back(m_s3d_octreeActor_tool);
	stage_tools.push_back(m_s3d_animatedActor_tool);
	stage_tools.push_back(m_s3d_billboardActor_tool);
	stage_tools.push_back(m_s3d_lightActor_tool);

	stage_tools.push_back(m_s3d_terrainActor_tool);
	stage_tools.push_back(m_s3d_waterActor_tool);
	//stage_tools.push_back(m_geo_grass_tool);

	stage_tools.push_back(m_s3d_path_tool);
	stage_tools.push_back(m_s3d_particleActor_tool);

	asset_dir = wxStandardPaths::Get().GetExecutablePath();
	asset_dir.AppendDir(_("assets"));



	stage_window=new wxIrrlicht(m_stageViewport_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), m_stageViewport_panel->GetClientSize());
	//irrTst->SetBackgroundColour(wxColour("red"));

	stage_window->InitIrr();
	stage_window->StartRendering();

	stage_window->window_type = RC_IRR_WINDOW_NAV3D;
	stage_window->SetViews(RC_CAMERA_VIEW_FRONT);

	irr::IrrlichtDevice* device = stage_window->GetDevice();
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	stage_window->camera[0].camera.setPosition(0, 0, -100);
	stage_window->camera[0].camera.setRotation(0, 0, 0);

	stage_window->camera[1].camera.setPosition(-100, 0, 0);
	stage_window->camera[1].camera.setRotation(0, 90, 0);

	stage_window->camera[2].camera.setPosition(0, 100, 0);
	stage_window->camera[2].camera.setRotation(90, 0, 0);

	stage_window->camera[3].camera.setPosition(0, 30, -40);
	stage_window->camera[3].camera.setRotation(0, 5, 0);

	current_window = stage_window;


	//----------MATERIALS TAB--------------------------

	//MATERIAL TYPES
	rc_addMaterialType("MATERIAL_TYPE_DETAIL_MAP", irr::video::EMT_DETAIL_MAP);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP", irr::video::EMT_LIGHTMAP);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_ADD", irr::video::EMT_LIGHTMAP_ADD);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_LIGHTING", irr::video::EMT_LIGHTMAP_LIGHTING);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_LIGHTING_M2", irr::video::EMT_LIGHTMAP_LIGHTING_M2);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_LIGHTING_M4", irr::video::EMT_LIGHTMAP_LIGHTING_M4);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_M2", irr::video::EMT_LIGHTMAP_M2);
	rc_addMaterialType("MATERIAL_TYPE_LIGHTMAP_M4", irr::video::EMT_LIGHTMAP_M4);
	rc_addMaterialType("MATERIAL_TYPE_NORMAL_MAP_SOLID", irr::video::EMT_NORMAL_MAP_SOLID);
	rc_addMaterialType("MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_ADD_COLOR", irr::video::EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR);
	rc_addMaterialType("MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA", irr::video::EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA);
	rc_addMaterialType("MATERIAL_TYPE_ONETEXTURE_BLEND", irr::video::EMT_ONETEXTURE_BLEND);
	rc_addMaterialType("MATERIAL_TYPE_PARALLAX_MAP_SOLID", irr::video::EMT_PARALLAX_MAP_SOLID);
	rc_addMaterialType("MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_ADD_COLOR", irr::video::EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR);
	rc_addMaterialType("MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA", irr::video::EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA);
	rc_addMaterialType("MATERIAL_TYPE_REFLECTION_2_LAYER", irr::video::EMT_REFLECTION_2_LAYER);
	rc_addMaterialType("MATERIAL_TYPE_SOLID", irr::video::EMT_SOLID);
	rc_addMaterialType("MATERIAL_TYPE_SOLID_2_LAYER", irr::video::EMT_SOLID_2_LAYER);
	rc_addMaterialType("MATERIAL_TYPE_SPHERE_MAP", irr::video::EMT_SPHERE_MAP);
	rc_addMaterialType("MATERIAL_TYPE_TRANSPARENT_ADD_COLOR", irr::video::EMT_TRANSPARENT_ADD_COLOR);
	rc_addMaterialType("MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL", irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	rc_addMaterialType("MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL_REF", irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
	rc_addMaterialType("MATERIAL_TYPE_TRANSPARENT_REFLECTION_2_LAYER", irr::video::EMT_TRANSPARENT_REFLECTION_2_LAYER);
	rc_addMaterialType("MATERIAL_TYPE_TRANSPARENT_VERTEX_ALPHA", irr::video::EMT_TRANSPARENT_VERTEX_ALPHA);

	m_material_type_comboBox->Clear();
	for(int i = 0; i < rc_material_types_list.size(); i++)
	{
		m_material_type_comboBox->Insert(wxString::FromUTF8(rc_material_types_list[i].key.c_str()), i);
	}


	//ANTI ALIAS
	rc_addAntiAliasType("ANTI_ALIAS_ALPHA_TO_COVERAGE", irr::video::EAAM_ALPHA_TO_COVERAGE);
	rc_addAntiAliasType("ANTI_ALIAS_FULL_BASIC", irr::video::EAAM_FULL_BASIC);
	rc_addAntiAliasType("ANTI_ALIAS_LINE_SMOOTH", irr::video::EAAM_LINE_SMOOTH);
	rc_addAntiAliasType("ANTI_ALIAS_OFF", irr::video::EAAM_OFF);
	rc_addAntiAliasType("ANTI_ALIAS_POINT_SMOOTH", irr::video::EAAM_POINT_SMOOTH);
	rc_addAntiAliasType("ANTI_ALIAS_QUALITY", irr::video::EAAM_QUALITY);
	rc_addAntiAliasType("ANTI_ALIAS_SIMPLE", irr::video::EAAM_SIMPLE);

	m_material_antiAlias_comboBox->Clear();
	for(int i = 0; i < rc_anti_alias_types_list.size(); i++)
	{
		m_material_antiAlias_comboBox->Insert(wxString::FromUTF8(rc_anti_alias_types_list[i].key.c_str()), i);
	}


	//BLEND MODE
	rc_addBlendModeType("BLENDMODE_ADD", irr::video::EBO_ADD);
	rc_addBlendModeType("BLENDMODE_MAX", irr::video::EBO_MAX);
	rc_addBlendModeType("BLENDMODE_MAX_ALPHA", irr::video::EBO_MAX_ALPHA);
	rc_addBlendModeType("BLENDMODE_MAX_FACTOR", irr::video::EBO_MAX_FACTOR);
	rc_addBlendModeType("BLENDMODE_MIN", irr::video::EBO_MIN);
	rc_addBlendModeType("BLENDMODE_MIN_ALPHA", irr::video::EBO_MIN_ALPHA);
	rc_addBlendModeType("BLENDMODE_MIN_FACTOR", irr::video::EBO_MIN_FACTOR);
	rc_addBlendModeType("BLENDMODE_NONE", irr::video::EBO_NONE);
	rc_addBlendModeType("BLENDMODE_REVSUBTRACT", irr::video::EBO_REVSUBTRACT);
	rc_addBlendModeType("BLENDMODE_SUBTRACT", irr::video::EBO_SUBTRACT);

	m_material_blendMode_comboBox->Clear();
	for(int i = 0; i < rc_blendmode_types_list.size(); i++)
	{
		m_material_blendMode_comboBox->Insert(wxString::FromUTF8(rc_blendmode_types_list[i].key.c_str()), i);
	}


	//COLOR MASK
	rc_addColorMaskType("COLORMASK_ALL", irr::video::ECP_ALL);
	rc_addColorMaskType("COLORMASK_ALPHA", irr::video::ECP_ALPHA);
	rc_addColorMaskType("COLORMASK_BLUE", irr::video::ECP_BLUE);
	rc_addColorMaskType("COLORMASK_GREEN", irr::video::ECP_GREEN);
	rc_addColorMaskType("COLORMASK_NONE", irr::video::ECP_NONE);
	rc_addColorMaskType("COLORMASK_RED", irr::video::ECP_RED);
	rc_addColorMaskType("COLORMASK_RGB", irr::video::ECP_RGB);

	m_material_colorMask_comboBox->Clear();
	for(int i = 0; i < rc_colormask_types_list.size(); i++)
	{
		m_material_colorMask_comboBox->Insert(wxString::FromUTF8(rc_colormask_types_list[i].key.c_str()), i);
	}

	//COLOR MODE
	rc_addColorModeType("COLOR_MODE_AMBIENT", irr::video::ECM_AMBIENT);
	rc_addColorModeType("COLOR_MODE_DIFFUSE", irr::video::ECM_DIFFUSE);
	rc_addColorModeType("COLOR_MODE_DIFFUSE_AND_AMBIENT", irr::video::ECM_DIFFUSE_AND_AMBIENT);
	rc_addColorModeType("COLOR_MODE_EMISSIVE", irr::video::ECM_EMISSIVE);
	rc_addColorModeType("COLOR_MODE_NONE", irr::video::ECM_NONE);
	rc_addColorModeType("COLOR_MODE_SPECULAR", irr::video::ECM_SPECULAR);

	m_material_colorMode_comboBox->Clear();
	for(int i = 0; i < rc_colormode_types_list.size(); i++)
	{
		m_material_colorMode_comboBox->Insert(wxString::FromUTF8(rc_colormode_types_list[i].key.c_str()), i);
	}

	material_preview_camera_distance = 15;
	material_preview_camera_speed = 0.2;

	meshTab_preview_obj.node = NULL;

	project.setGridColor( irr::video::SColor(255, 70, 70, 70).color );
	project.setGridSize(5000);
	project.setGridSpacing(100);
	project.grid_visible = true;
	project.show_axis_lines = true;
	project.show_axis_rings = true;
	project.show_camera_pos = false;
	project.show_camera_rot = false;
	project.camera_speed = 5;
	project.hud_color = irr::video::SColor(255,255,255,255);

	if(current_window)
	{
		current_window->grid_size = project.grid_size;
		current_window->grid_color = irr::video::SColor(project.grid_color);
		current_window->grid_spacing = project.grid_spacing;
		current_window->grid_visible = project.grid_visible;
		current_window->show_axis_lines = project.show_axis_lines;
		current_window->show_axis_rings = project.show_axis_rings;
		current_window->show_camera_pos = project.show_camera_pos;
		current_window->show_camera_rot = project.show_camera_rot;
		current_window->cam_move_speed = project.camera_speed;
		current_window->hud_color = project.hud_color;
	}

	m_viewportSettings_showGrid_checkBox->SetValue(project.grid_visible);
	m_viewportSettings_gridSize_spinCtrl->SetValue(project.grid_size);
	m_viewportSettings_gridSpacing_spinCtrl->SetValue(project.grid_spacing);
	m_viewportSettings_gridColor_colourPicker->SetColour( wxColour(70, 70, 70, 255) );

	m_toolSettings_showAxisLines_checkBox->SetValue(project.show_axis_lines);
	m_toolSettings_showAxisRings_checkBox->SetValue(project.show_axis_rings);
	m_cameraSettings_showPosition_checkBox->SetValue(project.show_camera_pos);
	m_cameraSettings_showRotation_checkBox->SetValue(project.show_camera_rot);
	m_cameraSettings_moveSpeed_spinCtrlDouble->SetValue(project.camera_speed);
	m_viewHUD_color_colourPicker->SetColour( wxColour(255, 255, 255, 255) );

	editor_path = wxStandardPaths::Get().GetExecutablePath();

	wxFileName image_fname(editor_path);
	image_fname.AppendDir(_("icons"));

	project.project_name = "No Project Loaded";

	stage_tree_imageList = new wxImageList(16,16,true);
    stage_tree_rootImage = stage_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_FOLDER, wxART_MENU ));;
    stage_tree_stageImage  = stage_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_FOLDER, wxART_MENU ));
    stage_tree_assetImage = stage_tree_imageList->Add(wxArtProvider::GetBitmap( wxART_NORMAL_FILE, wxART_MENU ));
	stage_tree_lightImage = stage_tree_assetImage;
	stage_tree_particleImage = stage_tree_assetImage;
	stage_tree_terrainImage = stage_tree_assetImage;
	stage_tree_primitiveImage = stage_tree_assetImage;
	stage_tree_pathImage = stage_tree_assetImage;
	stage_tree_groupImage = stage_tree_stageImage;

    m_project_stage_treeCtrl->AssignImageList(stage_tree_imageList);

	stage_tree_root = m_project_stage_treeCtrl->AddRoot(wxString::FromUTF8(project.project_name), stage_tree_rootImage);
}

bool SerenityEditorSerenity3D_Frame::isValidID(wxString id_name, int id_type, int mesh_index)
{
	if(id_name.compare(_(""))==0)
		return false;

	if(id_name.substr(0, 1).IsNumber())
		return false;

	for(int i = 0; i < id_name.length(); i++)
	{
		wxString id_char = id_name.substr(i,1);

		if(id_char.compare(_(" "))==0 || id_char.compare(_("\t"))==0 || id_char.compare(_("`"))==0 || id_char.compare(_("~"))==0 ||
		   id_char.compare(_("!"))==0 || id_char.compare(_("@"))==0 || id_char.compare(_("#"))==0 || id_char.compare(_("$"))==0 || id_char.compare(_("%"))==0 ||
		   id_char.compare(_("^"))==0 || id_char.compare(_("&"))==0 || id_char.compare(_("*"))==0 || id_char.compare(_("("))==0 || id_char.compare(_(")"))==0 ||
		   id_char.compare(_("-"))==0 || id_char.compare(_("="))==0 || id_char.compare(_("+"))==0 || id_char.compare(_("["))==0 ||
		   id_char.compare(_("]"))==0 || id_char.compare(_("{"))==0 || id_char.compare(_("}"))==0 || id_char.compare(_("|"))==0 || id_char.compare(_("\\"))==0 ||
		   id_char.compare(_(";"))==0 || id_char.compare(_(":"))==0 || id_char.compare(_("'"))==0 || id_char.compare(_("\""))==0 || id_char.compare(_(","))==0 ||
		   id_char.compare(_("<"))==0 || id_char.compare(_(">"))==0 || id_char.compare(_("."))==0 || id_char.compare(_("/"))==0 || id_char.compare(_("?"))==0)
			return false;
	}

	//Need to make sure id_name does not exists already.
	//Since IDs are just variables in a program, id can't match any existing ID in texture, material, mesh, animation, or actor

	id_name = id_name.Lower();
	wxString p_id = _("");
	int id_count = 0;

	if(id_type == RC_ID_TEXTURE)
	{
		//Check textures
		for(int i = 0; i < project.textures.size(); i++)
		{
			p_id = wxString::FromUTF8(project.textures[i].id_name.c_str());
			p_id = p_id.Lower();

			if(p_id.compare(_(""))==0)
				continue;

			if(p_id.compare(id_name) == 0)
			{
				id_count++;

				if(id_count > 1)
					break;
			}
		}

		if(id_count > 1)
		{
			wxMessageBox(_("Texture ID matches existing ID"));
			return false;
		}
	}


	if(id_type == RC_ID_MATERIAL)
	{
		//Check materials
		for(int i = 0; i < project.materials.size(); i++)
		{
			p_id = wxString::FromUTF8(project.materials[i].id_name.c_str());
			p_id = p_id.Lower();

			if(p_id.compare(_(""))==0)
				continue;

			if(p_id.compare(id_name) == 0)
			{
				id_count++;

				if(id_count > 1)
					break;
			}
		}

		if(id_count > 1)
		{
			wxMessageBox(_("Material ID matches existing ID"));
			return false;
		}
	}


	if(id_type == RC_ID_MESH)
	{
		//Check meshes
		for(int i = 0; i < project.meshes.size(); i++)
		{
			p_id = wxString::FromUTF8(project.meshes[i].id_name.c_str());
			p_id = p_id.Lower();

			if(p_id.compare(_(""))==0)
				continue;

			if(p_id.compare(id_name) == 0)
			{
				id_count++;

				if(id_count > 1)
					break;
			}
		}

		if(id_count > 1)
		{
			wxMessageBox(_("Mesh ID matches existing ID"));
			return false;
		}
	}


	if(id_type == RC_ID_ANIMATION)
	{
		//Check animations
		for(int i = 0; i < project.meshes[mesh_index].animation.size(); i++)
		{
			p_id = wxString::FromUTF8(project.meshes[mesh_index].animation[i].id_name.c_str());
			p_id = p_id.Lower();

			if(p_id.compare(_(""))==0)
				continue;

			if(p_id.compare(id_name) == 0)
			{
				id_count++;

				if(id_count > 1)
					break;
			}
		}

		if(id_count > 1)
		{
			wxMessageBox(_("Animation ID matches existing ID"));
			return false;
		}
	}


	if(id_type == RC_ID_STAGE)
	{
		//Check stages
		for(int i = 0; i < project.stages.size(); i++)
		{
			p_id = wxString::FromUTF8(project.stages[i].id_name.c_str());
			p_id = p_id.Lower();

			if(p_id.compare(_(""))==0)
				continue;

			if(p_id.compare(id_name) == 0)
			{
				id_count++;

				if(id_count > 1)
					break;
			}
		}

		if(id_count > 0) //For stages, we don't add them before checking so we are only checking if we found 1
		{
			wxMessageBox(_("Stage ID matches existing ID"));
			return false;
		}
	}


	return true;
}

void SerenityEditorSerenity3D_Frame::createIrrlichtStageWindow()
{
	m_stageViewport_panel->SetFocus();

	stage_window=new wxIrrlicht(m_stageViewport_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
	stage_window->window_type = RC_IRR_WINDOW_NAV3D;

	//wxMessageBox(_("PRE:") + wxString::Format(_("%d"), (int)project.grid_size) + _(", ") + wxString::Format(_("%d"), (int)project.grid_spacing) + _(", ") + wxString::Format(_("%d"), (int)project.grid_visible));

	stage_window->grid_color = project.grid_color;
	stage_window->grid_size = project.grid_size;
	stage_window->grid_spacing = project.grid_spacing;
	stage_window->grid_visible = project.grid_visible;
	stage_window->show_axis_lines = project.show_axis_lines;
	stage_window->show_axis_rings = project.show_axis_rings;
	stage_window->show_camera_pos = project.show_camera_pos;
	stage_window->show_camera_rot = project.show_camera_rot;
	stage_window->cam_move_speed = project.camera_speed;
	stage_window->hud_color = project.hud_color;

	stage_window->InitIrr();
	stage_window->StartRendering();

	irr::IrrlichtDevice* device = stage_window->GetDevice();
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	//wxMessageBox(_("Grid Visible: ") + (stage_window->grid_visible ? _("true") : _("false")));

	stage_window->num_views = current_stage_settings.num_views;

	if(stage_window->num_views == 1)
	{
		switch(current_stage_settings.camera[0].pov)
		{
			case RC_CAMERA_VIEW_FRONT: m_stagePOV_comboBox->SetValue(_("Front")); break;
			case RC_CAMERA_VIEW_RIGHT: m_stagePOV_comboBox->SetValue(_("Right")); break;
			case RC_CAMERA_VIEW_TOP: m_stagePOV_comboBox->SetValue(_("Top")); break;
			case RC_CAMERA_VIEW_PERSPECTIVE: m_stagePOV_comboBox->SetValue(_("Perspective")); break;
		}
	}
	else
	{
		m_stagePOV_comboBox->SetValue(_("All"));
	}

	stage_window->camera[0].pov = current_stage_settings.camera[0].pov;
	stage_window->camera[1].pov = current_stage_settings.camera[1].pov;
	stage_window->camera[2].pov = current_stage_settings.camera[2].pov;
	stage_window->camera[3].pov = current_stage_settings.camera[3].pov;

	stage_window->camera[0].camera.setPosition(current_stage_settings.camera[0].position.x,
											   current_stage_settings.camera[0].position.y,
											   current_stage_settings.camera[0].position.z);

	stage_window->camera[0].camera.setRotation(current_stage_settings.camera[0].rotation.x,
											   current_stage_settings.camera[0].rotation.y,
											   current_stage_settings.camera[0].rotation.z);

	stage_window->camera[1].camera.setPosition(current_stage_settings.camera[1].position.x,
											   current_stage_settings.camera[1].position.y,
											   current_stage_settings.camera[1].position.z);

	stage_window->camera[1].camera.setRotation(current_stage_settings.camera[1].rotation.x,
											   current_stage_settings.camera[1].rotation.y,
											   current_stage_settings.camera[1].rotation.z);

	stage_window->camera[2].camera.setPosition(current_stage_settings.camera[2].position.x,
											   current_stage_settings.camera[2].position.y,
											   current_stage_settings.camera[2].position.z);

	stage_window->camera[2].camera.setRotation(current_stage_settings.camera[2].rotation.x,
											   current_stage_settings.camera[2].rotation.y,
											   current_stage_settings.camera[2].rotation.z);

	stage_window->camera[3].camera.setPosition(current_stage_settings.camera[3].position.x,
											   current_stage_settings.camera[3].position.y,
											   current_stage_settings.camera[3].position.z);

	stage_window->camera[3].camera.setRotation(current_stage_settings.camera[3].rotation.x,
											   current_stage_settings.camera[3].rotation.y,
											   current_stage_settings.camera[3].rotation.z);

	stage_window->SetCameraViewParam();
}

void SerenityEditorSerenity3D_Frame::updatePreviewMesh()
{
	int n = meshTab_selected_mesh_project_index;

	if(!animation_window)
		return;

	irr::IrrlichtDevice* device = animation_window->GetDevice();
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	if(n < 0 || n >= project.meshes.size())
		return;


	if(!project.meshes[n].mesh)
		return;


	//delete scene and make scene node of currently selected mesh
	if(n != meshTab_preview_obj.project_mesh_index)
	{
		if(meshTab_preview_obj.node)
			meshTab_preview_obj.node->remove();
		meshTab_preview_obj.node = NULL;
		meshTab_preview_obj.project_mesh_index = n;

	}

	if(!meshTab_preview_obj.node)
	{
		meshTab_preview_obj.node = smgr->addAnimatedMeshSceneNode(project.meshes[n].mesh);

		if(!meshTab_preview_obj.node)
			return;

		int bb_height = meshTab_preview_obj.node->getBoundingBox().MaxEdge.Y - meshTab_preview_obj.node->getBoundingBox().MinEdge.Y;
		int distance = meshTab_preview_obj.node->getAbsolutePosition().Z - bb_height;
		int cy = meshTab_preview_obj.node->getBoundingBox().MaxEdge.Y + (distance/2);
		current_window->camera[0].camera.setPosition(0, cy, distance);
	}

	//Set Materials
	for(int i = 0; i < project.meshes[n].material_index.size(); i++)
	{
		if(project.meshes[n].material_index[i] >= 0 && project.meshes[n].material_index[i] < project.materials.size())
		{
			int mat_index = project.meshes[n].material_index[i];
			if(project.materials[mat_index].id_name.compare("")!=0)
			{
				meshTab_preview_obj.node->getMaterial(i) = project.materials[mat_index].material;
			}
			else
			{
				meshTab_preview_obj.node->getMaterial(i) = irr::video::SMaterial();
			}
		}
		else
		{
			meshTab_preview_obj.node->getMaterial(i) = irr::video::SMaterial();
		}
	}

	//Set Animation
	if(meshTab_isPlaying && meshTab_preview_obj.animation_change && meshTab_preview_obj.node != NULL)
	{
		if(project.meshes[n].isMD2 && (meshTab_active_animation_index >= 0 && meshTab_active_animation_index < irr::scene::EMAT_COUNT))
		{
			meshTab_preview_obj.node->setMD2Animation(project.meshes[n].animation[meshTab_active_animation_index].md2_animation);
		}
		else if(meshTab_active_animation_index >= 0 && meshTab_active_animation_index < project.meshes[n].animation.size())
		{
			int start_frame = project.meshes[n].animation[meshTab_active_animation_index].start_frame;
			int end_frame = project.meshes[n].animation[meshTab_active_animation_index].end_frame;
			double speed = project.meshes[n].animation[meshTab_active_animation_index].speed;
			meshTab_preview_obj.node->setFrameLoop(start_frame, end_frame);
			meshTab_preview_obj.node->setAnimationSpeed(speed);
			meshTab_preview_obj.animation_change = false;
		}
	}
	else if(meshTab_preview_obj.node != NULL)
	{
		meshTab_preview_obj.node->setFrameLoop(0, 0);
	}
}

void SerenityEditorSerenity3D_Frame::createIrrlichtAnimationWindow()
{
	m_mesh_animationPreview_panel->SetFocus();

    animation_window=new wxIrrlicht(m_mesh_animationPreview_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
		animation_window->window_type = RC_IRR_WINDOW_ANIMATION;
		animation_window->InitIrr();
		animation_window->StartRendering();

		irr::IrrlichtDevice* device = animation_window->GetDevice();
		irr::video::IVideoDriver* driver = device->getVideoDriver();
        irr::scene::ISceneManager* smgr = device->getSceneManager();
        irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

		animation_window->camera[0].camera.setPosition(0, 0, -100);
		animation_window->camera[0].camera.setRotation(0, 0, 0);

		animation_window->SetViews(RC_CAMERA_VIEW_PERSPECTIVE);

		meshTab_preview_obj.node = NULL;
		meshTab_preview_obj.project_mesh_index = -1;
}

void SerenityEditorSerenity3D_Frame::createIrrlichtMaterialWindow()
{
	m_material_materialPreview_panel->SetFocus();

    material_window=new wxIrrlicht(m_material_materialPreview_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
		material_window->window_type = RC_IRR_WINDOW_MATERIAL;
		material_window->InitIrr();
		material_window->StartRendering();

		material_window->material_view_camera_speed = material_preview_camera_speed;

		irr::IrrlichtDevice* device = material_window->GetDevice();
		irr::video::IVideoDriver* driver = device->getVideoDriver();
        irr::scene::ISceneManager* smgr = device->getSceneManager();
        irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

        test_material_mesh = smgr->addCubeSceneNode();

        test_material_light = smgr->addLightSceneNode();
        test_material_light->setPosition(irr::core::vector3df(0, 30, 30));
        test_material_light->setRadius(material_preview_light_radius);

		material_window->camera[0].camera.setPosition(0, 7, -1 * material_preview_camera_distance);
		material_window->camera[0].camera.setRotation(26, 0, 0);

		material_window->SetViews(RC_CAMERA_VIEW_PERSPECTIVE);
}

void SerenityEditorSerenity3D_Frame::createIrrlichtTextureWindow()
{
	m_texture_texturePreview_panel->SetFocus();

    texture_window=new wxIrrlicht(m_texture_texturePreview_panel, wxID_ANY, false, wxPoint(ClientW(0), ClientH(0)), wxGetDisplaySize());
    texture_window->window_type = RC_IRR_WINDOW_VIEW2D;
		texture_window->InitIrr();
		texture_window->StartRendering();

		texture_window->camera[0].camera.setPosition(0, 0, -10);
		texture_window->camera[0].camera.setRotation(0, 0, 0);

		texture_window->SetViews(RC_CAMERA_VIEW_FRONT);
}

void SerenityEditorSerenity3D_Frame::OnProjectPropertiesNotebookChanged( wxAuiNotebookEvent& event )
{
	//wxMessageBox(_("PROJECT PROPETIES HAS CHANGED EVENT"));
	//event.Skip();
}

void SerenityEditorSerenity3D_Frame::OnMainEditorNotebookPageChanged( wxAuiNotebookEvent& event )
{
	//wxMessageBox(_("Changing Main AUI notebook"));

	//Make Sure material ID is valid on current material
	if(materialTab_selected_material_project_index >= 0 && materialTab_selected_material_project_index < project.materials.size())
	{
		if(!isValidID(wxString::FromUTF8(project.materials[materialTab_selected_material_project_index].id_name.c_str()), RC_ID_MATERIAL))
		{
			wxMessageBox(_("Warning: Material ID is invalid. A default Material ID will be generated."));
			project.materials[materialTab_selected_material_project_index].id_name = project.genMaterialID().ToStdString();
		}
	}

	//Make Sure texture ID is valid on current texture
	if(textureTab_selected_texture_project_index >= 0 && textureTab_selected_texture_project_index < project.textures.size())
	{
		if(!isValidID(wxString::FromUTF8(project.textures[textureTab_selected_texture_project_index].id_name.c_str()), RC_ID_TEXTURE))
		{
			wxMessageBox(_("Warning: Texture ID is invalid. A default Texture ID will be generated."));
			project.textures[textureTab_selected_texture_project_index].id_name = project.genTextureID().ToStdString();
		}
	}


	//Make Sure mesh ID is valid on current mesh
	if(meshTab_selected_mesh_project_index >= 0 && meshTab_selected_mesh_project_index < project.meshes.size())
	{
		int n = meshTab_selected_mesh_project_index;

		if(!isValidID(wxString::FromUTF8(project.meshes[n].id_name.c_str()), RC_ID_MESH))
		{
			wxMessageBox(_("Warning: Mesh ID is invalid. A default Mesh ID will be generated."));
			project.meshes[n].id_name = project.genMeshID().ToStdString();
		}

		//Make Sure animation ID is valid on current texture
		if(meshTab_active_animation_index >= 0 && meshTab_active_animation_index < project.meshes[n].animation.size())
		{
			if(!isValidID(wxString::FromUTF8(project.meshes[n].animation[meshTab_active_animation_index].id_name), RC_ID_ANIMATION, n))
			{
				wxMessageBox(_("Warning: Animation ID is invalid. A default Animation ID will be generated."));
				project.meshes[n].animation[meshTab_active_animation_index].id_name = project.genMeshAnimationID(n).ToStdString();
				//wxMessageBox(_("NEW ID: ") + project.meshes[n].animation[meshTab_active_animation_index].id_name);
			}
		}
	}


	if(current_window)
	{
		if(stage_window)
		{
			current_stage_settings.num_views = stage_window->num_views;

			current_stage_settings.camera[0].pov = stage_window->camera[0].pov;
			current_stage_settings.camera[1].pov = stage_window->camera[1].pov;
			current_stage_settings.camera[2].pov = stage_window->camera[2].pov;
			current_stage_settings.camera[3].pov = stage_window->camera[3].pov;

			current_stage_settings.camera[0].position.x = stage_window->camera[0].camera.x;
			current_stage_settings.camera[0].position.y = stage_window->camera[0].camera.y;
			current_stage_settings.camera[0].position.z = stage_window->camera[0].camera.z;

			current_stage_settings.camera[0].rotation.x = stage_window->camera[0].camera.rx;
			current_stage_settings.camera[0].rotation.y = stage_window->camera[0].camera.ry;
			current_stage_settings.camera[0].rotation.z = stage_window->camera[0].camera.rz;

			current_stage_settings.camera[1].position.x = stage_window->camera[1].camera.x;
			current_stage_settings.camera[1].position.y = stage_window->camera[1].camera.y;
			current_stage_settings.camera[1].position.z = stage_window->camera[1].camera.z;

			current_stage_settings.camera[1].rotation.x = stage_window->camera[1].camera.rx;
			current_stage_settings.camera[1].rotation.y = stage_window->camera[1].camera.ry;
			current_stage_settings.camera[1].rotation.z = stage_window->camera[1].camera.rz;

			current_stage_settings.camera[2].position.x = stage_window->camera[2].camera.x;
			current_stage_settings.camera[2].position.y = stage_window->camera[2].camera.y;
			current_stage_settings.camera[2].position.z = stage_window->camera[2].camera.z;

			current_stage_settings.camera[2].rotation.x = stage_window->camera[2].camera.rx;
			current_stage_settings.camera[2].rotation.y = stage_window->camera[2].camera.ry;
			current_stage_settings.camera[2].rotation.z = stage_window->camera[2].camera.rz;

			current_stage_settings.camera[3].position.x = stage_window->camera[3].camera.x;
			current_stage_settings.camera[3].position.y = stage_window->camera[3].camera.y;
			current_stage_settings.camera[3].position.z = stage_window->camera[3].camera.z;

			current_stage_settings.camera[3].rotation.x = stage_window->camera[3].camera.rx;
			current_stage_settings.camera[3].rotation.y = stage_window->camera[3].camera.ry;
			current_stage_settings.camera[3].rotation.z = stage_window->camera[3].camera.rz;
		}
		project.clearProject();

		for(int i = 0; i < project.stages.size(); i++)
			project.stages[i].clearStage();

		current_window->GetDevice()->closeDevice();
		current_window->Close();
		delete current_window;
		current_window = NULL;
	}

	stage_window = NULL;
	animation_window = NULL;
	material_window = NULL;
	texture_window = NULL;

	int page_index = event.GetSelection();

	if(page_index < 0 || page_index >= m_editorMain_auinotebook->GetPageCount())
	{
		wxMessageBox(_("Failed to create render device"));
		return;
	}

	project.grid_size = m_viewportSettings_gridSize_spinCtrl->GetValue();
	project.grid_spacing = m_viewportSettings_gridSpacing_spinCtrl->GetValue();
	project.grid_color = irr::video::SColor(m_viewportSettings_gridColor_colourPicker->GetColour().GetAlpha(),
											m_viewportSettings_gridColor_colourPicker->GetColour().GetRed(),
											m_viewportSettings_gridColor_colourPicker->GetColour().GetGreen(),
											m_viewportSettings_gridColor_colourPicker->GetColour().GetBlue()).color;
	project.grid_visible = m_viewportSettings_showGrid_checkBox->GetValue();

	wxPanel* new_panel = (wxPanel*)m_editorMain_auinotebook->GetPage(page_index);

	if(new_panel == m_stage_panel)
	{
		createIrrlichtStageWindow();
		current_window = stage_window;

		//current_window->setGridSize(project.grid_size);
		//current_window->setGridSpacing(project.grid_spacing);
		//current_window->setGridColor(project.grid_color);
	}
	else if(new_panel == m_meshDB_panel)
	{
		createIrrlichtAnimationWindow();
		current_window = animation_window;

		int list_count = m_mesh_mesh_listBox->GetCount();
		int list_item = m_mesh_mesh_listBox->GetSelection();
		list_item = ( (list_item < 0 || list_item >= list_count) ? 0 : list_item);
		if(list_item < list_count)
			m_mesh_mesh_listBox->SetSelection(list_item);
	}
	else if(new_panel == m_materialDB_panel)
	{
		createIrrlichtMaterialWindow();
		current_window = material_window;
	}
	else if(new_panel == m_textureDB_panel)
	{
		createIrrlichtTextureWindow();
		current_window = texture_window;
	}

	reloadResources();

	current_window->force_refresh();

	if(stageTab_active_stage_project_index >= 0 && stageTab_active_stage_project_index < project.stages.size() && stage_window != NULL)
		open_stage(stageTab_active_stage_project_index);
}

void SerenityEditorSerenity3D_Frame::reloadResources()
{
	if(!current_window)
		return;

	if(!project.project_path.Exists())
		return;

	//project = serenity_project(project.project_path.GetAbsolutePath().ToStdString(), "", current_window->GetDevice());
	project.device = current_window->GetDevice();
	project.reload_assets();

	current_window->view2D_texture = NULL;

	//wxMessageBox(_("RELOAD COMPLETE"));

	m_material_material_listBox->Clear();
	m_mesh_mesh_listBox->Clear();
	m_texture_textureList_listBox->Clear();
	m_material_textureLevel_listBox->Clear();

	//populate materials from project
	for(int i = 0; i < project.materials.size(); i++)
	{
		if(project.materials[i].id_name.compare(_(""))!=0)
			m_material_material_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.materials[i].id_name.c_str()));
	}

	//populate mesh from project
	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare(_(""))!=0)
			m_mesh_mesh_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.meshes[i].id_name.c_str()));
	}

	//populate textures from project
	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare(_(""))!=0)
			m_texture_textureList_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.textures[i].id_name.c_str()));
	}
}

void SerenityEditorSerenity3D_Frame::OnPlayClicked( wxCommandEvent& event )
{
}

void SerenityEditorSerenity3D_Frame::OnStopClicked( wxCommandEvent& event )
{

}


//--------------PROJECT STAGE SETTINGS-------------------------------
void SerenityEditorSerenity3D_Frame::On_Stage_NewStage( wxCommandEvent& event )
{
	if(project.project_name.compare("")==0)
		return;

	SerenityEditor_NewStage_Dialog* dialog = new SerenityEditor_NewStage_Dialog(this);

	dialog->ShowModal();

	if(!dialog->create_flag)
		return;

	wxString stage_id = dialog->stage_id.Trim();
	if(!isValidID(stage_id, RC_ID_STAGE))
	{
		wxMessageBox(_("Warning: Stage ID is invalid. A default Stage ID will be generated."));
		stage_id = project.genStageID();
	}

	rc_stage new_stage;
	new_stage.id_name = stage_id.ToStdString();
	new_stage.idIsActive = true;
	new_stage.file = stage_id.ToStdString() + ".snst";
	int project_index = project.stages.size();
	project.stages.push_back(new_stage);

	Serenity_StageNode tree_node;
	tree_node.active = false;
	tree_node.project_index = project_index;
	tree_node.node_type = RC_STAGE_NODE_STAGE;
	tree_node.stage_group = 0;
	tree_node.group_label = stage_id;
	tree_node.parent_item = stage_tree_root;
	tree_node.tree_item = m_project_stage_treeCtrl->AppendItem(stage_tree_root, stage_id, stage_tree_stageImage);

	int stage_index = stage_tree_nodes.size();
	stage_tree_nodes.push_back(tree_node);

}

void SerenityEditorSerenity3D_Frame::On_Stage_DeleteStage( wxCommandEvent& event )
{
	wxTreeItemId selection = m_project_stage_treeCtrl->GetSelection();

	int stage_node_index = -1;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		if(stage_tree_nodes[i].tree_item == selection)
		{
			stage_node_index = i;
			break;
		}
	}

	if(stage_node_index < 0)
	{
		wxMessageBox(_("Can't delete stage. A stage has not been selected"));
		return;
	}

	wxString stage_id = _("");
	int stage_project_index = stage_tree_nodes[stage_node_index].project_index;

	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	stage_id = wxString::FromUTF8(project.stages[stage_project_index].id_name);

	if(stage_id.compare(_(""))==0)
		return;

	SerenityEditor_DeleteStageAlert_Dialog* dialog = new SerenityEditor_DeleteStageAlert_Dialog(this);

	dialog->setStageID(stage_id);

	dialog->ShowModal();

	if(dialog->delete_flag)
	{
		if(stageTab_active_stage_project_index == stage_project_index)
		{
			project.stages[stage_project_index].clearStage();
			stageTab_active_stage_project_index = -1;
		}

		stage_tree_nodes[stage_node_index].project_index = -1;
		m_project_stage_treeCtrl->Delete(stage_tree_nodes[stage_node_index].tree_item);
		stage_tree_nodes[stage_node_index].node_type = RC_STAGE_NODE_NONE;

		stage_tree_nodes[stage_node_index].groups.clear();
		stage_tree_nodes[stage_node_index].actors.clear();

		project.stages[stage_project_index].idIsActive = false;
		project.stages[stage_project_index].id_name = "";

		project.stages[stage_project_index].actors.clear();
	}
}

void SerenityEditorSerenity3D_Frame::On_Stage_NewGroup( wxCommandEvent& event )
{
	if(stageTab_active_stage_project_index < 0 && stageTab_active_stage_project_index < project.stages.size())
	{
		return;
	}

	SerenityEditor_CreateStageGroup_Dialog* dialog = new SerenityEditor_CreateStageGroup_Dialog(this);

	for(int i = 0; i < project.stages.size(); i++)
	{
		if(project.stages[i].id_name.compare("") != 0)
		{
			dialog->stages.push_back(wxString::FromUTF8(project.stages[i].id_name).Trim());
		}
	}

	wxString selected_stage = _("");

	wxTreeItemId selection = m_project_stage_treeCtrl->GetSelection();

	int selected_stage_node_index = -1;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		int stage_index = stage_tree_nodes[i].project_index;

		if(stage_tree_nodes[i].tree_item == selection)
		{
			if(stage_index >= 0 && stage_index < project.stages.size())
			{
				selected_stage = wxString::FromUTF8(project.stages[stage_index].id_name);
				selected_stage_node_index = i;
				break;
			}
		}

		bool node_found = false;

		for(int n = 0; n < stage_tree_nodes[i].actors.size(); n++)
		{
			if(stage_tree_nodes[i].actors[n].tree_item == selection)
			{
				node_found = true;
				selected_stage = wxString::FromUTF8(project.stages[stage_index].id_name);
				break;
			}
		}

		if(!node_found)
		{
			for(int n = 0; n < stage_tree_nodes[i].groups.size(); n++)
			{
				if(stage_tree_nodes[i].groups[n].tree_item == selection)
				{
					node_found = true;
					selected_stage = wxString::FromUTF8(project.stages[stage_index].id_name);
					break;
				}
			}
		}

		if(node_found)
		{
			selected_stage_node_index = i;
			break;
		}
	}

	if(selected_stage_node_index < 0)
		return;

	dialog->selected_stage = selected_stage;

	dialog->refresh_list();

	dialog->ShowModal();



	selected_stage = dialog->selected_stage;

	selection = m_project_stage_treeCtrl->GetSelection();

	selected_stage_node_index = -1;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		int project_index = stage_tree_nodes[i].project_index;

		if(project_index >= 0 && project_index < project.stages.size())
		{
			if(project.stages[project_index].id_name.compare(selected_stage.ToStdString())==0)
			{
				selected_stage_node_index = i;
				selection = stage_tree_nodes[i].tree_item;
				break;
			}
		}
	}

	if(dialog->set_flag && (selected_stage_node_index < 0))
	{
		wxMessageBox(_("Create Group Error: No stage was selected for group"));
		return;
	}

	if(dialog->set_flag)
	{
		wxString group_name = dialog->group_name;

		if(group_name.Trim().compare(_(""))==0)
		{
			wxMessageBox(_("Group must have a label"));
			return;
		}

		rc_group new_group;
		new_group.label = group_name.Trim().ToStdString();

		int stage_project_index = stage_tree_nodes[selected_stage_node_index].project_index;

		if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		{
			wxMessageBox(_("Create Group Error: Stage Id not found"));
			return;
		}

		for(int i = 0; i < project.stages[stage_project_index].groups.size(); i++)
		{
			if(project.stages[stage_project_index].groups[i].label.compare(new_group.label)==0)
			{
				wxMessageBox(_("Group label already exists. A default group label will be generated"));
				new_group.label = project.genGroupLabel(stage_project_index);
			}
		}

		int stage_group_index = project.stages[stage_project_index].groups.size();

		project.stages[stage_project_index].groups.push_back(new_group);

		if(stage_tree_nodes[selected_stage_node_index].node_type == RC_STAGE_NODE_STAGE)
		{
			Serenity_StageNode group_node;
			group_node.group_label = wxString::FromUTF8(new_group.label);
			group_node.active = false;
			group_node.actors.clear();
			group_node.groups.clear();
			group_node.node_type = RC_STAGE_NODE_GROUP;
			group_node.parent_item = stage_tree_nodes[selected_stage_node_index].tree_item;
			group_node.project_index = -1;
			group_node.stage_group = stage_group_index;
			group_node.tree_item = m_project_stage_treeCtrl->AppendItem(group_node.parent_item, group_node.group_label, stage_tree_groupImage);
			stage_tree_nodes[selected_stage_node_index].groups.push_back(group_node);
		}

	}
}

bool SerenityEditorSerenity3D_Frame::delete_actor(int stage_index, int actor_stage_index)
{
	if(stage_index < 0 || stage_index >= project.stages.size())
		return false;

	if(actor_stage_index < 0 || actor_stage_index >= project.stages[stage_index].actors.size())
		return false;

	if(project.stages[stage_index].actors[actor_stage_index].node)
		project.stages[stage_index].actors[actor_stage_index].node->remove();

	project.stages[stage_index].actors[actor_stage_index].node = NULL;
	project.stages[stage_index].actors[actor_stage_index].id_name = _("");
	project.stages[stage_index].actors[actor_stage_index].group_name = _("");
	project.stages[stage_index].actors[actor_stage_index].mesh_index = -1;
	project.stages[stage_index].actors[actor_stage_index].type = -1;

	if(stage_index == stageTab_active_stage_project_index && stage_window != NULL)
	{
		stage_window->selected_actors.clear();
		for(int i = 0; i < stage_window->scene_actors.size(); i++)
		{
			if(stage_window->scene_actors[i].actor_index == actor_stage_index)
			{
				stage_window->scene_actors.erase(i);
				break;
			}
		}
	}

	return true;
}

void SerenityEditorSerenity3D_Frame::On_Stage_DeleteGroup( wxCommandEvent& event )
{
	SerenityEditor_DeleteGroupAlert_Dialog* dialog = new SerenityEditor_DeleteGroupAlert_Dialog(this);

	wxTreeItemId selection = m_project_stage_treeCtrl->GetSelection();

	int stage_node_index = -1;
	int group_node_index = -1;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		for(int group_index = 0; group_index < stage_tree_nodes[i].groups.size(); group_index++)
		{
			if(stage_tree_nodes[i].groups[group_index].tree_item == selection)
			{
				stage_node_index = i;
				group_node_index = group_index;
				break;
			}
		}

		if(group_node_index >= 0)
			break;
	}

	if(group_node_index < 0)
	{
		wxMessageBox(_("Can't delete group. A group has not been selected"));
		return;
	}

	if(stage_tree_nodes[stage_node_index].groups[group_node_index].node_type == RC_STAGE_NODE_NONE)
		return;

	dialog->setGroupName(stage_tree_nodes[stage_node_index].groups[group_node_index].group_label);

	dialog->ShowModal();

	if(!dialog->deleteFlag)
		return;

	//delete all actors in the selected group
	wxTreeItemId group_item = stage_tree_nodes[stage_node_index].groups[group_node_index].tree_item;

	for(int i = 0; i < stage_tree_nodes[stage_node_index].actors.size(); i++)
	{
		if(stage_tree_nodes[stage_node_index].actors[i].parent_item == group_item)
		{
			delete_actor(stage_tree_nodes[stage_node_index].project_index, stage_tree_nodes[stage_node_index].actors[i].project_index);
			m_project_stage_treeCtrl->Delete(stage_tree_nodes[stage_node_index].actors[i].tree_item);
			stage_tree_nodes[stage_node_index].actors[i].node_type = RC_STAGE_NODE_NONE;
		}
	}

	int stage_p_index = stage_tree_nodes[stage_node_index].project_index;
	if(stage_p_index >= 0 && stage_p_index < project.stages.size())
	{
		for(int i = 0; i < project.stages[ stage_p_index ].groups.size(); i++)
		{
			if(project.stages[ stage_p_index ].groups[i].label.compare(stage_tree_nodes[stage_node_index].groups[group_node_index].group_label.ToStdString())==0)
			{
				project.stages[ stage_p_index ].groups[i].label = "";
				break;
			}
		}
	}

	m_project_stage_treeCtrl->Delete(group_item);
	stage_tree_nodes[stage_node_index].groups[group_node_index].group_label = _("");
	stage_tree_nodes[stage_node_index].groups[group_node_index].node_type = RC_STAGE_NODE_NONE;
}

void SerenityEditorSerenity3D_Frame::On_Stage_EditGroup( wxCommandEvent& event )
{
	SerenityEditor_EditStageGroup_Dialog* dialog = new SerenityEditor_EditStageGroup_Dialog(this);


	wxTreeItemId selection = m_project_stage_treeCtrl->GetSelection();

	int stage_node_index = -1;
	int group_node_index = -1;


	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		for(int group_index = 0; group_index < stage_tree_nodes[i].groups.size(); group_index++)
		{
			if(stage_tree_nodes[i].groups[group_index].tree_item == selection)
			{
				stage_node_index = i;
				group_node_index = group_index;
				break;
			}
		}

		if(group_node_index >= 0)
			break;
	}

	if(group_node_index < 0)
	{
		wxMessageBox(_("Can't edit group. A group has not been selected"));
		return;
	}

	if(stage_tree_nodes[stage_node_index].groups[group_node_index].node_type != RC_STAGE_NODE_GROUP)
		return;

	wxTreeItemId group_item = stage_tree_nodes[stage_node_index].groups[group_node_index].tree_item;

	int p_stage_index = stage_tree_nodes[stage_node_index].project_index;

	if(p_stage_index < 0 || p_stage_index >= project.stages.size())
		return;

	//Add actors to src and dst
	for(int i = 0; i < stage_tree_nodes[stage_node_index].actors.size(); i++)
	{
		if(stage_tree_nodes[stage_node_index].actors[i].node_type == RC_STAGE_NODE_ACTOR) //will be set to RC_STAGE_NODE_NONE when yeeted
		{
			if(stage_tree_nodes[stage_node_index].actors[i].parent_item == group_item)
			{
				int actor_stage_index = stage_tree_nodes[stage_node_index].actors[i].project_index;

				if(actor_stage_index >= 0 && actor_stage_index < project.stages[p_stage_index].actors.size())
				{
					if(project.stages[p_stage_index].actors[actor_stage_index].id_name.compare("") != 0)
					{
						dialog->dst_actors.push_back(wxString::FromUTF8(project.stages[p_stage_index].actors[actor_stage_index].id_name));
					}
				}
			}
			else
			{
				int actor_stage_index = stage_tree_nodes[stage_node_index].actors[i].project_index;

				if(actor_stage_index >= 0 && actor_stage_index < project.stages[p_stage_index].actors.size())
				{
					if(project.stages[p_stage_index].actors[actor_stage_index].id_name.compare("") != 0)
					{
						dialog->src_actors.push_back(wxString::FromUTF8(project.stages[p_stage_index].actors[actor_stage_index].id_name));
					}
				}
			}
		}
	}

	if(stage_tree_nodes[stage_node_index].groups[group_node_index].group_label.Trim().compare(_(""))==0)
		return;

	dialog->group_name = stage_tree_nodes[stage_node_index].groups[group_node_index].group_label;

	dialog->refresh_groupName();
	dialog->refresh_list();

	dialog->ShowModal();

	if(!dialog->applyFlag)
		return;

	stage_tree_nodes[stage_node_index].groups[group_node_index].group_label = dialog->group_name;
	m_project_stage_treeCtrl->SetItemText(group_item, dialog->group_name);

	for(int i = 0; i < dialog->dst_actors.size(); i++)
	{
		wxString new_actor_id = dialog->dst_actors.Item(i);
		for(int actor_node_index = 0; actor_node_index < stage_tree_nodes[stage_node_index].actors.size(); actor_node_index++)
		{
			if(stage_tree_nodes[stage_node_index].actors[actor_node_index].parent_item == group_item) //already in group
				continue;

			int actor_project_index = stage_tree_nodes[stage_node_index].actors[actor_node_index].project_index;

			if(actor_project_index < 0 || actor_project_index >= project.stages[p_stage_index].actors.size())
				continue;

			if(project.stages[p_stage_index].actors[actor_project_index].id_name.compare(new_actor_id.ToStdString())==0)
			{
				m_project_stage_treeCtrl->Delete(stage_tree_nodes[stage_node_index].actors[actor_node_index].tree_item);
				stage_tree_nodes[stage_node_index].actors[actor_node_index].tree_item = m_project_stage_treeCtrl->AppendItem(group_item, new_actor_id, stage_tree_assetImage);
				stage_tree_nodes[stage_node_index].actors[actor_node_index].parent_item = group_item;
				project.stages[p_stage_index].actors[actor_project_index].group_name = stage_tree_nodes[stage_node_index].groups[group_node_index].group_label.ToStdString();
				break;
			}
		}
	}

	wxTreeItemId stage_item = stage_tree_nodes[stage_node_index].tree_item;

	for(int i = 0; i < dialog->src_actors.size(); i++)
	{
		wxString src_actor_id = dialog->src_actors.Item(i);
		for(int actor_node_index = 0; actor_node_index < stage_tree_nodes[stage_node_index].actors.size(); actor_node_index++)
		{
			if(stage_tree_nodes[stage_node_index].actors[actor_node_index].parent_item != group_item) //only want to continue if actor is currently in group but needs to be removed
				continue;

			//If it gets here, then actor is in group. If it matches the src_actor_id then it needs to be removed from group and added back to stage

			int actor_project_index = stage_tree_nodes[stage_node_index].actors[actor_node_index].project_index;

			if(actor_project_index < 0 || actor_project_index >= project.stages[p_stage_index].actors.size())
				continue;

			if(project.stages[p_stage_index].actors[actor_project_index].id_name.compare(src_actor_id.ToStdString())==0)
			{
				m_project_stage_treeCtrl->Delete(stage_tree_nodes[stage_node_index].actors[actor_node_index].tree_item);
				stage_tree_nodes[stage_node_index].actors[actor_node_index].tree_item = m_project_stage_treeCtrl->AppendItem(stage_item, src_actor_id, stage_tree_assetImage);
				stage_tree_nodes[stage_node_index].actors[actor_node_index].parent_item = stage_item;
				project.stages[p_stage_index].actors[actor_project_index].group_name = "";
				break;
			}
		}
	}
}

int SerenityEditorSerenity3D_Frame::getCurrentStageNodeIndex()
{
	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		if(stage_tree_nodes[i].project_index == stageTab_active_stage_project_index)
			return i;
	}
	return -1;
}

int SerenityEditorSerenity3D_Frame::getActorNodeIndex(int stage_node_index, int actor_project_index)
{
	for(int i = 0; i < stage_tree_nodes[stage_node_index].actors.size(); i++)
	{
		if(stage_tree_nodes[stage_node_index].actors[i].project_index == actor_project_index)
			return i;
	}
	return -1;
}

void SerenityEditorSerenity3D_Frame::updateProjectFromStageEdit()
{
	int stage_project_index = stageTab_active_stage_project_index;

	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	//project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_ANIMATED
	for(int i = 0; i < stage_window->selected_actors.size(); i++)
	{
		int actor_project_index = stage_window->selected_actors[i].actor_index;

		if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
			continue;

		irr::scene::ISceneNode* scene_node = project.stages[stage_project_index].actors[actor_project_index].node;

		if(!scene_node)
			continue;

		project.stages[stage_project_index].actors[actor_project_index].position = scene_node->getAbsolutePosition();
		//project.stages[stage_project_index].actors[actor_project_index].rotation = stage_window->selected_actors[i].rotation; //This is now a pointer
		project.stages[stage_project_index].actors[actor_project_index].scale = scene_node->getScale();

		//stage_window->scene_actors[i].id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;
	}
}

void SerenityEditorSerenity3D_Frame::OnStageUpdate( wxUpdateUIEvent& event )
{
	if(stage_window)
	{
		if(stage_window->selected_actors.size() >= 1)
		{

			selected_actor_in_active_stage = stage_window->selected_actors[0].actor_index;

			int stage_node_index = getCurrentStageNodeIndex();
			if(stage_node_index < 0)
				return;

			if(selected_actor_in_active_stage < 0)
				return;

			int actor_node_index = getActorNodeIndex(stage_node_index, selected_actor_in_active_stage);

			if(actor_node_index < 0)
				return;

			if(stage_tree_nodes[stage_node_index].actors[actor_node_index].project_index < 0)
				return;

			m_project_stage_treeCtrl->SelectItem(stage_tree_nodes[stage_node_index].actors[actor_node_index].tree_item);


			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;

			int actor_stage_index = stage_window->selected_actors[0].actor_index;

			if(actor_stage_index < 0 || actor_stage_index >= project.stages[stage_project_index].actors.size())
				return;

			if(!project.stages[stage_project_index].actors[actor_stage_index].node)
				return;

			updateProjectFromStageEdit();

			if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_ANIMATED)
			{
				m_stage_propertyGridManager->SelectPage(m_animatedActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_OCTREE)
			{
				m_stage_propertyGridManager->SelectPage(m_octreeActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_LIGHT)
			{
				m_stage_propertyGridManager->SelectPage(m_lightActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_BILLBOARD)
			{
				m_stage_propertyGridManager->SelectPage(m_billboardActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_TERRAIN)
			{
				m_stage_propertyGridManager->SelectPage(m_terrainActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_WATER)
			{
				m_stage_propertyGridManager->SelectPage(m_waterActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_PARTICLE)
			{
				m_stage_propertyGridManager->SelectPage(m_particleActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_CUBE)
			{
				m_stage_propertyGridManager->SelectPage(m_cubeActorProperties_propertyGridPage);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_SPHERE)
			{
				m_stage_propertyGridManager->SelectPage(m_sphereActorProperties_propertyGridPage);
			}
			else
				return;

			int selected_page_index = m_stage_propertyGridManager->GetSelectedPage();
			wxPropertyGridPage* page = m_stage_propertyGridManager->GetPage(selected_page_index);

			if(stage_window->stage_window_isActive)
			{
				//-------------Setting Position---------------------------
				irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_stage_index].position;
				page->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
				page->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
				page->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

				//-------------Setting Rotation---------------------------
				irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_stage_index].rotation;
				page->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
				page->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
				page->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

				//-------------Setting Scale---------------------------
				irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_stage_index].scale;
				page->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
				page->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
				page->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);
			}

		}
	}
}

void SerenityEditorSerenity3D_Frame::open_stage(int stage_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	int old_index = stageTab_active_stage_project_index;
	stageTab_active_stage_project_index = -1;


	if(!current_window)
		return;


	for(int i = 0; i < project.stages.size(); i++)
		project.stages[i].clearStage();

	irr::scene::ISceneManager* smgr = current_window->GetDevice()->getSceneManager();

	wxFileName icon_path(editor_path);
	icon_path.AppendDir(_("icons"));

	wxFileName light_icon_fname = icon_path;
	light_icon_fname.SetFullName(_("lamp.png"));

	//wxMessageBox(_("LGP: ") + light_icon_fname.GetAbsolutePath());

	project.stages[stage_project_index].light_icon = current_window->GetDevice()->getVideoDriver()->getTexture(light_icon_fname.GetAbsolutePath().ToStdString().c_str());

	if(project.stages[stage_project_index].light_icon)
		current_window->GetDevice()->getVideoDriver()->makeColorKeyTexture(project.stages[stage_project_index].light_icon, irr::video::SColor(0));

	stageTab_active_stage_project_index = stage_project_index;

	current_window->scene_actors.clear();
	current_window->selected_actors.clear();

	for(int i = 0; i < project.stages[stage_project_index].actors.size(); i++)
	{
		project.stages[stage_project_index].actors[i].node = NULL;
		project.stages[stage_project_index].actors[i].icon_node = NULL;
		refresh_actor(i);
	}
}

void SerenityEditorSerenity3D_Frame::refresh_actor(int actor_project_index)
{
	if(!current_window)
		return;

	int stage_project_index = stageTab_active_stage_project_index;
	int i = actor_project_index;

	irr::scene::ISceneManager* smgr = current_window->GetDevice()->getSceneManager();

	switch(project.stages[stage_project_index].actors[i].type)
	{
		case SN_ACTOR_TYPE_ANIMATED:
		{
			int mesh_index = project.stages[stage_project_index].actors[i].mesh_index;

			if(!project.stages[stage_project_index].actors[i].node)
			{
				irr::scene::IAnimatedMesh* mesh = NULL;

				if(mesh_index >= 0 && mesh_index < project.meshes.size())
					mesh = project.meshes[mesh_index].mesh;

				if(mesh)
				{
					project.stages[stage_project_index].actors[i].node = smgr->addAnimatedMeshSceneNode(mesh);
				}
			}


			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less


				//Set starting animation
				int animation_index = project.stages[stage_project_index].actors[i].animation_index;
				if(animation_index < 0 || animation_index >= project.meshes[mesh_index].animation.size())
				{
					node->setFrameLoop(0, 0);
				}
				else if(project.meshes[mesh_index].isMD2)
				{
					node->setMD2Animation(project.meshes[mesh_index].animation[animation_index].md2_animation);
					node->setAnimationSpeed(project.meshes[mesh_index].animation[animation_index].speed);
				}
				else
				{
					node->setFrameLoop(project.meshes[mesh_index].animation[animation_index].start_frame, project.meshes[mesh_index].animation[animation_index].end_frame);
					node->setAnimationSpeed(project.meshes[mesh_index].animation[animation_index].speed);
				}


				//-----APPLY MATERIAL-----------
				for(int i = 0; i < project.meshes[mesh_index].material_index.size(); i++)
				{
					if(project.meshes[mesh_index].material_index[i] >= 0 && project.meshes[mesh_index].material_index[i] < project.materials.size())
					{
						int mat_index = project.meshes[mesh_index].material_index[i];
						if(project.materials[mat_index].id_name.compare("") != 0)
							node->getMaterial(i) = project.materials[mat_index].material;
						else
							node->getMaterial(i) = irr::video::SMaterial();
					}
				}

			}
		}
		break;


		case SN_ACTOR_TYPE_BILLBOARD:
		{
			if(!project.stages[stage_project_index].actors[i].node)
				project.stages[stage_project_index].actors[i].node = smgr->addBillboardSceneNode();


			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::IBillboardSceneNode* node = (irr::scene::IBillboardSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						node->getMaterial(0) = project.materials[mat_index].material;
				}
			}
		}
		break;


		case SN_ACTOR_TYPE_CUBE:
		{
			double cube_size = project.stages[stage_project_index].actors[i].cube_size;

			if(!project.stages[stage_project_index].actors[i].node)
				project.stages[stage_project_index].actors[i].node = smgr->addCubeSceneNode(cube_size);


			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

				//-----APPLY MATERIAL-----------
				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						node->getMaterial(0) = project.materials[mat_index].material;
				}
			}
		}
		break;


		case SN_ACTOR_TYPE_LIGHT:
		{
			if(!project.stages[stage_project_index].actors[i].node)
				project.stages[stage_project_index].actors[i].node = smgr->addLightSceneNode();

			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less
				if(!project.stages[stage_project_index].actors[i].icon_node)
					project.stages[stage_project_index].actors[i].icon_node = smgr->addBillboardSceneNode(0, irr::core::dimension2df(10, 10));
				irr::scene::IBillboardSceneNode* icon_node = (irr::scene::IBillboardSceneNode*)project.stages[stage_project_index].actors[i].icon_node;

				if(project.stages[stage_project_index].light_icon)
				{
					//icon_node->setMaterialTexture(0, project.stages[stage_project_index].light_icon);
					//icon_node->setMaterialTexture(1, project.stages[stage_project_index].light_icon);
					icon_node->getMaterial(0).MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
					icon_node->getMaterial(0).Lighting = false;
					icon_node->getMaterial(0).ZWriteEnable = irr::video::EZW_OFF;
					icon_node->getMaterial(0).ZBuffer = false;
					icon_node->getMaterial(0).BackfaceCulling = false;
					icon_node->getMaterial(0).TextureLayer[0].Texture = project.stages[stage_project_index].light_icon;
					//icon_node->getMaterial(0).TextureLayer[0].BilinearFilter = rc_bilinear_filter; //TODO: Add option to switch this on/off
					icon_node->getMaterial(0).BlendOperation = irr::video::EBO_ADD;
					icon_node->getMaterial(0).MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
				}

				//-----APPLY MATERIAL-----------
				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						node->getMaterial(0) = project.materials[mat_index].material;
				}

				icon_node->setPosition(node->getPosition());

			}
		}
		break;


		case SN_ACTOR_TYPE_OCTREE:
		{
			int mesh_index = project.stages[stage_project_index].actors[i].mesh_index;

			irr::scene::IAnimatedMesh* mesh = NULL;

			if(mesh_index >= 0 && mesh_index < project.meshes.size())
				mesh = project.meshes[mesh_index].mesh;

			if(!project.stages[stage_project_index].actors[i].node)
			{
				if(mesh)
				{
					project.stages[stage_project_index].actors[i].node = smgr->addOctreeSceneNode(mesh);
				}
			}


			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

				//-----APPLY MATERIAL-----------
				for(int i = 0; i < project.meshes[mesh_index].material_index.size(); i++)
				{
					if(project.meshes[mesh_index].material_index[i] >= 0 && project.meshes[mesh_index].material_index[i] < project.materials.size())
					{
						int mat_index = project.meshes[mesh_index].material_index[i];
						if(project.materials[mat_index].id_name.compare("") != 0)
							node->getMaterial(i) = project.materials[mat_index].material;
						else
							node->getMaterial(i) = irr::video::SMaterial();
					}
				}

			}
		}
		break;


		case SN_ACTOR_TYPE_PARTICLE:
		{
			if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_BOX)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();
				irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

				if(!project.stages[stage_project_index].actors[i].particle_emitter)
				{
					irr::scene::IParticleBoxEmitter* p_box_emitter = p_node->createBoxEmitter(project.stages[stage_project_index].actors[i].box,
																							  project.stages[stage_project_index].actors[i].direction,
																							  project.stages[stage_project_index].actors[i].min_per_sec,
																							  project.stages[stage_project_index].actors[i].max_per_sec,
																							  project.stages[stage_project_index].actors[i].min_start_color,
																							  project.stages[stage_project_index].actors[i].max_start_color,
																							  project.stages[stage_project_index].actors[i].min_life,
																							  project.stages[stage_project_index].actors[i].max_life,
																							  project.stages[stage_project_index].actors[i].angle,
																							  irr::core::dimension2df(project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height),
																							  irr::core::dimension2df(project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height));
					project.stages[stage_project_index].actors[i].particle_emitter = p_box_emitter;
				}
			}
			else if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_CYLINDER)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();

				irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

				if(!project.stages[stage_project_index].actors[i].particle_emitter)
				{
					irr::scene::IParticleCylinderEmitter* p_cylinder_emitter = p_node->createCylinderEmitter(project.stages[stage_project_index].actors[i].center,
																								   project.stages[stage_project_index].actors[i].radius,
																								   project.stages[stage_project_index].actors[i].normal,
																								   project.stages[stage_project_index].actors[i].cylinder_length,
																								   project.stages[stage_project_index].actors[i].use_outline_only,
																								   project.stages[stage_project_index].actors[i].direction,
																								   project.stages[stage_project_index].actors[i].min_per_sec,
																								   project.stages[stage_project_index].actors[i].max_per_sec,
																								   project.stages[stage_project_index].actors[i].min_start_color,
																								   project.stages[stage_project_index].actors[i].max_start_color,
																								   project.stages[stage_project_index].actors[i].min_life,
																								   project.stages[stage_project_index].actors[i].max_life,
																								   project.stages[stage_project_index].actors[i].angle,
																								   irr::core::dimension2df(project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height),
																								   irr::core::dimension2df(project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height));
					project.stages[stage_project_index].actors[i].particle_emitter = p_cylinder_emitter;
				}
			}
			else if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_MESH)
			{
				int mesh_index = project.stages[stage_project_index].actors[i].mesh_index;

				irr::scene::IAnimatedMesh* mesh = NULL;

				if(mesh_index >= 0 && mesh_index < project.meshes.size())
					mesh = project.meshes[mesh_index].mesh;

				if(mesh)
				{
					if(!project.stages[stage_project_index].actors[i].node)
						project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();
					irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

					if(!project.stages[stage_project_index].actors[i].particle_emitter)
					{
						irr::scene::IParticleMeshEmitter* p_mesh_emitter = p_node->createMeshEmitter(mesh,
																									 project.stages[stage_project_index].actors[i].use_normal_direction,
																									 project.stages[stage_project_index].actors[i].direction,
																									 project.stages[stage_project_index].actors[i].use_normal_mod,
																									 -1,
																									 project.stages[stage_project_index].actors[i].use_every_vertex,
																									 project.stages[stage_project_index].actors[i].min_per_sec,
																									 project.stages[stage_project_index].actors[i].max_per_sec,
																									 project.stages[stage_project_index].actors[i].min_start_color,
																									 project.stages[stage_project_index].actors[i].max_start_color,
																									 project.stages[stage_project_index].actors[i].min_life,
																									 project.stages[stage_project_index].actors[i].max_life,
																									 project.stages[stage_project_index].actors[i].angle,
																									 irr::core::dimension2df( project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height ),
																									 irr::core::dimension2df( project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height ) );

						project.stages[stage_project_index].actors[i].particle_emitter = p_mesh_emitter;
					}
					//-----APPLY MATERIAL-----------
					for(int i = 0; i < project.meshes[mesh_index].material_index.size(); i++)
					{
						if(project.meshes[mesh_index].material_index[i] >= 0 && project.meshes[mesh_index].material_index[i] < project.materials.size())
						{
							int mat_index = project.meshes[mesh_index].material_index[i];
							if(project.materials[mat_index].id_name.compare("") != 0)
								p_node->getMaterial(i) = project.materials[mat_index].material;
							else
								p_node->getMaterial(i) = irr::video::SMaterial();
						}
					}
				}

			}
			else if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_POINT)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();
				irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

				if(!project.stages[stage_project_index].actors[i].particle_emitter)
				{
					irr::scene::IParticlePointEmitter* p_point_emitter = p_node->createPointEmitter(project.stages[stage_project_index].actors[i].direction,
																									project.stages[stage_project_index].actors[i].min_per_sec,
																									project.stages[stage_project_index].actors[i].max_per_sec,
																									project.stages[stage_project_index].actors[i].min_start_color,
																									project.stages[stage_project_index].actors[i].max_start_color,
																									project.stages[stage_project_index].actors[i].min_life,
																									project.stages[stage_project_index].actors[i].max_life,
																									project.stages[stage_project_index].actors[i].angle,
																									irr::core::dimension2df(project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height),
																									irr::core::dimension2df(project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height));
					project.stages[stage_project_index].actors[i].particle_emitter = p_point_emitter;
				}
			}
			else if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_RING)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();
				irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

				if(!project.stages[stage_project_index].actors[i].particle_emitter)
				{
					irr::scene::IParticleRingEmitter* p_ring_emitter = p_node->createRingEmitter(project.stages[stage_project_index].actors[i].center,
																								 project.stages[stage_project_index].actors[i].radius,
																								 project.stages[stage_project_index].actors[i].ring_thickness,
																								 project.stages[stage_project_index].actors[i].direction,
																								 project.stages[stage_project_index].actors[i].min_per_sec,
																								 project.stages[stage_project_index].actors[i].max_per_sec,
																								 project.stages[stage_project_index].actors[i].min_start_color,
																								 project.stages[stage_project_index].actors[i].max_start_color,
																								 project.stages[stage_project_index].actors[i].min_life,
																								 project.stages[stage_project_index].actors[i].max_life,
																								 project.stages[stage_project_index].actors[i].angle,
																								 irr::core::dimension2df(project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height),
																								 irr::core::dimension2df(project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height));
					project.stages[stage_project_index].actors[i].particle_emitter = p_ring_emitter;
				}
			}
			else if(project.stages[stage_project_index].actors[i].particle_type == SN_PARTICLE_TYPE_SPHERE)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addParticleSystemSceneNode();
				irr::scene::IParticleSystemSceneNode* p_node = (irr::scene::IParticleSystemSceneNode*) project.stages[stage_project_index].actors[i].node;

				if(!project.stages[stage_project_index].actors[i].particle_emitter)
				{
					irr::scene::IParticleSphereEmitter* p_sphere_emitter = p_node->createSphereEmitter(project.stages[stage_project_index].actors[i].center,
																									   project.stages[stage_project_index].actors[i].radius,
																									   project.stages[stage_project_index].actors[i].direction,
																									   project.stages[stage_project_index].actors[i].min_per_sec,
																									   project.stages[stage_project_index].actors[i].max_per_sec,
																									   project.stages[stage_project_index].actors[i].min_start_color,
																									   project.stages[stage_project_index].actors[i].max_start_color,
																									   project.stages[stage_project_index].actors[i].min_life,
																									   project.stages[stage_project_index].actors[i].max_life,
																									   project.stages[stage_project_index].actors[i].angle,
																									   irr::core::dimension2df(project.stages[stage_project_index].actors[i].min_width, project.stages[stage_project_index].actors[i].min_height),
																									   irr::core::dimension2df(project.stages[stage_project_index].actors[i].max_width, project.stages[stage_project_index].actors[i].max_height));
					project.stages[stage_project_index].actors[i].particle_emitter = p_sphere_emitter;
				}
			}

			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				//-----APPLY MATERIAL-----------
				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						project.stages[stage_project_index].actors[i].node->getMaterial(0) = project.materials[mat_index].material;
				}

			}
		}
		break;


		case SN_ACTOR_TYPE_SPHERE:
		{
			if(!project.stages[stage_project_index].actors[i].node)
				project.stages[stage_project_index].actors[i].node = smgr->addSphereSceneNode(project.stages[stage_project_index].actors[i].radius);

			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				//-----APPLY MATERIAL-----------
				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						project.stages[stage_project_index].actors[i].node->getMaterial(0) = project.materials[mat_index].material;
				}

			}
		}
		break;


		case SN_ACTOR_TYPE_TERRAIN:
		{
			wxFileName hmap_fname = project.project_path;
			hmap_fname.AppendDir(_("textures"));

			if(project.stages[stage_project_index].actors[i].terrain_hmap_file.compare("") != 0)
				hmap_fname.SetFullName(wxString::FromUTF8(project.stages[stage_project_index].actors[i].terrain_hmap_file));

			if(!hmap_fname.Exists())
				break;

			if(!project.stages[stage_project_index].actors[i].node)
				project.stages[stage_project_index].actors[i].node = smgr->addTerrainSceneNode(hmap_fname.GetAbsolutePath().ToStdString().c_str());

			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

				//-----APPLY MATERIAL-----------
				int mat_index = project.stages[stage_project_index].actors[i].override_material_index;
				if(mat_index >= 0 && mat_index < project.materials.size())
				{
					if(project.materials[mat_index].id_name.compare("")!=0)
						node->getMaterial(0) = project.materials[mat_index].material;
				}

			}
		}
		break;


		case SN_ACTOR_TYPE_WATER:
		{
			int mesh_index = project.stages[stage_project_index].actors[i].mesh_index;

			irr::scene::IAnimatedMesh* mesh = NULL;

			if(mesh_index >= 0 && mesh_index < project.meshes.size())
				mesh = project.meshes[mesh_index].mesh;

			if(mesh)
			{
				if(!project.stages[stage_project_index].actors[i].node)
					project.stages[stage_project_index].actors[i].node = smgr->addWaterSurfaceSceneNode(mesh,
																										project.stages[stage_project_index].actors[i].wave_height,
																										project.stages[stage_project_index].actors[i].wave_speed,
																										project.stages[stage_project_index].actors[i].wave_length);
			}


			if(project.stages[stage_project_index].actors[i].node != NULL)
			{
				irr::scene::ISceneNode* node = (irr::scene::ISceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

				//-----APPLY MATERIAL-----------
				for(int i = 0; i < project.meshes[mesh_index].material_index.size(); i++)
				{
					if(project.meshes[mesh_index].material_index[i] >= 0 && project.meshes[mesh_index].material_index[i] < project.materials.size())
					{
						int mat_index = project.meshes[mesh_index].material_index[i];
						if(project.materials[mat_index].id_name.compare("") != 0)
							node->getMaterial(i) = project.materials[mat_index].material;
						else
							node->getMaterial(i) = irr::video::SMaterial();
					}
				}

			}
		}
		break;
	}



	if(project.stages[stage_project_index].actors[i].node)
	{
		irr::scene::ISceneNode* node = (irr::scene::ISceneNode*)project.stages[stage_project_index].actors[i].node;

		//Set Position
		node->setPosition(project.stages[stage_project_index].actors[i].position);

		//Apply Rotation in Y,X,Z order
		node->setRotation( irr::core::vector3df(0, 0, 0) );

		irr::core::vector3df rot;
		irr::core::matrix4 m;
		irr::core::matrix4 n;

		//Rotate on Y
		m.setRotationDegrees(node->getRotation());

		rot.set(0, project.stages[stage_project_index].actors[i].rotation.Y, 0);

		n.setRotationDegrees(rot);

		m *= n;

		node->setRotation( m.getRotationDegrees() );
		node->updateAbsolutePosition();

		//Rotate on X
		m.setRotationDegrees(node->getRotation());

		rot.set(project.stages[stage_project_index].actors[i].rotation.X, 0, 0);

		n.setRotationDegrees(rot);

		m *= n;

		node->setRotation( m.getRotationDegrees() );
		node->updateAbsolutePosition();

		//Rotate on Z
		m.setRotationDegrees(node->getRotation());

		rot.set(0, 0, project.stages[stage_project_index].actors[i].rotation.Z);

		n.setRotationDegrees(rot);

		m *= n;

		node->setRotation( m.getRotationDegrees() );
		node->updateAbsolutePosition();

		//Scale
		node->setScale(project.stages[stage_project_index].actors[i].scale);


		//-----Render Settings----------------
		node->setVisible(project.stages[stage_project_index].actors[i].visible);
		node->setAutomaticCulling(project.stages[stage_project_index].actors[i].auto_culling);

		//------ICON NODE-------------------
		bool use_icon_bbox = false;

		if(project.stages[stage_project_index].actors[i].icon_node)
		{
			irr::core::vector3df pos = project.stages[stage_project_index].actors[i].node->getAbsolutePosition();
			project.stages[stage_project_index].actors[i].icon_node->setPosition(pos);
			project.stages[stage_project_index].actors[i].icon_node->setVisible(project.stages[stage_project_index].actors[i].visible);
			use_icon_bbox = true;
		}

		actor_object scene_obj;
		scene_obj.actor_index = i;
		scene_obj.id_name = project.stages[stage_project_index].actors[i].id_name;
		scene_obj.isSelected = false;
		scene_obj.node = node;
		scene_obj.rotation = &project.stages[stage_project_index].actors[i].rotation;

		if(use_icon_bbox)
		{
			scene_obj.use_override_size = true;
			scene_obj.override_box = project.stages[stage_project_index].actors[i].icon_node->getBoundingBox();
		}

		bool scene_actor_exists = false;
		for(int scene_actors_n=0; scene_actors_n < current_window->scene_actors.size(); scene_actors_n++)
		{
			if(current_window->scene_actors[scene_actors_n].actor_index == i)
			{
				scene_actor_exists = true;
				break;
			}
		}
		if(!scene_actor_exists)
		{
			current_window->scene_actors.push_back(scene_obj);
		}
	}

	for(int sn = 0; sn < current_window->scene_actors.size(); sn++)
	{
		if(current_window->scene_actors[sn].actor_index == i)
		{
			current_window->scene_actors[sn].node = project.stages[stage_project_index].actors[i].node;
		}
	}

	for(int sn = 0; sn < current_window->selected_actors.size(); sn++)
	{
		if(current_window->selected_actors[sn].actor_index == i)
		{
			current_window->selected_actors[sn].node = project.stages[stage_project_index].actors[i].node;
		}
	}
}

void SerenityEditorSerenity3D_Frame::On_Stage_StageNodeActivated( wxTreeEvent& event )
{
	if(project.stages.size() <= 0)
		return;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		if(event.GetItem() == stage_tree_nodes[i].tree_item)
		{
			if(stage_tree_nodes[i].project_index != stageTab_active_stage_project_index)
			{
				open_stage(stage_tree_nodes[i].project_index);

				for(int n = 0; n < stage_tree_nodes.size(); n++)
					stage_tree_nodes[n].active = false;

				stage_tree_nodes[i].active = true;
				break;
			}
		}

		//TODO: Check stage actors and groups activations here
	}
}

void SerenityEditorSerenity3D_Frame::getGridAllMaterialList(wxPGChoices* choices)
{
	choices->Clear();

	choices->Add(_("NONE"));


	for(int i = 0; i < project.materials.size(); i++)
	{
		if(project.materials[i].id_name.compare("")!=0)
		{
			choices->Add(wxString::FromUTF8(project.materials[i].id_name));
		}
	}
}

void SerenityEditorSerenity3D_Frame::getGridAnimationList(int mesh_project_index, wxPGChoices* choices)
{
	choices->Clear();

	choices->Add(_("NONE"));

	if(mesh_project_index < 0 || mesh_project_index >= project.meshes.size())
		return;


	for(int i = 0; i < project.meshes[mesh_project_index].animation.size(); i++)
	{
		if(project.meshes[mesh_project_index].animation[i].id_name.compare("")!=0)
		{
			choices->Add(wxString::FromUTF8(project.meshes[mesh_project_index].animation[i].id_name));
		}
	}
}

void SerenityEditorSerenity3D_Frame::OnStagePropertyGridChanged( wxPropertyGridEvent& event )
{
	wxPGProperty* property = event.GetProperty();
	wxString property_name = property->GetName();

	int selected_page_index = m_stage_propertyGridManager->GetSelectedPage();
	wxPropertyGridPage* page = m_stage_propertyGridManager->GetPage(selected_page_index);



	if(property_name.compare(_("actor_id"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].id_name = page->GetProperty(_("actor_id"))->GetValueAsString();

		if(!isValidID(project.stages[stage_index].actors[actor_index].id_name, RC_ID_ACTOR))
		{
			wxMessageBox(_("ActorID is invalid. A valid ID will be generated"));
			project.stages[stage_index].actors[actor_index].id_name = project.genActorID(stage_index);
			page->GetProperty(_("actor_id"))->SetValueFromString(wxString::FromUTF8(project.stages[stage_index].actors[actor_index].id_name));
		}

		//update all actor names in tree nodes
		for(int i = 0; i < stage_tree_nodes.size(); i++)
		{
			int stage_project_index = stage_tree_nodes[i].project_index;

			if(stage_project_index < 0)
				continue;

			for(int ac = 0; ac < stage_tree_nodes[i].actors.size(); ac++)
			{
				int actor_project_index = stage_tree_nodes[i].actors[ac].project_index;

				if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
					continue;

				if(project.stages[stage_project_index].actors[actor_project_index].id_name.compare("")==0)
					continue;

				wxTreeItemId actor_item = stage_tree_nodes[i].actors[ac].tree_item;

				wxString node_label = m_project_stage_treeCtrl->GetItemText(actor_item);

				if(project.stages[stage_project_index].actors[actor_project_index].id_name.compare(node_label.ToStdString())!=0)
				{
					m_project_stage_treeCtrl->SetItemText(actor_item, wxString::FromUTF8(project.stages[stage_project_index].actors[actor_project_index].id_name));
				}
			}
		}
	}
	else if(property_name.compare(_("animation_mesh_id"))==0)
	{
		//wxMessageBox(_("balls: ") + wxString::Format(_("%d"), stageTabGrid_current_stage) + _(", ") + wxString::Format(_("%d"), stageTabGrid_current_actor));
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		//wxMessageBox(_("DO STUFF"));


		wxString init_animation_id = _("NONE");

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].mesh_index = project.getMeshIndex(property->GetValueAsString());
		project.stages[stage_index].actors[actor_index].animation_index = -1;
		project.stages[stage_index].actors[actor_index].num_loops = -1;

		int animation_index = -1;

		int num_loops = project.stages[stage_index].actors[actor_index].num_loops;
		int mesh_index = project.stages[stage_index].actors[actor_index].mesh_index;

		wxPGChoices animation_choice;
		getGridAnimationList(mesh_index, &animation_choice); //mesh_index error checking happens in the getGridAnimationList() function so I am not bothering here

		page->GetPropertyByName(_("init_animation_id"))->SetChoices(animation_choice);

		page->GetPropertyByName(_("init_animation_id"))->SetChoiceSelection(0);

		page->GetPropertyByName(_("num_loops"))->SetValueFromInt(-1);

		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("init_animation_id"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		wxString init_animation_id = _("NONE");

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		int mesh_index = project.stages[stage_index].actors[actor_index].mesh_index;
		project.stages[stage_index].actors[actor_index].animation_index = project.getAnimationIndex(mesh_index, page->GetPropertyByName(_("init_animation_id"))->GetValueAsString());

		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("num_loops"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		wxString init_animation_id = _("NONE");

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].num_loops = page->GetPropertyByName(_("num_loops"))->GetValue().GetInteger();
		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("visible"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].visible = page->GetPropertyByName(_("visible"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("shadow"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].hasShadow = page->GetPropertyByName(_("shadow"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("auto_culling"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].auto_culling = page->GetPropertyByName(_("auto_culling"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 4).compare(_("pos_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].position.X = page->GetPropertyByName(_("pos_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].position.Y = page->GetPropertyByName(_("pos_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].position.Z = page->GetPropertyByName(_("pos_z"))->GetValue().GetDouble();

		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 4).compare(_("rot_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].rotation.X = page->GetPropertyByName(_("rot_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].rotation.Y = page->GetPropertyByName(_("rot_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].rotation.Z = page->GetPropertyByName(_("rot_z"))->GetValue().GetDouble();

		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 6).compare(_("scale_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].scale.X = page->GetPropertyByName(_("scale_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].scale.Y = page->GetPropertyByName(_("scale_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].scale.Z = page->GetPropertyByName(_("scale_z"))->GetValue().GetDouble();

		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("stage_id"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].id_name = m_stageProperties_propertyGridPage->GetPropertyByName(_("stage_id"))->GetValueAsString();

		if(!isValidID(wxString::FromUTF8(project.stages[stage_index].id_name), RC_ID_ANY))
		{
			wxMessageBox(_("StageID is invalid. A valid ID will be generated"));
			project.stages[stage_index].id_name = project.genStageID();
			page->GetProperty(_("stage_id"))->SetValueFromString(wxString::FromUTF8(project.stages[stage_index].id_name));
		}

		//update all actor names in tree nodes
		for(int i = 0; i < stage_tree_nodes.size(); i++)
		{
			int stage_project_index = stage_tree_nodes[i].project_index;

			if(stage_project_index < 0 || stage_project_index >= project.stages.size())
				continue;

			wxTreeItemId stage_item = stage_tree_nodes[i].tree_item;

			m_project_stage_treeCtrl->SetItemText(stage_item, wxString::FromUTF8(project.stages[stage_project_index].id_name));
		}
	}
	else if(property_name.compare(_("skydome_hRes"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].sky.hRes = m_stageProperties_propertyGridPage->GetPropertyByName(_("skydome_hRes"))->GetValue().GetInteger();
	}
	else if(property_name.compare(_("skydome_vRes"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].sky.vRes = m_stageProperties_propertyGridPage->GetPropertyByName(_("skydome_vRes"))->GetValue().GetInteger();
	}
	else if(property_name.compare(_("sky_texture_pct"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].sky.txPCT = m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_texture_pct"))->GetValue().GetDouble();
	}
	else if(property_name.compare(_("sky_sphere_pct"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].sky.spherePCT = m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_sphere_pct"))->GetValue().GetDouble();
	}
	else if(property_name.compare(_("sky_radius"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		project.stages[stage_index].sky.dome_radius = m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_radius"))->GetValue().GetDouble();
	}
	else if(property_name.compare(_("sky_shape"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString sky_selection = m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_shape"))->GetValueAsString();
		project.stages[stage_index].sky.type = project.getSkyType(sky_selection);
	}
	else if(property_name.compare(_("sky_dome_image_id"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_dome_image_id"))->GetValueAsString();
		project.stages[stage_index].sky.dome_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_left_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_left_image"))->GetValueAsString();
		project.stages[stage_index].sky.left_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_right_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_right_image"))->GetValueAsString();
		project.stages[stage_index].sky.right_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_top_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_top_image"))->GetValueAsString();
		project.stages[stage_index].sky.top_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_bottom_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_bottom_image"))->GetValueAsString();
		project.stages[stage_index].sky.bottom_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_front_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_front_image"))->GetValueAsString();
		project.stages[stage_index].sky.front_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("skybox_back_image"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_back_image"))->GetValueAsString();
		project.stages[stage_index].sky.back_texture_index = project.getTextureIndex(img_id);
	}
	else if(property_name.compare(_("mesh_id"))==0 || property_name.compare(_("particle_mesh_id"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].mesh_index = project.getMeshIndex(property->GetValueAsString());
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("particle_type"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].particle_type = project.getParticleType(property->GetValueAsString());
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("use_every_vertex"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].use_every_vertex = page->GetPropertyByName(_("use_every_vertex"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("use_normal_direction"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].use_normal_direction = page->GetPropertyByName(_("use_normal_direction"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("use_normal_mod"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].use_normal_mod = page->GetPropertyByName(_("use_normal_mod"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("use_outline_only"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].use_outline_only = page->GetPropertyByName(_("use_outline_only"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("min_width"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].min_width = page->GetPropertyByName(_("min_width"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("min_height"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].min_height = page->GetPropertyByName(_("min_height"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_width"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].max_width = page->GetPropertyByName(_("max_width"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_height"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].max_height = page->GetPropertyByName(_("max_height"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("min_start_color"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		//wxColour color(page->GetPropertyByName(_("min_start_color"))->GetValue().GetWxObjectPtr()); //wxMessageBox(_("MSG: ") + page->GetPropertyByName(_("min_start_color"))->GetValue().GetString());
		//wxColourPropertyValue* pcolval = wxDynamicCast(page->GetPropertyByName(_("min_start_color")).GetWxObjectPtr(), wxColourPropertyValue);
		wxAny value = page->GetPropertyByName(_("min_start_color"))->GetValue();
		wxColour color = value.As<wxColour>();
		irr::u32 r = color.GetRed();
		irr::u32 g = color.GetGreen();
		irr::u32 b = color.GetBlue();
		irr::u32 a = color.GetAlpha();
		project.stages[stage_index].actors[actor_index].min_start_color = irr::video::SColor(a, r, g, b);
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_start_color"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		wxAny value = page->GetPropertyByName(_("max_start_color"))->GetValue();
		wxColour color = value.As<wxColour>();
		project.stages[stage_index].actors[actor_index].max_start_color = irr::video::SColor(color.GetAlpha(),
																							 color.GetRed(),
																							 color.GetGreen(),
																							 color.GetBlue());
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("min_per_sec"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].min_per_sec = page->GetPropertyByName(_("min_per_sec"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_per_sec"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].max_per_sec = page->GetPropertyByName(_("max_per_sec"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("min_life"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].min_life = page->GetPropertyByName(_("min_life"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_life"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].max_life = page->GetPropertyByName(_("max_life"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("max_angle"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].angle = page->GetPropertyByName(_("max_angle"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 7).compare(_("normal_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].normal.X = page->GetPropertyByName(_("normal_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].normal.Y = page->GetPropertyByName(_("normal_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].normal.Z = page->GetPropertyByName(_("normal_z"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 4).compare(_("dir_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].direction.X = page->GetPropertyByName(_("dir_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].direction.Y = page->GetPropertyByName(_("dir_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].direction.Z = page->GetPropertyByName(_("dir_z"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 7).compare(_("center_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].center.X = page->GetPropertyByName(_("center_x"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].center.Y = page->GetPropertyByName(_("center_y"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].center.Z = page->GetPropertyByName(_("center_z"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("radius"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].radius = page->GetPropertyByName(_("radius"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("cylinder_length"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].cylinder_length = page->GetPropertyByName(_("cylinder_length"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("ring_thickness"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].ring_thickness = page->GetPropertyByName(_("ring_thickness"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 8).compare(_("min_box_"))==0 || property_name.substr(0, 8).compare(_("max_box_"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		double min_x = page->GetPropertyByName(_("min_box_x"))->GetValue().GetDouble();
		double min_y = page->GetPropertyByName(_("min_box_y"))->GetValue().GetDouble();
		double min_z = page->GetPropertyByName(_("min_box_z"))->GetValue().GetDouble();

		double max_x = page->GetPropertyByName(_("max_box_x"))->GetValue().GetDouble();
		double max_y = page->GetPropertyByName(_("max_box_y"))->GetValue().GetDouble();
		double max_z = page->GetPropertyByName(_("max_box_z"))->GetValue().GetDouble();

		project.stages[stage_index].actors[actor_index].box = irr::core::aabbox3df(min_x, min_y, min_z, max_x, max_y, max_z);
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("hmap_image_id"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;
		wxString img_id = _("");

		img_id = m_stageProperties_propertyGridPage->GetPropertyByName(_("hmap_image_id"))->GetValueAsString();
		int img_index = project.getTextureIndex(img_id);

		if(img_index < 0 || img_index >= project.textures.size())
		{
			project.stages[stage_index].actors[actor_index].terrain_hmap_file = "";
		}
		else
		{
			if(project.textures[img_index].id_name.compare("")==0)
				project.stages[stage_index].actors[actor_index].terrain_hmap_file = "";
			else
				project.stages[stage_index].actors[actor_index].terrain_hmap_file = project.textures[img_index].file;
		}
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("light_type"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].light_type = project.getLightType(property->GetValueAsString());
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("ambient_color"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		//wxColour color(page->GetPropertyByName(_("min_start_color"))->GetValue().GetWxObjectPtr()); //wxMessageBox(_("MSG: ") + page->GetPropertyByName(_("min_start_color"))->GetValue().GetString());
		//wxColourPropertyValue* pcolval = wxDynamicCast(page->GetPropertyByName(_("min_start_color")).GetWxObjectPtr(), wxColourPropertyValue);
		wxAny value = page->GetPropertyByName(_("ambient_color"))->GetValue();
		wxColour color = value.As<wxColour>();
		irr::u32 r = color.GetRed();
		irr::u32 g = color.GetGreen();
		irr::u32 b = color.GetBlue();
		irr::u32 a = color.GetAlpha();
		project.stages[stage_index].actors[actor_index].ambient = irr::video::SColor(a, r, g, b);
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("diffuse_color"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		//wxColour color(page->GetPropertyByName(_("min_start_color"))->GetValue().GetWxObjectPtr()); //wxMessageBox(_("MSG: ") + page->GetPropertyByName(_("min_start_color"))->GetValue().GetString());
		//wxColourPropertyValue* pcolval = wxDynamicCast(page->GetPropertyByName(_("min_start_color")).GetWxObjectPtr(), wxColourPropertyValue);
		wxAny value = page->GetPropertyByName(_("diffuse_color"))->GetValue();
		wxColour color = value.As<wxColour>();
		irr::u32 r = color.GetRed();
		irr::u32 g = color.GetGreen();
		irr::u32 b = color.GetBlue();
		irr::u32 a = color.GetAlpha();
		project.stages[stage_index].actors[actor_index].diffuse = irr::video::SColor(a, r, g, b);
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("specular_color"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		//wxColour color(page->GetPropertyByName(_("min_start_color"))->GetValue().GetWxObjectPtr()); //wxMessageBox(_("MSG: ") + page->GetPropertyByName(_("min_start_color"))->GetValue().GetString());
		//wxColourPropertyValue* pcolval = wxDynamicCast(page->GetPropertyByName(_("min_start_color")).GetWxObjectPtr(), wxColourPropertyValue);
		wxAny value = page->GetPropertyByName(_("specular_color"))->GetValue();
		wxColour color = value.As<wxColour>();
		irr::u32 r = color.GetRed();
		irr::u32 g = color.GetGreen();
		irr::u32 b = color.GetBlue();
		irr::u32 a = color.GetAlpha();
		project.stages[stage_index].actors[actor_index].specular = irr::video::SColor(a, r, g, b);
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.substr(0, 4).compare(_("constant_attenuation"))==0 ||
			property_name.substr(0, 4).compare(_("linear_attenuation"))==0 ||
			property_name.substr(0, 4).compare(_("quadratic_attenuation"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;


		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].attenuation.X = page->GetPropertyByName(_("constant_attenuation"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].attenuation.Y = page->GetPropertyByName(_("linear_attenuation"))->GetValue().GetDouble();
		project.stages[stage_index].actors[actor_index].attenuation.Z = page->GetPropertyByName(_("quadratic_attenuation"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("inner_cone"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].inner_cone = page->GetPropertyByName(_("inner_cone"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("outer_cone"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].outer_cone = page->GetPropertyByName(_("outer_cone"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("falloff"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].falloff = page->GetPropertyByName(_("falloff"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("cast_shadow"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].isCastingShadow = page->GetPropertyByName(_("cast_shadow"))->GetValue().GetBool();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("material_id"))==0)
	{
		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;
		wxString mat_id = _("");

		mat_id = page->GetPropertyByName(_("material_id"))->GetValueAsString();
		project.stages[stage_index].actors[actor_index].override_material_index = project.getMaterialIndex(mat_id);
		if(stage_index == stageTab_active_stage_project_index)
		{
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("wave_height"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].wave_height = page->GetPropertyByName(_("wave_height"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("wave_length"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].wave_length = page->GetPropertyByName(_("wave_length"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("wave_speed"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].wave_speed = page->GetPropertyByName(_("wave_speed"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}
	else if(property_name.compare(_("cube_size"))==0)
	{
		if(stageTabGrid_current_stage < 0 || stageTabGrid_current_stage >= project.stages.size())
			return;

		if(stageTabGrid_current_actor < 0 || stageTabGrid_current_actor >= project.stages[stageTabGrid_current_stage].actors.size())
			return;

		int stage_index = stageTabGrid_current_stage;
		int actor_index = stageTabGrid_current_actor;

		project.stages[stage_index].actors[actor_index].cube_size = page->GetPropertyByName(_("cube_size"))->GetValue().GetDouble();
		if(stage_index == stageTab_active_stage_project_index)
		{
			project.stages[stage_index].actors[actor_index].node->remove();
			project.stages[stage_index].actors[actor_index].node = NULL;
			refresh_actor(actor_index);
		}
	}

}

void SerenityEditorSerenity3D_Frame::setAnimatedActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);

	//-------------Setting Mesh ID---------------------------
	int mesh_selection = -1;

	wxPGChoices mesh_choice;
	mesh_choice.Clear();

	mesh_choice.Add(_("NONE"));

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare("")!=0)
		{
			int n = mesh_choice.GetCount();

			if(project.meshes[i].id_name.compare(mesh_id.ToStdString())==0)
				mesh_selection = n;

			n++;

			mesh_choice.Add(wxString::FromUTF8(project.meshes[i].id_name));
		}
	}

	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("animation_mesh_id"))->SetChoices(mesh_choice);

	if(mesh_selection >= 0)
		m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("animation_mesh_id"))->SetChoiceSelection(mesh_selection);

	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//-------------Animation Stuff-------------------------------
	wxString init_animation_id = _("NONE");
	int animation_index = project.stages[stage_project_index].actors[actor_project_index].animation_index;
	int num_loops = project.stages[stage_project_index].actors[actor_project_index].num_loops;
	if(mesh_index >= 0 && mesh_index < project.meshes.size())
	{
		if(animation_index >= 0 && animation_index < project.meshes[mesh_index].animation.size())
		{
			init_animation_id = project.meshes[mesh_index].animation[animation_index].id_name;
		}
	}


	int animation_selection = (animation_index < 0 ? 0 : animation_index + 1); //0 will always be "NONE" and then every animation id after that

	wxPGChoices animation_choice;
	getGridAnimationList(mesh_index, &animation_choice);

	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("init_animation_id"))->SetChoices(animation_choice);

	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("init_animation_id"))->SetChoiceSelection(animation_selection);

	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("num_loops"))->SetValueFromInt(num_loops);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);



	//m_animatedActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))
}

void SerenityEditorSerenity3D_Frame::setOctreeActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);

	//-------------Setting Mesh ID---------------------------
	int mesh_selection = -1;

	wxPGChoices mesh_choice;
	mesh_choice.Clear();

	mesh_choice.Add(_("NONE"));

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare("")!=0)
		{
			int n = mesh_choice.GetCount();

			if(project.meshes[i].id_name.compare(mesh_id.ToStdString())==0)
				mesh_selection = n;

			n++;

			mesh_choice.Add(wxString::FromUTF8(project.meshes[i].id_name));
		}
	}

	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("mesh_id"))->SetChoices(mesh_choice);

	if(mesh_selection >= 0)
		m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("mesh_id"))->SetChoiceSelection(mesh_selection);

	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_octreeActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);



}

void SerenityEditorSerenity3D_Frame::setBillboardActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	//-------------Setting Actor ID---------------------------
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);


	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);



	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_billboardActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);
}

void SerenityEditorSerenity3D_Frame::setLightActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	//-------------Setting Actor ID---------------------------
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);


	//-------------Light Type----------------------------------
	wxPGChoices light_type_choice;
	light_type_choice.Clear();

	light_type_choice.Add(_("POINT"));
	light_type_choice.Add(_("SPOT"));
	light_type_choice.Add(_("DIRECTIONAL"));

	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("light_type"))->SetChoices(light_type_choice);

	if(project.stages[stage_project_index].actors[actor_project_index].light_type >= SN_LIGHT_TYPE_COUNT)
		project.stages[stage_project_index].actors[actor_project_index].light_type = 0;

	int light_type = project.stages[stage_project_index].actors[actor_project_index].light_type;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("light_type"))->SetChoiceSelection(light_type);

	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("visible"))->SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))->SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))->SetValue(auto_culling_flag);



	//-----------------COLOR---------------------------------
	irr::video::SColor c = project.stages[stage_project_index].actors[actor_project_index].ambient;
	wxColour ambient_color(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("ambient_color"))->SetValueFromString(ambient_color.GetAsString());


	c = project.stages[stage_project_index].actors[actor_project_index].diffuse;
	wxColour diffuse_color(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("diffuse_color"))->SetValueFromString(diffuse_color.GetAsString());

	c = project.stages[stage_project_index].actors[actor_project_index].specular;
	wxColour specular_color(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("specular_color"))->SetValueFromString(specular_color.GetAsString());

	//--------------ATTENUATION--------------------------------
	irr::core::vector3df attenuation = project.stages[stage_project_index].actors[actor_project_index].attenuation;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("constant_attenuation"))->SetValue(attenuation.X);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("linear_attenuation"))->SetValue(attenuation.Y);
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("quadratic_attenuation"))->SetValue(attenuation.Z);

	//--------------CONE----------------
	double inner_cone = project.stages[stage_project_index].actors[actor_project_index].inner_cone;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("inner_cone"))->SetValue(inner_cone);

	double outer_cone = project.stages[stage_project_index].actors[actor_project_index].outer_cone;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("outer_cone"))->SetValue(outer_cone);

	//--------------RADIUS----------------
	double radius = project.stages[stage_project_index].actors[actor_project_index].radius;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("radius"))->SetValue(radius);

	//--------------FALLOFF----------------
	double falloff = project.stages[stage_project_index].actors[actor_project_index].falloff;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("falloff"))->SetValue(falloff);

	//------------FLAGS------------------------------
	bool cast_shadow = project.stages[stage_project_index].actors[actor_project_index].isCastingShadow;
	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("cast_shadow"))->SetValue(cast_shadow);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_lightActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_lightActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);

}

void SerenityEditorSerenity3D_Frame::setTerrainActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	//-------------Setting Actor ID---------------------------
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);


	//-------------Materials----------------------------------
	int hmap_selection = 0;

	wxPGChoices hmap_choice;
	hmap_choice.Clear();

	getGridTextureList(&hmap_choice);

	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("hmap_image_id"))->SetChoices(hmap_choice);

	std::string hmap_selection_file = project.stages[stage_project_index].actors[actor_project_index].terrain_hmap_file;

	int hmap_texture_index = -1;

	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare("")==0)
			continue;

		if(project.textures[i].file.compare(hmap_selection_file)==0)
		{
			hmap_texture_index = i;
			break;
		}
	}

	if(hmap_texture_index < 0 || hmap_texture_index >= project.textures.size())
		hmap_selection = 0;
	else
	{
		if(project.textures[hmap_texture_index].id_name.compare("")==0)
			hmap_selection = 0;
		else
		{
			std::string texture_id = project.textures[hmap_texture_index].id_name;

			for(int i = 0; i < hmap_choice.GetCount(); i++)
			{
				if(hmap_choice.Item(i).GetText().compare(texture_id)==0)
				{
					hmap_selection = i;
					break;
				}
			}
		}
	}

	if(hmap_selection >= 0)
		m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("hmap_image_id"))->SetChoiceSelection(hmap_selection);



	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_terrainActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);
}

void SerenityEditorSerenity3D_Frame::setWaterActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);

	//-------------Setting Mesh ID---------------------------
	int mesh_selection = -1;

	wxPGChoices mesh_choice;
	mesh_choice.Clear();

	mesh_choice.Add(_("NONE"));

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare("")!=0)
		{
			int n = mesh_choice.GetCount();

			if(project.meshes[i].id_name.compare(mesh_id.ToStdString())==0)
				mesh_selection = n;

			n++;

			mesh_choice.Add(wxString::FromUTF8(project.meshes[i].id_name));
		}
	}

	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("mesh_id"))->SetChoices(mesh_choice);

	if(mesh_selection >= 0)
		m_waterActorProperties_propertyGridPage->GetPropertyByName(_("mesh_id"))->SetChoiceSelection(mesh_selection);

	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);


	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_waterActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);


	//-------------Wave Settings--------------------------------
	double wave_height = project.stages[stage_project_index].actors[actor_project_index].wave_height;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("wave_height"))->SetValue(wave_height);

	double wave_length = project.stages[stage_project_index].actors[actor_project_index].wave_length;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("wave_length"))->SetValue(wave_length);

	double wave_speed = project.stages[stage_project_index].actors[actor_project_index].wave_speed;
	m_waterActorProperties_propertyGridPage->GetPropertyByName(_("wave_speed"))->SetValue(wave_speed);
}

void SerenityEditorSerenity3D_Frame::setParticleActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);

	//-------------Setting Mesh ID---------------------------
	int mesh_selection = -1;

	wxPGChoices mesh_choice;
	mesh_choice.Clear();

	mesh_choice.Add(_("NONE"));

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare("")!=0)
		{
			int n = mesh_choice.GetCount();

			if(project.meshes[i].id_name.compare(mesh_id.ToStdString())==0)
				mesh_selection = n;

			n++;

			mesh_choice.Add(wxString::FromUTF8(project.meshes[i].id_name));
		}
	}

	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("particle_mesh_id"))->SetChoices(mesh_choice);

	if(mesh_selection >= 0)
		m_particleActorProperties_propertyGridPage->GetPropertyByName(_("particle_mesh_id"))->SetChoiceSelection(mesh_selection);


	//-------------Particle Type----------------------------------
	wxPGChoices particle_type_choice;
	particle_type_choice.Clear();

	particle_type_choice.Add(_("POINT"));
	particle_type_choice.Add(_("BOX"));
	particle_type_choice.Add(_("SPHERE"));
	particle_type_choice.Add(_("CYLINDER"));
	particle_type_choice.Add(_("MESH"));
	particle_type_choice.Add(_("RING"));

	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("particle_type"))->SetChoices(particle_type_choice);

	if(project.stages[stage_project_index].actors[actor_project_index].particle_type > 5)
		project.stages[stage_project_index].actors[actor_project_index].particle_type = 0;

	int particle_type = project.stages[stage_project_index].actors[actor_project_index].particle_type;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("particle_type"))->SetChoiceSelection(particle_type);

	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("visible"))->SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))->SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))->SetValue(auto_culling_flag);


	//----------------SIZE----------------------------
	double min_width = project.stages[stage_project_index].actors[actor_project_index].min_width;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_width"))->SetValue(min_width);

	double min_height = project.stages[stage_project_index].actors[actor_project_index].min_height;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_height"))->SetValue(min_height);

	double max_width = project.stages[stage_project_index].actors[actor_project_index].max_width;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_width"))->SetValue(max_width);

	double max_height = project.stages[stage_project_index].actors[actor_project_index].max_height;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_height"))->SetValue(max_height);


	//-----------------COLOR---------------------------------
	irr::video::SColor c = project.stages[stage_project_index].actors[actor_project_index].min_start_color;
	wxColour min_start_color(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_start_color"))->SetValueFromString(min_start_color.GetAsString());


	c = project.stages[stage_project_index].actors[actor_project_index].max_start_color;
	wxColour max_start_color(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_start_color"))->SetValueFromString(max_start_color.GetAsString());


	//-----------------SPEED---------------------------
	double min_per_sec = project.stages[stage_project_index].actors[actor_project_index].min_per_sec;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_per_sec"))->SetValue(min_per_sec);

	double max_per_sec = project.stages[stage_project_index].actors[actor_project_index].max_per_sec;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_per_sec"))->SetValue(max_per_sec);


	//-----------------LIFETIME---------------------------
	double min_life = project.stages[stage_project_index].actors[actor_project_index].min_life;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_life"))->SetValue(min_life);

	double max_life = project.stages[stage_project_index].actors[actor_project_index].max_life;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_life"))->SetValue(max_life);


	//-------------------NORMAL------------------------
	irr::core::vector3df normal = project.stages[stage_project_index].actors[actor_project_index].normal;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("normal_x"))->SetValue(normal.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("normal_y"))->SetValue(normal.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("normal_z"))->SetValue(normal.Z);


	//-------------------DIRECTION------------------------
	irr::core::vector3df direction = project.stages[stage_project_index].actors[actor_project_index].direction;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("dir_x"))->SetValue(direction.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("dir_y"))->SetValue(direction.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("dir_z"))->SetValue(direction.Z);


	//--------------MAX ANGLE----------------
	double max_angle = project.stages[stage_project_index].actors[actor_project_index].angle;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_angle"))->SetValue(max_angle);


	//-------------------CENTER------------------------
	irr::core::vector3df center = project.stages[stage_project_index].actors[actor_project_index].center;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("center_x"))->SetValue(center.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("center_y"))->SetValue(center.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("center_z"))->SetValue(center.Z);


	//--------------RADIUS----------------
	double radius = project.stages[stage_project_index].actors[actor_project_index].radius;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("radius"))->SetValue(radius);


	//--------------CYLINDER FLAGS---------------------
	bool use_every_vertex = project.stages[stage_project_index].actors[actor_project_index].use_every_vertex;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("use_every_vertex"))->SetValue(use_every_vertex);

	bool use_normal_direction = project.stages[stage_project_index].actors[actor_project_index].use_normal_direction;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("use_normal_direction"))->SetValue(use_normal_direction);

	bool use_normal_mod = project.stages[stage_project_index].actors[actor_project_index].use_normal_mod;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("use_normal_mod"))->SetValue(use_normal_mod);

	bool use_outline_only = project.stages[stage_project_index].actors[actor_project_index].use_outline_only;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("use_outline_only"))->SetValue(use_outline_only);


	double cylinder_length = project.stages[stage_project_index].actors[actor_project_index].cylinder_length;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("cylinder_length"))->SetValue(cylinder_length);


	irr::core::aabbox3d box = project.stages[stage_project_index].actors[actor_project_index].box;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_box_x"))->SetValue(box.MinEdge.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_box_y"))->SetValue(box.MinEdge.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("min_box_z"))->SetValue(box.MinEdge.Z);

	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_box_x"))->SetValue(box.MaxEdge.X);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_box_y"))->SetValue(box.MaxEdge.Y);
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("max_box_z"))->SetValue(box.MaxEdge.Z);


	//--------------------RING------------------------
	double ring_thickness = project.stages[stage_project_index].actors[actor_project_index].ring_thickness;
	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("ring_thickness"))->SetValue(ring_thickness);



	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_particleActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_particleActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);
}

void SerenityEditorSerenity3D_Frame::setCubeActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);


	//-------------Cube Size--------------------------------
	double cube_size = project.stages[stage_project_index].actors[actor_project_index].cube_size;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("cube_size"))->SetValue(cube_size);


	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_cubeActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);

}

void SerenityEditorSerenity3D_Frame::setSphereActorGrid(int stage_project_index, int actor_project_index)
{
	if(stage_project_index < 0 || stage_project_index >= project.stages.size())
		return;

	if(actor_project_index < 0 || actor_project_index >= project.stages[stage_project_index].actors.size())
		return;

	wxString id_name = project.stages[stage_project_index].actors[actor_project_index].id_name;

	int mesh_index = project.stages[stage_project_index].actors[actor_project_index].mesh_index;
	wxString mesh_id = ((mesh_index < 0 || mesh_index >= project.meshes.size()) ? _("NONE") : project.meshes[mesh_index].id_name);


	//-------------Setting Actor ID---------------------------
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("actor_id"))->SetValueFromString(id_name);


	//-------------Cube Size--------------------------------
	double radius = project.stages[stage_project_index].actors[actor_project_index].radius;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("radius"))->SetValue(radius);


	//-------------Setting Position---------------------------
	irr::core::vector3df pos = project.stages[stage_project_index].actors[actor_project_index].position;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("pos_x"))->SetValue(pos.X);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("pos_y"))->SetValue(pos.Y);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("pos_z"))->SetValue(pos.Z);

	//-------------Setting Rotation---------------------------
	irr::core::vector3df rot = project.stages[stage_project_index].actors[actor_project_index].rotation;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("rot_x"))->SetValue(rot.X);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("rot_y"))->SetValue(rot.Y);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("rot_z"))->SetValue(rot.Z);

	//-------------Setting Scale---------------------------
	irr::core::vector3df scale = project.stages[stage_project_index].actors[actor_project_index].scale;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("scale_x"))->SetValue(scale.X);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("scale_y"))->SetValue(scale.Y);
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("scale_z"))->SetValue(scale.Z);

	//------------Render Settings------------------------------
	bool visible_flag = project.stages[stage_project_index].actors[actor_project_index].visible;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("visible"))-> wxPGProperty::SetValue(visible_flag);

	bool shadow_flag = project.stages[stage_project_index].actors[actor_project_index].hasShadow;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("shadow"))-> wxPGProperty::SetValue(shadow_flag);

	bool auto_culling_flag = project.stages[stage_project_index].actors[actor_project_index].auto_culling;
	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("auto_culling"))-> wxPGProperty::SetValue(auto_culling_flag);

	//-------------Materials----------------------------------
	int material_selection = 0;

	wxPGChoices material_choice;
	material_choice.Clear();

	getGridAllMaterialList(&material_choice);

	m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoices(material_choice);

	int mat_index = project.stages[stage_project_index].actors[actor_project_index].override_material_index;

	if(mat_index < 0 || mat_index >= project.materials.size())
		material_selection = 0;
	else
	{
		if(project.materials[mat_index].id_name.compare("")==0)
			material_selection = 0;
		else
		{
			std::string mat_id = project.materials[mat_index].id_name;

			for(int i = 0; i < material_choice.GetCount(); i++)
			{
				if(material_choice.Item(i).GetText().compare(mat_id)==0)
				{
					material_selection = i;
					break;
				}
			}
		}
	}

	if(material_selection >= 0)
		m_sphereActorProperties_propertyGridPage->GetPropertyByName(_("material_id"))->SetChoiceSelection(material_selection);
}

void SerenityEditorSerenity3D_Frame::setStageGrid(int stage_project_index)
{
	wxString stage_id = wxString::FromUTF8(project.stages[stage_project_index].id_name);

	m_stageProperties_propertyGridPage->GetPropertyByName(_("stage_id"))->SetValueFromString(stage_id);


	m_stageProperties_propertyGridPage->GetPropertyByName(_("skydome_hRes"))->SetValueFromInt(project.stages[stage_project_index].sky.hRes);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skydome_vRes"))->SetValueFromInt(project.stages[stage_project_index].sky.vRes);

	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_texture_pct"))->SetValue(project.stages[stage_project_index].sky.txPCT);

	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_sphere_pct"))->SetValue(project.stages[stage_project_index].sky.spherePCT);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_radius"))->SetValue(project.stages[stage_project_index].sky.dome_radius);

	wxPGChoices sky_choice;
	sky_choice.Clear();

	sky_choice.Add(_("NONE"));
	sky_choice.Add(_("BOX"));
	sky_choice.Add(_("DOME"));


	project.stages[stage_project_index].sky.type = ((project.stages[stage_project_index].sky.type < 0 || project.stages[stage_project_index].sky.type >= 3) ? 0 : project.stages[stage_project_index].sky.type);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_shape"))->SetChoices(sky_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_shape"))->SetChoiceSelection(project.stages[stage_project_index].sky.type);


	wxPGChoices texture_choice;
	getGridTextureList(&texture_choice);

	int tx_index = project.stages[stage_project_index].sky.dome_texture_index;
	int tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);

	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_dome_image_id"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("sky_dome_image_id"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.top_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_top_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_top_image"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.bottom_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_bottom_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_bottom_image"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.left_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_left_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_left_image"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.right_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_right_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_right_image"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.front_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_front_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_front_image"))->SetChoiceSelection(tx_choice_selection);

	tx_index = project.stages[stage_project_index].sky.back_texture_index;
	tx_choice_selection = getGridTextureSelection(tx_index, &texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_back_image"))->SetChoices(texture_choice);
	m_stageProperties_propertyGridPage->GetPropertyByName(_("skybox_back_image"))->SetChoiceSelection(tx_choice_selection);
}

int SerenityEditorSerenity3D_Frame::getGridTextureSelection(int texture_project_index, wxPGChoices* choice)
{
	if(texture_project_index < 0 || texture_project_index >= project.textures.size())
	{
		return 0;
	}

	wxString tx_id_name = project.textures[texture_project_index].id_name;

	if(tx_id_name.compare(_("")) == 0)
		return 0;

	for(int i = 0; i < choice->GetCount(); i++)
	{
		if(choice->GetLabel(i).compare(tx_id_name)==0)
		{
			return i;
		}
	}

	return 0;
}

void SerenityEditorSerenity3D_Frame::getGridTextureList(wxPGChoices* choices)
{
	choices->Clear();

	choices->Add(_("NONE"));

	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare("")!=0)
		{
			choices->Add(wxString::FromUTF8(project.textures[i].id_name));
		}
	}
}

void SerenityEditorSerenity3D_Frame::On_Stage_StageNodeSelected( wxTreeEvent& event )
{
	wxTreeItemId selected_item = event.GetItem();
	int stage_node_index = -1;
	int group_node_index = -1;
	int actor_node_index = -1;

	int node_type = RC_STAGE_NODE_NONE;

	for(int i = 0; i < stage_tree_nodes.size(); i++)
	{
		if(stage_tree_nodes[i].tree_item == selected_item)
		{
			node_type = RC_STAGE_NODE_STAGE;
			stage_node_index = i;
			break;
		}

		for(int actor = 0; actor < stage_tree_nodes[i].actors.size(); actor++)
		{
			if(stage_tree_nodes[i].actors[actor].tree_item == selected_item)
			{
				node_type = RC_STAGE_NODE_ACTOR;
				stage_node_index = i;
				actor_node_index = actor;
				break;
			}
		}

		for(int group = 0; group < stage_tree_nodes[i].groups.size(); group++)
		{
			if(stage_tree_nodes[i].groups[group].tree_item == selected_item)
			{
				node_type = RC_STAGE_NODE_GROUP;
				stage_node_index = i;
				group_node_index = group;
				break;
			}
		}
	}

	stageTabGrid_current_stage = -1;
	stageTabGrid_current_group = -1;
	stageTabGrid_current_actor = -1;

	switch(node_type)
	{
		case RC_STAGE_NODE_STAGE:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;

			stageTabGrid_current_stage = stage_project_index;

			m_stage_propertyGridManager->SelectPage(m_stageProperties_propertyGridPage);
			setStageGrid(stage_project_index);
		}
		break;

		case RC_STAGE_NODE_ACTOR:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;
			int actor_stage_index = stage_tree_nodes[stage_node_index].actors[actor_node_index].project_index;

			stageTabGrid_current_stage = stage_project_index;
			stageTabGrid_current_actor = actor_stage_index;

			if(stage_window != NULL && stage_project_index == stageTab_active_stage_project_index)
			{
				bool is_selected = false;
				for(int i = 0; i < stage_window->selected_actors.size(); i++)
				{
					if(stage_window->selected_actors[i].actor_index == actor_stage_index)
					{
						is_selected = true;
						break;
					}
				}

				if(!is_selected)
				{
					stage_window->selected_actors.clear();

					actor_object scene_obj;
					scene_obj.actor_index = actor_stage_index;
					scene_obj.id_name = project.stages[stage_project_index].actors[actor_stage_index].id_name;
					scene_obj.isSelected = true;
					scene_obj.node = project.stages[stage_project_index].actors[actor_stage_index].node;

					if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_LIGHT)
					{
						if(project.stages[stage_project_index].actors[actor_stage_index].icon_node)
						{
							scene_obj.use_override_size = true;
							scene_obj.override_box = project.stages[stage_project_index].actors[actor_stage_index].icon_node->getBoundingBox();
						}
					}

					stage_window->selected_actors.push_back(scene_obj);
				}
			}

			if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_ANIMATED)
			{
				m_stage_propertyGridManager->SelectPage(m_animatedActorProperties_propertyGridPage);
				setAnimatedActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_OCTREE)
			{
				m_stage_propertyGridManager->SelectPage(m_octreeActorProperties_propertyGridPage);
				setOctreeActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_LIGHT)
			{
				m_stage_propertyGridManager->SelectPage(m_lightActorProperties_propertyGridPage);
				setLightActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_BILLBOARD)
			{
				m_stage_propertyGridManager->SelectPage(m_billboardActorProperties_propertyGridPage);
				setBillboardActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_TERRAIN)
			{
				m_stage_propertyGridManager->SelectPage(m_terrainActorProperties_propertyGridPage);
				setTerrainActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_WATER)
			{
				m_stage_propertyGridManager->SelectPage(m_waterActorProperties_propertyGridPage);
				setWaterActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_PARTICLE)
			{
				m_stage_propertyGridManager->SelectPage(m_particleActorProperties_propertyGridPage);
				setParticleActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_CUBE)
			{
				m_stage_propertyGridManager->SelectPage(m_cubeActorProperties_propertyGridPage);
				setCubeActorGrid(stage_project_index, actor_stage_index);
			}
			else if(project.stages[stage_project_index].actors[actor_stage_index].type == SN_ACTOR_TYPE_SPHERE)
			{
				m_stage_propertyGridManager->SelectPage(m_sphereActorProperties_propertyGridPage);
				setSphereActorGrid(stage_project_index, actor_stage_index);
			}

			//TODO PLANE ACTORS

		}
		break;

		case RC_STAGE_NODE_GROUP:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;
			int group_stage_index = stage_tree_nodes[stage_node_index].groups[group_node_index].project_index;

			stageTabGrid_current_stage = stage_project_index;
			stageTabGrid_current_group = group_stage_index;

			m_stage_propertyGridManager->SelectPage(m_group_propertyGridPage);
		}
		break;

		default:
			m_stage_propertyGridManager->SelectPage(m_projectProperties_propertyGridPage);

			m_projectProperties_propertyGridPage->GetPropertyByName(_("project_name"))->SetValueFromString(project.project_name);
	}
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ShowGrid( wxCommandEvent& event )
{
	project.grid_visible = event.IsChecked();

	if(stage_window)
		stage_window->grid_visible = project.grid_visible;
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_SetGridSize( wxSpinEvent& event )
{
	project.grid_size = event.GetValue();

	if(stage_window)
		stage_window->setGridSize(project.grid_size);
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_SetGridSpacing( wxSpinEvent& event )
{
	project.grid_spacing = event.GetValue();

	if(stage_window)
		stage_window->setGridSpacing(project.grid_spacing);
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_SetGridColor( wxColourPickerEvent& event )
{
	project.grid_color = irr::video::SColor( event.GetColour().GetAlpha(),
											 event.GetColour().GetRed(),
											 event.GetColour().GetGreen(),
											 event.GetColour().GetBlue() ).color;

	if(stage_window)
		stage_window->setGridColor(project.grid_color);
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ShowAxisLines( wxCommandEvent& event )
{
	if(current_window)
		current_window->show_axis_lines = event.IsChecked();
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ShowAxisRings( wxCommandEvent& event )
{
	if(current_window)
		current_window->show_axis_rings = event.IsChecked();
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ShowViewCameraPosition( wxCommandEvent& event )
{
	if(current_window)
		current_window->show_camera_pos = event.IsChecked();
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ShowViewCameraRotation( wxCommandEvent& event )
{
	if(current_window)
		current_window->show_camera_rot = event.IsChecked();
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ViewCameraSpeed( wxSpinDoubleEvent& event )
{
	if(current_window)
		current_window->cam_move_speed = event.GetValue();
}

void SerenityEditorSerenity3D_Frame::On_StageSettings_ViewHUDColor( wxColourPickerEvent& event )
{
	if(current_window)
		current_window->hud_color = irr::video::SColor( event.GetColour().GetAlpha(),
														event.GetColour().GetRed(),
														event.GetColour().GetGreen(),
														event.GetColour().GetBlue() );
}



void SerenityEditorSerenity3D_Frame::updateToolSelection()
{
	for(int i = 0; i < stage_tools.size(); i++)
	{
		if(stage_tools[i]->GetKind() == wxITEM_CHECK)
		{
			stage_tools[i]->SetState(wxAUI_BUTTON_STATE_NORMAL);
		}
	}

	//This should always be true but better safe than sorry
	if(stage_tools_selection >= 0 && stage_tools_selection < stage_tools.size())
	{
		if(stage_tools[stage_tools_selection]->GetKind() == wxITEM_CHECK)
			stage_tools[stage_tools_selection]->SetState(wxAUI_BUTTON_STATE_CHECKED);
	}

	Refresh();
	Update();
}






int SerenityEditorSerenity3D_Frame::getStageToolIndex(wxAuiToolBarItem* toolbar_item)
{
	for(int i = 0; i < stage_tools.size(); i++)
	{
		if(stage_tools[i] == toolbar_item)
			return i;
	}
	return 0;
}

void SerenityEditorSerenity3D_Frame::OnS3DSelectClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_select_tool);
	updateToolSelection();
	current_window->stage_edit_tool = RC_EDIT_TOOL_SELECT;
}

void SerenityEditorSerenity3D_Frame::OnS3DBoxClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_boxSelect_tool);
	updateToolSelection();
	current_window->stage_edit_tool = RC_EDIT_TOOL_BOXSELECT;
}

void SerenityEditorSerenity3D_Frame::OnS3DMoveClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_move_tool);
	updateToolSelection();
	current_window->stage_edit_tool = RC_EDIT_TOOL_MOVE;
}

void SerenityEditorSerenity3D_Frame::OnS3DRotateClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_rotate_tool);
	updateToolSelection();
	current_window->stage_edit_tool = RC_EDIT_TOOL_ROTATE;
}

void SerenityEditorSerenity3D_Frame::OnS3DScaleClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_scale_tool);
	updateToolSelection();
	current_window->stage_edit_tool = RC_EDIT_TOOL_SCALE;
}

void SerenityEditorSerenity3D_Frame::OnS3DPlaneClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_plane_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DCubeClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_cube_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DSphereClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_sphere_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DCylinderClicked( wxCommandEvent& event )
{
	//stage_tools_selection = getStageToolIndex(m_prim3d_cylinder_tool);
	//updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DDumpClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_octreeActor_tool);
	updateToolSelection();

	SerenityEditor_NewOctree_Dialog* create_octree_win = new SerenityEditor_NewOctree_Dialog(this, &project);
	create_octree_win->ShowModal();
}

void SerenityEditorSerenity3D_Frame::OnS3DWizClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_animatedActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DBillboardClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_billboardActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DLightClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_lightActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DTerrainClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_terrainActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DWaterClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_waterActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DGrassClicked( wxCommandEvent& event )
{
	//stage_tools_selection = getStageToolIndex(m_geo_grass_tool);
	//updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DPathClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_path_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DEffectClicked( wxCommandEvent& event )
{
	if(!current_window)
		return;
	stage_tools_selection = getStageToolIndex(m_s3d_particleActor_tool);
	updateToolSelection();
}


//Stage Modes
void SerenityEditorSerenity3D_Frame::OnS3DModeEditClicked( wxCommandEvent& event )
{
	viewport_mode = RC_VIEWPORT_MODE_EDIT;
}

void SerenityEditorSerenity3D_Frame::OnS3DModeCameraClicked( wxCommandEvent& event )
{
	viewport_mode = RC_VIEWPORT_MODE_CAMERA;
}

void SerenityEditorSerenity3D_Frame::clearScene()
{
	if(!current_window)
		return;

	irr::scene::ISceneManager* smgr = current_window->GetDevice()->getSceneManager();
}

void SerenityEditorSerenity3D_Frame::OnNewProjectMenuSelection( wxCommandEvent& event )
{
	SerenityEditor_NewProject_Dialog* create_project_win = new SerenityEditor_NewProject_Dialog(this);
	create_project_win->ShowModal();

	if(create_project_win->createFlag)
	{
		project.clearProject();
		project = serenity_project(create_project_win->project_file.GetAbsolutePath().ToStdString(), create_project_win->project_name.ToStdString(), current_window->GetDevice());
	}
}

bool SerenityEditorSerenity3D_Frame::load_project(wxFileName pfile)
{
	project.clearProject();

	if(!current_window)
		return false;

	project = serenity_project("/home/n00b/test/stp/test.snprj", "", current_window->GetDevice());

	m_material_material_listBox->Clear();
	m_mesh_mesh_listBox->Clear();
	m_texture_textureList_listBox->Clear();
	m_material_textureLevel_listBox->Clear();

	//populate materials from project
	for(int i = 0; i < project.materials.size(); i++)
	{
		m_material_material_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.materials[i].id_name.c_str()));
	}

	//populate mesh from project
	for(int i = 0; i < project.meshes.size(); i++)
	{
		m_mesh_mesh_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.meshes[i].id_name.c_str()));
	}

	//populate textures from project
	for(int i = 0; i < project.textures.size(); i++)
	{
		m_texture_textureList_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.textures[i].id_name.c_str()));
	}

	//populate stages from project
    m_project_stage_treeCtrl->SetItemText(stage_tree_root, wxString::FromUTF8(project.project_name));
    m_project_stage_treeCtrl->DeleteChildren(stage_tree_root);
    stage_tree_nodes.clear();

	for(int i = 0; i < project.stages.size(); i++)
	{
		if(project.stages[i].id_name.compare("") != 0)
		{
			Serenity_StageNode tree_node;
			tree_node.active = false;
			tree_node.project_index = i;
			tree_node.node_type = RC_STAGE_NODE_STAGE;
			tree_node.stage_group = 0;
			tree_node.group_label = wxString::FromUTF8(project.stages[i].id_name);
			tree_node.parent_item = stage_tree_root;
			tree_node.tree_item = m_project_stage_treeCtrl->AppendItem(stage_tree_root, wxString::FromUTF8(project.stages[i].id_name), stage_tree_stageImage);

			int stage_index = stage_tree_nodes.size();
			stage_tree_nodes.push_back(tree_node);

			for(int group_index = 0; group_index < project.stages[i].groups.size(); group_index++)
			{
				Serenity_StageNode s_group;
				s_group.node_type = RC_STAGE_NODE_GROUP;
				s_group.group_label = wxString::FromUTF8(project.stages[i].groups[group_index].label);
				s_group.parent_item = tree_node.tree_item;
				s_group.active = false;
				s_group.project_index = -1;
				s_group.tree_item = m_project_stage_treeCtrl->AppendItem(tree_node.tree_item, s_group.group_label, stage_tree_groupImage);
				stage_tree_nodes[stage_index].groups.push_back(s_group);
				//wxMessageBox(_("Group: ") + s_group.group_label);
			}

			for(int ac_index = 0; ac_index < project.stages[i].actors.size(); ac_index++)
			{
				Serenity_StageNode s_actor_node;
				s_actor_node.node_type = RC_STAGE_NODE_ACTOR;
				s_actor_node.group_label = project.stages[i].actors[ac_index].group_name;
				s_actor_node.active = false;
				s_actor_node.project_index = ac_index; //index in stage.actors

				int a_group_index = -1;
				if(project.stages[i].actors[ac_index].group_name.compare("") != 0)
				{
					//search for actors group
					for(int g = 0; g < stage_tree_nodes[stage_index].groups.size(); g++)
					{
						if(stage_tree_nodes[stage_index].groups[g].group_label.compare(s_actor_node.group_label) == 0)
						{
							a_group_index = g;
							break;
						}
					}
				}

				if(a_group_index >= 0)
					s_actor_node.parent_item = stage_tree_nodes[stage_index].groups[a_group_index].tree_item;
				else
					s_actor_node.parent_item = tree_node.tree_item;

				s_actor_node.tree_item = m_project_stage_treeCtrl->AppendItem(s_actor_node.parent_item, wxString::FromUTF8(project.stages[i].actors[ac_index].id_name), stage_tree_assetImage );
				stage_tree_nodes[stage_index].actors.push_back(s_actor_node);
			}
		}
	}

    m_project_stage_treeCtrl->Expand(stage_tree_root);
    m_project_stage_treeCtrl->SetDoubleBuffered(true);

    return true;
}

void SerenityEditorSerenity3D_Frame::OnLoadProjectMenuSelection( wxCommandEvent& event )
{
	load_project(_("/home/n00b/test/stp/test.snprj"));

	return;
}

void SerenityEditorSerenity3D_Frame::OnStageViewportMouse( wxMouseEvent& event )
{
	return;
	//if(wxString::Format(_("%d"), event.GetEventType()).compare("10227")!=0 && wxString::Format(_("%d"), event.GetEventType()).compare("10226")!=0
	  // && wxString::Format(_("%d"), event.GetEventType()).compare("10228")!=0)
		//wxMessageBox(_("EVT DEBUG: ") + wxString::Format(_("%d"), event.GetEventType()));

	if(wxString::Format(_("%d"), event.GetEventType()).compare("10220")==0)
		wxMessageBox(_("LEFT"));

	if(event.GetEventType() == wxEVT_MOTION)
	{
		wxPoint pt = wxGetMousePosition();
		mouse_x = pt.x - m_stageViewport_panel->GetScreenPosition().x;
		mouse_y = pt.y - m_stageViewport_panel->GetScreenPosition().y;
	}
	else if(event.GetEventType() == wxEVT_LEFT_DOWN || event.GetEventType() == wxEVT_LEFT_UP)
	{
		mouse_button = ( event.GetEventType() == wxEVT_LEFT_DOWN ? RC_MOUSEBUTTON_LEFT : RC_MOUSEBUTTON_NONE);
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
	else if(event.GetEventType() == wxEVT_RIGHT_DOWN || event.GetEventType() == wxEVT_RIGHT_UP)
	{
		mouse_button = ( event.GetEventType() == wxEVT_RIGHT_DOWN ? RC_MOUSEBUTTON_RIGHT : RC_MOUSEBUTTON_NONE);
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
	else if(event.GetEventType() == wxEVT_MIDDLE_DOWN || event.GetEventType() == wxEVT_MIDDLE_UP)
	{
		return;
		mouse_button = ( event.GetEventType() == wxEVT_MIDDLE_DOWN ? RC_MOUSEBUTTON_MIDDLE : RC_MOUSEBUTTON_NONE);
		wxSize panel_size = m_stageViewport_panel->GetSize();
		viewport_camera_mouse_x = panel_size.GetWidth()/2;
		viewport_camera_mouse_y = panel_size.GetHeight()/2;

		if(mouse_button == RC_MOUSEBUTTON_MIDDLE && (!viewport_camera_active))
		{
			m_stageViewport_panel->CaptureMouse();
			HIDE_CURSOR;
			m_stageViewport_panel->WarpPointer(viewport_camera_mouse_x, viewport_camera_mouse_y);
			viewport_camera_active = true;
			wxMessageBox(_("HIDE"));
		}
		else if(viewport_camera_active)
		{
			m_stageViewport_panel->ReleaseMouse();
			SHOW_CURSOR;
			viewport_camera_active = false;
		}
		//wxMessageBox(_("Pos: ") + wxString::Format(_("%d"), mouse_x) + _(", ") + wxString::Format(_("%d"), mouse_y));
	}
}

void SerenityEditorSerenity3D_Frame::OnStageContainerMouse( wxMouseEvent& event )
{
	return;

	if(wxString::Format(_("%d"), event.GetEventType()).compare("10220")==0)
		wxMessageBox(_("LEFT"));

	int px = m_stageViewport_panel->GetPosition().x;
	int py = m_stageViewport_panel->GetPosition().y;

	int pw = m_stageViewport_panel->GetSize().GetWidth();
	int ph = m_stageViewport_panel->GetSize().GetHeight();

	if(event.LeftDown())
		wxMessageBox(_("inside"));
}

void SerenityEditorSerenity3D_Frame::OnStageViewportSetFocus( wxFocusEvent& event )
{
	//wxMessageBox(_("SET"));
}

void SerenityEditorSerenity3D_Frame::OnStageViewportKillFocus( wxFocusEvent& event )
{
	//wxMessageBox(_("KILL"));
}


void SerenityEditorSerenity3D_Frame::OnViewComboSelect( wxCommandEvent& event )
{
	wxString pov_selection = m_stagePOV_comboBox->GetStringSelection();
	//wxMessageBox(_("SELECT: ") + pov_selection);

	if(!stage_window)
	{
		return;
	}

	if(pov_selection.compare(_("Front"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_FRONT);

		stage_window->camera[0].camera.setPosition(0, 0, -100);
		stage_window->camera[0].camera.setRotation(0, 0, 0);
	}
	else if(pov_selection.compare(_("Right"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_RIGHT);

		stage_window->camera[0].camera.setPosition(-100, 0, 0);
        stage_window->camera[0].camera.setRotation(0, 90, 0);
	}
	else if(pov_selection.compare(_("Top"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_TOP);

		stage_window->camera[0].camera.setPosition(0, 100, 0);
        stage_window->camera[0].camera.setRotation(90, 0, 0);
	}
	else if(pov_selection.compare(_("Perspective"))==0)
	{
		stage_window->SetViews(RC_CAMERA_VIEW_PERSPECTIVE);

		stage_window->camera[0].camera.setPosition(0, 30, -40);
        stage_window->camera[0].camera.setRotation(0, 5, 0);
	}
	else
	{
		stage_window->SetViews(RC_CAMERA_VIEW_ALL, RC_CAMERA_VIEW_FRONT, RC_CAMERA_VIEW_RIGHT, RC_CAMERA_VIEW_TOP, RC_CAMERA_VIEW_PERSPECTIVE);

		stage_window->camera[0].camera.setPosition(0, 0, -100);
        stage_window->camera[0].camera.setRotation(0, 0, 0);

        stage_window->camera[1].camera.setPosition(-100, 0, 0);
        stage_window->camera[1].camera.setRotation(0, 90, 0);

        stage_window->camera[2].camera.setPosition(0, 100, 0);
        stage_window->camera[2].camera.setRotation(90, 0, 0);

        stage_window->camera[3].camera.setPosition(0, 30, -40);
        stage_window->camera[3].camera.setRotation(0, 5, 0);
	}
}


//---------------Mesh Tab------------------------

void SerenityEditorSerenity3D_Frame::On_Mesh_AnimationList_Select( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index >= 0 && meshTab_selected_mesh_project_index < project.meshes.size())
	{
		int n = meshTab_selected_mesh_project_index;

		//Make Sure animation ID is valid on current texture
		if(meshTab_active_animation_index >= 0 && meshTab_active_animation_index < project.meshes[n].animation.size())
		{
			if(!isValidID(wxString::FromUTF8(project.meshes[n].animation[meshTab_active_animation_index].id_name), RC_ID_ANIMATION, n))
			{
				wxMessageBox(_("Warning: Animation ID is invalid. A default Animation ID will be generated."));

				wxString id_name = m_mesh_animationID_textCtrl->GetValue();

				for(int i = 0; i < m_mesh_meshAnimation_listBox->GetCount(); i++)
				{
					if(m_mesh_meshAnimation_listBox->GetString(i).compare(id_name)==0)
					{
						project.meshes[n].animation[meshTab_active_animation_index].id_name = project.genMeshAnimationID(n).ToStdString();
						m_mesh_meshAnimation_listBox->SetString(i, wxString::FromUTF8(project.meshes[n].animation[meshTab_active_animation_index].id_name));
						break;
					}
				}
			}
		}
	}

	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		wxMessageBox(_("ERROR: Could not find mesh id"));
		return;
	}

	wxString id_name = event.GetString();

	int n = meshTab_selected_mesh_project_index;

	meshTab_active_animation_index = -1;

	for(int i = 0; i < project.meshes[n].animation.size(); i++)
	{
		if(project.meshes[n].animation[i].id_name.compare(id_name.ToStdString())==0)
		{
			meshTab_active_animation_index = i;
			break;
		}
	}

	int an_index = meshTab_active_animation_index;

	if(an_index < 0)
		return;

	if(project.meshes[n].isMD2 && (meshTab_active_animation_index < irr::scene::EMAT_COUNT))
	{
		m_mesh_animationID_textCtrl->SetValue( wxString::FromUTF8(project.meshes[n].animation[an_index].id_name.c_str()));
		m_mesh_animationStartFrame_textCtrl->SetValue( wxString::Format(_("%d"), -1));
		m_mesh_animationEndFrame_textCtrl->SetValue( wxString::Format(_("%d"), -1));
		m_mesh_animationSpeed_textCtrl->SetValue( wxString::FromDouble(-1));
	}
	else
	{
		m_mesh_animationID_textCtrl->SetValue( wxString::FromUTF8(project.meshes[n].animation[an_index].id_name.c_str()));
		m_mesh_animationStartFrame_textCtrl->SetValue( wxString::Format(_("%d"), project.meshes[n].animation[an_index].start_frame));
		m_mesh_animationEndFrame_textCtrl->SetValue( wxString::Format(_("%d"), project.meshes[n].animation[an_index].end_frame));
		m_mesh_animationSpeed_textCtrl->SetValue( wxString::FromDouble(project.meshes[n].animation[an_index].speed));
	}

	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();

	event.Skip();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Animation_AnimationID( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		wxMessageBox(_("ERROR: Could not find mesh id"));
		return;
	}

	int n = meshTab_selected_mesh_project_index;

	if(meshTab_active_animation_index < 0 || meshTab_active_animation_index >= project.meshes[n].animation.size())
	{
		//wxMessageBox(_("ERROR: Could not find animation id"));
		return;
	}

	if(project.meshes[n].isMD2 && (meshTab_active_animation_index < irr::scene::EMAT_COUNT))
		return;

	wxString id_name = wxString::FromUTF8(project.meshes[n].animation[meshTab_active_animation_index].id_name);

	for(int i = 0; i < m_mesh_meshAnimation_listBox->GetCount(); i++)
	{
		if(m_mesh_meshAnimation_listBox->GetString(i).compare(id_name)==0)
		{
			m_mesh_meshAnimation_listBox->SetString(i, event.GetString());
			project.meshes[n].animation[meshTab_active_animation_index].id_name = event.GetString().ToStdString();
			break;
		}
	}
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Animation_StartFrame( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		wxMessageBox(_("ERROR: Could not find mesh id"));
		return;
	}

	int n = meshTab_selected_mesh_project_index;

	if(meshTab_active_animation_index < 0 || meshTab_active_animation_index >= project.meshes[n].animation.size())
	{
		//wxMessageBox(_("ERROR: Could not find animation id"));
		return;
	}

	if(project.meshes[n].isMD2 && (meshTab_active_animation_index < irr::scene::EMAT_COUNT))
		return;

	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();

	event.GetString().ToInt(&project.meshes[n].animation[meshTab_active_animation_index].start_frame);
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Animation_EndFrame( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		wxMessageBox(_("ERROR: Could not find mesh id"));
		return;
	}

	int n = meshTab_selected_mesh_project_index;

	if(meshTab_active_animation_index < 0 || meshTab_active_animation_index >= project.meshes[n].animation.size())
	{
		//wxMessageBox(_("ERROR: Could not find animation id"));
		return;
	}

	if(project.meshes[n].isMD2 && (meshTab_active_animation_index < irr::scene::EMAT_COUNT))
		return;

	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();

	event.GetString().ToInt(&project.meshes[n].animation[meshTab_active_animation_index].end_frame);
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Animation_Speed( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		wxMessageBox(_("ERROR: Could not find mesh id"));
		return;
	}

	int n = meshTab_selected_mesh_project_index;

	if(meshTab_active_animation_index < 0 || meshTab_active_animation_index >= project.meshes[n].animation.size())
	{
		//wxMessageBox(_("ERROR: Could not find animation id"));
		return;
	}

	if(project.meshes[n].isMD2 && (meshTab_active_animation_index < irr::scene::EMAT_COUNT))
		return;

	double dval = 0;
	event.GetString().ToDouble(&dval);
	project.meshes[n].animation[meshTab_active_animation_index].speed = dval;

	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_MeshList_Select( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index >= 0 && meshTab_selected_mesh_project_index < project.meshes.size())
	{
		int n = meshTab_selected_mesh_project_index;

		if(!isValidID(wxString::FromUTF8(project.meshes[n].id_name.c_str()), RC_ID_MESH))
		{
			wxMessageBox(_("Warning: Mesh ID is invalid. A default Mesh ID will be generated."));
			project.meshes[n].id_name = project.genMeshID().ToStdString();
		}

		//Make Sure animation ID is valid on current texture
		if(meshTab_active_animation_index >= 0 && meshTab_active_animation_index < project.meshes[n].animation.size())
		{
			if(!isValidID(wxString::FromUTF8(project.meshes[n].animation[meshTab_active_animation_index].id_name), RC_ID_ANIMATION, n))
			{
				wxMessageBox(_("Warning: Animation ID is invalid. A default Animation ID will be generated."));
				project.meshes[n].animation[meshTab_active_animation_index].id_name = project.genMeshAnimationID(n).ToStdString();
			}
		}
	}

	meshTab_active_animation_index = -1;

	meshTab_selected_mesh_project_index = -1;
	wxString id_name = event.GetString();

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare(id_name.ToStdString())==0)
		{
			meshTab_selected_mesh_project_index = i;
			break;
		}
	}

	int n = meshTab_selected_mesh_project_index;

	m_mesh_meshID_textCtrl->SetValue(wxString::FromUTF8(project.meshes[n].id_name));
	m_mesh_meshFile_textCtrl->SetValue(wxString::FromUTF8(project.meshes[n].file));


	m_mesh_materialList_listBox->Clear();

	for(int i = 0; i < project.meshes[n].material_index.size(); i++)
	{
		int mat_index = project.meshes[n].material_index[i];

		if(mat_index >= 0 && mat_index < project.materials.size())
		{
			if(project.materials[mat_index].id_name.compare(_(""))==0)
				m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
			else
				m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":   ") + wxString::FromUTF8(project.materials[mat_index].id_name) );
		}
		else
			m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
	}

	m_mesh_meshAnimation_listBox->Clear();

	for(int i = 0; i < project.meshes[n].animation.size(); i++)
	{
		if(project.meshes[n].animation[i].id_name.compare("")==0)
			continue;

		m_mesh_meshAnimation_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.meshes[n].animation[i].id_name));
	}

	m_mesh_animationID_textCtrl->SetValue(_(""));
	m_mesh_animationStartFrame_textCtrl->SetValue(_(""));
	m_mesh_animationEndFrame_textCtrl->SetValue(_(""));
	m_mesh_animationSpeed_textCtrl->SetValue(_(""));

	if(animation_window)
	{
		animation_window->camera[0].camera.setPosition(0, 0, -100);
		animation_window->camera[0].camera.setRotation(0, 0, 0);
	}

	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Load_ButtonClick( wxCommandEvent& event )
{
	SerenityEditor_AddMesh_Dialog* dialog = new SerenityEditor_AddMesh_Dialog(this);

	dialog->model_path = project.project_path;
	dialog->model_path.AppendDir(_("models"));
	dialog->model_path.SetFullName(_(""));

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].file.compare("")!=0)
			dialog->project_files.push_back(project.meshes[i].file);
	}

	dialog->refresh_list();

	dialog->ShowModal();

	wxFileName fname = project.project_path;
	fname.AppendDir(_("data"));

	std::vector<serenity_project_dict_obj> param;
	serenity_project_dict_obj p_obj;

	wxString id_name = _("");

	for(int i = 0; i < dialog->selected_files.size(); i++)
	{
		p_obj.key = _("Mesh");
		p_obj.val = _("");
		param.push_back(p_obj);

		p_obj.key = _("id");
		id_name = project.genMeshID();
		p_obj.val = id_name;
		param.push_back(p_obj);

		p_obj.key = _("file");
		p_obj.val = dialog->selected_files[i];
		param.push_back(p_obj);

		fname.SetFullName(id_name + _(".snmd"));
		if(fname.Exists())
			wxRemoveFile(fname.GetAbsolutePath());

		fname.SetFullName(id_name + _(".sna"));
		if(fname.Exists())
			wxRemoveFile(fname.GetAbsolutePath());

		int mesh_index = project.load_mesh(param);

		if(mesh_index >= 0)
		{
			if(project.meshes[mesh_index].id_name.compare("")!=0)
				m_mesh_mesh_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.meshes[mesh_index].id_name));
		}
	}

	project.resolve_materialReferences();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Remove_ButtonClick( wxCommandEvent& event )
{
	int n = meshTab_selected_mesh_project_index;

	if(n < 0 || n >= project.meshes.size())
		return;

	if(project.meshes[n].mesh)
	{
		//project.meshes[n].mesh->drop();
	}

	project.meshes[n].mesh = NULL;

	wxFileName fname = project.project_path;
	fname.AppendDir(_("data"));

	fname.SetFullName(wxString::FromUTF8(project.meshes[n].id_name) + _(".snmd"));
	if(fname.Exists())
		wxRemoveFile(fname.GetAbsolutePath());

	fname.SetFullName(wxString::FromUTF8(project.meshes[n].id_name) + _(".sna"));
	if(fname.Exists())
		wxRemoveFile(fname.GetAbsolutePath());

	project.meshes[n].id_name = "";
	project.meshes[n].file = "";

	m_mesh_mesh_listBox->Clear();

	for(int i = 0; i < project.meshes.size(); i++)
	{
		if(project.meshes[i].id_name.compare("") != 0)
		{
			m_mesh_mesh_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.meshes[i].id_name));
		}
	}

	m_mesh_mesh_listBox->Update();

	meshTab_selected_mesh_project_index = -1;
	meshTab_active_animation_index = -1;
	meshTab_isPlaying = false;

	meshTab_preview_obj.animation_change = true;

	updatePreviewMesh();


	//set mesh for any actor using this mesh to -1
	for(int i = 0; i < project.stages.size(); i++)
	{
		for(int ac = 0; ac < project.stages[i].actors.size(); ac++)
		{
			if(project.stages[i].actors[ac].id_name.compare(_(""))==0)
				continue;

			if(project.stages[i].actors[ac].mesh_index == n)
			{
				project.stages[i].actors[ac].mesh_index = -1;
				project.stages[i].actors[ac].animation_index = -1;
			}
		}
	}
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Save_ButtonClick( wxCommandEvent& event )
{
	if(project.save_mesh_properties(meshTab_selected_mesh_project_index))
	{
		wxMessageBox(_("Saved Mesh Properties on Mesh(") + wxString::FromUTF8(project.meshes[meshTab_selected_mesh_project_index].id_name) + _(")"));
	}
	else
	{
		wxMessageBox(_("Failed to saved Mesh Properties on Mesh(") + wxString::FromUTF8(project.meshes[meshTab_selected_mesh_project_index].id_name) + _(")"));
	}
}

void SerenityEditorSerenity3D_Frame::On_Mesh_MeshID( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
	{
		return;
	}


	int n = meshTab_selected_mesh_project_index;

	project.meshes[n].id_name = m_mesh_meshID_textCtrl->GetValue().ToStdString();

	int current_list_item = m_mesh_mesh_listBox->GetSelection();

	if(current_list_item < 0 && current_list_item >= m_mesh_mesh_listBox->GetCount())
		return;

	m_mesh_mesh_listBox->SetString(current_list_item, wxString::FromUTF8(project.meshes[n].id_name.c_str()));

	m_mesh_mesh_listBox->Update();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_AddMaterial( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	int mat_num = project.meshes[n].material_index.size();
	project.meshes[n].material_index.push_back(-1);

	m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), mat_num) + _(":") );
}

void SerenityEditorSerenity3D_Frame::On_Mesh_RemoveMaterial( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	project.meshes[n].material_index.pop_back();

	m_mesh_materialList_listBox->Clear();

	for(int i = 0; i < project.meshes[n].material_index.size(); i++)
	{
		int mat_index = project.meshes[n].material_index[i];

		if(mat_index >= 0 && mat_index < project.materials.size())
		{
			if(project.materials[mat_index].id_name.compare(_(""))==0)
				m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
			else
				m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":   ") + wxString::FromUTF8(project.materials[mat_index].id_name) );
		}
		else
			m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
	}

	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_SetMaterial( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	int mat_num = m_mesh_materialList_listBox->GetSelection();

	if(mat_num < 0 || mat_num >= m_mesh_materialList_listBox->GetCount())
		return;

	if(mat_num >= project.meshes[n].material_index.size())
		return;

	SerenityEditor_SetMeshMaterialLevel_Dialog* dialog = new SerenityEditor_SetMeshMaterialLevel_Dialog(this);

	for(int i = 0; i < project.materials.size(); i++)
	{
		if(project.materials[i].id_name.compare("")!=0)
			dialog->id_list.push_back( wxString::FromUTF8(project.materials[i].id_name));
	}

	dialog->refresh_list();
	dialog->ShowModal();

	if(dialog->selected_material_id.compare(_("")) != 0)
	{
		m_mesh_materialList_listBox->Clear();

		wxString id_name = dialog->selected_material_id;

		for(int i = 0; i < project.materials.size(); i++)
		{
			if(project.materials[i].id_name.compare(id_name.ToStdString())==0)
			{
				project.meshes[n].material_index[mat_num] = i;
				break;
			}
		}

		for(int i = 0; i < project.meshes[n].material_index.size(); i++)
		{
			int mat_index = project.meshes[n].material_index[i];

			if(mat_index >= 0 && mat_index < project.materials.size())
			{
				if(project.materials[mat_index].id_name.compare(_(""))==0)
					m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
				else
					m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":   ") + wxString::FromUTF8(project.materials[mat_index].id_name) );
			}
			else
				m_mesh_materialList_listBox->AppendAndEnsureVisible( _("Material ") + wxString::Format(_("%d"), i) + _(":"));
		}
	}

	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_Material_Clear( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	int mat_num = m_mesh_materialList_listBox->GetSelection();

	if(mat_num < 0 || mat_num >= m_mesh_materialList_listBox->GetCount())
		return;

	if(mat_num >= project.meshes[n].material_index.size())
		return;


	m_mesh_materialList_listBox->SetString(mat_num, _("Material ") + wxString::Format(_("%d"), mat_num) + _(":"));
	project.meshes[n].material_index[mat_num] = -1;

	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_previewPlay( wxCommandEvent& event )
{
	meshTab_isPlaying = true;
	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_previewStop( wxCommandEvent& event )
{
	meshTab_isPlaying = false;
	meshTab_preview_obj.animation_change = true;
	updatePreviewMesh();
}

void SerenityEditorSerenity3D_Frame::On_Mesh_NewAnimation( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	rc_animation animation_obj;
	animation_obj.id_name = project.genMeshAnimationID(n).ToStdString();
	animation_obj.start_frame = 0;
	animation_obj.end_frame = 0;
	animation_obj.speed = 0;

	project.meshes[n].animation.push_back(animation_obj);
	m_mesh_meshAnimation_listBox->AppendAndEnsureVisible(animation_obj.id_name);
}

void SerenityEditorSerenity3D_Frame::On_Mesh_DeleteAnimation( wxCommandEvent& event )
{
	if(meshTab_selected_mesh_project_index < 0 || meshTab_selected_mesh_project_index >= project.meshes.size())
		return;

	int n = meshTab_selected_mesh_project_index;

	int ani_index = meshTab_active_animation_index;
	int list_item = m_mesh_meshAnimation_listBox->GetSelection();

	if(ani_index < 0 || ani_index >= project.meshes[n].animation.size())
		return;

	project.meshes[n].animation[ani_index].id_name = "";

	m_mesh_meshAnimation_listBox->Clear();

	for(int i = 0; i < project.meshes[n].animation.size(); i++)
	{
		if(project.meshes[n].animation[i].id_name.compare("") != 0)
		{
			m_mesh_meshAnimation_listBox->AppendAndEnsureVisible(project.meshes[n].animation[i].id_name);
		}
	}

	if(list_item >= m_mesh_meshAnimation_listBox->GetCount())
	{
		list_item = m_mesh_meshAnimation_listBox->GetCount()-1;
	}

	meshTab_active_animation_index = -1;
	if(list_item >= 0)
	{
		m_mesh_meshAnimation_listBox->SetSelection(list_item);
		std::string id_name = m_mesh_meshAnimation_listBox->GetString(list_item).ToStdString();

		for(int i = 0; i < project.meshes[n].animation.size(); i++)
		{
			if(project.meshes[n].animation[i].id_name.compare(id_name)==0)
			{
				meshTab_active_animation_index = i;
				break;
			}
		}
	}

	//set active animation for any actor using this mesh to -1
	for(int i = 0; i < project.stages.size(); i++)
	{
		for(int ac = 0; ac < project.stages[i].actors.size(); ac++)
		{
			if(project.stages[i].actors[ac].id_name.compare(_(""))==0)
				continue;

			if(project.stages[i].actors[ac].mesh_index == n)
			{
				project.stages[i].actors[ac].animation_index = -1;
			}
		}
	}
}



void SerenityEditorSerenity3D_Frame::clearMeshMaterialList()
{
}

void SerenityEditorSerenity3D_Frame::appendMeshMaterialList(int material_index)
{
}


//------------MATERIALS TAB--------------------
void SerenityEditorSerenity3D_Frame::On_Material_NewMaterial_ButtonClicked( wxCommandEvent& event )
{
	rc_material new_material;
	new_material.id_name = project.genMaterialID().ToStdString();
	new_material.file = new_material.id_name + ".snmtl";

	project.materials.push_back(new_material);

	m_material_material_listBox->AppendAndEnsureVisible(wxString::FromUTF8(new_material.id_name));
}

void SerenityEditorSerenity3D_Frame::On_Material_LoadMaterial_ButtonClicked( wxCommandEvent& event )
{
	SerenityEditor_AddMaterial_Dialog* dialog = new SerenityEditor_AddMaterial_Dialog(this);

	for(int i = 0; i < project.materials.size(); i++)
	{
		if(project.materials[i].file.compare(_(""))!=0)
			dialog->project_files.push_back(wxString::FromUTF8(project.materials[i].file));
	}

	dialog->material_path = project.project_path;
	dialog->material_path.AppendDir(_("materials"));
	dialog->material_path.SetFullName(_(""));
	dialog->refresh_list();

	dialog->ShowModal();


	std::vector<serenity_project_dict_obj> param;
	serenity_project_dict_obj param_obj;

	for(int i = 0; i < dialog->selected_files.size(); i++)
	{
		param.clear();

		param_obj.key = _("Material");
		param_obj.val = _("");
		param.push_back(param_obj);

		param_obj.key = _("id");
		param_obj.val = project.genMaterialID();
		param.push_back(param_obj);

		param_obj.key = _("file");
		param_obj.val = dialog->selected_files[i];

		bool mat_file_inUse = false;

		//flag file already in use
		for(int mf = 0; mf < project.materials.size(); mf++)
		{
			if(project.materials[mf].file.compare(param_obj.val)==0)
			{
				mat_file_inUse = true;
				break;
			}
		}

		param.push_back(param_obj);

		int mat_index = project.load_material(param);

		if(mat_file_inUse)
		{
			wxString tmp_name = wxString::FromUTF8(project.materials[mat_index].file.c_str());
			tmp_name.Replace(_(".snmtl"), _(""));
			project.materials[mat_index].file = project.genMaterialFileName(tmp_name).ToStdString();
		}

		if(mat_index < 0 || mat_index >= project.materials.size())
		{
			wxMessageBox(_("Failed to Load Material (") + dialog->selected_files[i] + _(")"));
		}
	}

	refreshMaterialList();
}

void SerenityEditorSerenity3D_Frame::On_Material_SaveMaterial_ButtonClicked( wxCommandEvent& event )
{
	project.save_material(materialTab_selected_material_project_index);
}

void SerenityEditorSerenity3D_Frame::refreshMaterialList()
{
	m_material_material_listBox->Clear();

	for(int i = 0; i < project.materials.size(); i++)
	{
		if(project.materials[i].id_name.compare(_(""))!=0)
			m_material_material_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.materials[i].id_name));
	}
}

void SerenityEditorSerenity3D_Frame::On_Material_RemoveMaterial_ButtonClicked( wxCommandEvent& event )
{
	if(materialTab_selected_material_project_index < 0 || materialTab_selected_material_project_index >= project.materials.size())
	{
		return;
	}

	for(int i = 0; i < project.meshes.size(); i++)
	{
		for(int m = 0; m < project.meshes[i].material_index.size(); m++)
		{
			if(project.meshes[i].material_index[m] == materialTab_selected_material_project_index)
			{
				project.meshes[i].material_index[m] = -1;
			}
		}
	}

	project.materials[materialTab_selected_material_project_index].id_name = "";
	project.materials[materialTab_selected_material_project_index].file = "";
	project.materials[materialTab_selected_material_project_index].texture_id.clear();

	refreshMaterialList();

	materialTab_selected_material_project_index = -1;

	event.Skip();
}


void SerenityEditorSerenity3D_Frame::On_Material_MaterialList_Select( wxCommandEvent& event )
{
	if(materialTab_selected_material_project_index >= 0 && materialTab_selected_material_project_index < project.materials.size())
	{
		if(!isValidID(wxString::FromUTF8(project.materials[materialTab_selected_material_project_index].id_name.c_str()), RC_ID_MATERIAL))
		{
			wxMessageBox(_("Warning: Material ID is invalid. A default Material ID will be generated."));
			project.materials[materialTab_selected_material_project_index].id_name = project.genMaterialID().ToStdString();

			refreshMaterialList();
		}
	}

	materialTab_selected_material_project_index = -1;
	wxString id_name = event.GetString();

	for(int i = 0; i < project.materials.size(); i++)
	{
		if(id_name.compare(wxString::FromUTF8(project.materials[i].id_name))==0)
		{
			materialTab_selected_material_project_index = i;
		}
	}

	if(materialTab_selected_material_project_index < 0 || materialTab_selected_material_project_index >= project.materials.size())
	{
		wxMessageBox(_("Material (") + id_name + _(") does not match a project material id"));
		return;
	}

	int n = materialTab_selected_material_project_index;

	m_material_id_textCtrl->SetValue(wxString::FromUTF8(project.materials[n].id_name));

	m_material_materialFile_textCtrl->SetValue(wxString::FromUTF8(project.materials[n].file));

	for(int i = 0; i < rc_material_types_list.size(); i++)
	{
		if(project.materials[n].material.MaterialType == rc_material_types_list[i].val)
		{
			m_material_type_comboBox->SetValue(wxString::FromUTF8(rc_material_types_list[i].key));
			break;
		}
	}

	wxColor ambient(project.materials[n].material.AmbientColor.getRed(),
					project.materials[n].material.AmbientColor.getGreen(),
					project.materials[n].material.AmbientColor.getBlue(),
					project.materials[n].material.AmbientColor.getAlpha());
	m_material_ambient_colourPicker->SetColour(ambient);

	wxColor diffuse(project.materials[n].material.DiffuseColor.getRed(),
					project.materials[n].material.DiffuseColor.getGreen(),
					project.materials[n].material.DiffuseColor.getBlue(),
					project.materials[n].material.DiffuseColor.getAlpha());
	m_material_diffuse_colourPicker->SetColour(diffuse);

	wxColor emissive(project.materials[n].material.EmissiveColor.getRed(),
					 project.materials[n].material.EmissiveColor.getGreen(),
					 project.materials[n].material.EmissiveColor.getBlue(),
					 project.materials[n].material.EmissiveColor.getAlpha());
	m_material_emissive_colourPicker->SetColour(emissive);

	wxColor specular(project.materials[n].material.SpecularColor.getRed(),
					 project.materials[n].material.SpecularColor.getGreen(),
					 project.materials[n].material.SpecularColor.getBlue(),
					 project.materials[n].material.SpecularColor.getAlpha());
	m_material_specular_colourPicker->SetColour(specular);


	for(int i = 0; i < rc_anti_alias_types_list.size(); i++)
	{
		if(project.materials[n].material.AntiAliasing == rc_anti_alias_types_list[i].val)
		{
			m_material_antiAlias_comboBox->SetValue(wxString::FromUTF8(rc_anti_alias_types_list[i].key));
			break;
		}
	}


	m_material_backFaceCulling_checkBox->SetValue(project.materials[n].material.BackfaceCulling);

	m_material_frontFaceCulling_checkBox->SetValue(project.materials[n].material.FrontfaceCulling);

	m_material_blendFactor_spinCtrlDouble->SetValue(project.materials[n].material.BlendFactor);


	for(int i = 0; i < rc_blendmode_types_list.size(); i++)
	{
		if(project.materials[n].material.BlendOperation == rc_blendmode_types_list[i].val)
		{
			m_material_blendMode_comboBox->SetValue(wxString::FromUTF8(rc_blendmode_types_list[i].key));
			break;
		}
	}


	for(int i = 0; i < rc_colormask_types_list.size(); i++)
	{
		if(project.materials[n].material.ColorMask == rc_colormask_types_list[i].val)
		{
			m_material_colorMask_comboBox->SetValue(wxString::FromUTF8(rc_colormask_types_list[i].key));
			break;
		}
	}


	for(int i = 0; i < rc_colormode_types_list.size(); i++)
	{
		if(project.materials[n].material.ColorMaterial == rc_colormode_types_list[i].val)
		{
			m_material_colorMode_comboBox->SetValue(wxString::FromUTF8(rc_colormode_types_list[i].key));
			break;
		}
	}


	m_material_fog_checkBox->SetValue(project.materials[n].material.FogEnable);

	m_material_gouradShading_checkBox->SetValue(project.materials[n].material.GouraudShading);

	m_material_lighting_checkBox->SetValue(project.materials[n].material.Lighting);

	m_material_normalize_checkBox->SetValue(project.materials[n].material.NormalizeNormals);

	m_material_pointCloud_checkBox->SetValue(project.materials[n].material.PointCloud);

	m_material_shineness_spinCtrl->SetValue(project.materials[n].material.Shininess);


	//TEXTURE LEVELS
	setMaterialTextureLevels();

	updateTestMesh();

	event.Skip();
}

void SerenityEditorSerenity3D_Frame::updateTestMesh()
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	if(test_material_mesh && current_window)
	{
		test_material_mesh->getMaterial(0) = project.materials[n].material;
	}
}

void SerenityEditorSerenity3D_Frame::setMaterialTextureLevels()
{
	m_material_textureLevel_listBox->Clear();
	texture_levels.clear();

	if(materialTab_selected_material_project_index < 0 || materialTab_selected_material_project_index >= project.materials.size())
		return;

	int n = materialTab_selected_material_project_index;

	for(int i = 0; i < project.materials[n].texture_id.size(); i++)
	{
		Serenity_TextureLevel tx_level;
		tx_level.level = i;

		wxString texture_id_name = _("[NULL]");
		wxString texture_file = _("");
		if(project.materials[n].texture_id[i] >= 0 && project.materials[n].texture_id[i] < project.textures.size())
		{
			texture_id_name = wxString::FromUTF8(project.textures[ project.materials[n].texture_id[i] ].id_name);
			texture_file = wxString::FromUTF8(project.textures[ project.materials[n].texture_id[i] ].file);
		}

		wxString property_name = _("TEXTURE ") + wxString::Format(_("%d"), i) + _(":   ") + texture_id_name;
		m_material_textureLevel_listBox->AppendAndEnsureVisible(property_name);
		tx_level.list_item = property_name;
		texture_levels.push_back(tx_level);
		//tx_level.property_item = m_material_textureLevel_propertyGrid->Append( new wxImageFileProperty( property_name, wxT("Propety_Name") ) );
	}
}


void SerenityEditorSerenity3D_Frame::On_Material_MaterialID_Update( wxCommandEvent& event )
{
	if(materialTab_selected_material_project_index < 0 || materialTab_selected_material_project_index >= project.materials.size())
	{
		return;
	}


	int n = materialTab_selected_material_project_index;

	project.materials[n].id_name = m_material_id_textCtrl->GetValue().ToStdString();

	int current_list_item = m_material_material_listBox->GetSelection();

	if(current_list_item < 0 && current_list_item >= m_material_material_listBox->GetCount())
		return;

	m_material_material_listBox->SetString(current_list_item, wxString::FromUTF8(project.materials[n].id_name.c_str()));

	m_material_material_listBox->Update();

}

void SerenityEditorSerenity3D_Frame::On_Material_MaterialType_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	for(int i = 0; i < rc_material_types_list.size(); i++)
	{
		if(rc_material_types_list[i].key.compare(m_material_type_comboBox->GetValue().ToStdString())==0)
		{
			project.materials[n].material.MaterialType = rc_material_types_list[i].val;
			break;
		}
	}

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Ambient_Update( wxColourPickerEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.AmbientColor = irr::video::SColor(m_material_ambient_colourPicker->GetColour().GetAlpha(),
																	m_material_ambient_colourPicker->GetColour().GetRed(),
																	m_material_ambient_colourPicker->GetColour().GetGreen(),
																	m_material_ambient_colourPicker->GetColour().GetBlue());

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Diffuse_Update( wxColourPickerEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.DiffuseColor = irr::video::SColor(m_material_diffuse_colourPicker->GetColour().GetAlpha(),
																	m_material_diffuse_colourPicker->GetColour().GetRed(),
																	m_material_diffuse_colourPicker->GetColour().GetGreen(),
																	m_material_diffuse_colourPicker->GetColour().GetBlue());

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Emissive_Update( wxColourPickerEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.EmissiveColor = irr::video::SColor(m_material_emissive_colourPicker->GetColour().GetAlpha(),
																	 m_material_emissive_colourPicker->GetColour().GetRed(),
																	 m_material_emissive_colourPicker->GetColour().GetGreen(),
																	 m_material_emissive_colourPicker->GetColour().GetBlue());

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Specular_Update( wxColourPickerEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.SpecularColor = irr::video::SColor(m_material_specular_colourPicker->GetColour().GetAlpha(),
																	 m_material_specular_colourPicker->GetColour().GetRed(),
																	 m_material_specular_colourPicker->GetColour().GetGreen(),
																	 m_material_specular_colourPicker->GetColour().GetBlue());

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_AntiAlias_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	for(int i = 0; i < rc_anti_alias_types_list.size(); i++)
	{
		if(m_material_antiAlias_comboBox->GetValue().compare(wxString::FromUTF8(rc_anti_alias_types_list[i].key))==0)
		{
			project.materials[n].material.AntiAliasing = rc_anti_alias_types_list[i].val;
			break;
		}
	}

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_BackfaceCulling_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.BackfaceCulling = m_material_backFaceCulling_checkBox->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_FrontfaceCulling_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.FrontfaceCulling = m_material_frontFaceCulling_checkBox->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_BlendFactor_Update( wxSpinDoubleEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.BlendFactor = m_material_blendFactor_spinCtrlDouble->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_BlendMode_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	for(int i = 0; i < rc_blendmode_types_list.size(); i++)
	{
		if(m_material_blendMode_comboBox->GetValue().compare(wxString::FromUTF8(rc_blendmode_types_list[i].key))==0)
		{
			project.materials[n].material.BlendOperation = rc_blendmode_types_list[i].val;
			break;
		}
	}

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_ColorMask_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	for(int i = 0; i < rc_colormask_types_list.size(); i++)
	{
		if(m_material_colorMask_comboBox->GetValue().compare( wxString::FromUTF8(rc_colormask_types_list[i].key)) == 0)
		{
			project.materials[n].material.ColorMask = rc_colormask_types_list[i].val;
			break;
		}
	}

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_ColorMode_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	for(int i = 0; i < rc_colormode_types_list.size(); i++)
	{
		if(m_material_colorMode_comboBox->GetValue().compare( wxString::FromUTF8(rc_colormode_types_list[i].key) ) == 0)
		{
			project.materials[n].material.ColorMaterial = rc_colormode_types_list[i].val;
			break;
		}
	}

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Fog_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	project.materials[n].material.FogEnable = m_material_fog_checkBox->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_GouradShading_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.GouraudShading = m_material_gouradShading_checkBox->GetValue();
}

void SerenityEditorSerenity3D_Frame::On_Material_Lighting_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.Lighting = m_material_lighting_checkBox->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_Normalize_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.NormalizeNormals = m_material_normalize_checkBox->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_PointCloud_Update( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.PointCloud = m_material_pointCloud_checkBox->GetValue();

	updateTestMesh();
}


void SerenityEditorSerenity3D_Frame::On_Material_Shineness_Update( wxSpinEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].material.Shininess = m_material_shineness_spinCtrl->GetValue();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_previewNoLight_Selected( wxCommandEvent& event )
{
	if(!test_material_light)
		return;

	test_material_light->setVisible(false);
}

void SerenityEditorSerenity3D_Frame::On_Material_previewDirectionlight_Selected( wxCommandEvent& event )
{
	if(!test_material_light)
		return;

	test_material_light->setVisible(true);
	test_material_light->setRotation(irr::core::vector3df(-20, 0, 0));
	test_material_light->setLightType(irr::video::ELT_DIRECTIONAL);
}

void SerenityEditorSerenity3D_Frame::On_Material_previewPointlight_Selected( wxCommandEvent& event )
{
	if(!test_material_light)
		return;

	test_material_light->setVisible(true);
	test_material_light->setLightType(irr::video::ELT_POINT);
}

void SerenityEditorSerenity3D_Frame::OnSetMaterialPreviewMesh( wxCommandEvent& event )
{
	if(!current_window)
		return;

	SerenityEditor_SetMaterialPreviewMesh_Dialog* dialog = new SerenityEditor_SetMaterialPreviewMesh_Dialog(this);

	for(int i = 0; i < project.meshes.size(); i++)
	{
		dialog->mesh_list.push_back(project.meshes[i].id_name);
	}

	dialog->refresh_list();

	dialog->ShowModal();

	wxString id_name = dialog->selected_mesh_id;

	if(id_name.compare(_(""))==0)
		return;

	if(test_material_mesh)
		test_material_mesh->remove();

	test_material_mesh = NULL;

	if(id_name.compare(_("[DEFAULT_CUBE]"))==0)
	{
		test_material_mesh = current_window->GetDevice()->getSceneManager()->addCubeSceneNode();
	}
	else if(id_name.compare(_("[DEFAULT_SPHERE]"))==0)
	{
		test_material_mesh = current_window->GetDevice()->getSceneManager()->addSphereSceneNode();
	}
	else
	{
		for(int i = 0; i < project.meshes.size(); i++)
		{
			if(project.meshes[i].id_name.compare(id_name.ToStdString())==0)
			{
				if(project.meshes[i].mesh)
				{
					test_material_mesh = current_window->GetDevice()->getSceneManager()->addMeshSceneNode(project.meshes[i].mesh);
					break;
				}
			}
		}
	}

	if(test_material_mesh)
	{
		updateTestMesh();
	}
}

void SerenityEditorSerenity3D_Frame::On_Material_previewSettings_Selected( wxCommandEvent& event )
{
	if(!material_window)
		return;

	SerenityEditor_MaterialPreviewSettings_Dialog * dialog = new SerenityEditor_MaterialPreviewSettings_Dialog(this);

	dialog->setFields(material_preview_camera_speed, material_preview_camera_distance, material_preview_light_radius);

	dialog->ShowModal();

	if(!dialog->apply_changes)
		return;

	material_preview_camera_speed = dialog->camera_speed;
	material_preview_camera_distance = ( dialog->camera_distance < 0 ? dialog->camera_distance * -1: dialog->camera_distance );
	material_preview_light_radius = dialog->light_radius;

	if(material_window)
	{
		material_window->camera[0].camera.setPosition(0, 7, -1 * material_preview_camera_distance);
		material_window->camera[0].camera.setRotation(26, 0, 0);
		material_window->material_view_camera_speed = material_preview_camera_speed;
	}

	if(test_material_light)
		test_material_light->setRadius(material_preview_light_radius);
}





void SerenityEditorSerenity3D_Frame::On_Material_AddTextureLevel_ButtonClicked( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	project.materials[n].texture_id.push_back(-1);
	setMaterialTextureLevels();
}

void SerenityEditorSerenity3D_Frame::On_Material_RemoveTextureLevel_ButtonClicked( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	int t_level = project.materials[n].texture_id.size()-1;

	if(t_level < 0)
		return;

	project.materials[n].material.setTexture(t_level, NULL);
	project.materials[n].texture_id.pop_back();
	texture_levels.pop_back();

	setMaterialTextureLevels();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_SetTextureLevel_ButtonClicked( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	int t_level = m_material_textureLevel_listBox->GetSelection();

	if(t_level < 0 || t_level >= project.materials[n].texture_id.size())
		return;

	SerenityEditor_SetMaterialTextureLevel_Dialog * dialog = new SerenityEditor_SetMaterialTextureLevel_Dialog(this);

	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare("")!=0)
			dialog->id_list.push_back(wxString::FromUTF8(project.textures[i].id_name));
	}

	dialog->refresh_list();
	dialog->ShowModal();

	wxString selected_texture = dialog->selected_texture_id;

	if(selected_texture.compare(_(""))==0)
		return;


	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare(selected_texture.ToStdString())==0)
		{
			project.materials[n].texture_id[t_level] = i;
			project.materials[n].material.setTexture(t_level, NULL);

			if(project.textures[i].texture)
				project.materials[n].material.setTexture(t_level, project.textures[i].texture);

			break;
		}
	}

	setMaterialTextureLevels();

	updateTestMesh();
}

void SerenityEditorSerenity3D_Frame::On_Material_ClearTextureLevel_ButtonClicked( wxCommandEvent& event )
{
	int n = materialTab_selected_material_project_index;

	if(n < 0 || n >= project.materials.size())
		return;

	int t_level = m_material_textureLevel_listBox->GetSelection();

	if(t_level < 0 || t_level >= project.materials[n].texture_id.size())
		return;

	project.materials[n].texture_id[t_level] = -1;
	project.materials[n].material.setTexture(t_level, NULL);

	setMaterialTextureLevels();

	updateTestMesh();
}

//-------------------TEXTURE TAB-------------------------


void SerenityEditorSerenity3D_Frame::On_Texture_AddTexture_ButtonClicked( wxCommandEvent& event )
{
	SerenityEditor_AddTexture_Dialog * dialog = new SerenityEditor_AddTexture_Dialog(this);

	dialog->texture_path = project.project_path;
	dialog->texture_path.AppendDir(_("textures"));
	dialog->texture_path.SetFullName(_(""));

	for(int i = 0; i < project.textures.size(); i++)
	{
		dialog->project_files.push_back(wxString::FromUTF8(project.textures[i].file));
	}

	dialog->refresh_list();
	dialog->ShowModal();

	std::vector<serenity_project_dict_obj> param;
	serenity_project_dict_obj param_obj;

	for(int i = 0; i < dialog->selected_files.size(); i++)
	{
		param.clear();

		param_obj.key = _("Image");
		param_obj.val = _("");
		param.push_back(param_obj);

		param_obj.key = _("id");
		param_obj.val = project.genTextureID();
		param.push_back(param_obj);

		param_obj.key = _("file");
		param_obj.val = dialog->selected_files[i];
		param.push_back(param_obj);

		int img_index = project.load_texture(param);

		if(img_index >= 0 && img_index < project.textures.size())
		{
			m_texture_textureList_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.textures[img_index].id_name));
		}
		else
		{
			wxMessageBox(_("Failed to Load Image (") + dialog->selected_files[i] + _(")"));
		}
	}

}

void SerenityEditorSerenity3D_Frame::On_Texture_RemoveTexture_ButtonClicked( wxCommandEvent& event )
{
	int current_selection = m_texture_textureList_listBox->GetSelection();

	int t_index = textureTab_selected_texture_project_index;

	current_window->view2D_texture = NULL;

	if(current_selection < 0 || current_selection >= m_texture_textureList_listBox->GetCount())
		return;

	project.remove_texture(t_index);

	m_texture_textureList_listBox->Clear();

	//populate textures from project
	for(int i = 0; i < project.textures.size(); i++)
	{
		if(project.textures[i].id_name.compare("") != 0)
			m_texture_textureList_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.textures[i].id_name));
	}

	int new_selection = -1;
	if(current_selection < m_texture_textureList_listBox->GetCount())
	{
		m_texture_textureList_listBox->SetSelection(current_selection);
		new_selection = current_selection;
	}
	else if(m_texture_textureList_listBox->GetCount() > 0)
	{
		m_texture_textureList_listBox->SetSelection(m_texture_textureList_listBox->GetCount()-1);
		new_selection = m_texture_textureList_listBox->GetSelection();
	}

	if(new_selection >= 0)
	{
		wxString t_select = m_texture_textureList_listBox->GetString(new_selection);
		current_window->view2D_texture = NULL;
		for(int i = 0; i < project.textures.size(); i++)
		{
			if(project.textures[i].id_name.compare(t_select.ToStdString())==0)
			{
				textureTab_selected_texture_project_index = i;

				if(current_window)
					current_window->view2D_texture = project.textures[i].texture;

				break;
			}
		}
	}
	else
		textureTab_selected_texture_project_index = -1;
}

void SerenityEditorSerenity3D_Frame::On_Texture_TextureList_Select( wxCommandEvent& event )
{
	//Make Sure texture ID is valid on current texture
	if(textureTab_selected_texture_project_index >= 0 && textureTab_selected_texture_project_index < project.textures.size())
	{
		if(!isValidID(wxString::FromUTF8(project.textures[textureTab_selected_texture_project_index].id_name), RC_ID_TEXTURE))
		{
			wxMessageBox(_("Warning: Texture ID is invalid. A default Texture ID will be generated."));
			project.textures[textureTab_selected_texture_project_index].id_name = project.genTextureID().ToStdString();

			wxMessageBox(_("NEW ID: ") + wxString::FromUTF8(project.textures[textureTab_selected_texture_project_index].id_name.c_str()));

			m_texture_textureList_listBox->Clear();

			for(int i = 0; i < project.textures.size(); i++)
			{
				m_texture_textureList_listBox->AppendAndEnsureVisible(wxString::FromUTF8(project.textures[i].id_name));
			}
		}
	}

	textureTab_selected_texture_project_index = -1;
	wxString id_name = event.GetString();

	for(int i = 0; i < project.textures.size(); i++)
	{
		if(id_name.compare(wxString::FromUTF8(project.textures[i].id_name))==0)
		{
			textureTab_selected_texture_project_index = i;
		}
	}

	if(textureTab_selected_texture_project_index < 0)
	{
		wxMessageBox(_("Texture (") + id_name + _(") does not match a project texture id"));
		return;
	}

	int n = textureTab_selected_texture_project_index;

	m_texture_textureID_textCtrl->SetValue(wxString::FromUTF8(project.textures[n].id_name));
	m_texture_textureFile_textCtrl->SetValue(wxString::FromUTF8(project.textures[n].file));
	m_texture_useColorKey_checkBox->SetValue(project.textures[n].use_colorKey);

	wxColor color_key(project.textures[n].colorkey.getRed(),
					  project.textures[n].colorkey.getGreen(),
					  project.textures[n].colorkey.getBlue(),
					  project.textures[n].colorkey.getAlpha());
	m_texture_colorKey_colourPicker->SetColour(color_key);

	if(current_window)
	{
		current_window->view2D_texture = project.textures[n].texture;
	}
}

void SerenityEditorSerenity3D_Frame::On_Texture_TextureID_Update( wxCommandEvent& event )
{
	wxString id_name = m_texture_textureID_textCtrl->GetValue();

	int n = textureTab_selected_texture_project_index;

	if(n < 0 || n >= project.textures.size())
		return;

	int listbox_index = m_texture_textureList_listBox->GetSelection();
	if(listbox_index < 0 || listbox_index >= m_texture_textureList_listBox->GetCount())
		return;

	project.textures[n].id_name = id_name.ToStdString();
	m_texture_textureList_listBox->SetString(listbox_index, id_name);
}

void SerenityEditorSerenity3D_Frame::On_Texture_UseColorkey_Update( wxCommandEvent& event )
{
	int n = textureTab_selected_texture_project_index;

	if(n < 0 || n >= project.textures.size())
		return;

	project.textures[n].use_colorKey = event.IsChecked();
}

void SerenityEditorSerenity3D_Frame::On_Texture_Colorkey_Update( wxColourPickerEvent& event )
{
	int n = textureTab_selected_texture_project_index;

	if(n < 0 || n >= project.textures.size())
		return;

	project.textures[n].colorkey = irr::video::SColor(event.GetColour().Alpha(),
													  event.GetColour().Red(),
													  event.GetColour().Green(),
													  event.GetColour().Blue());
}

