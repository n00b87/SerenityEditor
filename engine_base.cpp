#include <wx/wx.h>
#include <wx/filename.h>
#include <vector>
#include "rc_stage.h"
#include "engine_base.h"
#include "an8parser.h"

void serenity_project::clearProject()
{
	for(int i = 0; i < stages.size(); i++)
	{
		stages[i].clearStage();
	}

	for(int i = 0; i < textures.size(); i++)
	{
		if(textures[i].texture)
		{
			//textures[i].texture->drop();
			textures[i].texture = NULL;
		}
	}

	for(int i = 0; i < meshes.size(); i++)
	{
		if(meshes[i].mesh)
		{
			//meshes[i].mesh->drop();
			meshes[i].mesh = NULL;
		}
	}

	for(int i = 0; i < materials.size(); i++)
	{
		for(int t = 0; t < materials[i].texture_id.size(); t++)
		{
			materials[i].material.setTexture(t, NULL);
		}
	}

	//textures.clear();
	//meshes.clear();
	//anim8or_projects.clear();
	//materials.clear();
}

void serenity_project::remove_texture(int t_index)
{
	//REMOVE TEXTURE FROM MATERIALS
	for(int mat_index = 0; mat_index < materials.size(); mat_index++)
	{
		for(int i = 0; i < materials[mat_index].texture_id.size(); i++)
		{
			if(materials[mat_index].texture_id[i] == t_index)
			{
				materials[mat_index].material.setTexture(i, NULL);
				materials[mat_index].texture_id[i] = -1;
			}
		}
	}

	device->getVideoDriver()->removeTexture(textures[t_index].texture);
	textures[t_index].texture = NULL;
	textures[t_index].id_name = "";
	textures[t_index].file = "";
	textures[t_index].use_colorKey = false;
	textures[t_index].colorkey = irr::video::SColor(0);

}

std::vector<serenity_project_file_obj> serenity_project::getParams(wxString p_data)
{
	std::vector<serenity_project_file_obj> dlist;

	serenity_project_file_obj dlist_obj;

	std::vector<serenity_project_dict_obj> dict;
	serenity_project_dict_obj dict_obj;
	dict_obj.key = _("");
	dict_obj.val = _("");

	p_data.Replace(_(";"), _(" ;"));
	p_data.Replace(_("\n"), _(""));
	p_data.Replace(_("\r"), _(""));
	p_data.Replace(_("\t"), _(" "));

	bool isKey = true;

	bool in_quotes = false;

	for(int i = 0; i < p_data.length(); i++)
	{
		if(p_data.substr(i, 1).compare(_(";"))==0)
		{
			dlist.push_back(dlist_obj);
			dlist_obj.dict.clear();

			//clear parameters
			dict_obj.key = _("");
			dict_obj.val = _("");
			continue;
		}

		if( (in_quotes && p_data.substr(i, 1).compare(_("\""))==0) || ((!in_quotes) && p_data.substr(i, 1).compare(_(" "))==0) )
		{
			if(dict_obj.key.compare(_(""))!=0)
				dlist_obj.dict.push_back(dict_obj);
			dict_obj.key = _("");
			dict_obj.val = _("");
			isKey = true;
			in_quotes = false;
		}
		else if(p_data.substr(i, 1).compare(_("="))==0)
		{
			isKey = false;
		}
		else if(p_data.substr(i, 1).compare(_("\""))==0)
		{
			in_quotes = true;
		}
		else if(isKey)
		{
			dict_obj.key.Append(p_data.substr(i,1));
		}
		else
		{
			dict_obj.val.Append(p_data.substr(i,1));
		}
	}

	return dlist;
}

void serenity_project::reload_assets()
{
	clearProject();
	std::vector<serenity_project_dict_obj> param;
	serenity_project_dict_obj obj;
	param.push_back(obj);
	param.push_back(obj);
	param.push_back(obj);
	param.push_back(obj);

	for(int i = 0; i < textures.size(); i++)
	{
		if(textures[i].id_name.compare(_(""))!=0) //every asset will have an id by the time reload is called
			load_texture(param, i);
	}

	for(int i = 0; i < materials.size(); i++)
	{
		if(materials[i].id_name.compare(_(""))!=0) //every asset will have an id by the time reload is called
			load_material(param, i);
	}

	for(int i = 0; i < meshes.size(); i++)
	{
		if(meshes[i].id_name.compare(_(""))!=0) //every asset will have an id by the time reload is called
			load_mesh(param, i);
	}
}

serenity_project::serenity_project(std::string project_file, std::string p_name, irr::IrrlichtDevice* scene_device)
{
	project_path = wxFileName(project_file.c_str());
	project_name = p_name;
	device = scene_device;

	if(!project_path.Exists())
	{
		//set defaults and return
		setDefaults();
		return;
	}

	wxFile pfile(project_path.GetAbsolutePath());

	wxString p_data;
	pfile.ReadAll(&p_data);
	pfile.Close();

	std::vector<serenity_project_dict_obj> dict;
	dict.clear();

	serenity_project_dict_obj dict_obj;
	dict_obj.key = _("");
	dict_obj.val = _("");

	p_data.Replace(_(";"), _(" ;"));
	p_data.Replace(_("\n"), _(""));
	p_data.Replace(_("\r"), _(""));
	p_data.Replace(_("\t"), _(" "));

	bool isKey = true;

	bool in_quotes = false;

	for(int i = 0; i < p_data.length(); i++)
	{
		if(p_data.substr(i, 1).compare(_(";"))==0)
		{
			//do something with parameters
			if(dict[0].key.compare(_("Stage"))==0)
				load_stage(dict);
			else if(dict[0].key.compare(_("Project"))==0)
				init_project(dict);

			//clear parameters
			dict_obj.key = _("");
			dict_obj.val = _("");
			dict.clear();
			continue;
		}

		if( (in_quotes && p_data.substr(i, 1).compare(_("\""))==0) || ((!in_quotes) && p_data.substr(i, 1).compare(_(" "))==0) )
		{
			if(dict_obj.key.compare(_(""))!=0)
				dict.push_back(dict_obj);
			dict_obj.key = _("");
			dict_obj.val = _("");
			isKey = true;
			in_quotes = false;
		}
		else if(p_data.substr(i, 1).compare(_("="))==0)
		{
			isKey = false;
		}
		else if(p_data.substr(i, 1).compare(_("\""))==0)
		{
			in_quotes = true;
		}
		else if(isKey)
		{
			dict_obj.key.Append(p_data.substr(i,1));
		}
		else
		{
			dict_obj.val.Append(p_data.substr(i,1));
		}
	}
}

serenity_project::~serenity_project()
{
}

void serenity_project::init_project(std::vector<serenity_project_dict_obj> param)
{
	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("name"))==0)
		{
			project_name = param[i].val.ToStdString();
		}
	}
}

void serenity_project::resolve_materialReferences()
{
	//resolve material ids to indices in meshes
	for(int i = 0; i < meshes.size(); i++)
	{
		for(int mesh_mat_index = 0; mesh_mat_index < meshes[i].ref_material_id.size(); mesh_mat_index++)
		{
			bool mat_index_found = false;
			for(int project_mat_index = 0; project_mat_index < materials.size(); project_mat_index++)
			{
				std::string mesh_mat_id = meshes[i].ref_material_id[mesh_mat_index];
				std::string project_mat_id = materials[project_mat_index].id_name;

				if(mesh_mat_id.compare(project_mat_id)==0)
				{
					meshes[i].material_index.push_back(project_mat_index);
					mat_index_found = true;
					break;
				}
			}
			if(!mat_index_found)
			{
				meshes[i].material_index.push_back(-1);
			}
		}

		meshes[i].ref_material_id.clear();
	}
}

