#ifndef ENGINE_BASE_H_INCLUDED
#define ENGINE_BASE_H_INCLUDED

#include <wx/wx.h>
#include <wx/filename.h>
#include <vector>
#include <irrlicht.h>
#include <cinttypes>
#include "rc_stage.h"
#include "wxIrrlicht.h"

struct serenity_project_dict_obj
{
	wxString key;
	wxString val;
};

struct serenity_project_file_obj
{
	std::vector<serenity_project_dict_obj> dict;
};

class serenity_project
{
public:
	bool grid_visible;
	float grid_size;
	float grid_spacing;
	bool show_axis_lines = true;
	bool show_axis_rings = true;
	bool show_camera_pos = false;
	bool show_camera_rot = false;
	double camera_speed = 5;
	irr::video::SColor hud_color;
	std::vector<rc_stage> stages;
	std::vector<rc_material> materials;
	std::vector<rc_texture> textures;
	std::vector<rc_mesh> meshes;
	std::vector<rc_an8> anim8or_projects;

	std::vector<int> tmp_mesh_index;

	uint32_t grid_color;
	irr::IrrlichtDevice* device;

	wxFileName project_path;
	std::string project_name;

	int active_stage;

	serenity_project(std::string project_file, std::string p_name, irr::IrrlichtDevice* scene_device, wxIrrlicht* st_win, wxIrrlicht* ani_win, wxIrrlicht* mat_win, wxIrrlicht* tx_win);
	serenity_project()
	{
		setDefaults();
	}
	~serenity_project();

	wxFileName rcbasic_project_path;
	wxString rcbasic_main_bas;
	bool genRCBasicProject();

	void reload_assets();

	int load_stage(std::vector<serenity_project_dict_obj> stage_param, bool isActive=false);
	void save_stage(int stage_id);
	void remove_stage(int stage_id);

	wxString genTextureID(); //generate a texture id name if needed
	wxString genMaterialID(); //generate a material id name if needed
	wxString genMaterialFileName(wxString tmp_name);
	wxString genMeshID(); //generate a mesh id name if needed
	wxString genMeshAnimationID(int mesh_index); //generate a mesh id name if needed
	wxString genAN8ID(); //generate a anim8or project id name if needed
	wxString genActorID(int stage_index);
	wxString genGroupLabel(int stage_index);
	wxString genStageID();

	int load_texture(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	int load_an8(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	int load_mesh(std::vector<serenity_project_dict_obj> stage_param, int m_index=-1, int reload_index=-1);
	int load_material(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	rc_actor load_actor(std::vector<serenity_project_dict_obj> stage_param);
	rc_sky load_sky(std::vector<serenity_project_dict_obj> stage_param);

	int getMeshIndex(wxString mesh_id);
	int getMaterialIndex(wxString material_id);
	int getTextureIndex(wxString texture_id);
	int getAnimationIndex(int mesh_index, wxString animation_id);

	wxString getSkyTypeString(int sky_type);
	int getSkyType(wxString sky_type_string);

	wxString getActorTypeString(int actor_type);
	int getActorType(wxString actor_type_string);
	wxString getLightTypeString(int light_type);
	int getLightType(wxString light_type_string);
	wxString getParticleTypeString(int particle_type);
	int getParticleType(wxString particle_type_string);
	wxString getPhysicsShapeString(int physics_shape);
	int getPhysicsShape(wxString physics_shape_string);

	void load_material_list(rc_mesh* p_mesh, wxString ml_file);
	bool save_material_list(rc_mesh p_mesh);
	rc_material loadMaterialFile(wxString mfile, wxString mID);
	bool save_material(int material_index);
	bool save_mesh_properties(int mesh_index);
	void resolve_materialReferences();

	void remove_texture(int t_index);

	void clearProject();
	void init_project(std::vector<serenity_project_dict_obj> param);

	void init_grid(std::vector<serenity_project_dict_obj> param);
	void init_tools(std::vector<serenity_project_dict_obj> param);
	void init_camera(std::vector<serenity_project_dict_obj> param);
	void init_hud(std::vector<serenity_project_dict_obj> param);

	void setGridVisible(bool flag);
	void setGridSize(float g_size);
	void setGridSpacing(float g_spacing);
	void setGridColor(uint32_t color);

	std::vector<serenity_project_file_obj> getParams(wxString p_data);

	void setDefaults()
	{
		setGridColor( irr::video::SColor(255, 70, 70, 70).color );
		setGridSize(5000);
		setGridSpacing(100);
		grid_visible = true;
		show_axis_lines = true;
		show_axis_rings = true;
		show_camera_pos = false;
		show_camera_rot = false;
		camera_speed = 5;
		hud_color = irr::video::SColor(255,255,255,255);
	}

	wxIrrlicht* stage_window = NULL;
	wxIrrlicht* animation_window = NULL;
	wxIrrlicht* material_window = NULL;
	wxIrrlicht* texture_window = NULL;
	void setControlContext(wxIrrlicht* tgt_control);
	wxIrrlicht* getCurrentContextControl();

	void swapMaterialTexture(wxIrrlicht* control_window);
};

#endif // ENGINE_BASE_H_INCLUDED
