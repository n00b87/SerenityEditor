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

	bool dbg_out = false;
	int dbg_index = 0;

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
			/*if(dict_obj.val.compare(_("sydney"))==0)
			{
				dbg_out = true;
				dbg_index = dlist.size();
			}*/

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

	/*if(dbg_out)
	{
		for(int i = 0; i < dlist[dbg_index].dict.size(); i++)
			wxMessageBox(_("Key=") + dlist[dbg_index].dict[i].key + _(",   Value=") + dlist[dbg_index].dict[i].val);
	}*/

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

	setDefaults();

	if(!project_path.Exists())
	{
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
			else if(dict[0].key.compare(_("Grid"))==0)
				init_grid(dict);
			else if(dict[0].key.compare(_("Tool"))==0)
				init_tools(dict);
			else if(dict[0].key.compare(_("Camera"))==0)
				init_camera(dict);
			else if(dict[0].key.compare(_("HUD"))==0)
				init_hud(dict);


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

bool serenity_project::genRCBasicProject()
{
	rcbasic_project_path = project_path;
	rcbasic_project_path.SetExt(_("rcprj"));

	wxMessageBox(_("RC: ") + rcbasic_project_path.GetAbsolutePath());

	if(!rcbasic_project_path.Exists())
	{
		wxFile rc_project_file(rcbasic_project_path.GetAbsolutePath(), wxFile::write);

		if(!rc_project_file.IsOpened())
		{
			wxMessageBox(_("Error: Failed to generate RCBasic Studio Project"));
			return false;
		}

		//Project File stuff here
		//RCBASIC_STUDIO:1.0
		//PROJECT_NAME:Simple 3D Platformer
		//PROJECT_MAIN:main.bas
		//AUTHOR:n00b
		//WEBSITE:rcbasic.freeforums.net
		//DESCRIPTION:A simple physics example in RCBasic 4
		//SOURCE_REL:main.bas
		//SOURCE_REL:util.bas

		rcbasic_main_bas = _("serenity_main.bas");

		rc_project_file.Write(_("RCBASIC_STUDIO:1.0") + _("\n"));
		rc_project_file.Write(_("PROJECT_NAME:") + wxString::FromUTF8(project_name) + _("\n"));
		rc_project_file.Write(_("PROJECT_MAIN:") + rcbasic_main_bas + _("\n"));
		rc_project_file.Write(_("SOURCE_REL:") + rcbasic_main_bas + _("\n"));
		rc_project_file.Write(_("SOURCE_REL:main.bas") + _("\n"));


		rc_project_file.Close();
	}

	//Write project structures to rcbasic_main_bas
	wxFileName main_file_path = project_path;
	main_file_path.SetFullName(_("serenity_main.bas"));
	wxFile pfile(main_file_path.GetAbsolutePath(), wxFile::write);

	if(!pfile.IsOpened())
	{
		wxMessageBox(_("Error: Failed to output project structures"));
		return false;
	}

	pfile.Write(_("path_separator$ = \"/\" : "));

	pfile.Write(_("If OS$ = \"WINDOWS\" : path_separator$ = \"\\\\\" : End If") + _("\n"));
	pfile.Write(_("\n\n"));

	pfile.Write(_("Const SN_MESH_TYPE_NORMAL = 0") + _("\n"));
	pfile.Write(_("Const SN_MESH_TYPE_ZIPPED = 1") + _("\n"));
	pfile.Write(_("Const SN_MESH_TYPE_AN8_SCENE = 2") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Const SN_LIGHT_TYPE_POINT = 0") + _("\n"));
	pfile.Write(_("Const SN_LIGHT_TYPE_SPOT = 1") + _("\n"));
	pfile.Write(_("Const SN_LIGHT_TYPE_DIRECTIONAL = 2") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Const SN_PARTICLE_TYPE_POINT = 0") + _("\n"));
	pfile.Write(_("Const SN_PARTICLE_TYPE_BOX = 1") + _("\n"));
	pfile.Write(_("Const SN_PARTICLE_TYPE_SPHERE = 2") + _("\n"));
	pfile.Write(_("Const SN_PARTICLE_TYPE_CYLINDER = 3") + _("\n"));
	pfile.Write(_("Const SN_PARTICLE_TYPE_MESH = 4") + _("\n"));
	pfile.Write(_("Const SN_PARTICLE_TYPE_RING = 5") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Const SN_PHYSICS_SHAPE_NONE = 0") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_BOX = 1") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_SPHERE = 2") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_CYLINDER = 3") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_CAPSULE = 4") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_CONE = 5") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_CONVEXHULL = 6") + _("\n"));
	pfile.Write(_("Const SN_PHYSICS_SHAPE_TRIMESH = 7") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Const SN_ACTOR_TYPE_ANIMATED = 0") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_OCTREE = 1") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_LIGHT = 2") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_BILLBOARD = 3") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_TERRAIN = 4") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_WATER = 5") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_PARTICLE = 6") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_CUBE = 7") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_SPHERE = 8") + _("\n"));
	pfile.Write(_("Const SN_ACTOR_TYPE_PLANE = 9") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Const SN_SKY_TYPE_NONE = 0") + _("\n"));
	pfile.Write(_("Const SN_SKY_TYPE_BOX = 1") + _("\n"));
	pfile.Write(_("Const SN_SKY_TYPE_DOME = 2") + _("\n"));

	pfile.Write(_("\n\n"));

	//Vector Structure
	pfile.Write(_("Type Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim x") + _("\n"));
	pfile.Write(_("Dim y") + _("\n"));
	pfile.Write(_("Dim z") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Size Structure
	pfile.Write(_("Type Serenity_Size") + _("\n"));
	pfile.Write(_("Dim Width") + _("\n"));
	pfile.Write(_("Dim Height") + _("\n"));
	pfile.Write(_("Dim Depth") + _("\n")); //won't be used for much but I don't want to have 2 size structs for 2d and 3d
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));


	//Create Vector3D Function
	pfile.Write(_("Function Serenity_CreateVector3D(x, y, z) As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("\tDim v As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("\tv.x = x") + _("\n"));
	pfile.Write(_("\tv.y = y") + _("\n"));
	pfile.Write(_("\tv.z = z") + _("\n"));
	pfile.Write(_("\tReturn v") + _("\n"));
	pfile.Write(_("End Function") + _("\n"));

	pfile.Write(_("\n"));

	//Create Size3D Function
	pfile.Write(_("Function Serenity_CreateSize3D(w, h, d) As Serenity_Size") + _("\n"));
	pfile.Write(_("\tDim v As Serenity_Size") + _("\n"));
	pfile.Write(_("\tv.width = w") + _("\n"));
	pfile.Write(_("\tv.height = h") + _("\n"));
	pfile.Write(_("\tv.depth = d") + _("\n"));
	pfile.Write(_("\tReturn v") + _("\n"));
	pfile.Write(_("End Function") + _("\n"));

	pfile.Write(_("\n"));

	//Create Texture Structure
	pfile.Write(_("Type Serenity_Texture") + _("\n"));
	pfile.Write(_("Dim ID") + _("\n"));
	pfile.Write(_("Dim File$ ") + _("\n"));
	pfile.Write(_("Dim UseColorKey") + _("\n"));
	pfile.Write(_("Dim TextureColorKey ") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));
	pfile.Write(_("\n"));

	//Create Texture Reference Structure
	pfile.Write(_("Type Serenity_Texture_Reference") + _("\n"));
	pfile.Write(_("Dim SN_ID") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));
	pfile.Write(_("\n"));

	pfile.Write(_("Dim Serenity_Global_Texture_List[") + wxString::Format(_("%d"),(int)(textures.size() == 0 ? 1 : textures.size())) + _("] As Serenity_Texture") + _("\n"));
	pfile.Write(_("\n"));


	//Create Textures List Structure
	wxString p_textures_list_struct_name = _("Serenity_Textures_List_Structure");
	std::vector<wxString> p_textures_list_struct_field_define;
	pfile.Write(_("Type ") + p_textures_list_struct_name  + _("\n"));

	wxString p_texture_define = _("");

	uint32_t tx_sn_id = 0;

	for(int i = 0; i < textures.size(); i++)
	{
		if(textures[i].id_name.compare("")!=0)
		{
			pfile.Write(_("Dim ") + wxString::FromUTF8(textures[i].id_name)  + _(" As Serenity_Texture_Reference\n"));

			wxString tx_id = _("Serenity_Global_Texture_List[") + _("Textures.") + wxString::FromUTF8(textures[i].id_name) + _(".SN_ID") + _("]");

			wxString tx_path = _("\"textures\" + path_separator$ + ");
			wxString tx_file = tx_path + tx_id + _(".File$");
			wxString tx_colorkey = tx_id + _(".TextureColorKey");
			wxString p_cmd = _("\t") + _("Serenity_Global_Texture_List[ ") + _("Textures.") + wxString::FromUTF8(textures[i].id_name) + _(".SN_ID ].ID = ") +
															(textures[i].use_colorKey ? _("LoadImageEx(") + tx_file + _(", ") + tx_colorkey + _(")") :
																						_("LoadImage(") + tx_file + _(")") ) + _("\n");

			textures[i].p_cmd = p_cmd.ToStdString();

			p_texture_define += _("Textures.") + wxString::FromUTF8(textures[i].id_name) + _(".SN_ID = ") + wxString::Format(_("%u"),tx_sn_id) + _("\n");
			p_texture_define += tx_id + _(".ID = -1") + _("\n");
			p_texture_define += tx_id + _(".File$ = \"") + wxString::FromUTF8(textures[i].file) + _("\"") + _("\n");
			p_texture_define += tx_id + _(".TextureColorKey = ") + wxString::Format(_("%u"), textures[i].colorkey.color) + _("\n");
			p_texture_define += _("\n");

			tx_sn_id++;
		}
	}

	pfile.Write(_("End Type")  + _("\n"));

	pfile.Write(_("\n\n"));


	//Create Texture Reference Structure
	pfile.Write(_("Type Serenity_Material") + _("\n"));
	pfile.Write(_("Dim ID") + _("\n"));
	pfile.Write(_("Dim Textures[30] \'Index in Serenity_Global_Texture_List") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));
	pfile.Write(_("\n"));

	//Create Texture Reference Structure
	pfile.Write(_("Type Serenity_Material_Reference") + _("\n"));
	pfile.Write(_("Dim SN_ID") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));
	pfile.Write(_("\n"));

	pfile.Write(_("Dim Serenity_Global_Material_List[") + wxString::Format(_("%d"), (int)(materials.size() == 0 ? 1 : materials.size())) + _("] As Serenity_Material") + _("\n"));
	pfile.Write(_("\n"));



	//Create Materials List Structure
	wxString p_materials_list_struct_name = _("Serenity_Materials_List_Structure");
	std::vector<wxString> p_materials_list_struct_field_define;
	pfile.Write(_("Type ") + p_materials_list_struct_name  + _("\n"));

	uint32_t mat_sn_id = 0;

	for(int i = 0; i < materials.size(); i++)
	{
		if(materials[i].id_name.compare("")!=0)
		{
			pfile.Write(_("Dim ") + wxString::FromUTF8(materials[i].id_name)  + _(" As Serenity_Material_Reference\n"));

			wxString mat_ref_id = _("Materials") + _(".") + wxString::FromUTF8(materials[i].id_name) + _(".SN_ID");

			wxString mat_id = _("Serenity_Global_Material_List[") + mat_ref_id + _("].ID");
			wxString mat_str = _("\'------------MATERIAL[ ") + wxString::FromUTF8(materials[i].id_name) + _(" ]---------------") + _("\n");
			mat_str += mat_ref_id + _(" = ") + wxString::Format(_("%u"), mat_sn_id) + _("\n\n");

			mat_str += mat_id + _(" = CreateMaterial()") + _(" \n");

			mat_str += _("SetMaterialAmbientColor(") + mat_id + _(", ") + wxString::Format(_("%u"), materials[i].material.AmbientColor.color) + _(")") + _(" \n");
			mat_str += _("SetMaterialDiffuseColor(") + mat_id + _(", ") + wxString::Format(_("%u"), materials[i].material.DiffuseColor.color) + _(")") + _(" \n");
			mat_str += _("SetMaterialEmissiveColor(") + mat_id + _(", ") + wxString::Format(_("%u"), materials[i].material.EmissiveColor.color) + _(")") + _(" \n");
			mat_str += _("SetMaterialSpecularColor(") + mat_id + _(", ") + wxString::Format(_("%u"), materials[i].material.SpecularColor.color) + _(")") + _(" \n");

			switch(materials[i].material.AntiAliasing)
			{
				case irr::video::EAAM_OFF:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_OFF )") + _(" \n");
				}
				break;

				case irr::video::EAAM_SIMPLE:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_SIMPLE )") + _(" \n");
				}
				break;

				case irr::video::EAAM_QUALITY:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_QUALITY )") + _(" \n");
				}
				break;

				case irr::video::EAAM_LINE_SMOOTH:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_LINE_SMOOTH )") + _(" \n");
				}
				break;

				case irr::video::EAAM_POINT_SMOOTH:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_POINT_SMOOTH )") + _(" \n");
				}
				break;

				case irr::video::EAAM_FULL_BASIC:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_FULL_BASIC )") + _(" \n");
				}
				break;

				case irr::video::EAAM_ALPHA_TO_COVERAGE:
				{
					mat_str += _("SetMaterialAntiAliasing(") + mat_id + _(", AA_MODE_ALPHA_TO_COVERAGE )") + _(" \n");
				}
				break;
			}

			mat_str += _("SetMaterialBackfaceCulling(") + mat_id + _(", ") + (materials[i].material.BackfaceCulling ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");
			mat_str += _("SetMaterialFrontfaceCulling(") + mat_id + _(", ") + (materials[i].material.FrontfaceCulling ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");

			mat_str += _("SetMaterialBlendFactor(") + mat_id + _(", ") + wxString::FromDouble((double)materials[i].material.BlendFactor) + _(")") + _(" \n");

			switch(materials[i].material.BlendOperation)
			{
				case irr::video::EBO_NONE:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_NONE )") + _(" \n");
				}
				break;

				case irr::video::EBO_ADD:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_ADD )") + _(" \n");
				}
				break;

				case irr::video::EBO_SUBTRACT:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_SUBTRACT )") + _(" \n");
				}
				break;

				case irr::video::EBO_REVSUBTRACT:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_REVSUBTRACT )") + _(" \n");
				}
				break;

				case irr::video::EBO_MIN:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MIN )") + _(" \n");
				}
				break;

				case irr::video::EBO_MAX:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MAX )") + _(" \n");
				}
				break;

				case irr::video::EBO_MIN_FACTOR:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MIN_FACTOR )") + _(" \n");
				}
				break;

				case irr::video::EBO_MAX_FACTOR:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MAX_FACTOR )") + _(" \n");
				}
				break;

				case irr::video::EBO_MIN_ALPHA:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MIN_ALPHA )") + _(" \n");
				}
				break;

				case irr::video::EBO_MAX_ALPHA:
				{
					mat_str += _("SetMaterialBlendMode(") + mat_id + _(", BLEND_MODE_MAX_ALPHA )") + _(" \n");
				}
				break;
			}



			switch(materials[i].material.ColorMask)
			{
				case irr::video::ECP_NONE:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_NONE )") + _(" \n");
				}
				break;

				case irr::video::ECP_ALPHA:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_ALPHA )") + _(" \n");
				}
				break;

				case irr::video::ECP_RED:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_RED )") + _(" \n");
				}
				break;

				case irr::video::ECP_GREEN:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_GREEN )") + _(" \n");
				}
				break;

				case irr::video::ECP_BLUE:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_BLUE )") + _(" \n");
				}
				break;

				case irr::video::ECP_RGB:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_RGB )") + _(" \n");
				}
				break;

				case irr::video::ECP_ALL:
				{
					mat_str += _("SetMaterialColorMask(") + mat_id + _(", COLOR_MASK_ALL )") + _(" \n");
				}
				break;
			}



			switch(materials[i].material.ColorMaterial)
			{
				case irr::video::ECM_NONE:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_NONE )") + _(" \n");
				}
				break;

				case irr::video::ECM_DIFFUSE:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_DIFFUSE )") + _(" \n");
				}
				break;

				case irr::video::ECM_AMBIENT:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_AMBIENT )") + _(" \n");
				}
				break;

				case irr::video::ECM_EMISSIVE:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_EMISSIVE )") + _(" \n");
				}
				break;

				case irr::video::ECM_SPECULAR:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_SPECULAR )") + _(" \n");
				}
				break;

				case irr::video::ECM_DIFFUSE_AND_AMBIENT:
				{
					mat_str += _("SetMaterialColorMode(") + mat_id + _(", COLOR_MODE_DIFFUSE_AND_AMBIENT )") + _(" \n");
				}
				break;
			}


			mat_str += _("SetMaterialFog(") + mat_id + _(", ") + (materials[i].material.FogEnable ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");
			mat_str += _("SetMaterialGouraudShading(") + mat_id + _(", ") + (materials[i].material.GouraudShading ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");
			mat_str += _("SetMaterialLighting(") + mat_id + _(", ") + (materials[i].material.Lighting ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");

			switch(materials[i].material.MaterialType)
			{
				case irr::video::EMT_DETAIL_MAP:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_DETAIL_MAP )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_ADD:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_ADD )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_LIGHTING:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_LIGHTING )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_LIGHTING_M2:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_LIGHTING_M2 )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_LIGHTING_M4:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_LIGHTING_M4 )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_M2:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_M2 )") + _(" \n");
				}
				break;

				case irr::video::EMT_LIGHTMAP_M4:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_LIGHTMAP_M4 )") + _(" \n");
				}
				break;

				case irr::video::EMT_NORMAL_MAP_SOLID:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_NORMAL_MAP_SOLID )") + _(" \n");
				}
				break;

				case irr::video::EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_ADD_COLOR )") + _(" \n");
				}
				break;

				case irr::video::EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA )") + _(" \n");
				}
				break;

				case irr::video::EMT_ONETEXTURE_BLEND:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_ONETEXTURE_BLEND )") + _(" \n");
				}
				break;

				case irr::video::EMT_PARALLAX_MAP_SOLID:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_PARALLAX_MAP_SOLID )") + _(" \n");
				}
				break;

				case irr::video::EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_ADD_COLOR )") + _(" \n");
				}
				break;

				case irr::video::EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA )") + _(" \n");
				}
				break;

				case irr::video::EMT_REFLECTION_2_LAYER:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_REFLECTION_2_LAYER )") + _(" \n");
				}
				break;

				case irr::video::EMT_SOLID:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_SOLID )") + _(" \n");
				}
				break;

				case irr::video::EMT_SOLID_2_LAYER:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_SOLID_2_LAYER )") + _(" \n");
				}
				break;

				case irr::video::EMT_SPHERE_MAP:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_SPHERE_MAP )") + _(" \n");
				}
				break;

				case irr::video::EMT_TRANSPARENT_ADD_COLOR:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_TRANSPARENT_ADD_COLOR )") + _(" \n");
				}
				break;

				case irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL )") + _(" \n");
				}
				break;

				case irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_TRANSPARENT_ALPHA_CHANNEL_REF )") + _(" \n");
				}
				break;

				case irr::video::EMT_TRANSPARENT_REFLECTION_2_LAYER:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_TRANSPARENT_REFLECTION_2_LAYER )") + _(" \n");
				}
				break;

				case irr::video::EMT_TRANSPARENT_VERTEX_ALPHA:
				{
					mat_str += _("SetMaterialType(") + mat_id + _(", MATERIAL_TYPE_TRANSPARENT_VERTEX_ALPHA )") + _(" \n");
				}
				break;
			}

			mat_str += _("SetMaterialNormalize(") + mat_id + _(", ") + (materials[i].material.NormalizeNormals ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");
			mat_str += _("SetMaterialPointCloud(") + mat_id + _(", ") + (materials[i].material.PointCloud ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");

			mat_str += _("SetMaterialShininess(") + mat_id + _(", ") + wxString::FromDouble((double)materials[i].material.Shininess) + _(")") + _(" \n");
			mat_str += _("SetMaterialThickness(") + mat_id + _(", ") + wxString::FromDouble((double)materials[i].material.Thickness) + _(")") + _(" \n");

			mat_str += _("SetMaterialWireframe(") + mat_id + _(", ") + (materials[i].material.Wireframe ? _("TRUE") : _("FALSE")) + _(")") + _(" \n");

			mat_str += _("\n");


			wxString p_onLoad_cmd = _("");
			for(int m_texture_level = 0; m_texture_level < materials[i].texture_id.size(); m_texture_level++)
			{
				int mt_index = materials[i].texture_id[m_texture_level];

				if(mt_index < 0 || mt_index >= textures.size())
					continue;

				wxString tx_id = wxString::FromUTF8(textures[mt_index].id_name).Trim();

				if(tx_id.compare(_(""))==0)
					continue;

				tx_id = _("Textures.") + tx_id + _(".SN_ID");

				wxString mat_struct = _("Serenity_Global_Material_List[") + mat_ref_id + _("]");

				mat_str += mat_struct + _(".Textures[") + wxString::Format(_("%d"), m_texture_level) + _("] = ") + tx_id + _("\n");

				p_onLoad_cmd += _("\t") + _("SetMaterialTexture(") + mat_id + _(", ") + wxString::Format(_("%d"), m_texture_level) + _(", Serenity_Global_Texture_List[") + tx_id + _("].ID )") + _(" \n");
			}

			mat_sn_id++;

			materials[i].p_cmd = mat_str.ToStdString();
			materials[i].p_onLoad_cmd = p_onLoad_cmd.ToStdString();
		}
	}

	pfile.Write(_("End Type") + _("\n"));


	pfile.Write(_("\n"));

	//Create Anim8or project structures
	wxString p_an8_structure_name = _("Serenity_AN8_Projects_Structure");
	pfile.Write(_("Type ") + p_an8_structure_name + _("\n"));

	for(int i = 0; i < anim8or_projects.size(); i++)
	{
		wxString an8_id = wxString::FromUTF8(anim8or_projects[i].id_name).Trim();
		if(an8_id.compare("")==0)
			continue;

		pfile.Write(_("Dim ") + an8_id + _("\n"));

		wxString mesh_path = _("\"models\" + path_separator$ + ");
		wxString p_cmd = _("Anim8or_Projects.") + an8_id + _(" = LoadAN8(") + mesh_path + _("\"") + wxString::FromUTF8(anim8or_projects[i].file) + _("\")");
		anim8or_projects[i].p_cmd = p_cmd.ToStdString();
	}

	pfile.Write(_("End Type") + _(" \n"));

	pfile.Write(_("\n"));

	//Create Mesh Animation Structure
	pfile.Write(_("Type Serenity_Mesh_Animation") + _("\n"));
	pfile.Write(_("Dim Name$ ") + _("\n"));
	pfile.Write(_("Dim Start_Frame") + _("\n"));
	pfile.Write(_("Dim End_Frame") + _("\n"));
	pfile.Write(_("Dim Speed") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));
	pfile.Write(_("\n"));


	//Create Mesh Structures
	pfile.Write(_("Type Serenity_Mesh") + _("\n"));

	pfile.Write(_("Dim ID ") + _("\n"));
	pfile.Write(_("Dim SN_ID") + _("\n"));
	pfile.Write(_("Dim MeshType ") + _("\n"));
	pfile.Write(_("Dim AN8 ") + _("\n"));
	pfile.Write(_("Dim AN8_Scene$ ") + _("\n"));
	pfile.Write(_("Dim Zip$ ") + _("\n"));
	pfile.Write(_("Dim File$ ") + _("\n"));
	pfile.Write(_("Dim Materials[30] ") + _("\n"));
	pfile.Write(_("Dim MaterialCount ") + _("\n"));
	pfile.Write(_("Dim Animations[20] As Serenity_Mesh_Animation") + _("\n"));
	pfile.Write(_("Dim AnimationCount ") + _("\n"));

	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Create Mesh Structures
	pfile.Write(_("Type Serenity_Mesh_Reference") + _("\n"));
	pfile.Write(_("Dim SN_ID") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));


	pfile.Write(_("\n"));

	pfile.Write(_("Dim Serenity_Global_Mesh_List[") + wxString::Format(_("%u"), (int)(meshes.size()==0 ? 1 : meshes.size())) + _("] As Serenity_Mesh") + _("\n"));

	pfile.Write(_("\n"));


	//Create Mesh and Animation List Structures (A different animation structure will be made for every mesh)
	std::vector<wxString> p_mesh_struct_field_define;
	int mesh_sn_id = 0;

	for(int i = 0; i < meshes.size(); i++)
	{
		wxString mesh_id = wxString::FromUTF8(meshes[i].id_name).Trim();

		if(mesh_id.compare(_(""))==0)
			continue;

		wxString mesh_struct_field = _("Dim ") + mesh_id + _(" As Serenity_Mesh_Reference") + _(" \n");
		p_mesh_struct_field_define.push_back(mesh_struct_field);

		wxString p_cmd = _("\'-----MESH[ ") + mesh_id + _(" ]------------") + _("\n");

		wxString mesh_path = _("\"models\" + path_separator$ + ");

		meshes[i].sn_id = mesh_sn_id;
		wxString mesh_sn_str = _("Meshes.") + mesh_id + _(".SN_ID");
		p_cmd += _("Meshes.") + mesh_id + _(".SN_ID = ") + wxString::Format(_("%d"), mesh_sn_id) + _("\n");

		wxString mesh_list_id = _("Serenity_Global_Mesh_List[") + mesh_sn_str + _("]");
		mesh_sn_id++;


		if(meshes[i].isAN8Scene)
		{
			p_cmd += mesh_list_id + _(".MeshType = SN_MESH_TYPE_AN8_SCENE") + _("\n");

			int an8_index = meshes[i].an8_index;
			wxString an8_id = _("-1");
			if(an8_index >= 0 && an8_index < anim8or_projects.size())
			{
				an8_id = wxString::FromUTF8(anim8or_projects[an8_index].id_name);
			}
			p_cmd += mesh_list_id + _(".AN8 = Anim8or_Projects.") + an8_id + _("\n");

			wxString an8_scene = wxString::FromUTF8(meshes[i].an8_scene);
			p_cmd += mesh_list_id + _(".AN8_Scene$ = \"") + an8_scene + _("\" \n");

			meshes[i].p_cmd = p_cmd.ToStdString();

			//OnLoad
			p_cmd = mesh_list_id + _(".ID = LoadMeshFromAN8(") + an8_id + _(", \"") + an8_scene + _("\")") + _("\n");
			meshes[i].p_onLoad_cmd = p_cmd;

			p_cmd = _("");
		}
		else if(meshes[i].isZipped)
		{
			p_cmd += mesh_list_id + _(".MeshType = SN_MESH_TYPE_ZIPPED") + _("\n");
			p_cmd += mesh_list_id + _(".Zip$ = ") + _("\"") + wxString::FromUTF8(meshes[i].zip_file) + _("\"") + _("\n");
			p_cmd += mesh_list_id + _(".File$ = \"") + wxString::FromUTF8(meshes[i].file) + _("\"") + _("\n");

			meshes[i].p_cmd = p_cmd.ToStdString();

			p_cmd = _("");
			p_cmd = mesh_list_id + _(".ID = LoadMeshFromArchive(") + mesh_path + _("\"") + wxString::FromUTF8(meshes[i].zip_file) + _("\", \"") + wxString::FromUTF8(meshes[i].file) + _("\")") + _("\n");
			meshes[i].p_onLoad_cmd = p_cmd;
		}
		else
		{
			p_cmd += mesh_list_id + _(".MeshType = SN_MESH_TYPE_NORMAL") + _("\n");
			p_cmd += mesh_list_id + _(".File$ = ") +  _("\"") + wxString::FromUTF8(meshes[i].file) + _("\"") + _("\n");

			meshes[i].p_cmd = p_cmd.ToStdString();

			p_cmd = mesh_list_id + _(".ID = LoadMesh(") + mesh_path + _("\"") + wxString::FromUTF8(meshes[i].file) + _("\")") + _("\n");
			meshes[i].p_onLoad_cmd = p_cmd;
		}

		p_cmd = _("\n");
		p_cmd += mesh_list_id + _(".AnimationCount = ") + wxString::Format(_("%d"), (int)meshes[i].animation.size()) + _("\n");

		if(!meshes[i].isMD2)
		{
			for(uint32_t ani = 0; ani < meshes[i].animation.size(); ani++)
			{
				p_cmd += mesh_list_id + _(".Animations[") + wxString::Format(_("%u"), ani) + _("].Name$ = \"") + wxString::FromUTF8(meshes[i].animation[ani].id_name) + _("\"\n");
				p_cmd += mesh_list_id + _(".Animations[") + wxString::Format(_("%u"), ani) + _("].Start_Frame = ") + wxString::Format(_("%d"), meshes[i].animation[ani].start_frame) + _("\n");
				p_cmd += mesh_list_id + _(".Animations[") + wxString::Format(_("%u"), ani) + _("].End_Frame = ") + wxString::Format(_("%d"), meshes[i].animation[ani].end_frame) + _("\n");
				p_cmd += mesh_list_id + _(".Animations[") + wxString::Format(_("%u"), ani) + _("].Speed = ") + wxString::FromDouble(meshes[i].animation[ani].speed) + _("\n");
				p_cmd += _("\n");
			}

			meshes[i].p_cmd += p_cmd.ToStdString();
		}

		p_cmd = _("");

		if(meshes[i].material_index.size() > 30)
		{
			//Resizing TYPE fields does not currently work in RCBasic. I will come back to this once I add this feature to RCBasic
			//p_cmd += _("ReDim ") + mesh_list_id + _(".Materials[") wxString::Format(_("%d"), meshes[i].material_index.size()) + _("]") + _("\n");
		}

		for(int mat = 0; mat < meshes[i].material_index.size(); mat++)
		{
			if(meshes[i].material_index[mat] >= 0 && meshes[i].material_index[mat] < materials.size())
			{
				int mat_index = meshes[i].material_index[mat];

				if(materials[mat_index].id_name.compare("")==0)
					continue;

				wxString mat_ref_id = _("Materials") + _(".") + wxString::FromUTF8(materials[mat_index].id_name) + _(".SN_ID");
				p_cmd += mesh_list_id + _(".Materials[") + wxString::Format(_("%d"), mat) + _("] = ") + mat_ref_id + _("\n");
			}
		}

		meshes[i].p_cmd += p_cmd.ToStdString();
	}

	//Output Global Mesh Project Structure
	pfile.Write(_("\n"));
	pfile.Write(_("Type Serenity_Meshes_List_Structure") + _(" \n"));

	for(int i = 0; i < p_mesh_struct_field_define.size(); i++)
	{
		pfile.Write(p_mesh_struct_field_define[i]);
	}

	pfile.Write(_("End Type")  + _("\n"));

	//Create Sky Structure
	pfile.Write(_("\n"));

	wxString p_sky_struct_name = _("Serenity_Sky_Structure");

	pfile.Write(_("Type Serenity_Sky_Dome") + _("\n"));
	pfile.Write(_("Dim Image ") + _("\n"));
	pfile.Write(_("Dim hRes ") + _("\n"));
	pfile.Write(_("Dim vRes ") + _("\n"));
	pfile.Write(_("Dim TexturePCT ") + _("\n"));
	pfile.Write(_("Dim SpherePCT ") + _("\n"));
	pfile.Write(_("Dim Radius ") + _("\n"));
	pfile.Write(_("End Type ") + _("\n"));
	pfile.Write(_("\n"));

	pfile.Write(_("Type Serenity_Sky_Box ") + _("\n"));
	pfile.Write(_("Dim Image_Left ") + _("\n"));
	pfile.Write(_("Dim Image_Right ") + _("\n"));
	pfile.Write(_("Dim Image_Top ") + _("\n"));
	pfile.Write(_("Dim Image_Bottom ") + _("\n"));
	pfile.Write(_("Dim Image_Front ") + _("\n"));
	pfile.Write(_("Dim Image_Back ") + _("\n"));
	pfile.Write(_("End Type ") + _("\n"));
	pfile.Write(_("\n"));

	pfile.Write(_("Type ") + p_sky_struct_name + _("\n"));
	pfile.Write(_("Dim Shape ") + _("\n"));
	pfile.Write(_("Dim Dome As Serenity_Sky_Dome ") + _("\n"));
	pfile.Write(_("Dim Box As Serenity_Sky_Box ") + _("\n"));
	pfile.Write(_("End Type ") + _("\n"));
	pfile.Write(_("\n"));

	//Create Stage Structures
	pfile.Write(_("\n"));

	//Actor Physics Structure
	pfile.Write(_("Type Serenity_Actor_Physics") + _("\n"));
	pfile.Write(_("Dim Shape") + _("\n"));
	pfile.Write(_("Dim Mass") + _("\n"));
	pfile.Write(_("Dim isSolid") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));



	//Actor Light Structure
	pfile.Write(_("Type Serenity_Light_Properties") + _("\n"));
	pfile.Write(_("Dim LightType") + _("\n"));
	pfile.Write(_("Dim CastShadow") + _("\n"));
	pfile.Write(_("Dim InnerCone") + _("\n"));
	pfile.Write(_("Dim OuterCone") + _("\n"));
	pfile.Write(_("Dim Radius") + _("\n"));
	pfile.Write(_("Dim FallOff") + _("\n"));
	pfile.Write(_("Dim Ambient") + _("\n"));
	pfile.Write(_("Dim Diffuse") + _("\n"));
	pfile.Write(_("Dim Specular") + _("\n"));
	pfile.Write(_("Dim Constant") + _("\n"));
	pfile.Write(_("Dim Linear") + _("\n"));
	pfile.Write(_("Dim Quadratic") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Actor Terrain Structure
	pfile.Write(_("Type Serenity_Terrain_Properties") + _("\n"));
	pfile.Write(_("Dim HeightMap$") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Actor Animation Structure
	pfile.Write(_("Type Serenity_ActorAnimation_Properties") + _("\n"));
	pfile.Write(_("Dim AnimationID") + _("\n"));
	pfile.Write(_("Dim NumLoops") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Actor Water Structure
	pfile.Write(_("Type Serenity_Water_Properties") + _("\n"));
	pfile.Write(_("Dim WaveHeight") + _("\n"));
	pfile.Write(_("Dim WaveLength") + _("\n"));
	pfile.Write(_("Dim WaveSpeed") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	//Actor Particle Structure
	pfile.Write(_("Type Serenity_Particle_Properties") + _("\n"));
	pfile.Write(_("Dim ParticleType") + _("\n"));
	pfile.Write(_("Dim MinSize As Serenity_Size") + _("\n"));
	pfile.Write(_("Dim MaxSize As Serenity_Size") + _("\n"));
	pfile.Write(_("Dim MinStartColor") + _("\n"));
	pfile.Write(_("Dim MaxStartColor") + _("\n"));
	pfile.Write(_("Dim MinSpeed") + _("\n"));
	pfile.Write(_("Dim MaxSpeed") + _("\n"));
	pfile.Write(_("Dim MinLife") + _("\n"));
	pfile.Write(_("Dim MaxLife") + _("\n"));
	pfile.Write(_("Dim Normal As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim Direction As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim MaxAngle") + _("\n"));
	pfile.Write(_("Dim CircleCenter As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim Radius") + _("\n"));
	pfile.Write(_("Dim UseEveryVertex") + _("\n"));
	pfile.Write(_("Dim UseNormalDirection") + _("\n"));
	pfile.Write(_("Dim NormalDirectionModifier") + _("\n"));
	pfile.Write(_("Dim CylinderLength") + _("\n"));
	pfile.Write(_("Dim UseOutlineOnly") + _("\n"));
	pfile.Write(_("Dim MinBoxSize As Serenity_Size") + _("\n"));
	pfile.Write(_("Dim MaxBoxSize As Serenity_Size") + _("\n"));
	pfile.Write(_("Dim RingThickness") + _("\n"));
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));


	//Actor Structure
	pfile.Write(_("Type Serenity_Actor") + _("\n"));
	pfile.Write(_("Dim ID ") + _("\n"));
	pfile.Write(_("Dim SN_ID ") + _("\n"));
	pfile.Write(_("Dim ActorType ") + _("\n"));
	pfile.Write(_("Dim Mesh  \'Index in Global Mesh list") + _("\n"));
	pfile.Write(_("Dim Position As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim Rotation As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim Scale As Serenity_Vector3D") + _("\n"));
	pfile.Write(_("Dim Material") + _("\n"));
	pfile.Write(_("Dim Shadow") + _("\n"));
	pfile.Write(_("Dim AutoCulling") + _("\n"));
	pfile.Write(_("Dim Physics As Serenity_Actor_Physics") + _("\n"));
	pfile.Write(_("Dim Animation As Serenity_ActorAnimation_Properties") + _("\n"));
	pfile.Write(_("Dim Light As Serenity_Light_Properties") + _("\n"));
	pfile.Write(_("Dim Terrain As Serenity_Terrain_Properties") + _("\n"));
	pfile.Write(_("Dim Water As Serenity_Water_Properties") + _("\n"));
	pfile.Write(_("Dim Particle As Serenity_Particle_Properties") + _("\n"));
	pfile.Write(_("Dim CubeSize") + _("\n"));
	pfile.Write(_("Dim SphereRadius") + _("\n"));
	pfile.Write(_("Dim Visible") + _("\n"));
	pfile.Write(_("End Type ") + _("\n"));

	pfile.Write(_("\n"));

	//Actor Structure
	pfile.Write(_("Type Serenity_Actor_Reference") + _("\n"));
	pfile.Write(_("Dim SN_ID ") + _("\n"));
	pfile.Write(_("End Type ") + _("\n"));
	pfile.Write(_("\n"));


	wxString p_stage_struct_name_template = _("Serenity_Stage_[STAGE_ID]_Structure");
	wxString p_stage_actors_struct_name_template = _("Serenity_Stage_Actors_[STAGE_ID]_Structure");

	wxString p_stage_define = _("");
	wxString p_stage_actor_define;

	for(int stage_index = 0; stage_index < stages.size(); stage_index++)
	{
		if(stages[stage_index].id_name.compare("")==0)
			continue;

		pfile.Write(_("\'----------------STAGE[") + wxString::FromUTF8(stages[stage_index].id_name) + _("]----------------------\n"));

		p_stage_actor_define = _("");

		//Create Actor Structures
		for(int actor_index = 0; actor_index < stages[stage_index].actors.size(); actor_index++)
		{
			wxString actor_id = wxString::FromUTF8(stages[stage_index].actors[actor_index].id_name).Trim();

			if(actor_id.compare(_(""))==0)
				continue;

			p_stage_actor_define += _("Dim ") + actor_id + _(" As Serenity_Actor_Reference") + _("\n");
		}

		pfile.Write(_("\n"));

		wxString stage_actors_struct = p_stage_actors_struct_name_template;
		stage_actors_struct.Replace(_("[STAGE_ID]"), wxString::FromUTF8(stages[stage_index].id_name));

		pfile.Write(_("Type ") + stage_actors_struct + _("\n"));

		pfile.Write(p_stage_actor_define);

		pfile.Write(_("End Type ") + _("\n"));

		pfile.Write(_("\n"));

		wxString stage_struct = p_stage_struct_name_template;
		stage_struct.Replace(_("[STAGE_ID]"), wxString::FromUTF8(stages[stage_index].id_name));

		uint32_t num_actors = (int)stages[stage_index].actors.size();

		pfile.Write(_("Type ") + stage_struct + _("\n"));
		pfile.Write(_("Dim ID ") + _("\n"));
		pfile.Write(_("Dim ActorList[") + wxString::Format(_("%u"), (num_actors == 0 ? 1 : num_actors)) + _("] As Serenity_Actor") + _("\n"));
		pfile.Write(_("Dim Actors As ") + stage_actors_struct + _("\n"));
		pfile.Write(_("Dim Sky As ") + p_sky_struct_name + _("\n"));
		pfile.Write(_("End Type ") + _("\n"));

		p_stage_define += _("Dim ") + wxString::FromUTF8(stages[stage_index].id_name) + _(" As ") + stage_struct + _("\n");

		pfile.Write(_("\n"));
	}

	pfile.Write(_("\n"));

	pfile.Write(_("Type Serenity_Stages_Structure") + _("\n"));
	pfile.Write(p_stage_define);
	pfile.Write(_("End Type") + _("\n"));

	pfile.Write(_("\n"));

	pfile.Write(_("Dim Textures As Serenity_Textures_List_Structure") + _("\n"));
	pfile.Write(_("\'TEXTURES ARE LOADED AND UNLOADED WHEN LOADSTAGE() IS CALLED") + _("\n"));
	pfile.Write(p_texture_define);
	pfile.Write(_("\n"));


	pfile.Write(_("Dim Materials As Serenity_Materials_List_Structure") + _("\n"));
	pfile.Write(_("\'-----------------DEFINE MATERIALS---------------") + _("\n"));

	for(int i = 0; i < materials.size(); i++)
	{
		if(materials[i].id_name.compare("")==0)
			continue;

		pfile.Write(wxString::FromUTF8(materials[i].p_cmd));
		pfile.Write(_("\n\n"));
	}
	pfile.Write(_("\n"));


	pfile.Write(_("Dim Anim8or_Projects As ") + p_an8_structure_name + _("\n"));
	pfile.Write(_("\'-----------------LOAD AN8 PROJECTS---------------") + _("\n"));

	for(int i = 0; i < anim8or_projects.size(); i++)
	{
		if(anim8or_projects[i].id_name.compare("")==0)
			continue;

		pfile.Write(wxString::FromUTF8(anim8or_projects[i].p_cmd) + _("\n"));
		//pfile.Write(wxString::FromUTF8(anim8or_projects[i]) _("LoadAN8(") + mesh_path + _("\"") + wxString::FromUTF8(anim8or_projects[i].file) + _("\")") + _("\n"));
	}

	pfile.Write(_("\n"));

	pfile.Write(_("Dim Meshes As Serenity_Meshes_List_Structure") + _("\n"));
	pfile.Write(_("\'-----------------DEFINE MESHES---------------") + _("\n"));
	for(int i = 0; i < meshes.size(); i++)
	{
		if(meshes[i].id_name.compare("")==0)
			continue;

		pfile.Write(wxString::FromUTF8(meshes[i].p_cmd) + _("\n"));
	}

	pfile.Write(_("\n\n"));


	pfile.Write(_("Dim Stages As Serenity_Stages_Structure") + _("\n"));
	pfile.Write(_("\'-----------------DEFINE STAGES---------------") + _("\n"));

	int num_actor_types = 10;
	wxString actor_type_str[num_actor_types];
	actor_type_str[0] = _("SN_ACTOR_TYPE_ANIMATED");
	actor_type_str[1] = _("SN_ACTOR_TYPE_OCTREE");
	actor_type_str[2] = _("SN_ACTOR_TYPE_LIGHT");
	actor_type_str[3] = _("SN_ACTOR_TYPE_BILLBOARD");
	actor_type_str[4] = _("SN_ACTOR_TYPE_TERRAIN");
	actor_type_str[5] = _("SN_ACTOR_TYPE_WATER");
	actor_type_str[6] = _("SN_ACTOR_TYPE_PARTICLE");
	actor_type_str[7] = _("SN_ACTOR_TYPE_CUBE");
	actor_type_str[8] = _("SN_ACTOR_TYPE_SPHERE");
	actor_type_str[9] = _("SN_ACTOR_TYPE_PLANE");

	wxString sky_type_str[3];
	sky_type_str[0] = _("SN_SKY_TYPE_NONE");
	sky_type_str[1] = _("SN_SKY_TYPE_BOX");
	sky_type_str[2] = _("SN_SKY_TYPE_DOME");

	int actor_sn_id = 0;

	int stage_sn_id = 0;

	wxString stage_load_fn = _("");

	wxString actor_load_properties = _("");

	for(int stage = 0; stage < stages.size(); stage++)
	{
		if(stages[stage].id_name.compare("")==0)
			continue;

		for(int n = 0; n < materials.size(); n++)
			materials[n].load_flag = false;

		for(int n = 0; n < meshes.size(); n++)
			meshes[n].load_flag = false;

		for(int n = 0; n < textures.size(); n++)
			textures[n].load_flag = false;

		wxString tx_load = _("");
		wxString mat_load = _("");
		wxString mesh_load = _("");


		wxString stage_id = _("Stages.") + wxString::FromUTF8(stages[stage].id_name);

		stage_load_fn += _("Sub Load_") + wxString::FromUTF8(stages[stage].id_name) + _("( )") + _("\n");
		stage_load_fn += _("[PREPEND_MATERIAL_TEXTURE_BLOCK]") + _("\n");

		pfile.Write(_("\'----------------INIT STAGE: [ ") + wxString::FromUTF8(stages[stage].id_name) + _(" ]-----------------------\n"));

		pfile.Write(stage_id + _(".ID = ") + wxString::Format(_("%d"), stage_sn_id) + _("\n"));
		stage_sn_id++;

		switch(stages[stage].sky.type)
		{
			case SN_SKY_TYPE_BOX:
			{
				pfile.Write(stage_id + _(".Sky.Shape = SN_SKY_TYPE_BOX") + _("\n"));

				int left_img_index = -1;
				int right_img_index = -1;
				int front_img_index = -1;
				int back_img_index = -1;
				int top_img_index = -1;
				int bottom_img_index = -1;

				wxString img_id = _("");

				bool hasSkyBoxComplete = true;

				//LEFT
				img_id = _("");
				left_img_index = stages[stage].sky.left_texture_index;
				if(left_img_index >= 0 && left_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[left_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Left = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				//RIGHT
				img_id = _("");
				right_img_index = stages[stage].sky.right_texture_index;
				if(right_img_index >= 0 && right_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[right_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Right = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				//FRONT
				img_id = _("");
				front_img_index = stages[stage].sky.front_texture_index;
				if(front_img_index >= 0 && front_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[front_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Front = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				//BACK
				img_id = _("");
				back_img_index = stages[stage].sky.back_texture_index;
				if(back_img_index >= 0 && back_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[back_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Back = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				//TOP
				img_id = _("");
				top_img_index = stages[stage].sky.top_texture_index;
				if(top_img_index >= 0 && top_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[top_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Top = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				//BOTTOM
				img_id = _("");
				bottom_img_index = stages[stage].sky.bottom_texture_index;
				if(bottom_img_index >= 0 && bottom_img_index < textures.size())
					img_id = wxString::FromUTF8(textures[bottom_img_index].id_name).Trim();

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Box.Image_Bottom = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasSkyBoxComplete = false;

				if(hasSkyBoxComplete)
				{
					wxString box_id = stage_id + _(".Sky.Box");

					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Top ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Top ].File$ )") + _("\n");
					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Bottom ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Bottom ].File$ )") + _("\n");
					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Left ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Left ].File$ )") + _("\n");
					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Right ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Right ].File$ )") + _("\n");
					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Front ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Front ].File$ )") + _("\n");
					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Back ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[ ") + box_id + _(".Image_Back ].File$ )") + _("\n");

					textures[left_img_index].load_flag = true;
					textures[right_img_index].load_flag = true;
					textures[front_img_index].load_flag = true;
					textures[back_img_index].load_flag = true;
					textures[top_img_index].load_flag = true;
					textures[bottom_img_index].load_flag = true;

					stage_load_fn += _("\tAddSceneSkyBox(") + _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Top ].ID, ") +
															  _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Bottom ].ID, ") +
															  _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Left ].ID, ") +
															  _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Right ].ID, ") +
															  _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Front ].ID, ") +
															  _("Serenity_Global_Texture_List[ ") + box_id + _(".Image_Back ].ID )") + _("\n");
				}
			}
			break;

			case SN_SKY_TYPE_DOME:
			{
				pfile.Write(stage_id + _(".Sky.Shape = SN_SKY_TYPE_DOME") + _("\n"));

				int img_index = -1;
				wxString img_id = _("");

				//LEFT
				img_id = _("");
				img_index = stages[stage].sky.dome_texture_index;
				if(img_index >= 0 && img_index < textures.size())
					img_id = wxString::FromUTF8(textures[img_index].id_name).Trim();

				bool hasDomeImage = true;

				if(img_id.compare(_(""))!=0)
					pfile.Write(stage_id + _(".Sky.Dome.Image = Textures.") + img_id + _(".SN_ID") + _("\n"));
				else
					hasDomeImage = false;

				pfile.Write(stage_id + _(".Sky.Dome.hRes = ") + wxString::FromDouble(stages[stage].sky.hRes) + _("\n"));
				pfile.Write(stage_id + _(".Sky.Dome.vRes = ") + wxString::FromDouble(stages[stage].sky.vRes) + _("\n"));
				pfile.Write(stage_id + _(".Sky.Dome.TexturePCT = ") + wxString::FromDouble(stages[stage].sky.txPCT) + _("\n"));
				pfile.Write(stage_id + _(".Sky.Dome.SpherePCT = ") + wxString::FromDouble(stages[stage].sky.spherePCT) + _("\n"));
				pfile.Write(stage_id + _(".Sky.Dome.Radius = ") + wxString::FromDouble(stages[stage].sky.dome_radius) + _("\n"));

				if(hasDomeImage)
				{
					wxString dome_id = stage_id + _(".Sky.Dome");

					tx_load += _("\t") + _("Serenity_Global_Texture_List[ ") + dome_id + _(".Image ].ID = LoadImage( \"textures\" + path_separator$ + Serenity_Global_Texture_List[") + dome_id + _(".Image].File$ )") + _("\n");
					textures[img_index].load_flag = true;

					stage_load_fn += _("\tAddSceneSkyDomeEx( ") + _("Serenity_Global_Texture_List[ ") + dome_id + _(".Image ].ID, ") +
																  dome_id + _(".hRes, ") +
																  dome_id + _(".vRes, ") +
																  dome_id + _(".TexturePCT, ") +
																  dome_id + _(".SpherePCT, ") +
																  dome_id + _(".Radius ) ") + _("\n");
				}

			}
			break;
		}

		pfile.Write(_("\n"));

		actor_sn_id = 0;

		for(int actor = 0; actor < stages[stage].actors.size(); actor++)
		{
			if(stages[stage].actors[actor].id_name.compare("")==0)
				continue;

			actor_load_properties = _("");

			stages[stage].actors[actor].sn_id = actor_sn_id;
			actor_sn_id++;

			wxString actor_define = _("\'-----------ACTOR [ ") + stage_id + _(".Actors.") + wxString::FromUTF8(stages[stage].actors[actor].id_name) + _(" ]----------------\n");
			actor_define += stage_id + _(".Actors.") + wxString::FromUTF8(stages[stage].actors[actor].id_name) + _(".SN_ID = ") + wxString::Format(_("%d"), stages[stage].actors[actor].sn_id) + _("\n\n");

			wxString actor_id = stage_id + _(".ActorList[") + wxString::Format(_("%d"), stages[stage].actors[actor].sn_id) + _("]");

			int actor_type = stages[stage].actors[actor].type;
			actor_type = ((actor_type < 0 || actor_type >= num_actor_types) ? 0 : actor_type);

			actor_define += actor_id + _(".ID = -1") + _("\n");
			actor_define += actor_id + _(".ActorType = ") + actor_type_str[actor_type] + _("\n");

			int mesh_index = stages[stage].actors[actor].mesh_index;
			wxString mesh_id = _("");

			if(mesh_index >= 0 && mesh_index < meshes.size())
				mesh_id = wxString::FromUTF8(meshes[mesh_index].id_name).Trim();

			wxString mesh_material_str = _("");

			if(mesh_id.compare("")!=0)
			{
				actor_define += actor_id + _(".Mesh = Meshes.") + mesh_id + _(".SN_ID") + _("\n");

				if(!meshes[mesh_index].load_flag)
				{
					mesh_load += wxString::FromUTF8(meshes[mesh_index].p_onLoad_cmd) + _("\n");
					meshes[mesh_index].load_flag = true;
					//Load Materials For mesh if flag is not set
					for(int mat = 0; mat < meshes[mesh_index].material_index.size(); mat++)
					{
						int mat_index = meshes[mesh_index].material_index[mat];

						if(materials[mat_index].id_name.compare("")==0)
							continue;

						if(materials[mat_index].load_flag)
							continue;

						wxString mat_str = _("");

						mat_str += _("\t") + _("\'----------LOAD MATERIAL TEXTURE LEVELS [ ") + wxString::FromUTF8(materials[mat_index].id_name) + _("]-----------") + _("\n");

						//Load Texture Levels for material
						for(int tx = 0; tx < materials[mat_index].texture_id.size(); tx++)
						{
							int tx_index = materials[mat_index].texture_id[tx];

							if(textures[tx_index].id_name.compare("")==0)
								continue;

							if(textures[tx_index].load_flag)
								continue;

							tx_load += wxString::FromUTF8(textures[tx_index].p_cmd);
							textures[tx_index].load_flag = true;
						}

						mat_load += wxString::FromUTF8(materials[mat_index].p_onLoad_cmd);
						materials[mat_index].load_flag = true;

						wxString mat_sn_id = _("Materials.") + wxString::FromUTF8(materials[mat_index].id_name) + _(".SN_ID");
						wxString mat_id = _("Serenity_Global_Material_List[") + mat_sn_id + _("].ID");
						mesh_material_str += _("SetActorMaterial( [ACTOR], ") + wxString::Format(_("%d"), mat) + _(", ") + mat_id + _(" )") + _("\n");
					}

					meshes[mesh_index].mat_load_str = mesh_material_str.ToStdString();
				}
			}

			wxString actor_pos_str = wxString::FromDouble((double)stages[stage].actors[actor].position.X) + _(", ") +
									 wxString::FromDouble((double)stages[stage].actors[actor].position.Y) + _(", ") +
									 wxString::FromDouble((double)stages[stage].actors[actor].position.Z);
			actor_define += actor_id + _(".Position = Serenity_CreateVector3D(") + actor_pos_str + _(")") + _("\n");

			actor_load_properties += _("\t") + _("SetActorPosition( [ACTOR], ") + actor_id + _(".Position.X, ") +
																				  actor_id + _(".Position.Y, ") +
																				  actor_id + _(".Position.Z ) ") + _("\n");

			wxString actor_rot_str = wxString::FromDouble((double)stages[stage].actors[actor].rotation.X) + _(", ") +
									 wxString::FromDouble((double)stages[stage].actors[actor].rotation.Y) + _(", ") +
									 wxString::FromDouble((double)stages[stage].actors[actor].rotation.Z);
			actor_define += actor_id + _(".Rotation = Serenity_CreateVector3D(") + actor_rot_str + _(")") + _("\n");

			actor_load_properties += _("\t") + _("SetActorRotation( [ACTOR], ") + actor_id + _(".Rotation.X, ") +
																				  actor_id + _(".Rotation.Y, ") +
																				  actor_id + _(".Rotation.Z ) ") + _("\n");

			wxString actor_scale_str = wxString::FromDouble((double)stages[stage].actors[actor].scale.X) + _(", ") +
									   wxString::FromDouble((double)stages[stage].actors[actor].scale.Y) + _(", ") +
									   wxString::FromDouble((double)stages[stage].actors[actor].scale.Z);
			actor_define += actor_id + _(".Scale = Serenity_CreateVector3D(") + actor_scale_str + _(")") + _("\n");

			actor_load_properties += _("\t") + _("SetActorScale( [ACTOR], ") + actor_id + _(".Scale.X, ") +
																			   actor_id + _(".Scale.Y, ") +
																			   actor_id + _(".Scale.Z ) ") + _("\n");

			int mat_index = stages[stage].actors[actor].override_material_index;
			wxString mat_id = _("");

			if(mat_index >= 0 && mat_index < materials.size())
				mat_id = wxString::FromUTF8(materials[mat_index].id_name).Trim();

			if(mat_id.compare(_(""))!=0)
			{
				actor_define += actor_id + _(".Material = Materials.") + mat_id + _(".SN_ID") + _("\n");

				actor_load_properties += _("\t") + _("SetActorMaterial( [ACTOR], 0, Serenity_Global_Material_List[ ") + _("Materials.") + mat_id + _(".SN_ID ].ID )") + _("\n");
			}

			actor_define += actor_id + _(".Shadow = ") + (stages[stage].actors[actor].hasShadow ? _("TRUE") : _("FALSE")) + _("\n");
			actor_define += actor_id + _(".AutoCulling = ") + (stages[stage].actors[actor].auto_culling ? _("TRUE") : _("FALSE")) + _("\n");
			actor_define += actor_id + _(".Visible = ") + (stages[stage].actors[actor].visible ? _("TRUE") : _("FALSE")) + _("\n");

			//Physics Properties
			actor_define += actor_id + _(".Physics.isSolid = ") + (stages[stage].actors[actor].physics.isSolid ? _("TRUE") : _("FALSE")) + _("\n");
			actor_define += actor_id + _(".Physics.Mass = ") + wxString::FromDouble(stages[stage].actors[actor].physics.mass) + _("\n");
			actor_define += actor_id + _(".Physics.Shape = ") + wxString::Format(_("%d"), stages[stage].actors[actor].physics.shape) + _("\n");

			switch(stages[stage].actors[actor].type)
			{
				case SN_ACTOR_TYPE_ANIMATED:
				{
					//Animation Properties
					int animation_index = stages[stage].actors[actor].animation_index;
					wxString animation_id = _("");

					if(mesh_index >= 0 && mesh_index < meshes.size())
						if(animation_index >= 0 && animation_index < meshes[mesh_index].animation.size())
							animation_id = wxString::FromUTF8(meshes[mesh_index].animation[animation_index].id_name);

					if(animation_id.compare(_(""))!=0)
					{
						actor_define += actor_id + _(".Animation.AnimationID = ") + animation_id + _("\n");
						actor_define += actor_id + _(".Animation.NumLoops = ") + wxString::Format(_("%d"),stages[stage].actors[actor].num_loops) + _("\n");
					}

					if(mesh_id.compare(_(""))!=0)
					{
						stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateAnimatedActor( Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].ID ) ") + _("\n");

						uint32_t ani_sn_id = 0;
						for(int ani = 0; ani < meshes[mesh_index].animation.size(); ani++)
						{
							if(meshes[mesh_index].animation[ani].id_name.compare("")==0)
								continue;

							wxString ani_sn_id_str = wxString::Format(_("%u"), ani_sn_id);
							ani_sn_id++;

							wxString start_frame_str = _("Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].Animations[") + ani_sn_id_str + _("].Start_Frame");
							wxString end_frame_str = _("Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].Animations[") + ani_sn_id_str + _("].End_Frame");
							wxString speed_str = _("Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].Animations[") + ani_sn_id_str + _("].Speed");

							actor_load_properties += _("\t") + _("CreateActorAnimation( [ACTOR], ") + start_frame_str + _(", ") + end_frame_str + _(", ") + speed_str + _(" )") + _("\n");
						}

						actor_load_properties += _("\n");
						actor_load_properties += _("\t") + _("SetActorAnimation( [ACTOR], ") + actor_id + _(".Animation.AnimationID, ") + actor_id + _(".Animation.NumLoops ) ") + _("\n");
					}
				}
				break;

				case SN_ACTOR_TYPE_OCTREE:
				{
					if(mesh_id.compare(_(""))!=0)
					{
						stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateOctreeActor( Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].ID ) ") + _("\n");
					}
				}
				break;

				case SN_ACTOR_TYPE_BILLBOARD:
				{
					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateBillboardActor( ) ") + _("\n");
				}
				break;

				case SN_ACTOR_TYPE_LIGHT:
				{
					//Light Type
					actor_define += actor_id + _(".Light.LightType = SN_LIGHT_TYPE_") + getLightTypeString(stages[stage].actors[actor].light_type) + _("\n");

					wxString lightType_id_str = actor_id + _(".Light.LightType");
					actor_load_properties += _("\t") + _("SetLightType( [ACTOR], ") + lightType_id_str + _(" )") + _("\n");

					//Cast Shadow
					actor_define += actor_id + _(".Light.CastShadow = ") + (stages[stage].actors[actor].isCastingShadow ? _("TRUE") : _("FALSE")) + _("\n");

					wxString castShadow_id_str = actor_id + _(".Light.CastShadow");
					actor_load_properties += _("\t") + _("SetLightShadowCast( [ACTOR], ") + castShadow_id_str + _(" )") + _("\n");

					//Inner Cone
					actor_define += actor_id + _(".Light.InnerCone = ") + wxString::FromDouble(stages[stage].actors[actor].inner_cone) + _("\n");

					wxString innerCone_id_str = actor_id + _(".Light.InnerCone");
					actor_load_properties += _("\t") + _("SetLightInnerCone( [ACTOR], ") + innerCone_id_str + _(" )") + _("\n");

					//Outer Cone
					actor_define += actor_id + _(".Light.OuterCone = ") + wxString::FromDouble(stages[stage].actors[actor].outer_cone) + _("\n");

					wxString outerCone_id_str = actor_id + _(".Light.OuterCone");
					actor_load_properties += _("\t") + _("SetLightOuterCone( [ACTOR], ") + outerCone_id_str + _(" )") + _("\n");

					//Radius
					actor_define += actor_id + _(".Light.Radius = ") + wxString::FromDouble(stages[stage].actors[actor].radius) + _("\n");

					wxString radius_id_str = actor_id + _(".Light.Radius");
					actor_load_properties += _("\t") + _("SetLightRadius( [ACTOR], ") + radius_id_str + _(" )") + _("\n");

					//Fall Off
					actor_define += actor_id + _(".Light.FallOff = ") + wxString::FromDouble(stages[stage].actors[actor].falloff) + _("\n");

					wxString fallOff_id_str = actor_id + _(".Light.FallOff");
					actor_load_properties += _("\t") + _("SetLightFallOff( [ACTOR], ") + fallOff_id_str + _(" )") + _("\n");

					//Ambient
					actor_define += actor_id + _(".Light.Ambient = ") + wxString::Format(_("%u"), stages[stage].actors[actor].ambient.color) + _("\n");

					wxString ambient_id_str = actor_id + _(".Light.Ambient");
					actor_load_properties += _("\t") + _("SetLightAmbientColor( [ACTOR], ") + ambient_id_str + _(" )") + _("\n");

					//Diffuse
					actor_define += actor_id + _(".Light.Diffuse = ") + wxString::Format(_("%u"), stages[stage].actors[actor].diffuse.color) + _("\n");

					wxString diffuse_id_str = actor_id + _(".Light.Diffuse");
					actor_load_properties += _("\t") + _("SetLightDiffuseColor( [ACTOR], ") + diffuse_id_str + _(" )") + _("\n");

					//Specular
					actor_define += actor_id + _(".Light.Specular = ") + wxString::Format(_("%u"), stages[stage].actors[actor].specular.color) + _("\n");

					wxString specular_id_str = actor_id + _(".Light.Specular");
					actor_load_properties += _("\t") + _("SetLightSpecularColor( [ACTOR], ") + specular_id_str + _(" )") + _("\n");

					//Attenuation
					actor_define += actor_id + _(".Light.Constant = ") + wxString::FromDouble(stages[stage].actors[actor].attenuation.X) + _("\n");
					actor_define += actor_id + _(".Light.Linear = ") + wxString::FromDouble(stages[stage].actors[actor].attenuation.Y) + _("\n");
					actor_define += actor_id + _(".Light.Quadratic = ") + wxString::FromDouble(stages[stage].actors[actor].attenuation.Z) + _("\n");

					wxString constant_id_str = actor_id + _(".Light.Constant");
					wxString linear_id_str = actor_id + _(".Light.Linear");
					wxString quadratic_id_str = actor_id + _(".Light.Quadratic");
					actor_load_properties += _("\t") + _("SetLightAttenuation( [ACTOR], ") + constant_id_str + _(", ") +
																							 linear_id_str + _(", ") +
																							 quadratic_id_str + _(" ) ") + _("\n");


					//Create Light Actor
					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateLightActor( ) ") + _("\n");
				}
				break;

				case SN_ACTOR_TYPE_TERRAIN:
				{
					actor_define += actor_id + _(".Terrain.HeightMap$ = \"") + wxString::FromUTF8(stages[stage].actors[actor].terrain_hmap_file) + _("\"\n");

					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateTerrainActor( ") + _("\"textures\" + path_separator$ + ") + actor_id + _(".Terrain.HeightMap$ ) ") + _("\n");
				}
				break;

				case SN_ACTOR_TYPE_WATER:
				{
					actor_define += actor_id + _(".Water.WaveHeight = ") + wxString::FromDouble(stages[stage].actors[actor].wave_height) + _("\n");
					actor_define += actor_id + _(".Water.WaveLength = ") + wxString::FromDouble(stages[stage].actors[actor].wave_length) + _("\n");
					actor_define += actor_id + _(".Water.WaveSpeed = ") + wxString::FromDouble(stages[stage].actors[actor].wave_speed) + _("\n");

					if(mesh_id.compare(_(""))!=0)
					{
						stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateWaterActor( Serenity_Global_Mesh_List[") +  actor_id + _(".Mesh].ID, ") +
																					    actor_id + _(".Water.WaveHeight, ") +
																					    actor_id + _(".Water.WaveSpeed, ") +
																					    actor_id + _(".Water.WaveLength ) ") + _("\n");
					}
				}
				break;

				case SN_ACTOR_TYPE_PARTICLE:
				{
					actor_define += actor_id + _(".Particle.ParticleType = SN_PARTICLE_TYPE_") + getParticleTypeString(stages[stage].actors[actor].particle_type) + _("\n");

					//Min Size
					wxString minSize_str = wxString::FromDouble((double)stages[stage].actors[actor].min_width) + _(", ") +
										   wxString::FromDouble((double)stages[stage].actors[actor].min_height) + _(", ") +
										   wxString::FromDouble((double)0);
					actor_define += actor_id + _(".Particle.MinSize = Serenity_CreateSize3D(") + minSize_str + _(")") + _("\n");

					wxString minSize_id_str = actor_id + _(".Particle.MinSize");
					actor_load_properties += _("\t") + _("setParticleMinStartSize( [ACTOR], ") + minSize_id_str + _(".Width, ") + minSize_id_str + _(".Height )") + _("\n");

					//Max Size
					wxString maxSize_str = wxString::FromDouble((double)stages[stage].actors[actor].max_width) + _(", ") +
										   wxString::FromDouble((double)stages[stage].actors[actor].max_height) + _(", ") +
										   wxString::FromDouble((double)0);
					actor_define += actor_id + _(".Particle.MaxSize = Serenity_CreateSize3D(") + maxSize_str + _(")") + _("\n");

					wxString maxSize_id_str = actor_id + _(".Particle.MaxSize");
					actor_load_properties += _("\t") + _("setParticleMaxStartSize( [ACTOR], ") + maxSize_id_str + _(".Width, ") + maxSize_id_str + _(".Height )") + _("\n");

					//Min Color
					actor_define += actor_id + _(".Particle.MinStartColor = ") + wxString::Format(_("%u"), stages[stage].actors[actor].min_start_color.color) + _("\n");

					wxString minStartColor_id_str = actor_id + _(".Particle.MinStartColor");
					actor_load_properties += _("\t") + _("setParticleMinStartColor( [ACTOR], ") + minStartColor_id_str + _(" )") + _("\n");

					//Max Color
					actor_define += actor_id + _(".Particle.MaxStartColor = ") + wxString::Format(_("%u"), stages[stage].actors[actor].max_start_color.color) + _("\n");

					wxString maxStartColor_id_str = actor_id + _(".Particle.MaxStartColor");
					actor_load_properties += _("\t") + _("setParticleMaxStartColor( [ACTOR], ") + maxStartColor_id_str + _(" )") + _("\n");

					//Min Speed
					actor_define += actor_id + _(".Particle.MinSpeed = ") + wxString::FromDouble(stages[stage].actors[actor].min_per_sec) + _("\n");

					wxString minSpeed_id_str = actor_id + _(".Particle.MinSpeed");
					actor_load_properties += _("\t") + _("SetMinParticlesPerSecond( [ACTOR], ") + minSpeed_id_str + _(" )") + _("\n");

					//Max Speed
					actor_define += actor_id + _(".Particle.MaxSpeed = ") + wxString::FromDouble(stages[stage].actors[actor].max_per_sec) + _("\n");

					wxString maxSpeed_id_str = actor_id + _(".Particle.MaxSpeed");
					actor_load_properties += _("\t") + _("SetMaxParticlesPerSecond( [ACTOR], ") + maxSpeed_id_str + _(" )") + _("\n");

					//Min Life
					actor_define += actor_id + _(".Particle.MinLife = ") + wxString::FromDouble(stages[stage].actors[actor].min_life) + _("\n");

					wxString minLife_id_str = actor_id + _(".Particle.MinLife");
					actor_load_properties += _("\t") + _("SetParticleMinLife( [ACTOR], ") + minLife_id_str + _(" )") + _("\n");

					//Max  Life
					actor_define += actor_id + _(".Particle.MaxLife = ") + wxString::FromDouble(stages[stage].actors[actor].max_life) + _("\n");

					wxString maxLife_id_str = actor_id + _(".Particle.MaxLife");
					actor_load_properties += _("\t") + _("SetParticleMaxLife( [ACTOR], ") + maxLife_id_str + _(" )") + _("\n");


					//Normal
					wxString normal_str = wxString::FromDouble((double)stages[stage].actors[actor].normal.X) + _(", ") +
										   wxString::FromDouble((double)stages[stage].actors[actor].normal.Y) + _(", ") +
										   wxString::FromDouble((double)stages[stage].actors[actor].normal.Z);
					actor_define += actor_id + _(".Particle.Normal = Serenity_CreateVector3D(") + normal_str + _(")") + _("\n");

					wxString normal_id_str = actor_id + _(".Particle.Normal");
					actor_load_properties += _("\t") + _("SetParticleNormal( [ACTOR], ") + normal_id_str + _(".X, ") + normal_id_str + _(".Y, ") + normal_id_str + _(".Z") + _(" )") + _("\n");

					//Direction
					wxString direction_str = wxString::FromDouble((double)stages[stage].actors[actor].direction.X) + _(", ") +
										     wxString::FromDouble((double)stages[stage].actors[actor].direction.Y) + _(", ") +
										     wxString::FromDouble((double)stages[stage].actors[actor].direction.Z);
					actor_define += actor_id + _(".Particle.Direction = Serenity_CreateVector3D(") + direction_str + _(")") + _("\n");

					wxString direction_id_str = actor_id + _(".Particle.Direction");
					actor_load_properties += _("\t") + _("SetParticleDirection( [ACTOR], ") + direction_id_str + _(".X, ") + direction_id_str + _(".Y, ") + direction_id_str + _(".Z") + _(" )") + _("\n");


					//Max Angle
					actor_define += actor_id + _(".Particle.MaxAngle = ") + wxString::FromDouble(stages[stage].actors[actor].angle) + _("\n");

					wxString maxAngle_id_str = actor_id + _(".Particle.MaxAngle");
					actor_load_properties += _("\t") + _("SetParticleMaxAngle( [ACTOR], ") + maxAngle_id_str + _(" )") + _("\n");


					//Circle Center
					wxString center_str = wxString::FromDouble((double)stages[stage].actors[actor].center.X) + _(", ") +
										  wxString::FromDouble((double)stages[stage].actors[actor].center.Y) + _(", ") +
										  wxString::FromDouble((double)stages[stage].actors[actor].center.Z);
					actor_define += actor_id + _(".Particle.CircleCenter = Serenity_CreateVector3D(") + center_str + _(")") + _("\n");

					wxString center_id_str = actor_id + _(".Particle.CircleCenter");
					actor_load_properties += _("\t") + _("SetParticleCenter( [ACTOR], ") + center_id_str + _(".X, ") + center_id_str + _(".Y, ") + center_id_str + _(".Z") + _(" )") + _("\n");


					//Radius
					actor_define += actor_id + _(".Particle.Radius = ") + wxString::FromDouble(stages[stage].actors[actor].radius) + _("\n");

					wxString radius_id_str = actor_id + _(".Particle.Radius");
					actor_load_properties += _("\t") + _("SetParticleRadius( [ACTOR], ") + radius_id_str + _(" )") + _("\n");

					//Use Every Vertex
					actor_define += actor_id + _(".Particle.UseEveryVertex = ") + (stages[stage].actors[actor].use_every_vertex ? _("TRUE") : _("FALSE")) + _("\n");

					wxString useVertex_id_str = actor_id + _(".Particle.UseEveryVertex");
					actor_load_properties += _("\t") + _("UseParticleEveryMeshVertex( [ACTOR], ") + useVertex_id_str + _(" )") + _("\n");

					//Use Normal Direction
					actor_define += actor_id + _(".Particle.UseNormalDirection = ") + (stages[stage].actors[actor].use_normal_direction ? _("TRUE") : _("FALSE")) + _("\n");

					wxString useNormal_id_str = actor_id + _(".Particle.UseNormalDirection");
					actor_load_properties += _("\t") + _("UseParticleNormalDirection( [ACTOR], ") + useNormal_id_str + _(" )") + _("\n");

					//Normal Direction Modifier
					actor_define += actor_id + _(".Particle.NormalDirectionModifier = ") + wxString::FromDouble(stages[stage].actors[actor].normal_direction_modifier) + _("\n");

					wxString normalDirMod_id_str = actor_id + _(".Particle.NormalDirectionModifier");
					actor_load_properties += _("\t") + _("SetParticleNormalDirectionMod( [ACTOR], ") + normalDirMod_id_str + _(" )") + _("\n");

					//Cylinder Length
					actor_define += actor_id + _(".Particle.CylinderLength = ") + wxString::FromDouble(stages[stage].actors[actor].cylinder_length) + _("\n");

					wxString cylinderLength_id_str = actor_id + _(".Particle.CylinderLength");
					actor_load_properties += _("\t") + _("SetParticleLength( [ACTOR], ") + cylinderLength_id_str + _(" )") + _("\n");

					//Use Outline Only
					actor_define += actor_id + _(".Particle.UseOutlineOnly = ") + (stages[stage].actors[actor].use_outline_only ? _("TRUE") : _("FALSE")) + _("\n");

					wxString useOutline_id_str = actor_id + _(".Particle.UseOutlineOnly");
					actor_load_properties += _("\t") + _("UseParticleOutlineOnly( [ACTOR], ") + useOutline_id_str + _(" )") + _("\n");


					//Box Size
					wxString minBoxSize_str = wxString::FromDouble((double)stages[stage].actors[actor].box.MinEdge.X) + _(", ") +
											  wxString::FromDouble((double)stages[stage].actors[actor].box.MinEdge.Y) + _(", ") +
											  wxString::FromDouble((double)stages[stage].actors[actor].box.MinEdge.Z);
					actor_define += actor_id + _(".Particle.MinBoxSize = Serenity_CreateSize3D(") + minBoxSize_str + _(")") + _("\n");

					wxString maxBoxSize_str = wxString::FromDouble((double)stages[stage].actors[actor].box.MaxEdge.X) + _(", ") +
											  wxString::FromDouble((double)stages[stage].actors[actor].box.MaxEdge.Y) + _(", ") +
											  wxString::FromDouble((double)stages[stage].actors[actor].box.MaxEdge.Z);
					actor_define += actor_id + _(".Particle.MaxBoxSize = Serenity_CreateSize3D(") + maxBoxSize_str + _(")") + _("\n");


					wxString minBox_id_str = actor_id + _(".Particle.MinBoxSize");
					wxString maxBox_id_str = actor_id + _(".Particle.MaxBoxSize");
					actor_load_properties += _("\t") + _("SetParticleBox( [ACTOR], ") + minBox_id_str + _(".Width, ") +
																						minBox_id_str + _(".Height, ") +
																						minBox_id_str + _(".Depth, ") +
																						maxBox_id_str + _(".Width, ") +
																						maxBox_id_str + _(".Height, ") +
																						maxBox_id_str + _(".Depth ) ") + _("\n");



					//Ring Thickness
					actor_define += actor_id + _(".Particle.RingThickness = ") + wxString::FromDouble(stages[stage].actors[actor].ring_thickness) + _("\n");

					wxString ringThickness_id_str = actor_id + _(".Particle.RingThickness");
					actor_load_properties += _("\t") + _("SetParticleRingThickness( [ACTOR], ") + ringThickness_id_str + _(" )") + _("\n");


					//Create Particle Actor
					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateParticleActor( ") + actor_id + _(".Particle.ParticleType ) ") + _("\n");


				}
				break;

				case SN_ACTOR_TYPE_CUBE:
				{
					actor_define += actor_id + _(".CubeSize = ") + wxString::FromDouble(stages[stage].actors[actor].cube_size) + _("\n");

					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateCubeActor( ") + actor_id + _(".CubeSize ) ") + _("\n");
				}
				break;

				case SN_ACTOR_TYPE_SPHERE:
				{
					actor_define += actor_id + _(".SphereRadius = ") + wxString::FromDouble(stages[stage].actors[actor].radius) + _("\n");

					stage_load_fn += _("\t") + actor_id + _(".ID = ") + _(" CreateSphereActor( ") + actor_id + _(".SphereRadius ) ") + _("\n");
				}
				break;
			}

			actor_load_properties += _("\n");

			actor_load_properties += _("\t") + _("SetActorVisible( [ACTOR], ") + actor_id + _(".Visible ) ") + _("\n");
			actor_load_properties += _("\t") + _("SetActorAutoCulling( [ACTOR], ") + actor_id + _(".AutoCulling ) ") + _("\n");

			if(stages[stage].actors[actor].type != SN_ACTOR_TYPE_TERRAIN && stages[stage].actors[actor].type != SN_ACTOR_TYPE_WATER && stages[stage].actors[actor].type != SN_ACTOR_TYPE_LIGHT)
				actor_load_properties += _("\t") + (stages[stage].actors[actor].hasShadow ? _("AddActorShadow( [ACTOR] ) ") : _("RemoveActorShadow( [ACTOR] ) ") )  + _("\n");

			actor_load_properties += _("\t") + _("SetActorCollisionShape( [ACTOR], ") + actor_id + _(".Physics.Shape, ") + actor_id + _(".Physics.Mass ) ") + _("\n");
			actor_load_properties += _("\t") + _("SetActorSolid( [ACTOR], ") + actor_id + _(".Physics.isSolid ) ") + _("\n");

			actor_load_properties += _("\n");

			actor_load_properties.Replace(_("[ACTOR]"), actor_id + _(".ID"));

			pfile.Write(actor_define);

			stage_load_fn += _("\n");
			stage_load_fn += actor_load_properties + _("\n");


			pfile.Write(_("\n"));
		}

		wxString prepend_block = _("\t") + _("\'---------STAGE TEXTURES-------------") + _("\n");
		prepend_block += _("\t") + tx_load + _("\n");
		prepend_block += _("\n");

		prepend_block += _("\t") + _("\'---------STAGE MATERIALS-------------") + _("\n");
		prepend_block += _("\t") + mat_load + _("\n");
		prepend_block += _("\n");

		prepend_block += _("\t") + _("\'---------STAGE MESHES-------------") + _("\n");
		prepend_block += _("\t") + mesh_load + _("\n");
		prepend_block += _("\n");


		stage_load_fn += _("End Sub") + _("\n\n\n\n");
		stage_load_fn.Replace(_("[PREPEND_MATERIAL_TEXTURE_BLOCK]"), prepend_block);

		pfile.Write(_("\n"));
	}

	pfile.Write(_("\'------------[STAGE LOAD FUNCTIONS]-----------") + _("\n"));
	pfile.Write(stage_load_fn);
	pfile.Write(_("\n"));

	pfile.Close();

	return true;
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