int serenity_project::load_stage(std::vector<serenity_project_dict_obj> stage_param, bool isActive)
{
	if(stage_param.size() < 3)
		return -1;

	wxString id_name = _("");
	wxFileName fname = project_path;
	fname.SetFullName(_(""));

	fname.AppendDir(_("stages"));

	rc_stage p_stage;

	for(int i = 0; i < stage_param.size(); i++)
	{
		if(stage_param[i].key.compare(_("file"))==0)
		{
			fname.SetFullName(stage_param[i].val);
			p_stage.file = stage_param[i].val.ToStdString();
		}
		else if(stage_param[i].key.compare(_("id"))==0)
		{
			p_stage.id_name = stage_param[i].val.ToStdString();
		}
	}

	//wxMessageBox(_("Stage Path:") + fname.GetAbsolutePath());

	if(!fname.Exists())
		return -1;

	wxFile st_file(fname.GetAbsolutePath());
	wxString content;
	st_file.ReadAll(&content);
	st_file.Close();

	std::vector<serenity_project_file_obj> st_obj = getParams(content);

	for(int i = 0; i < st_obj.size(); i++)
	{
		if(st_obj[i].dict[0].key.compare(_("Image"))==0)
			load_texture(st_obj[i].dict);
		else if(st_obj[i].dict[0].key.compare(_("Mesh"))==0)
			load_mesh(st_obj[i].dict);
		else if(st_obj[i].dict[0].key.compare(_("AN8"))==0)
			load_an8(st_obj[i].dict);
		else if(st_obj[i].dict[0].key.compare(_("Material"))==0)
			load_material(st_obj[i].dict);
		else if(st_obj[i].dict[0].key.compare(_("Actor"))==0)
		{
			rc_actor p_actor = load_actor(st_obj[i].dict);

			if(p_actor.id_name.compare("") != 0)
				p_stage.actors.push_back(p_actor);
		}
		else if(st_obj[i].dict[0].key.compare(_("Group"))==0)
		{
			rc_group p_group;

			for(int n_item = 0; n_item < st_obj[i].dict.size(); n_item++)
			{
				if(st_obj[i].dict[n_item].key.compare(_("label"))==0)
				{
					p_group.label = st_obj[i].dict[n_item].val.ToStdString();
					break;
				}
			}

			if(p_group.label.compare("") != 0)
				p_stage.groups.push_back(p_group);
		}
	}

	//attempt to reload an8 meshes that were missing an8 projects the first time
	std::vector<serenity_project_dict_obj> tmp_param; //This is just an empty vector because its a required parameter for load_mesh()
	for(int i = 0; i < tmp_mesh_index.size(); i++)
	{
		load_mesh(tmp_param, tmp_mesh_index[i]);
	}

	//resolve material ids to indices in meshes
	resolve_materialReferences();

	int stage_index = stages.size();
	stages.push_back(p_stage);

	return stage_index;
}

void serenity_project::save_stage(int stage_id)
{
}

void serenity_project::remove_stage(int stage_id)
{
}

void serenity_project::setGridSize(float g_size)
{
	grid_size = g_size;
}

void serenity_project::setGridSpacing(float g_spacing)
{
	grid_spacing = g_spacing;
}

void serenity_project::setGridVisible(bool flag)
{
	grid_visible = flag;
}

void serenity_project::setGridColor(uint32_t color)
{
	grid_color = color;
}

wxString serenity_project::getLightTypeString(int light_type)
{
	switch(light_type)
	{
		case SN_LIGHT_TYPE_DIRECTIONAL: return _("DIRECTIONAL");
		case SN_LIGHT_TYPE_POINT: return _("POINT");
		case SN_LIGHT_TYPE_SPOT: return _("SPOT");
	}
	return _("");
}

int serenity_project::getLightType(wxString light_type_string)
{
	if(light_type_string.compare(_("DIRECTIONAL"))==0)
		return SN_LIGHT_TYPE_DIRECTIONAL;
	else if(light_type_string.compare(_("POINT"))==0)
		return SN_LIGHT_TYPE_POINT;
	else if(light_type_string.compare(_("SPOT"))==0)
		return SN_LIGHT_TYPE_SPOT;

	return -1;
}

wxString serenity_project::getActorTypeString(int actor_type)
{
	switch(actor_type)
	{
		case SN_ACTOR_TYPE_ANIMATED: return _("ANIMATED");
		case SN_ACTOR_TYPE_OCTREE:	return _("OCTREE");
		case SN_ACTOR_TYPE_LIGHT:	return _("LIGHT");
		case SN_ACTOR_TYPE_BILLBOARD: return _("BILLBOARD");
		case SN_ACTOR_TYPE_TERRAIN: return _("TERRAIN");
		case SN_ACTOR_TYPE_WATER:	return _("WATER");
		case SN_ACTOR_TYPE_PARTICLE:	return _("PARTICLE");
		case SN_ACTOR_TYPE_CUBE:	return _("CUBE");
		case SN_ACTOR_TYPE_SPHERE:	return _("SPHERE");
		case SN_ACTOR_TYPE_PLANE:	return _("PLANE");
	}
	return _("");
}

int serenity_project::getActorType(wxString actor_type_string)
{
	if(actor_type_string.compare(_("ANIMATED"))==0)
		return SN_ACTOR_TYPE_ANIMATED;
	else if(actor_type_string.compare(_("OCTREE"))==0)
		return SN_ACTOR_TYPE_OCTREE;
	else if(actor_type_string.compare(_("LIGHT"))==0)
		return SN_ACTOR_TYPE_LIGHT;
	else if(actor_type_string.compare(_("BILLBOARD"))==0)
		return SN_ACTOR_TYPE_BILLBOARD;
	else if(actor_type_string.compare(_("TERRAIN"))==0)
		return SN_ACTOR_TYPE_TERRAIN;
	else if(actor_type_string.compare(_("WATER"))==0)
		return SN_ACTOR_TYPE_WATER;
	else if(actor_type_string.compare(_("PARTICLE"))==0)
		return SN_ACTOR_TYPE_PARTICLE;
	else if(actor_type_string.compare(_("CUBE"))==0)
		return SN_ACTOR_TYPE_CUBE;
	else if(actor_type_string.compare(_("SPHERE"))==0)
		return SN_ACTOR_TYPE_SPHERE;
	else if(actor_type_string.compare(_("PLANE"))==0)
		return SN_ACTOR_TYPE_PLANE;

	return -1;
}

