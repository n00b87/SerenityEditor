#include <wx/wx.h>
#include <wx/filename.h>
#include <vector>
#include "rc_stage.h"
#include "engine_base.h"

serenity_project::serenity_project(std::string project_file)
{
	project_path = wxFileName(project_file.c_str());

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

	for(int i = 0; i < p_data.length(); i++)
	{
		if(p_data.substr(i, 1).compare(_(";"))==0)
		{
			//do something with parameters
			if(dict[0].key.compare(_("Stage"))==0)
				load_stage(dict);

			//clear parameters
			dict_obj.key = _("");
			dict_obj.val = _("");
			dict.clear();
			continue;
		}

		if(p_data.substr(i, 1).compare(_(" "))==0)
		{
			if(dict_obj.key.compare(_(""))!=0)
				dict.push_back(dict_obj);
			dict_obj.key = _("");
			dict_obj.val = _("");
			isKey = true;
		}
		else if(p_data.substr(i, 1).compare(_("="))==0)
		{
			isKey = false;
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

int serenity_project::load_stage(std::vector<serenity_project_dict_obj> stage_param)
{
	if(stage_param.size() < 3)
		return -1;

	wxString id_name = _("");
	wxFileName fname = project_path;
	fname.SetFullName(_(""));

	fname.AppendDir(_("stages"));

	for(int i = 0; i < stage_param.size(); i++)
	{
		if(stage_param[i].key.compare(_("file"))==0)
		{
			fname.SetFullName(stage_param[i].val);
		}
	}

	wxMessageBox(_("Stage Path:") + fname.GetAbsolutePath());

	return 0;
}

void serenity_project::save_stage(int stage_id)
{
}

void serenity_project::remove_stage(int stage_id)
{
}

void serenity_project::setGridSize(float g_size)
{
}

void serenity_project::setGridSpacing(float g_spacing)
{
}

void serenity_project::setGridVisible(bool flag)
{
}