void serenity_project::init_grid(std::vector<serenity_project_dict_obj> param)
{
	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("color"))==0)
		{
			irr::u32 c_val = 0;
			param[i].val.ToUInt(&c_val);
			grid_color = irr::video::SColor(c_val).color;
		}
		else if(param[i].key.compare(_("visible"))==0)
		{
			grid_visible = (param[i].val.compare(_("true"))==0);
		}
		else if(param[i].key.compare(_("size"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			grid_size = n;
		}
		else if(param[i].key.compare(_("spacing"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			grid_spacing = n;
		}
	}
}

void serenity_project::init_tools(std::vector<serenity_project_dict_obj> param)
{
	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("show_lines"))==0)
		{
			show_axis_lines = (param[i].val.compare(_("true"))==0);
		}
		else if(param[i].key.compare(_("show_rings"))==0)
		{
			show_axis_rings = (param[i].val.compare(_("true"))==0);
		}
	}
}

void serenity_project::init_camera(std::vector<serenity_project_dict_obj> param)
{
	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("show_position"))==0)
		{
			show_camera_pos = (param[i].val.compare(_("true"))==0);
		}
		else if(param[i].key.compare(_("show_rotation"))==0)
		{
			show_camera_rot = (param[i].val.compare(_("true"))==0);
		}
		else if(param[i].key.compare(_("speed"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			camera_speed = n;
		}
	}
}