rc_actor serenity_project::load_actor(std::vector<serenity_project_dict_obj> param)
{
	rc_actor p_actor;

	double pos_x, pos_y, pos_z, rot_x, rot_y, rot_z, scale_x, scale_y, scale_z;

	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("type"))==0)
			p_actor.type = getActorType(param[i].val.ToStdString());
		else if(param[i].key.compare(_("id"))==0)
			p_actor.id_name = param[i].val.ToStdString();
		else if(param[i].key.compare(_("group"))==0)
			p_actor.group_name = param[i].val.ToStdString();
		else if(param[i].key.compare(_("mesh"))==0)
			param[i].val.ToInt(&p_actor.mesh_index);
		else if(param[i].key.compare(_("pos_x"))==0)
			param[i].val.ToDouble(&pos_x);
		else if(param[i].key.compare(_("pos_y"))==0)
			param[i].val.ToDouble(&pos_y);
		else if(param[i].key.compare(_("pos_z"))==0)
			param[i].val.ToDouble(&pos_z);
		else if(param[i].key.compare(_("rot_x"))==0)
			param[i].val.ToDouble(&rot_x);
		else if(param[i].key.compare(_("rot_y"))==0)
			param[i].val.ToDouble(&rot_y);
		else if(param[i].key.compare(_("rot_z"))==0)
			param[i].val.ToDouble(&rot_z);
		else if(param[i].key.compare(_("scale_x"))==0)
			param[i].val.ToDouble(&scale_x);
		else if(param[i].key.compare(_("scale_y"))==0)
			param[i].val.ToDouble(&scale_y);
		else if(param[i].key.compare(_("scale_z"))==0)
			param[i].val.ToDouble(&scale_z);
		else if(param[i].key.compare(_("material"))==0)
			param[i].val.ToInt(&p_actor.override_material_index);
		else if(param[i].key.compare(_("animation"))==0)
			param[i].val.ToInt(&p_actor.animation_index);
		else if(param[i].key.compare(_("num_loops"))==0)
			param[i].val.ToInt(&p_actor.num_loops);
		else if(param[i].key.compare(_("visible"))==0)
			p_actor.visible = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("shadow"))==0)
			p_actor.hasShadow = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("cast_shadow"))==0)
			p_actor.isCastingShadow = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("auto_culling"))==0)
			p_actor.auto_culling = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("cube_size"))==0)
			param[i].val.ToDouble(&p_actor.cube_size);
		else if(param[i].key.compare(_("radius"))==0)
			param[i].val.ToDouble(&p_actor.radius);
		else if(param[i].key.compare(_("texture_index"))==0)
			param[i].val.ToInt(&p_actor.texture_index);
		else if(param[i].key.compare(_("light_type"))==0)
			p_actor.light_type = getLightType(param[i].val);
		else if(param[i].key.compare(_("angle"))==0)
			param[i].val.ToDouble(&p_actor.angle);
		else if(param[i].key.compare(_("falloff"))==0)
			param[i].val.ToDouble(&p_actor.falloff);
		else if(param[i].key.compare(_("ambient"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.ambient = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("emissive"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.emissive = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("diffuse"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.diffuse = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("specular"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.specular = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("terrain_hmap_file"))==0)
			p_actor.terrain_hmap_file = param[i].val.ToStdString();
		else if(param[i].key.compare(_("wave_height"))==0)
			param[i].val.ToDouble(&p_actor.wave_height);
		else if(param[i].key.compare(_("wave_length"))==0)
			param[i].val.ToDouble(&p_actor.wave_length);
		else if(param[i].key.compare(_("wave_speed"))==0)
			param[i].val.ToDouble(&p_actor.wave_speed);
	}

	p_actor.position = irr::core::vector3df(pos_x, pos_y, pos_z);
	p_actor.rotation = irr::core::vector3df(rot_x, rot_y, rot_z);
	p_actor.scale = irr::core::vector3df(scale_x, scale_y, scale_z);
	p_actor.node = NULL;

	return p_actor;
}

int serenity_project::load_texture(std::vector<serenity_project_dict_obj> param, int reload_index)
{
	if(param.size() < 3)
		return -1;

	wxString id_name = _("");
	wxString file_name = _("");

	bool has_colorKey = false;
	int color_key = -1;

	if(reload_index >= 0)
	{
		id_name = wxString::FromUTF8(textures[reload_index].id_name.c_str());
		file_name = wxString::FromUTF8(textures[reload_index].file.c_str());
		has_colorKey = textures[reload_index].use_colorKey;
		color_key = textures[reload_index].colorkey.color;
	}
	else
	{
		for(int i = 0; i < param.size(); i++)
		{
			if(param[i].key.compare(_("id"))==0)
				id_name = param[i].val;
			else if(param[i].key.compare(_("file"))==0)
				file_name = param[i].val;
			else if(param[i].key.compare(_("color_key"))==0)
			{
				has_colorKey = true;
				param[i].val.ToInt(&color_key);
			}
		}
	}

	wxFileName image_fname = project_path;
	image_fname.AppendDir(_("textures"));
	image_fname.SetFullName(file_name);

	if(!image_fname.Exists())
	{
		wxMessageBox(_("Failed to load texture (") + file_name + _("): File not found."));
		return -1;
	}

	if(reload_index < 0)
	{
		for(int i = 0; i < textures.size(); i++)
		{
			if(textures[i].id_name.compare(id_name)==0)
			{
				return -1; //don't add image if id is already loaded
			}
		}
	}

	rc_texture p_texture;
	p_texture.file = file_name.ToStdString();
	p_texture.id_name = id_name.ToStdString();
	p_texture.texture = device->getVideoDriver()->getTexture(image_fname.GetAbsolutePath().ToStdString().c_str());
	p_texture.use_colorKey = has_colorKey;

    if(p_texture.texture == NULL)
	{
		if(reload_index >= 0)
		{
			wxMessageBox(_("TEXTURE COULD NOT LOAD: ") + p_texture.id_name + _(" -->[") + image_fname.GetAbsolutePath() + _("]"));
 			textures[reload_index].texture = NULL;
		}

		return -1;
	}

	if(has_colorKey)
	{
		if(color_key == -1)
		{
			irr::u32* img_pixels = (irr::u32*)p_texture.texture->lock();
			color_key = img_pixels[0];
			p_texture.texture->unlock();
		}
	}

    if(has_colorKey)
	{
		device->getVideoDriver()->makeColorKeyTexture(p_texture.texture, irr::video::SColor(color_key));
		p_texture.colorkey = irr::video::SColor(color_key);
	}

	int t_index = (reload_index >= 0 ? reload_index : textures.size());

	if(reload_index >= 0)
	{
		textures[reload_index] = p_texture;
		//wxMessageBox(_("SUCCESS TX RL"));
	}
	else
		textures.push_back(p_texture);

	return t_index;
}

int serenity_project::load_an8(std::vector<serenity_project_dict_obj> param, int reload_index)
{
	if(param.size() < 3)
		return -1;

	if(reload_index >= 0)
		return reload_index; //AN8 projects are not tied to irrlicht scenes so we never have to reload it

	wxString id_name = _("");
	wxString file_name = _("");

	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("id"))==0)
			id_name = param[i].val;
		else if(param[i].key.compare(_("file"))==0)
			file_name = param[i].val;
	}

	wxFileName fname = project_path;
	fname.AppendDir(_("models"));
	fname.SetFullName(file_name);

	if(!fname.Exists())
	{
		wxMessageBox(_("Failed to load anim8or project (") + file_name + _("): File not found."));
		return -1;
	}

	for(int i = 0; i < anim8or_projects.size(); i++)
	{
		if(anim8or_projects[i].id_name.compare(id_name)==0)
		{
			return -1; //don't add image if id is already loaded
		}
	}

	rc_an8 p_an8;
	p_an8.file = file_name.ToStdString();
	p_an8.id_name = id_name.ToStdString();
	p_an8.project = an8::loadAN8(fname.GetAbsolutePath().ToStdString());

    if(!p_an8.project.exists)
        return -1;

	int t_index = anim8or_projects.size();
	anim8or_projects.push_back(p_an8);

	return t_index;
}

