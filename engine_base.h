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
	uint32_t grid_color;

	wxFileName project_path;

	serenity_project(std::string project_file);
	serenity_project()
	{
		setDefaults();
	}
	~serenity_project();

	int load_stage(std::vector<serenity_project_dict_obj> stage_param);
	void save_stage(int stage_id);
	void remove_stage(int stage_id);

	void setGridVisible(bool flag);
	void setGridSize(float g_size);
	void setGridSpacing(float g_spacing);

	void setDefaults()
	{
		grid_visible = true;
		grid_size = 2500;
		grid_spacing = 100;
		grid_color = irr::video::SColor(255, 100, 100, 100).color;
	}
};

#endif // ENGINE_BASE_H_INCLUDED