void serenity_project::init_hud(std::vector<serenity_project_dict_obj> param)
{
	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("color"))==0)
		{
			irr::u32 c_val = 0;
			param[i].val.ToUInt(&c_val);
			hud_color = irr::video::SColor(c_val);
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
	p_stage.sky.node = NULL;

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
		else if(st_obj[i].dict[0].key.compare(_("Sky"))==0)
		{
			rc_sky p_sky = load_sky(st_obj[i].dict);

			p_stage.sky = p_sky;
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
	if(stage_id < 0 || stage_id >= stages.size())
		return;

	wxFileName stage_fname = project_path;
	stage_fname.AppendDir(_("stages"));
	stage_fname.SetFullName(wxString::FromUTF8(stages[stage_id].file));
	//stage_fname.SetFullName(_("test_out.snst"));

	//wxMessageBox(_("Save to: ") + stage_fname.GetAbsolutePath());

	wxFile stage_file(stage_fname.GetAbsolutePath(), wxFile::write);

	if(!stage_file.IsOpened())
	{
		wxMessageBox(_("Stage could not be saved"));
		return;
	}

	stage_file.Write(_("Stage id=") + stages[stage_id].id_name + _(";\n"));

	stage_file.Write(_("\n---------------[Resources]----------------;\n\n"));

	for(int i = 0; i < textures.size(); i++)
	{
		wxString id_name = wxString::FromUTF8(textures[i].id_name);
		if(id_name.Trim().compare(_(""))==0)
			continue;

		id_name = _("id=") + id_name;

		wxString tx_file = _("file=\"") + wxString::FromUTF8(textures[i].file) + _("\"");
		wxString colkey = textures[i].use_colorKey ? _("color_key=") + wxString::Format(_("%u"), textures[i].colorkey.color) : _("");

		stage_file.Write(_("Image ") + id_name + _(" ") + tx_file + _(" ") + colkey + _(";\n"));
	}

	stage_file.Write(_("\n\n"));

	for(int i = 0; i < materials.size(); i++)
	{
		wxString id_name = wxString::FromUTF8(materials[i].id_name);
		if(id_name.Trim().compare(_(""))==0)
			continue;

		id_name = _("id=") + id_name;

		wxString mat_file = _("file=\"") + wxString::FromUTF8(materials[i].file) + _("\"");

		stage_file.Write(_("Material ") + id_name + _(" ") + mat_file + _(";\n"));
	}

	stage_file.Write(_("\n\n"));

	for(int i = 0; i < anim8or_projects.size(); i++)
	{
		wxString id_name = wxString::FromUTF8(anim8or_projects[i].id_name);
		if(id_name.Trim().compare(_(""))==0)
			continue;

		id_name = _("id=") + id_name;

		wxString a8_file = _("file=\"") + wxString::FromUTF8(anim8or_projects[i].file) + _("\"");

		stage_file.Write(_("AN8 ") + id_name + _(" ") + a8_file + _(";\n"));
	}

	stage_file.Write(_("\n\n"));

	for(int i = 0; i < meshes.size(); i++)
	{
		wxString id_name = wxString::FromUTF8(meshes[i].id_name);
		if(id_name.Trim().compare(_(""))==0)
			continue;

		id_name = _("id=") + id_name;

		wxString mesh_file = _("file=\"") + wxString::FromUTF8(meshes[i].file) + _("\"");

		wxString a8_data = _("");
		if(meshes[i].isAN8Scene)
		{
			a8_data = _("an8=");
			int a8_index = meshes[i].an8_index;
			if(a8_index >= 0 && a8_index < anim8or_projects.size())
				a8_data += wxString::FromUTF8(anim8or_projects[a8_index].id_name);

			a8_data += _(" scene=\"") + wxString::FromUTF8(meshes[i].an8_scene) + _("\"");
			stage_file.Write(_("Mesh ") + id_name + _(" ") + a8_data);
		}
		else if(meshes[i].isZipped)
		{
			wxString zip_file = _("zip=\"") + wxString::FromUTF8(meshes[i].zip_file) + _("\"");
			stage_file.Write(_("Mesh ") + id_name + _(" ") + zip_file + _(" ") + mesh_file);
		}
		else if(meshes[i].file.substr(0,1).compare("!")==0)
		{
			if(meshes[i].file.compare("!plane")==0)
			{
				stage_file.Write(_("Mesh ") + id_name + _(" ") + mesh_file + _(" ") +
								_("tile_width=") + wxString::Format(_("%d"), meshes[i].tile_width) + _(" ") +
								_("tile_height=") + wxString::Format(_("%d"), meshes[i].tile_height) + _(" ") +
								_("tile_count_x=") + wxString::Format(_("%d"), meshes[i].tile_count_x) + _(" ") +
								_("tile_count_y=") + wxString::Format(_("%d"), meshes[i].tile_count_y) + _(" ") +
								_("tx_repeat_x=") + wxString::Format(_("%d"), meshes[i].tile_txRepeat_x) + _(" ") +
								_("tx_repeat_y=") + wxString::Format(_("%d"), meshes[i].tile_txRepeat_y));
			}
			else if(meshes[i].file.compare("!cone")==0)
			{
				stage_file.Write(_("Mesh ") + id_name + _(" ") + mesh_file + _(" ") +
								_("radius=") + wxString::FromDouble(meshes[i].radius) + _(" ") +
								_("length=") + wxString::FromDouble(meshes[i].length) + _(" ") +
								_("tesselation=") + wxString::Format(_("%d"), meshes[i].tesselation) + _(" ") +
								_("top_color=") + wxString::Format(_("%u"), meshes[i].cone_top_color.color) + _(" ") +
								_("bottom_color=") + wxString::Format(_("%u"), meshes[i].cone_bottom_color.color));
			}
			else if(meshes[i].file.compare("!cylinder")==0)
			{
				stage_file.Write(_("Mesh ") + id_name + _(" ") + mesh_file + _(" ") +
								_("radius=") + wxString::FromDouble(meshes[i].radius) + _(" ") +
								_("length=") + wxString::FromDouble(meshes[i].length) + _(" ") +
								_("tesselation=") + wxString::Format(_("%d"), meshes[i].tesselation) + _(" ") +
								_("cylinder_color=") + wxString::Format(_("%u"), meshes[i].cylinder_color.color) + _(" ") +
								_("close_top=") + (meshes[i].cylinder_top_close ? _("true") : _("false")));
			}
		}
		else
		{
			stage_file.Write(_("Mesh ") + id_name + _(" ") + mesh_file);
		}

		for(int m_index = 0; m_index < meshes[i].material_index.size(); m_index++)
		{
			int mat_index = meshes[i].material_index[m_index];
			if(mat_index < 0 || mat_index >= materials.size())
				stage_file.Write(_(" material=[NULL]"));
			else
				stage_file.Write(_(" material=") + (materials[mat_index].id_name.compare("")==0 ? _("[NULL]") :  wxString::FromUTF8(materials[mat_index].id_name)));
		}

		stage_file.Write(_(";\n"));

	}


	stage_file.Write(_("\n\n"));

	for(int i = 0; i < stages[stage_id].groups.size(); i++)
	{
		if(stages[stage_id].groups[i].label.compare("")==0)
			continue;

		stage_file.Write(_("Group label=\"") + wxString::FromUTF8(stages[stage_id].groups[i].label) + ("\";\n"));
	}

	stage_file.Write(_("\n---------------[Scene]----------------;\n\n"));

	int tx_index = stages[stage_id].sky.dome_texture_index;
	wxString dome_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.left_texture_index;
	wxString lf_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.right_texture_index;
	wxString rt_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.top_texture_index;
	wxString up_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.bottom_texture_index;
	wxString dn_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.back_texture_index;
	wxString bk_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	tx_index = stages[stage_id].sky.front_texture_index;
	wxString ft_img = ( tx_index < 0 || tx_index >= textures.size() ? _("[NULL]") : wxString::FromUTF8(textures[tx_index].id_name) );

	stage_file.Write( _("Sky type=") + getSkyTypeString(stages[stage_id].sky.type) + _(" ") +
					  _("dome=") + dome_img + _(" ") +
					  _("lf=") + lf_img + _(" ") +
					  _("rt=") + rt_img + _(" ") +
					  _("up=") + up_img + _(" ") +
					  _("dn=") + dn_img + _(" ") +
					  _("ft=") + ft_img + _(" ") +
					  _("bk=") + bk_img + _(" ") +
					  _("h=") + wxString::FromDouble(stages[stage_id].sky.hRes) + _(" ") +
					  _("v=") + wxString::FromDouble(stages[stage_id].sky.vRes) + _(" ") +
					  _("tx_pct=") + wxString::FromDouble(stages[stage_id].sky.txPCT) + _(" ") +
					  _("sp_pct=") + wxString::FromDouble(stages[stage_id].sky.spherePCT) + _(" ") +
					  _("radius=") + wxString::FromDouble(stages[stage_id].sky.dome_radius) + _(";\n") );

	stage_file.Write(_("\n\n"));

	for(int i = 0; i < stages[stage_id].actors.size(); i++)
	{
		if(stages[stage_id].actors[i].id_name.compare("")==0)
			continue;

		wxString actor_group = wxString::FromUTF8(stages[stage_id].actors[i].group_name);
		wxString actor_mesh = _("[NULL]");
		wxString actor_animation = _("[NULL]");
		wxString actor_material = _("[NULL]");
		wxString actor_hmap = _("[NULL]");

		if(stages[stage_id].actors[i].mesh_index >= 0 && stages[stage_id].actors[i].mesh_index < meshes.size())
		{
			actor_mesh = wxString::FromUTF8(meshes[ stages[stage_id].actors[i].mesh_index ].id_name);

			int animation_index = stages[stage_id].actors[i].animation_index;
			if(animation_index >= 0 && animation_index < meshes[ stages[stage_id].actors[i].mesh_index ].animation.size())
				actor_animation = meshes[ stages[stage_id].actors[i].mesh_index ].animation[animation_index].id_name;
		}

		if(stages[stage_id].actors[i].override_material_index >= 0 && stages[stage_id].actors[i].override_material_index < materials.size())
			actor_material = materials[stages[stage_id].actors[i].override_material_index].id_name;

		stage_file.Write(_("Actor type=") + getActorTypeString(stages[stage_id].actors[i].type) + _(" ") +
							_("id=") + wxString::FromUTF8(stages[stage_id].actors[i].id_name) + _(" ") +
							( actor_group.Trim().compare(_(""))==0 ? _("") : _("group=\"") + actor_group + _("\"")) + _(" ") +
							_("mesh=") + actor_mesh + _(" ") +
							_("animation=") + actor_animation + _(" ") +
							_("loops=") + wxString::Format(_("%d"), stages[stage_id].actors[i].num_loops) + _(" ") +
							_("material=") + actor_material + _(" ") +
							_("pos_x=") + wxString::FromDouble((double)stages[stage_id].actors[i].position.X) + _(" ") +
							_("pos_y=") + wxString::FromDouble((double)stages[stage_id].actors[i].position.Y) + _(" ") +
							_("pos_z=") + wxString::FromDouble((double)stages[stage_id].actors[i].position.Z) + _(" ") +
							_("rot_x=") + wxString::FromDouble((double)stages[stage_id].actors[i].rotation.X) + _(" ") +
							_("rot_y=") + wxString::FromDouble((double)stages[stage_id].actors[i].rotation.Y) + _(" ") +
							_("rot_z=") + wxString::FromDouble((double)stages[stage_id].actors[i].rotation.Z) + _(" ") +
							_("scale_x=") + wxString::FromDouble((double)stages[stage_id].actors[i].scale.X) + _(" ") +
							_("scale_y=") + wxString::FromDouble((double)stages[stage_id].actors[i].scale.Y) + _(" ") +
							_("scale_z=") + wxString::FromDouble((double)stages[stage_id].actors[i].scale.Z) + _(" ") +
							_("visible=") + (stages[stage_id].actors[i].visible ? _("true") : _("false")) + _(" ") +
							_("shadow=") + (stages[stage_id].actors[i].hasShadow ? _("true") : _("false")) + _(" ") +
							_("auto_culling=") + (stages[stage_id].actors[i].auto_culling ? _("true") : _("false")) + _(" ") +
							_("physics_shape=") + getPhysicsShapeString(stages[stage_id].actors[i].physics.shape) + _(" ") +
							_("physics_solid=") + (stages[stage_id].actors[i].physics.isSolid ? _("true") : _("false")) + _(" ") +
							_("physics_mass=") + wxString::FromDouble(stages[stage_id].actors[i].physics.mass) + _(" ") +
							_("cube_size=") + wxString::FromDouble(stages[stage_id].actors[i].cube_size) + _(" ") +
							_("radius=") + wxString::FromDouble(stages[stage_id].actors[i].radius) + _(" ") +
							_("cast_shadow=") + (stages[stage_id].actors[i].isCastingShadow ? _("true") : _("false")) + _(" ") +
							_("light_type=") + getLightTypeString(stages[stage_id].actors[i].light_type) + _(" ") +
							_("falloff=") + wxString::FromDouble(stages[stage_id].actors[i].falloff) + _(" ") +
							_("ambient=") + wxString::Format(_("%u"), stages[stage_id].actors[i].ambient.color) + _(" ") +
							_("diffuse=") + wxString::Format(_("%u"), stages[stage_id].actors[i].diffuse.color) + _(" ") +
							_("specular=") + wxString::Format(_("%u"), stages[stage_id].actors[i].specular.color) + _(" ") +
							_("inner_cone=") + wxString::FromDouble(stages[stage_id].actors[i].inner_cone) + _(" ") +
							_("outer_cone=") + wxString::FromDouble(stages[stage_id].actors[i].outer_cone) + _(" ") +
							_("constant=") + wxString::FromDouble(stages[stage_id].actors[i].attenuation.X) + _(" ") +
							_("linear=") + wxString::FromDouble(stages[stage_id].actors[i].attenuation.Y) + _(" ") +
							_("quadratic=") + wxString::FromDouble(stages[stage_id].actors[i].attenuation.Z) + _(" ") +
							_("particle_type=") + getParticleTypeString(stages[stage_id].actors[i].particle_type) + _(" ") +
							_("dir_x=") + wxString::FromDouble(stages[stage_id].actors[i].direction.X) + _(" ") +
							_("dir_y=") + wxString::FromDouble(stages[stage_id].actors[i].direction.Y) + _(" ") +
							_("dir_z=") + wxString::FromDouble(stages[stage_id].actors[i].direction.Z) + _(" ") +
							_("use_every_vertex=") + (stages[stage_id].actors[i].use_every_vertex ? _("true") : _("false")) + _(" ") +
							_("normal_dir_mod=") + wxString::FromDouble(stages[stage_id].actors[i].normal_direction_modifier) + _(" ") +
							_("use_normal_dir=") + (stages[stage_id].actors[i].use_normal_direction ? _("true") : _("false")) + _(" ") +
							_("min_per_sec=") + wxString::FromDouble(stages[stage_id].actors[i].min_per_sec) + _(" ") +
							_("max_per_sec=") + wxString::FromDouble(stages[stage_id].actors[i].max_per_sec) + _(" ") +
							_("min_start_color=") + wxString::Format(_("%u"), stages[stage_id].actors[i].min_start_color.color) + _(" ") +
							_("max_start_color=") + wxString::Format(_("%u"), stages[stage_id].actors[i].max_start_color.color) + _(" ") +
							_("min_life=") + wxString::FromDouble(stages[stage_id].actors[i].min_life) + _(" ") +
							_("max_life=") + wxString::FromDouble(stages[stage_id].actors[i].max_life) + _(" ") +
							_("max_angle=") + wxString::FromDouble(stages[stage_id].actors[i].angle) + _(" ") +
							_("min_start_width=") + wxString::FromDouble(stages[stage_id].actors[i].min_width) + _(" ") +
							_("min_start_height=") + wxString::FromDouble(stages[stage_id].actors[i].min_height) + _(" ") +
							_("max_start_width=") + wxString::FromDouble(stages[stage_id].actors[i].max_width) + _(" ") +
							_("max_start_height=") + wxString::FromDouble(stages[stage_id].actors[i].max_height) + _(" ") +
							_("center_x=") + wxString::FromDouble(stages[stage_id].actors[i].center.X) + _(" ") +
							_("center_y=") + wxString::FromDouble(stages[stage_id].actors[i].center.Y) + _(" ") +
							_("center_z=") + wxString::FromDouble(stages[stage_id].actors[i].center.Z) + _(" ") +
							_("ring_thickness=") + wxString::FromDouble(stages[stage_id].actors[i].ring_thickness) + _(" ") +
							_("box_min_x=") + wxString::FromDouble(stages[stage_id].actors[i].box.MinEdge.X) + _(" ") +
							_("box_min_y=") + wxString::FromDouble(stages[stage_id].actors[i].box.MinEdge.Y) + _(" ") +
							_("box_min_z=") + wxString::FromDouble(stages[stage_id].actors[i].box.MinEdge.Z) + _(" ") +
							_("box_max_x=") + wxString::FromDouble(stages[stage_id].actors[i].box.MaxEdge.X) + _(" ") +
							_("box_max_y=") + wxString::FromDouble(stages[stage_id].actors[i].box.MaxEdge.Y) + _(" ") +
							_("box_max_z=") + wxString::FromDouble(stages[stage_id].actors[i].box.MaxEdge.Z) + _(" ") +
							_("normal_x=") + wxString::FromDouble(stages[stage_id].actors[i].normal.X) + _(" ") +
							_("normal_y=") + wxString::FromDouble(stages[stage_id].actors[i].normal.Y) + _(" ") +
							_("normal_z=") + wxString::FromDouble(stages[stage_id].actors[i].normal.Z) + _(" ") +
							_("length=") + wxString::FromDouble(stages[stage_id].actors[i].cylinder_length) + _(" ") +
							_("use_outline_only=") + (stages[stage_id].actors[i].use_outline_only ? _("true") : _("false")) + _(" ") +
							_("terrain_hmap_file=") + wxString::FromUTF8(stages[stage_id].actors[i].terrain_hmap_file) + _(" ") +
							_("wave_height=") + wxString::FromDouble(stages[stage_id].actors[i].wave_height) + _(" ") +
							_("wave_speed=") + wxString::FromDouble(stages[stage_id].actors[i].wave_speed) + _(" ") +
							_("wave_length=") + wxString::FromDouble(stages[stage_id].actors[i].wave_length) + _(";\n") );

	}

	stage_file.Close();
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

wxString serenity_project::getParticleTypeString(int particle_type)
{
	switch(particle_type)
	{
		case SN_PARTICLE_TYPE_POINT:	return _("POINT");
		case SN_PARTICLE_TYPE_BOX:		return _("BOX");
		case SN_PARTICLE_TYPE_SPHERE:	return _("SPHERE");
		case SN_PARTICLE_TYPE_CYLINDER:	return _("CYLINDER");
		case SN_PARTICLE_TYPE_MESH:		return _("MESH");
		case SN_PARTICLE_TYPE_RING:		return _("RING");
	}
	return _("POINT");
}

int serenity_project::getParticleType(wxString particle_type_string)
{
	if(particle_type_string.compare(_("POINT"))==0)
		return SN_PARTICLE_TYPE_POINT;
	else if(particle_type_string.compare(_("BOX"))==0)
		return SN_PARTICLE_TYPE_BOX;
	else if(particle_type_string.compare(_("SPHERE"))==0)
		return SN_PARTICLE_TYPE_SPHERE;
	else if(particle_type_string.compare(_("CYLINDER"))==0)
		return SN_PARTICLE_TYPE_CYLINDER;
	else if(particle_type_string.compare(_("MESH"))==0)
		return SN_PARTICLE_TYPE_MESH;
	else if(particle_type_string.compare(_("RING"))==0)
		return SN_PARTICLE_TYPE_RING;

	return 0;
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

wxString serenity_project::getPhysicsShapeString(int physics_shape)
{
	switch(physics_shape)
	{
		case SN_PHYSICS_SHAPE_BOX:			return _("BOX");
		case SN_PHYSICS_SHAPE_SPHERE:		return _("SPHERE");
		case SN_PHYSICS_SHAPE_CYLINDER:		return _("CYLINDER");
		case SN_PHYSICS_SHAPE_CAPSULE:		return _("CAPSULE");
		case SN_PHYSICS_SHAPE_CONE:			return _("CONE");
		case SN_PHYSICS_SHAPE_CONVEXHULL:	return _("CONVEXHULL");
		case SN_PHYSICS_SHAPE_TRIMESH:		return _("TRIMESH");
	}
	return _("NONE");
}

int serenity_project::getPhysicsShape(wxString physics_shape_string)
{
	if(physics_shape_string.compare(_("BOX"))==0)
		return SN_PHYSICS_SHAPE_BOX;
	else if(physics_shape_string.compare(_("SPHERE"))==0)
		return SN_PHYSICS_SHAPE_SPHERE;
	else if(physics_shape_string.compare(_("CYLINDER"))==0)
		return SN_PHYSICS_SHAPE_CYLINDER;
	else if(physics_shape_string.compare(_("CAPSULE"))==0)
		return SN_PHYSICS_SHAPE_CAPSULE;
	else if(physics_shape_string.compare(_("CONE"))==0)
		return SN_PHYSICS_SHAPE_CONE;
	else if(physics_shape_string.compare(_("CONVEXHULL"))==0)
		return SN_PHYSICS_SHAPE_CONVEXHULL;
	else if(physics_shape_string.compare(_("TRIMESH"))==0)
		return SN_PHYSICS_SHAPE_TRIMESH;

	return 0;
}

int serenity_project::getMeshIndex(wxString mesh_id)
{
	for(int i = 0; i < meshes.size(); i++)
	{
		if(meshes[i].id_name.compare(mesh_id.ToStdString())==0)
			return i;
	}
	return -1;
}

int serenity_project::getMaterialIndex(wxString material_id)
{
	for(int i = 0; i < materials.size(); i++)
	{
		if(materials[i].id_name.compare(material_id.ToStdString())==0)
			return i;
	}
	return -1;
}

int serenity_project::getTextureIndex(wxString texture_id)
{
	for(int i = 0; i < textures.size(); i++)
	{
		if(textures[i].id_name.compare(texture_id.ToStdString())==0)
			return i;
	}
	return -1;
}

int serenity_project::getAnimationIndex(int mesh_index, wxString animation_id)
{
	if(mesh_index < 0 || mesh_index >= meshes.size())
		return -1;

	for(int i = 0; i < meshes[mesh_index].animation.size(); i++)
	{
		if(meshes[mesh_index].animation[i].id_name.compare(animation_id.ToStdString())==0)
			return i;
	}
	return -1;
}

rc_actor serenity_project::load_actor(std::vector<serenity_project_dict_obj> param)
{
	rc_actor p_actor;

	double pos_x, pos_y, pos_z, rot_x, rot_y, rot_z, scale_x, scale_y, scale_z, normal_x, normal_y, normal_z;
	double dir_x, dir_y, dir_z, center_x, center_y, center_z, box_min_x, box_min_y, box_min_z, box_max_x, box_max_y, box_max_z;

	wxString animation_id = _(""); //storing this and getting it after reading args since mesh_index might not be read before animation_id


	p_actor.id_name = "";
	p_actor.type = 0;
	p_actor.group_name = "";
	p_actor.mesh_index = -1; //project index
	p_actor.node = NULL; //cast to object type
	p_actor.position = irr::core::vector3df(0,0,0);
	p_actor.rotation = irr::core::vector3df(0,0,0);
	p_actor.scale = irr::core::vector3df(1,1,1);
	p_actor.override_material_index = -1; //if less than 0 then mesh material is used
	p_actor.animation_index = -1; //if less than 0 then frame 0 is set
	p_actor.num_loops = -1;
	p_actor.visible = true;
	p_actor.hasShadow = true;
	p_actor.isCastingShadow = true; //LIGHTS ONLY
	p_actor.auto_culling = true;
	p_actor.cube_size = 1;
	p_actor.radius = 1;
	p_actor.texture_index = -1; //in project
	p_actor.light_type = SN_LIGHT_TYPE_POINT;
	p_actor.angle = 0;
	p_actor.falloff = 0;
	p_actor.ambient = irr::video::SColor();
	p_actor.emissive = irr::video::SColor();
	p_actor.diffuse = irr::video::SColor();
	p_actor.specular = irr::video::SColor();
	p_actor.terrain_hmap_file = "";
	p_actor.wave_height = 0;
	p_actor.wave_length = 0;
	p_actor.wave_speed = 0;
	p_actor.particle_type = 0;
	p_actor.normal = irr::core::vector3df(0,0,0);
	p_actor.direction = irr::core::vector3df(0,0,0);
	p_actor.box = irr::core::aabbox3df( irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0) );
	p_actor.center = irr::core::vector3df(0,0,0);

	p_actor.use_every_vertex = false;
	p_actor.use_normal_direction = false;
	p_actor.normal_direction_modifier = 100.0;

	p_actor.cylinder_length = 0;
	p_actor.use_outline_only = false;

	p_actor.ring_thickness = 0;

	p_actor.min_width = 0;
	p_actor.min_height = 0;

	p_actor.max_width = 0;
	p_actor.max_height = 0;

	p_actor.min_per_sec = 0;
	p_actor.max_per_sec = 0;

	p_actor.min_start_color = irr::video::SColor();
	p_actor.max_start_color = irr::video::SColor();

	p_actor.min_life = 0;
	p_actor.max_life = 0;

	p_actor.inner_cone = 0;
	p_actor.outer_cone = 0;
	p_actor.attenuation = irr::core::vector3df(0, 0, 0);

	p_actor.physics.isSolid = true;
	p_actor.physics.shape = SN_PHYSICS_SHAPE_BOX;
	p_actor.physics.mass = 1;

	double constant_n = 0;
	double linear_n = 0;
	double quadratic_n = 0;



	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("type"))==0)
			p_actor.type = getActorType(param[i].val.ToStdString());
		else if(param[i].key.compare(_("id"))==0)
			p_actor.id_name = param[i].val.ToStdString();
		else if(param[i].key.compare(_("group"))==0)
			p_actor.group_name = param[i].val.ToStdString();
		else if(param[i].key.compare(_("mesh"))==0)
			p_actor.mesh_index = getMeshIndex(param[i].val);
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
			p_actor.override_material_index = getMaterialIndex(param[i].val);
		else if(param[i].key.compare(_("animation"))==0)
			animation_id = param[i].val;
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
		else if(param[i].key.compare(_("texture"))==0)
			p_actor.texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("light_type"))==0)
			p_actor.light_type = getLightType(param[i].val);
		else if(param[i].key.compare(_("particle_type"))==0)
			p_actor.particle_type = getParticleType(param[i].val);
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
		else if(param[i].key.compare(_("min_start_color"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.min_start_color = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("max_start_color"))==0)
		{
			irr::u32 c = 0;
			param[i].val.ToUInt(&c);
			p_actor.max_start_color = irr::video::SColor(c);
		}
		else if(param[i].key.compare(_("dir_x"))==0)
			param[i].val.ToDouble(&dir_x);
		else if(param[i].key.compare(_("dir_y"))==0)
			param[i].val.ToDouble(&dir_y);
		else if(param[i].key.compare(_("dir_z"))==0)
			param[i].val.ToDouble(&dir_z);
		else if(param[i].key.compare(_("center_x"))==0)
			param[i].val.ToDouble(&center_x);
		else if(param[i].key.compare(_("center_y"))==0)
			param[i].val.ToDouble(&center_y);
		else if(param[i].key.compare(_("center_z"))==0)
			param[i].val.ToDouble(&center_z);
		else if(param[i].key.compare(_("normal_x"))==0)
			param[i].val.ToDouble(&normal_x);
		else if(param[i].key.compare(_("normal_y"))==0)
			param[i].val.ToDouble(&normal_y);
		else if(param[i].key.compare(_("normal_z"))==0)
			param[i].val.ToDouble(&normal_z);
		else if(param[i].key.compare(_("box_min_x"))==0)
			param[i].val.ToDouble(&box_min_x);
		else if(param[i].key.compare(_("box_min_y"))==0)
			param[i].val.ToDouble(&box_min_y);
		else if(param[i].key.compare(_("box_min_z"))==0)
			param[i].val.ToDouble(&box_min_z);
		else if(param[i].key.compare(_("box_max_x"))==0)
			param[i].val.ToDouble(&box_max_x);
		else if(param[i].key.compare(_("box_max_y"))==0)
			param[i].val.ToDouble(&box_max_y);
		else if(param[i].key.compare(_("box_max_z"))==0)
			param[i].val.ToDouble(&box_max_z);
		else if(param[i].key.compare(_("use_every_vertex"))==0)
			p_actor.use_every_vertex = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("use_normal_direction"))==0)
			p_actor.use_normal_direction = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("use_outline_only"))==0)
			p_actor.use_outline_only = (param[i].val.compare(_("true"))==0 ? true : false);
		else if(param[i].key.compare(_("normal_dir_mod"))==0)
			param[i].val.ToDouble(&p_actor.normal_direction_modifier);
		else if(param[i].key.compare(_("length"))==0)
			param[i].val.ToDouble(&p_actor.cylinder_length);
		else if(param[i].key.compare(_("ring_thickness"))==0)
			param[i].val.ToDouble(&p_actor.ring_thickness);
		else if(param[i].key.compare(_("min_start_width"))==0)
			param[i].val.ToDouble(&p_actor.min_width);
		else if(param[i].key.compare(_("min_start_height"))==0)
			param[i].val.ToDouble(&p_actor.min_height);
		else if(param[i].key.compare(_("max_start_width"))==0)
			param[i].val.ToDouble(&p_actor.max_width);
		else if(param[i].key.compare(_("max_start_height"))==0)
			param[i].val.ToDouble(&p_actor.max_height);
		else if(param[i].key.compare(_("min_per_sec"))==0)
			param[i].val.ToDouble(&p_actor.min_per_sec);
		else if(param[i].key.compare(_("max_per_sec"))==0)
			param[i].val.ToDouble(&p_actor.max_per_sec);
		else if(param[i].key.compare(_("min_life"))==0)
			param[i].val.ToDouble(&p_actor.min_life);
		else if(param[i].key.compare(_("max_life"))==0)
			param[i].val.ToDouble(&p_actor.max_life);
		else if(param[i].key.compare(_("inner_cone"))==0)
			param[i].val.ToDouble(&p_actor.inner_cone);
		else if(param[i].key.compare(_("outer_cone"))==0)
			param[i].val.ToDouble(&p_actor.outer_cone);
		else if(param[i].key.compare(_("constant"))==0)
			param[i].val.ToDouble(&constant_n);
		else if(param[i].key.compare(_("linear"))==0)
			param[i].val.ToDouble(&linear_n);
		else if(param[i].key.compare(_("quadratic"))==0)
			param[i].val.ToDouble(&quadratic_n);
		else if(param[i].key.compare(_("physics_shape"))==0)
			p_actor.physics.shape = getPhysicsShape(param[i].val);
		else if(param[i].key.compare(_("physics_mass"))==0)
			param[i].val.ToDouble(&p_actor.physics.mass);
		else if(param[i].key.compare(_("physics_solid"))==0)
			p_actor.physics.isSolid = (param[i].val.compare(_("true"))==0 ? true : false);
	}

	p_actor.animation_index = getAnimationIndex(p_actor.mesh_index, animation_id);

	p_actor.position = irr::core::vector3df(pos_x, pos_y, pos_z);
	p_actor.rotation = irr::core::vector3df(rot_x, rot_y, rot_z);
	p_actor.scale = irr::core::vector3df(scale_x, scale_y, scale_z);
	p_actor.normal = irr::core::vector3df(normal_x, normal_y, normal_z);
	p_actor.direction = irr::core::vector3df(dir_x, dir_y, dir_z);
	p_actor.center = irr::core::vector3df(center_x, center_y, center_z);
	p_actor.box = irr::core::aabbox3df(box_min_x, box_min_y, box_min_z, box_max_x, box_max_y, box_max_z);
	p_actor.attenuation = irr::core::vector3df(constant_n, linear_n, quadratic_n);

	p_actor.node = NULL;
	p_actor.icon_node = NULL;

	return p_actor;
}