int serenity_project::load_mesh(std::vector<serenity_project_dict_obj> param, int m_index, int reload_index)
{
	wxString id_name = _("");
	wxString file_name = _("");

	rc_mesh p_mesh;
	p_mesh.ref_an8_id = "";
	p_mesh.isAN8Scene = false;
	p_mesh.isMD2 = false;

	bool in_zip = false;
	wxString zip_file = "";

	wxString ani_file = _("");

	if(m_index < 0)
	{
		for(int i = 0; i < param.size(); i++)
		{
			if(param[i].key.compare(_("id"))==0)
				id_name = param[i].val;
			else if(param[i].key.compare(_("file"))==0)
				file_name = param[i].val;
			else if(param[i].key.compare(_("an8"))==0)
			{
				p_mesh.isAN8Scene = true;
				p_mesh.ref_an8_id = param[i].val.ToStdString();
			}
			else if(param[i].key.compare(_("scene"))==0)
			{
				p_mesh.an8_scene = param[i].val.ToStdString();
			}
			else if(param[i].key.compare(_("zip"))==0)
			{
				in_zip = true;
				zip_file = param[i].val;
				p_mesh.isZipped = true;
				p_mesh.zip_file = zip_file.ToStdString();
			}
		}
	}
	else
	{
		p_mesh = meshes[m_index];
		id_name = p_mesh.id_name;
		file_name = p_mesh.file;
		in_zip = p_mesh.isZipped;
		zip_file = p_mesh.zip_file;
	}

	wxFileName fname = project_path;
	fname.AppendDir(_("models"));
	if(in_zip)
		fname.SetFullName(zip_file);
	else
		fname.SetFullName(file_name);

	if(!fname.Exists())
	{
		wxMessageBox(_("Failed to load model (") + file_name + _("): File not found."));
		return -1;
	}

	if(m_index < 0)
	{
		for(int i = 0; i < meshes.size(); i++)
		{
			if(meshes[i].id_name.compare(id_name)==0)
			{
				return -1; //don't add mesh if id is already loaded
			}
		}
	}

	p_mesh.id_name = id_name.ToStdString();
	p_mesh.file = file_name.ToStdString();

	if(in_zip)
	{
		device->getFileSystem()->addFileArchive(fname.GetAbsolutePath().ToStdString().c_str());
		p_mesh.mesh = device->getSceneManager()->getMesh(file_name.ToStdString().c_str());
		device->getFileSystem()->removeFileArchive((irr::u32) 0);
	}
	else if(p_mesh.isAN8Scene)
	{
		p_mesh.an8_index = -1;
		for(int i = 0; i < anim8or_projects.size(); i++)
		{
			if(p_mesh.ref_an8_id.compare(anim8or_projects[i].id_name)==0)
			{
				p_mesh.an8_index = i;
				break;
			}
		}

		if(p_mesh.an8_index >= 0 && p_mesh.an8_index < anim8or_projects.size())
		{
			p_mesh.mesh = an8::loadAN8Scene(device, anim8or_projects[p_mesh.an8_index].project, p_mesh.an8_scene);
		}
	}
	else
		p_mesh.mesh = device->getSceneManager()->getMesh(fname.GetAbsolutePath().ToStdString().c_str());



	//Load Material
	load_material_list(&p_mesh, id_name + _(".snmd"));

	//Check if MD2
	if(p_mesh.file.length() > 4)
	{
		wxString ext = wxString::FromUTF8(p_mesh.file.substr(p_mesh.file.length()-4, 4)); //Checking extension in wxFileName is sometimes unreliable

		if(ext.Lower().compare(_(".md2")) == 0)
			p_mesh.isMD2 = true;
	}

	//Load MD2 animations if MD2 file
	if(p_mesh.isMD2)
	{
		rc_animation animation_obj;

		animation_obj.id_name = "MD2_STAND";
		animation_obj.md2_animation = irr::scene::EMAT_STAND;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_RUN";
		animation_obj.md2_animation = irr::scene::EMAT_RUN;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_ATTACK";
		animation_obj.md2_animation = irr::scene::EMAT_ATTACK;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_PAIN_A";
		animation_obj.md2_animation = irr::scene::EMAT_PAIN_A;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_PAIN_B";
		animation_obj.md2_animation = irr::scene::EMAT_PAIN_B;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_PAIN_C";
		animation_obj.md2_animation = irr::scene::EMAT_PAIN_C;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_JUMP";
		animation_obj.md2_animation = irr::scene::EMAT_JUMP;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_FLIP";
		animation_obj.md2_animation = irr::scene::EMAT_FLIP;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_SALUTE";
		animation_obj.md2_animation = irr::scene::EMAT_SALUTE;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_FALLBACK";
		animation_obj.md2_animation = irr::scene::EMAT_FALLBACK;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_WAVE";
		animation_obj.md2_animation = irr::scene::EMAT_WAVE;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_POINT";
		animation_obj.md2_animation = irr::scene::EMAT_POINT;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_CROUCH_STAND";
		animation_obj.md2_animation = irr::scene::EMAT_CROUCH_STAND;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_CROUCH_WALK";
		animation_obj.md2_animation = irr::scene::EMAT_CROUCH_WALK;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_CROUCH_ATTACK";
		animation_obj.md2_animation = irr::scene::EMAT_CROUCH_ATTACK;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_CROUCH_PAIN";
		animation_obj.md2_animation = irr::scene::EMAT_CROUCH_PAIN;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_CROUCH_DEATH";
		animation_obj.md2_animation = irr::scene::EMAT_CROUCH_DEATH;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_DEATH_FALLBACK";
		animation_obj.md2_animation = irr::scene::EMAT_DEATH_FALLBACK;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_DEATH_FALLFORWARD";
		animation_obj.md2_animation = irr::scene::EMAT_DEATH_FALLFORWARD;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_DEATH_FALLBACKSLOW";
		animation_obj.md2_animation = irr::scene::EMAT_DEATH_FALLBACKSLOW;
		p_mesh.animation.push_back(animation_obj);

		animation_obj.id_name = "MD2_BOOM";
		animation_obj.md2_animation = irr::scene::EMAT_BOOM;
		p_mesh.animation.push_back(animation_obj);
	}

	//Load animation
	wxFileName dpath = project_path;
	dpath.AppendDir(_("data"));
	dpath.SetFullName(id_name + _(".sna"));
	if(dpath.Exists())
	{
		wxFile af(dpath.GetAbsolutePath());

		if(af.IsOpened())
		{
			wxString af_content;
			af.ReadAll(&af_content);
			af.Close();


			std::vector<serenity_project_file_obj> file_obj = getParams(af_content);

			for(int i = 0; i < file_obj.size(); i++)
			{
				rc_animation animation_obj;
				animation_obj.id_name = _("");
				animation_obj.start_frame = 0;
				animation_obj.end_frame = 0;
				animation_obj.speed = 0;

				for(int n = 0; n < file_obj[i].dict.size(); n++)
				{
					if(file_obj[i].dict[n].key.compare(_("id"))==0)
						animation_obj.id_name = file_obj[i].dict[n].val;
					else if(file_obj[i].dict[n].key.compare(_("start"))==0)
						file_obj[i].dict[n].val.ToInt(&animation_obj.start_frame);
					else if(file_obj[i].dict[n].key.compare(_("end"))==0)
						file_obj[i].dict[n].val.ToInt(&animation_obj.end_frame);
					else if(file_obj[i].dict[n].key.compare(_("speed"))==0)
					{
						double dval = 0;
						file_obj[i].dict[n].val.ToDouble(&dval);
						animation_obj.speed = dval;
					}
				}

				if(animation_obj.id_name.compare(_(""))!=0)
					p_mesh.animation.push_back(animation_obj);
			}
		}
	}


	if(!p_mesh.mesh)
	{
		if(p_mesh.isAN8Scene && m_index < 0) //don't add current mesh to tmp if this is the second time trying to load it
		{
			int t_index = meshes.size();
			meshes.push_back(p_mesh);
			tmp_mesh_index.push_back(t_index); //the an8 id might not have been read yet so we can try it again at the end
			return t_index;
		}
		else if(reload_index >= 0)
		{
			meshes[reload_index].mesh = NULL;
			return reload_index;
		}

		return -1;
	}


	//-----------------

	int t_index = (reload_index >= 0 ? reload_index : m_index);

	if(reload_index >= 0)
	{
		meshes[t_index].mesh = p_mesh.mesh;
	}
	else if(t_index < 0)
	{
		t_index = meshes.size();
		meshes.push_back(p_mesh);
	}
	else
	{
		meshes[t_index].mesh = p_mesh.mesh;
	}

	return t_index;
}

