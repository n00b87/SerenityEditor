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
	project.setGridSize(2500);
	project.setGridSpacing(100);
	project.grid_visible = true;

	m_viewportSettings_showGrid_checkBox->SetValue(project.grid_visible);
	m_viewportSettings_gridSize_spinCtrl->SetValue(project.grid_size);
	m_viewportSettings_gridSpacing_spinCtrl->SetValue(project.grid_spacing);
	m_viewportSettings_gridColor_colourPicker->SetColour( wxColour(70, 70, 70, 255) );

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

	for(int i = 0; i < project.stages[stage_project_index].actors.size(); i++)
	{
		switch(project.stages[stage_project_index].actors[i].type)
		{
			case SN_ACTOR_TYPE_ANIMATED:
			{
				int mesh_index = project.stages[stage_project_index].actors[i].mesh_index;

				irr::scene::IAnimatedMesh* mesh = NULL;

				if(mesh_index >= 0 && mesh_index < project.meshes.size())
					mesh = project.meshes[mesh_index].mesh;

				project.stages[stage_project_index].actors[i].node = NULL;

				if(mesh)
				{
					project.stages[stage_project_index].actors[i].node = smgr->addAnimatedMeshSceneNode(mesh);
				}


				if(project.stages[stage_project_index].actors[i].node != NULL)
				{
					irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)project.stages[stage_project_index].actors[i].node; //So I can type less

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


					node->setVisible(project.stages[stage_project_index].actors[i].visible);

					node->setAutomaticCulling(project.stages[stage_project_index].actors[i].auto_culling);


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
	}

	stageTab_active_stage_project_index = stage_project_index;
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

	switch(node_type)
	{
		case RC_STAGE_NODE_STAGE:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;

		}
		break;

		case RC_STAGE_NODE_ACTOR:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;

			m_stage_propertyGridManager->SelectPage(m_waterActorProperties_propertyGridPage);
		}
		break;

		case RC_STAGE_NODE_GROUP:
		{
			int stage_project_index = stage_tree_nodes[stage_node_index].project_index;
		}
		break;

		default:
			m_stage_propertyGridManager->SelectPage(m_projectProperties_propertyGridPage);
			m_projectProperties_propertyGridPage->GetPropertyByName(_("project_name"))->SetValueFromString(_("test"));
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
	stage_tools_selection = getStageToolIndex(m_s3d_select_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DBoxClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_boxSelect_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DMoveClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_move_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DRotateClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_rotate_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DScaleClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_scale_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DPlaneClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_plane_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DCubeClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_cube_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DSphereClicked( wxCommandEvent& event )
{
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
	stage_tools_selection = getStageToolIndex(m_s3d_octreeActor_tool);
	updateToolSelection();

	SerenityEditor_NewOctree_Dialog* create_octree_win = new SerenityEditor_NewOctree_Dialog(this, &project);
	create_octree_win->ShowModal();
}

void SerenityEditorSerenity3D_Frame::OnS3DWizClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_animatedActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DBillboardClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_billboardActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DLightClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_lightActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DTerrainClicked( wxCommandEvent& event )
{
	stage_tools_selection = getStageToolIndex(m_s3d_terrainActor_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DWaterClicked( wxCommandEvent& event )
{
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
	stage_tools_selection = getStageToolIndex(m_s3d_path_tool);
	updateToolSelection();
}

void SerenityEditorSerenity3D_Frame::OnS3DEffectClicked( wxCommandEvent& event )
{
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