wxString serenity_project::getSkyTypeString(int sky_type)
{
	switch(sky_type)
	{
		case SN_SKY_TYPE_NONE: return _("NONE");
		case SN_SKY_TYPE_BOX:  return _("BOX");
		case SN_SKY_TYPE_DOME: return _("DOME");
	}
	return _("NONE");
}

int serenity_project::getSkyType(wxString sky_type_string)
{
	if(sky_type_string.compare(_("BOX"))==0)
		return SN_SKY_TYPE_BOX;
	else if(sky_type_string.compare(_("DOME"))==0)
		return SN_SKY_TYPE_DOME;

	return SN_SKY_TYPE_NONE;
}

rc_sky serenity_project::load_sky(std::vector<serenity_project_dict_obj> param)
{
	rc_sky p_sky;
	p_sky.node = NULL;

	for(int i = 0; i < param.size(); i++)
	{
		if(param[i].key.compare(_("type"))==0)
			p_sky.type = getSkyType(param[i].val.ToStdString());
		else if(param[i].key.compare(_("dome"))==0)
			p_sky.dome_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("lf"))==0)
			p_sky.left_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("rt"))==0)
			p_sky.right_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("ft"))==0)
			p_sky.front_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("bk"))==0)
			p_sky.back_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("up"))==0)
			p_sky.top_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("dn"))==0)
			p_sky.bottom_texture_index = getTextureIndex(param[i].val);
		else if(param[i].key.compare(_("h"))==0)
		{
			irr::u32 n = 0;
			param[i].val.ToUInt(&n);
			p_sky.hRes = n;
		}
		else if(param[i].key.compare(_("v"))==0)
		{
			irr::u32 n = 0;
			param[i].val.ToUInt(&n);
			p_sky.vRes = n;
		}
		else if(param[i].key.compare(_("tx_pct"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			p_sky.txPCT = n;
		}
		else if(param[i].key.compare(_("sp_pct"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			p_sky.spherePCT = n;
		}
		else if(param[i].key.compare(_("radius"))==0)
		{
			double n = 0;
			param[i].val.ToDouble(&n);
			p_sky.dome_radius = n;
		}

	}

	return p_sky;
}


int serenity_project::load_texture(std::vector<serenity_project_dict_obj> param, int reload_index)
{
	if(param.size() < 3)
		return -1;

	wxString id_name = _("");
	wxString file_name = _("");

	bool has_colorKey = false;
	irr::u32 color_key = -1;

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
				param[i].val.ToUInt(&color_key);
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
	p_texture.colorkey.set(0);

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
		if(anim8or_projects[i].file.compare(file_name.ToStdString())==0)
		{
			return i; //don't add image if id is already loaded
		}
	}

	rc_an8 p_an8;
	p_an8.file = file_name.ToStdString();
	p_an8.id_name = id_name.ToStdString();

	//wxMessageBox(_("LOAD AN8 PROJECT: ") + fname.GetAbsolutePath());

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
	p_mesh.isZipped = false;

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
			else if(param[i].key.compare(_("tile_width"))==0)
				param[i].val.ToInt(&p_mesh.tile_width);
			else if(param[i].key.compare(_("tile_height"))==0)
				param[i].val.ToInt(&p_mesh.tile_height);
			else if(param[i].key.compare(_("tile_count_x"))==0)
				param[i].val.ToInt(&p_mesh.tile_count_x);
			else if(param[i].key.compare(_("tile_count_y"))==0)
				param[i].val.ToInt(&p_mesh.tile_count_y);
			else if(param[i].key.compare(_("tx_repeat_x"))==0)
				param[i].val.ToInt(&p_mesh.tile_txRepeat_x);
			else if(param[i].key.compare(_("tx_repeat_y"))==0)
				param[i].val.ToInt(&p_mesh.tile_txRepeat_y);
			else if(param[i].key.compare(_("radius"))==0)
			{
				double dval = 0;
				param[i].val.ToDouble(&dval);
				p_mesh.radius = dval;
			}
			else if(param[i].key.compare(_("length"))==0)
			{
				double dval = 0;
				param[i].val.ToDouble(&dval);
				p_mesh.length = dval;
			}
			else if(param[i].key.compare(_("tesselation"))==0)
				param[i].val.ToInt(&p_mesh.tesselation);
			else if(param[i].key.compare(_("top_color"))==0)
			{
				irr::u32 c_val = 0;
				param[i].val.ToUInt(&c_val);
				p_mesh.cone_top_color = irr::video::SColor(c_val);
			}
			else if(param[i].key.compare(_("bottom_color"))==0)
			{
				irr::u32 c_val = 0;
				param[i].val.ToUInt(&c_val);
				p_mesh.cone_bottom_color = irr::video::SColor(c_val);
			}
			else if(param[i].key.compare(_("cylinder_color"))==0)
			{
				irr::u32 c_val = 0;
				param[i].val.ToUInt(&c_val);
				p_mesh.cylinder_color = irr::video::SColor(c_val);
			}
			else if(param[i].key.compare(_("close_top"))==0)
			{
				p_mesh.cylinder_top_close = (param[i].val.compare(_("true"))==0);
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

	if(file_name.Trim().substr(0,1).compare(_("!")) != 0)
	{
		if(!fname.Exists())
		{
			wxMessageBox(_("Failed to load model (") + file_name + _("): File not found."));
			return -1;
		}
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

	//wxMessageBox(_("MESH R: ") + p_mesh.id_name + _(" -- ") + (p_mesh.isAN8Scene ? _("true") : _("false")) + _(" -- ") + (in_zip ? _("true") : _("false")));

	if(in_zip)
	{
		device->getFileSystem()->addFileArchive(fname.GetAbsolutePath().ToStdString().c_str());
		p_mesh.mesh = device->getSceneManager()->getMesh(file_name.ToStdString().c_str());
		device->getFileSystem()->removeFileArchive((irr::u32) 0);
	}
	else if(p_mesh.isAN8Scene)
	{
		//if(m_index >= 0)
		//	wxMessageBox(_("RELOAD AN8"));

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
			//wxMessageBox(_("AN8 LOADED"));
		}
	}
	else if(p_mesh.file.substr(0,1).compare("!")==0)
	{
		const irr::scene::IGeometryCreator* gc = device->getSceneManager()->getGeometryCreator();
		if(p_mesh.file.compare("!plane")==0)
		{
			p_mesh.mesh = (irr::scene::IAnimatedMesh*)gc->createPlaneMesh( irr::core::dimension2d<irr::f32>(p_mesh.tile_width, p_mesh.tile_height),
											   irr::core::dimension2d<irr::u32>(p_mesh.tile_count_x, p_mesh.tile_count_y),
											   0,
											   irr::core::dimension2d<irr::f32>(p_mesh.tile_txRepeat_x, p_mesh.tile_txRepeat_y) );
		}
		else if(p_mesh.file.compare("!cone")==0)
		{
			p_mesh.mesh = (irr::scene::IAnimatedMesh*)gc->createConeMesh(p_mesh.radius, p_mesh.length, p_mesh.tesselation, p_mesh.cone_top_color, p_mesh.cone_bottom_color);
		}
		else if(p_mesh.file.compare("!cylinder")==0)
		{
			p_mesh.mesh = (irr::scene::IAnimatedMesh*)gc->createCylinderMesh(p_mesh.radius, p_mesh.length, p_mesh.tesselation, p_mesh.cylinder_color, p_mesh.cylinder_top_close);
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
			if(textures[i].id_name.compare(new_name.ToStdString())==0)
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
			if(materials[i].id_name.compare(new_name.ToStdString())==0)
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
			if(materials[i].file.compare(new_name.ToStdString())==0)
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
			if(meshes[i].id_name.compare(new_name.ToStdString())==0)
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
			if(meshes[mesh_index].animation[i].id_name.compare(new_name.ToStdString())==0)
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
			if(anim8or_projects[i].id_name.compare(new_name.ToStdString())==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}


wxString serenity_project::genActorID(int stage_index)
{
	if(stage_index < 0 || stage_index >= stages.size())
		return _("");

	wxString tmp_name = _("actor_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < stages[stage_index].actors.size(); i++)
		{
			if(stages[stage_index].actors[i].id_name.compare(new_name.ToStdString())==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genGroupLabel(int stage_index)
{
	if(stage_index < 0 || stage_index >= stages.size())
		return _("");

	wxString tmp_name = _("Group ");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < stages[stage_index].groups.size(); i++)
		{
			if(stages[stage_index].groups[i].label.compare(new_name.ToStdString())==0)
			{
				name_found = false;
				break;
			}
		}
	}

	return new_name;
}

wxString serenity_project::genStageID()
{
	wxString tmp_name = _("stage_id");
	wxString new_name = _("");

	bool name_found = false;
	int name_n = 0;

	while(!name_found)
	{
		new_name = tmp_name + wxString::Format(_("%d"), name_n);
		name_n++;

		name_found = true;

		for(int i = 0; i < stages.size(); i++)
		{
			if(stages[i].id_name.compare(new_name.ToStdString())==0)
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
				mat_file.Write(_("texture  level=") + wxString::Format(_("%d"), i) + _("  file=\"") + textures[tx_id].file + _("\";"));
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


bool serenity_project::save_material_list(rc_mesh p_mesh)
{
	wxFileName fname = project_path;
	fname.AppendDir(_("data"));

	wxString ml_file = wxString::FromUTF8(p_mesh.id_name) + _(".snmd");
	fname.SetFullName(ml_file);


	wxFile mfile(fname.GetAbsolutePath(), wxFile::write);

	if(!mfile.IsOpened())
	{
		wxMessageBox(_("Error: Could not write to material list"));
		return false;
	}

	for(int i = 0; i < p_mesh.material_index.size(); i++)
	{
		int mat_index = p_mesh.material_index[i];
		wxString material_id = ( (mat_index >= 0 && mat_index < materials.size()) ? wxString::FromUTF8(materials[mat_index].id_name) : _("[NULL]") );

		mfile.Write(_("material=") + (material_id.compare(_(""))==0 ? _("[NULL]") : material_id) + _(";\n"));
	}

	mfile.Close();

	return true;
}