int serenity_project::load_material(std::vector<serenity_project_dict_obj> param, int reload_index)
{
	if(param.size() < 3)
		return -1;

	if(reload_index >= 0)
	{
		irr::video::SMaterial mat;

		mat.AmbientColor = materials[reload_index].material.AmbientColor;
		mat.AntiAliasing = materials[reload_index].material.AntiAliasing;
		mat.BackfaceCulling = materials[reload_index].material.BackfaceCulling;
		mat.BlendFactor = materials[reload_index].material.BlendFactor;
		mat.BlendOperation = materials[reload_index].material.BlendOperation;
		mat.ColorMask = materials[reload_index].material.ColorMask;
		mat.ColorMaterial = materials[reload_index].material.ColorMaterial;
		mat.DiffuseColor = materials[reload_index].material.DiffuseColor;
		mat.EmissiveColor = materials[reload_index].material.EmissiveColor;
		mat.FogEnable = materials[reload_index].material.FogEnable;
		mat.FrontfaceCulling = materials[reload_index].material.FrontfaceCulling;
		mat.GouraudShading = materials[reload_index].material.GouraudShading;
		mat.Lighting = materials[reload_index].material.Lighting;
		mat.MaterialType = materials[reload_index].material.MaterialType;
		mat.MaterialTypeParam2 = materials[reload_index].material.MaterialTypeParam2;
		mat.MaterialTypeParam = materials[reload_index].material.MaterialTypeParam;
		mat.NormalizeNormals = materials[reload_index].material.NormalizeNormals;
		mat.PointCloud = materials[reload_index].material.PointCloud;
		mat.PolygonOffsetDepthBias = materials[reload_index].material.PolygonOffsetDepthBias;
		mat.PolygonOffsetDirection = materials[reload_index].material.PolygonOffsetDirection;
		mat.PolygonOffsetFactor = materials[reload_index].material.PolygonOffsetFactor;
		mat.PolygonOffsetSlopeScale = materials[reload_index].material.PolygonOffsetSlopeScale;
		mat.Shininess = materials[reload_index].material.Shininess;
		mat.SpecularColor = materials[reload_index].material.SpecularColor;
		mat.Thickness = materials[reload_index].material.Thickness;
		mat.UseMipMaps = materials[reload_index].material.UseMipMaps;
		mat.UserData = materials[reload_index].material.UserData;
		mat.Wireframe = materials[reload_index].material.Wireframe;
		mat.ZBuffer = materials[reload_index].material.ZBuffer;
		mat.ZWriteEnable = materials[reload_index].material.ZWriteEnable;

		for(int i = 0; i < materials[reload_index].texture_id.size(); i++)
		{

			if(materials[reload_index].texture_id[i] >= 0 && materials[reload_index].texture_id[i] < textures.size())
			{
				int t_index = materials[reload_index].texture_id[i];
				if(textures[t_index].texture)
				{
					mat.setTexture(i, textures[t_index].texture);
				}
			}
		}

		materials[reload_index].material = mat;

		return reload_index; //The only thing that needs to be reloaded with materials is the texture
	}

	wxString id_name = _("");
	wxString file_name = _("");

	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("id"))==0)
			id_name = param[i].val;
		else if(param[i].key.compare(_("file"))==0)
			file_name = param[i].val;
	}

	wxFileName fname = project_path;
	fname.AppendDir(_("materials"));
	fname.SetFullName(file_name);

	if(!fname.Exists())
	{
		wxMessageBox(_("Failed to load material (") + file_name + _("): File not found."));
		return -1;
	}

	for(int i = 0; i < materials.size(); i++)
	{
		if(materials[i].id_name.compare(id_name)==0)
		{
			return -1; //don't add material if id is already loaded
		}
	}

	rc_material p_mat = loadMaterialFile(file_name, id_name);

	int t_index = materials.size();
	materials.push_back(p_mat);

	return t_index;
}

