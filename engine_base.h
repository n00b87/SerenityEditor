#ifndef ENGINE_BASE_H_INCLUDED
#define ENGINE_BASE_H_INCLUDED

#include <wx/wx.h>
#include <wx/filename.h>
#include <vector>
#include <irrlicht.h>
#include <cinttypes>
#include "rc_stage.h"

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

	serenity_project(std::string project_file, std::string p_name, irr::IrrlichtDevice* scene_device);
	serenity_project()
	{
		setDefaults();
	}
	~serenity_project();

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

	int load_texture(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	int load_an8(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	int load_mesh(std::vector<serenity_project_dict_obj> stage_param, int m_index=-1, int reload_index=-1);
	int load_material(std::vector<serenity_project_dict_obj> stage_param, int reload_index=-1);
	rc_actor load_actor(std::vector<serenity_project_dict_obj> stage_param);

	int getMeshIndex(wxString mesh_id);
	int getMaterialIndex(wxString material_id);
	int getTextureIndex(wxString texture_id);
	int getAnimationIndex(int mesh_index, wxString animation_id);

	wxString getActorTypeString(int actor_type);
	int getActorType(wxString actor_type_string);
	wxString getLightTypeString(int light_type);
	int getLightType(wxString light_type_string);

	void load_material_list(rc_mesh* p_mesh, wxString ml_file);
	rc_material loadMaterialFile(wxString mfile, wxString mID);
	bool save_material(int material_index);
	bool save_mesh_properties(int mesh_index);
	void resolve_materialReferences();

	void remove_texture(int t_index);

	void clearProject();
	void init_project(std::vector<serenity_project_dict_obj> param);

	void setGridVisible(bool flag);
	void setGridSize(float g_size);
	void setGridSpacing(float g_spacing);
	void setGridColor(uint32_t color);

	std::vector<serenity_project_file_obj> getParams(wxString p_data);

	void setDefaults()
	{
		grid_visible = true;
		grid_size = 2500;
		grid_spacing = 100;
		grid_color = irr::video::SColor(255, 100, 100, 100).color;
	}
};

#endif // ENGINE_BASE_H_INCLUDED