rc_material serenity_project::loadMaterialFile(wxString mfile, wxString mID)
{
	rc_material p_mat;

	p_mat.id_name = mID;
	p_mat.file = mfile;

	wxFileName fname = project_path;
	fname.AppendDir(_("materials"));
	fname.SetFullName(mfile);

	if(!fname.Exists())
		return p_mat;

	wxFile mat_file(fname.GetAbsolutePath());

	wxString content = _("");
	mat_file.ReadAll(&content);

	mat_file.Close();

	std::vector<serenity_project_file_obj> st_obj = getParams(content);

	if(st_obj.size() < 0)
		return p_mat;

	//wxMessageBox(_("SZ: ") + wxString::Format(_("%d"), (int)st_obj.size()));


	for(int line_num = 0; line_num < st_obj.size(); line_num++)
	{
		for(int i = 0; i < st_obj[line_num].dict.size(); i++)
		{
			if(st_obj[line_num].dict[0].key.compare(_("type"))==0)
			{
				if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_DETAIL_MAP"))==0)
					p_mat.material.MaterialType = irr::video::EMT_DETAIL_MAP;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_ADD"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_ADD;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_LIGHTING"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_LIGHTING;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_LIGHTING_M2"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_LIGHTING_M2;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_LIGHTING_M4"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_LIGHTING_M4;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_M2"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_M2;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_LIGHTMAP_M4"))==0)
					p_mat.material.MaterialType = irr::video::EMT_LIGHTMAP_M4;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_NORMAL_MAP_SOLID"))==0)
					p_mat.material.MaterialType = irr::video::EMT_NORMAL_MAP_SOLID;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_ADD_COLOR"))==0)
					p_mat.material.MaterialType = irr::video::EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA"))==0)
					p_mat.material.MaterialType = irr::video::EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_ONETEXTURE_BLEND"))==0)
					p_mat.material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_PARALLAX_MAP_SOLID"))==0)
					p_mat.material.MaterialType = irr::video::EMT_PARALLAX_MAP_SOLID;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_ADD_COLOR"))==0)
					p_mat.material.MaterialType = irr::video::EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA"))==0)
					p_mat.material.MaterialType = irr::video::EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_REFLECTION_2_LAYER"))==0)
					p_mat.material.MaterialType = irr::video::EMT_REFLECTION_2_LAYER;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_SOLID"))==0)
					p_mat.material.MaterialType = irr::video::EMT_SOLID;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_SOLID_2_LAYER"))==0)
					p_mat.material.MaterialType = irr::video::EMT_SOLID_2_LAYER;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_SPHERE_MAP"))==0)
					p_mat.material.MaterialType = irr::video::EMT_SPHERE_MAP;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_TRANSPARENT_ADD_COLOR"))==0)
					p_mat.material.MaterialType = irr::video::EMT_TRANSPARENT_ADD_COLOR;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL"))==0)
					p_mat.material.MaterialType = irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL_REF"))==0)
					p_mat.material.MaterialType = irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_TRANSPARENT_REFLECTION_2_LAYER"))==0)
					p_mat.material.MaterialType = irr::video::EMT_TRANSPARENT_REFLECTION_2_LAYER;
				else if(st_obj[line_num].dict[0].val.compare(_("MATERIAL_TYPE_TRANSPARENT_VERTEX_ALPHA"))==0)
					p_mat.material.MaterialType = irr::video::EMT_TRANSPARENT_VERTEX_ALPHA;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("ambient_color"))==0)
			{
				irr::u32 c_val = 0;
				st_obj[line_num].dict[0].val.ToUInt(&c_val);
				p_mat.material.AmbientColor = irr::video::SColor(c_val);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("diffuse_color"))==0)
			{
				irr::u32 c_val = 0;
				st_obj[line_num].dict[0].val.ToUInt(&c_val);
				p_mat.material.DiffuseColor = irr::video::SColor(c_val);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("emissive_color"))==0)
			{
				irr::u32 c_val = 0;
				st_obj[line_num].dict[0].val.ToUInt(&c_val);
				p_mat.material.EmissiveColor = irr::video::SColor(c_val);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("specular_color"))==0)
			{
				irr::u32 c_val = 0;
				st_obj[line_num].dict[0].val.ToUInt(&c_val);
				p_mat.material.SpecularColor = irr::video::SColor(c_val);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("anti_alias"))==0)
			{
				if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_ALPHA_TO_COVERAGE")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_ALPHA_TO_COVERAGE;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_FULL_BASIC")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_FULL_BASIC;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_LINE_SMOOTH")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_LINE_SMOOTH;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_OFF")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_OFF;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_POINT_SMOOTH")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_POINT_SMOOTH;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_QUALITY")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_QUALITY;
				else if(st_obj[line_num].dict[0].val.compare("ANTI_ALIAS_SIMPLE")==0)
					p_mat.material.AntiAliasing = irr::video::EAAM_SIMPLE;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("backface_culling"))==0)
			{
				p_mat.material.BackfaceCulling = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("frontface_culling"))==0)
			{
				p_mat.material.FrontfaceCulling = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("blend_factor"))==0)
			{
				double factor = 0;
				st_obj[line_num].dict[0].val.ToDouble(&factor);
				p_mat.material.BlendFactor = factor;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("blend_mode"))==0)
			{
				if(st_obj[line_num].dict[0].val.compare("BLENDMODE_ADD")==0)
					p_mat.material.BlendOperation = irr::video::EBO_ADD;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MAX")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MAX;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MAX_ALPHA")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MAX_ALPHA;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MAX_FACTOR")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MAX_FACTOR;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MIN")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MIN;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MIN_ALPHA")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MIN_ALPHA;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_MIN_FACTOR")==0)
					p_mat.material.BlendOperation = irr::video::EBO_MIN_FACTOR;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_NONE")==0)
					p_mat.material.BlendOperation = irr::video::EBO_NONE;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_REVSUBTRACT")==0)
					p_mat.material.BlendOperation = irr::video::EBO_REVSUBTRACT;
				else if(st_obj[line_num].dict[0].val.compare("BLENDMODE_SUBTRACT")==0)
					p_mat.material.BlendOperation = irr::video::EBO_SUBTRACT;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("color_mask"))==0)
			{
				if(st_obj[line_num].dict[0].val.compare("COLORMASK_ALL")==0)
					p_mat.material.ColorMask = irr::video::ECP_ALL;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_ALPHA")==0)
					p_mat.material.ColorMask = irr::video::ECP_ALPHA;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_BLUE")==0)
					p_mat.material.ColorMask = irr::video::ECP_BLUE;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_GREEN")==0)
					p_mat.material.ColorMask = irr::video::ECP_GREEN;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_NONE")==0)
					p_mat.material.ColorMask = irr::video::ECP_NONE;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_RED")==0)
					p_mat.material.ColorMask = irr::video::ECP_RED;
				else if(st_obj[line_num].dict[0].val.compare("COLORMASK_RGB")==0)
					p_mat.material.ColorMask = irr::video::ECP_RGB;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("color_mode"))==0)
			{
				if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_AMBIENT")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_AMBIENT;
				else if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_DIFFUSE")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_DIFFUSE;
				else if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_DIFFUSE_AND_AMBIENT")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_DIFFUSE_AND_AMBIENT;
				else if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_EMISSIVE")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_EMISSIVE;
				else if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_NONE")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_NONE;
				else if(st_obj[line_num].dict[0].val.compare("COLOR_MODE_SPECULAR")==0)
					p_mat.material.ColorMaterial = irr::video::ECM_SPECULAR;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("fog"))==0)
			{
				p_mat.material.FogEnable = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("gourad_shading"))==0)
			{
				p_mat.material.GouraudShading = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("lighting"))==0)
			{
				p_mat.material.Lighting = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("normalize"))==0)
			{
				p_mat.material.NormalizeNormals = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("point_cloud"))==0)
			{
				p_mat.material.PointCloud = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("shineness"))==0)
			{
				double shineness = 0;
				st_obj[line_num].dict[0].val.ToDouble(&shineness);
				p_mat.material.Shininess = shineness;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("thickness"))==0)
			{
				double thickness = 0;
				st_obj[line_num].dict[0].val.ToDouble(&thickness);
				p_mat.material.Thickness = thickness;
			}
			else if(st_obj[line_num].dict[0].key.compare(_("wireframe"))==0)
			{
				p_mat.material.Wireframe = (st_obj[line_num].dict[0].val.compare(_("true"))==0);
			}
			else if(st_obj[line_num].dict[0].key.compare(_("texture"))==0)
			{
				int level = 0;
				wxString filename = _("");

				for(int tx_item = 1; tx_item < st_obj[line_num].dict.size(); tx_item++)
				{
					if(st_obj[line_num].dict[tx_item].key.compare(_("level"))==0)
					{
						st_obj[line_num].dict[tx_item].val.ToInt(&level);
					}
					else if(st_obj[line_num].dict[tx_item].key.compare(_("file"))==0)
					{
						filename = st_obj[line_num].dict[tx_item].val;
					}
				}

				bool texture_found = false;
				for(int project_texture_index = 0; project_texture_index < textures.size(); project_texture_index++)
				{
					if(textures[project_texture_index].file.compare(filename)==0)
					{
						while(p_mat.texture_id.size() < (level+1))
							p_mat.texture_id.push_back(-1);

						p_mat.texture_id[level] = project_texture_index;
						texture_found = true;

						if(textures[project_texture_index].texture)
						{
							p_mat.material.setTexture(level, textures[project_texture_index].texture);
						}

						//wxMessageBox(_("SET TEXTURE"));
						break;
					}
				}

				if(!texture_found)
				{
					//load texture here
					wxString new_texture_id_name = genTextureID();
					std::vector<serenity_project_dict_obj> tx_param;
					serenity_project_dict_obj t_obj;

					t_obj.key = _("Image");
					t_obj.val = _("");
					tx_param.push_back(t_obj);

					t_obj.key = _("id");
					t_obj.val = new_texture_id_name;
					tx_param.push_back(t_obj);

					t_obj.key = _("file");
					t_obj.val = filename;
					tx_param.push_back(t_obj);

					int project_texture_index = load_texture(tx_param);

					if(project_texture_index >= 0)
					{
						while(p_mat.texture_id.size() < (level+1))
							p_mat.texture_id.push_back(-1);

						p_mat.texture_id[level] = project_texture_index;

						if(textures[project_texture_index].texture)
						{
							p_mat.material.setTexture(level, textures[project_texture_index].texture);
						}
					}
				}
			}

			break;
		}
	}

	return p_mat;
}

wxString serenity_project::genTextureID()
{
	wxString tmp_name = _("texture_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < textures.size(); i++)
		{
			if(textures[i].id_name.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genMaterialID()
{
	wxString tmp_name = _("material_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < materials.size(); i++)
		{
			if(materials[i].id_name.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genMaterialFileName(wxString tmp_name)
{
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n) + _(".snmtl");
		name_n++;

		name_found = true;

		for(int i = 0; i < materials.size(); i++)
		{
			if(materials[i].file.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genMeshID()
{
	wxString tmp_name = _("mesh_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < meshes.size(); i++)
		{
			if(meshes[i].id_name.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genMeshAnimationID(int mesh_index)
{
	wxString tmp_name = _("ANIMATION_ID");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < meshes[mesh_index].animation.size(); i++)
		{
			if(meshes[mesh_index].animation[i].id_name.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genAN8ID()
{
	wxString tmp_name = _("an8_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < anim8or_projects.size(); i++)
		{
			if(anim8or_projects[i].id_name.compare(new_name)==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}





bool serenity_project::save_material(int material_index)
{
	if(material_index < 0 || material_index >= materials.size())
		return false;

	rc_material p_mat = materials[material_index];

	if(p_mat.file.compare(_(""))==0)
		return false;

	wxFileName fname = project_path;
	fname.AppendDir(_("materials"));
	fname.SetFullName(p_mat.file);

	wxFile mat_file(fname.GetAbsolutePath(), wxFile::write);

	if(!mat_file.IsOpened())
		return false;


	switch(p_mat.material.MaterialType)
	{
		case irr::video::EMT_DETAIL_MAP: 		mat_file.Write(_("type=MATERIAL_TYPE_DETAIL_MAP;")); break;

		case irr::video::EMT_LIGHTMAP: 	 		mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP;")); break;

		case irr::video::EMT_LIGHTMAP_ADD:		mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_ADD;")); break;

		case irr::video::EMT_LIGHTMAP_LIGHTING:	mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_LIGHTING;")); break;

		case irr::video::EMT_LIGHTMAP_LIGHTING_M2:	mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_LIGHTING_M2;")); break;

		case irr::video::EMT_LIGHTMAP_LIGHTING_M4:	mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_LIGHTING_M4;")); break;

		case irr::video::EMT_LIGHTMAP_M2:		mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_M2;")); break;

		case irr::video::EMT_LIGHTMAP_M4:		mat_file.Write(_("type=MATERIAL_TYPE_LIGHTMAP_M4;")); break;

		case irr::video::EMT_NORMAL_MAP_SOLID:	mat_file.Write(_("type=MATERIAL_TYPE_NORMAL_MAP_SOLID;")); break;

		case irr::video::EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR:	mat_file.Write(_("type=MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_ADD_COLOR;")); break;

		case irr::video::EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA:	mat_file.Write(_("type=MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA;")); break;

		case irr::video::EMT_ONETEXTURE_BLEND:	mat_file.Write(_("type=MATERIAL_TYPE_ONETEXTURE_BLEND;")); break;

		case irr::video::EMT_PARALLAX_MAP_SOLID:	mat_file.Write(_("type=MATERIAL_TYPE_PARALLAX_MAP_SOLID;")); break;

		case irr::video::EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR:	mat_file.Write(_("type=MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_ADD_COLOR;")); break;

		case irr::video::EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA:		mat_file.Write(_("type=MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA;")); break;

		case irr::video::EMT_REFLECTION_2_LAYER:	mat_file.Write(_("type=MATERIAL_TYPE_REFLECTION_2_LAYER;")); break;

		case irr::video::EMT_SOLID:		mat_file.Write(_("type=MATERIAL_TYPE_SOLID;")); break;

		case irr::video::EMT_SOLID_2_LAYER:		mat_file.Write(_("type=MATERIAL_TYPE_SOLID_2_LAYER;")); break;

		case irr::video::EMT_SPHERE_MAP:	mat_file.Write(_("type=MATERIAL_TYPE_SPHERE_MAP;")); break;

		case irr::video::EMT_TRANSPARENT_ADD_COLOR:		mat_file.Write(_("type=MATERIAL_TYPE_TRANSPARENT_ADD_COLOR;")); break;

		case irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL:		mat_file.Write(_("type=MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL;")); break;

		case irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF:		mat_file.Write(_("type=MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL_REF;")); break;

		case irr::video::EMT_TRANSPARENT_REFLECTION_2_LAYER:	mat_file.Write(_("type=MATERIAL_TYPE_TRANSPARENT_REFLECTION_2_LAYER;")); break;

		case irr::video::EMT_TRANSPARENT_VERTEX_ALPHA:		mat_file.Write(_("type=MATERIAL_TYPE_TRANSPARENT_VERTEX_ALPHA;")); break;
	}

	mat_file.Write(_("\n"));

	mat_file.Write(_("ambient_color=") + wxString::Format(_("%u"), p_mat.material.AmbientColor.color) + _(";"));
	mat_file.Write(_("\n"));

	mat_file.Write(_("diffuse_color=") + wxString::Format(_("%u"), p_mat.material.DiffuseColor.color) + _(";"));
	mat_file.Write(_("\n"));

	mat_file.Write(_("emissive_color=") + wxString::Format(_("%u"), p_mat.material.EmissiveColor.color) + _(";"));
	mat_file.Write(_("\n"));

	mat_file.Write(_("specular_color=") + wxString::Format(_("%u"), p_mat.material.SpecularColor.color) + _(";"));
	mat_file.Write(_("\n"));


	switch(p_mat.material.AntiAliasing)
	{
		case irr::video::EAAM_ALPHA_TO_COVERAGE:	mat_file.Write(_("anti_alias=ANTI_ALIAS_ALPHA_TO_COVERAGE;")); break;

		case irr::video::EAAM_FULL_BASIC:	mat_file.Write(_("anti_alias=ANTI_ALIAS_FULL_BASIC;")); break;

		case irr::video::EAAM_LINE_SMOOTH:	mat_file.Write(_("anti_alias=ANTI_ALIAS_LINE_SMOOTH;")); break;

		case irr::video::EAAM_OFF:	mat_file.Write(_("anti_alias=ANTI_ALIAS_OFF;")); break;

		case irr::video::EAAM_POINT_SMOOTH:		mat_file.Write(_("anti_alias=ANTI_ALIAS_POINT_SMOOTH;")); break;

		case irr::video::EAAM_QUALITY:	mat_file.Write(_("anti_alias=ANTI_ALIAS_QUALITY;")); break;

		case irr::video::EAAM_SIMPLE:	mat_file.Write(_("anti_alias=ANTI_ALIAS_SIMPLE;")); break;

	}

	mat_file.Write(_("\n"));

	mat_file.Write(_("backface_culling=") + ( p_mat.material.BackfaceCulling ? _("true;") : _("false;") ));
	mat_file.Write(_("\n"));

	mat_file.Write(_("frontface_culling=") + ( p_mat.material.FrontfaceCulling ? _("true;") : _("false;") ));
	mat_file.Write(_("\n"));

	mat_file.Write(_("blend_factor=") + wxString::FromDouble(p_mat.material.BlendFactor) + _(";"));
	mat_file.Write(_("\n"));

	switch(p_mat.material.BlendOperation)
	{
		case irr::video::EBO_ADD:	mat_file.Write(_("blend_mode=BLENDMODE_ADD;")); break;

		case irr::video::EBO_MAX:	mat_file.Write(_("blend_mode=BLENDMODE_MAX;")); break;

		case irr::video::EBO_MAX_ALPHA:	mat_file.Write(_("blend_mode=BLENDMODE_MAX_ALPHA;")); break;

		case irr::video::EBO_MAX_FACTOR:	mat_file.Write(_("blend_mode=BLENDMODE_MAX_FACTOR;")); break;

		case irr::video::EBO_MIN:	mat_file.Write(_("blend_mode=BLENDMODE_MIN;")); break;

		case irr::video::EBO_MIN_ALPHA:		mat_file.Write(_("blend_mode=BLENDMODE_MIN_ALPHA;")); break;

		case irr::video::EBO_MIN_FACTOR:	mat_file.Write(_("blend_mode=BLENDMODE_MIN_FACTOR;")); break;

		case irr::video::EBO_NONE:	mat_file.Write(_("blend_mode=BLENDMODE_NONE;")); break;

		case irr::video::EBO_REVSUBTRACT:	mat_file.Write(_("blend_mode=BLENDMODE_REVSUBTRACT;")); break;

		case irr::video::EBO_SUBTRACT:	mat_file.Write(_("blend_mode=BLENDMODE_SUBTRACT;")); break;

	}

	mat_file.Write(_("\n"));

	switch(p_mat.material.ColorMask)
	{
		case irr::video::ECP_ALL:	mat_file.Write(_("color_mask=COLORMASK_ALL;")); break;

		case irr::video::ECP_ALPHA: mat_file.Write(_("color_mask=COLORMASK_ALPHA;")); break;

		case irr::video::ECP_BLUE:	mat_file.Write(_("color_mask=COLORMASK_BLUE;")); break;

		case irr::video::ECP_GREEN:	mat_file.Write(_("color_mask=COLORMASK_GREEN;")); break;

		case irr::video::ECP_NONE:	mat_file.Write(_("color_mask=COLORMASK_NONE;")); break;

		case irr::video::ECP_RED:	mat_file.Write(_("color_mask=COLORMASK_RED;")); break;

		case irr::video::ECP_RGB:	mat_file.Write(_("color_mask=COLORMASK_RGB;")); break;
	}

	mat_file.Write(_("\n"));

	switch(p_mat.material.ColorMaterial)
	{
		case irr::video::ECM_AMBIENT:	mat_file.Write(_("color_mode=COLOR_MODE_AMBIENT;")); break;

		case irr::video::ECM_DIFFUSE:	mat_file.Write(_("color_mode=COLOR_MODE_DIFFUSE;")); break;

		case irr::video::ECM_DIFFUSE_AND_AMBIENT:	mat_file.Write(_("color_mode=COLOR_MODE_DIFFUSE_AND_AMBIENT;")); break;

		case irr::video::ECM_EMISSIVE:	mat_file.Write(_("color_mode=COLOR_MODE_EMISSIVE;")); break;

		case irr::video::ECM_NONE:	mat_file.Write(_("color_mode=COLOR_MODE_NONE;")); break;

		case irr::video::ECM_SPECULAR:	mat_file.Write(_("color_mode=COLOR_MODE_SPECULAR;")); break;
	}

	mat_file.Write(_("\n"));

	mat_file.Write(_("fog=") + (p_mat.material.FogEnable ? _("true;") : _("false;")));
	mat_file.Write(_("\n"));

	mat_file.Write(_("gourad_shading=") + (p_mat.material.GouraudShading ? _("true;") : _("false;")) );
	mat_file.Write(_("\n"));

	mat_file.Write(_("lighting=") + (p_mat.material.Lighting ? _("true;") : _("false;")) );
	mat_file.Write(_("\n"));

	mat_file.Write(_("normalize=") + (p_mat.material.NormalizeNormals ? _("true;") : _("false;")) );
	mat_file.Write(_("\n"));

	mat_file.Write(_("point_cloud=") + (p_mat.material.PointCloud ? _("true;") : _("false;")) );
	mat_file.Write(_("\n"));

	mat_file.Write(_("shineness=") + wxString::FromDouble(p_mat.material.Shininess) + _(";") );
	mat_file.Write(_("\n"));

	mat_file.Write(_("thickness=") + wxString::FromDouble(p_mat.material.Thickness) + _(";"));
	mat_file.Write(_("\n"));

	mat_file.Write(_("wireframe=") + (p_mat.material.Wireframe ? _("true;") : _("false;")) );
	mat_file.Write(_("\n"));

	for(int i = 0; i < p_mat.texture_id.size(); i++)
	{
		if(p_mat.texture_id[i] >= 0 && p_mat.texture_id[i] < textures.size())
		{
			int tx_id = p_mat.texture_id[i];

			if(textures[tx_id].file.compare(_(""))!=0 && textures[tx_id].id_name.compare(_(""))!=0)
			{
				mat_file.Write(_("texture  level=") + wxString::Format(_("%d"), i) + _("  file=") + textures[tx_id].file + _(";"));
				mat_file.Write(_("\n"));
			}
		}
	}

	mat_file.Close();

	return true;
}

bool serenity_project::save_mesh_properties(int mesh_index)
{
	if(mesh_index < 0 || mesh_index >= meshes.size())
		return false;

	rc_mesh p_mesh = meshes[mesh_index];

	if(p_mesh.id_name.compare("")==0)
		return false;

	wxFileName fname = project_path;
	fname.AppendDir(_("data"));
	fname.SetFullName(wxString::FromUTF8(p_mesh.id_name) + _(".snmd"));

	wxFile md_file(fname.GetAbsolutePath(), wxFile::write);

	if(!md_file.IsOpened())
		return false;

	for(int i = 0; i < p_mesh.material_index.size(); i++)
	{
		if(p_mesh.material_index[i] < 0 || p_mesh.material_index[i] >= materials.size())
		{
			md_file.Write(_("material=[NULL]; \n"));
			continue;
		}

		if(materials[ p_mesh.material_index[i] ].id_name.compare("") == 0)
		{
			md_file.Write(_("material=[NULL]; \n"));
			continue;
		}

		md_file.Write(_("material=") + materials[ p_mesh.material_index[i] ].id_name + _("; \n"));
	}


	md_file.Close();


	fname.SetFullName(wxString::FromUTF8(p_mesh.id_name) + _(".sna"));

	wxFile ani_file(fname.GetAbsolutePath(), wxFile::write);

	if(!ani_file.IsOpened())
		return false;

	for(int i = 0; i < p_mesh.animation.size(); i++)
	{
		if(p_mesh.isMD2 && i < irr::scene::EMAT_COUNT)  //Not adding default MD2 animations since it would only duplicate them on load
			continue;

		if(p_mesh.animation[i].id_name.compare("") != 0)
		{
			ani_file.Write(_("id=") + wxString::FromUTF8(p_mesh.animation[i].id_name) + _(" "));
			ani_file.Write(_("start=") + wxString::Format(_("%d"), p_mesh.animation[i].start_frame) + _(" "));
			ani_file.Write(_("end=") + wxString::Format(_("%d"), p_mesh.animation[i].end_frame) + _(" "));
			ani_file.Write(_("speed=") + wxString::FromDouble((double)p_mesh.animation[i].speed) + _("; \n"));
		}
	}

	ani_file.Close();

	return true;
}


void serenity_project::load_material_list(rc_mesh* p_mesh, wxString ml_file)
{
	wxFileName fname = project_path;
	fname.AppendDir(_("data"));
	fname.SetFullName(ml_file);

	if(!fname.Exists())
	{
		//wxMessageBox(_("Material List Not found"));
		return;
	}

	wxFile mfile(fname.GetAbsolutePath());

	if(!mfile.IsOpened())
		return;

	wxString content;
	mfile.ReadAll(&content);

	mfile.Close();

	std::vector<serenity_project_file_obj> file_obj = getParams(content);

	for(int i = 0; i < file_obj.size(); i++)
	{
		if(file_obj[i].dict.size() > 0)
		{
			if(file_obj[i].dict[0].key.compare(_("material"))==0)
				p_mesh->ref_material_id.push_back(file_obj[i].dict[0].val.ToStdString());
		}
	}
}
