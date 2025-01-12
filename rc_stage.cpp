#include <vector>
#include <irrlicht.h>

#include "engine_base.h"
#include "rc_stage.h"

void rc_addMaterialType(std::string rc_mat_val, irr::video::E_MATERIAL_TYPE irr_mat_val)
{
	rc_material_keyval_pair mat_obj;
	mat_obj.key = rc_mat_val;
	mat_obj.val = irr_mat_val;

	rc_material_types_list.push_back(mat_obj);
}

void rc_addAntiAliasType(std::string rc_aa_val, irr::video::E_ANTI_ALIASING_MODE irr_aa_val)
{
	rc_anti_alias_keyval_pair aa_obj;
	aa_obj.key = rc_aa_val;
	aa_obj.val = irr_aa_val;

	rc_anti_alias_types_list.push_back(aa_obj);
}

void rc_addBlendModeType(std::string rc_bmode_val, irr::video::E_BLEND_OPERATION irr_bmode_val)
{
	rc_blendmode_keyval_pair bm_obj;
	bm_obj.key = rc_bmode_val;
	bm_obj.val = irr_bmode_val;

	rc_blendmode_types_list.push_back(bm_obj);
}

void rc_addColorMaskType(std::string rc_cmask_val, irr::video::E_COLOR_PLANE irr_cmask_val)
{
	rc_colormask_keyval_pair cmask_obj;
	cmask_obj.key = rc_cmask_val;
	cmask_obj.val = irr_cmask_val;

	rc_colormask_types_list.push_back(cmask_obj);
}

void rc_addColorModeType(std::string rc_cmode_val, irr::video::E_COLOR_MATERIAL irr_cmode_val)
{
	rc_colormode_keyval_pair cmode_obj;
	cmode_obj.key = rc_cmode_val;
	cmode_obj.val = irr_cmode_val;

	rc_colormode_types_list.push_back(cmode_obj);
}

rc_stage::rc_stage()
{
	idIsActive=true;

	sky.left_texture_index = -1;
	sky.right_texture_index = -1;
	sky.top_texture_index = -1;
	sky.bottom_texture_index = -1;
	sky.front_texture_index = -1;
	sky.back_texture_index = -1;
	sky.dome_texture_index = -1;

	sky.hRes = 0;
	sky.vRes = 0;
	sky.dome_radius = 0;
	sky.spherePCT = 0;
	sky.txPCT = 0;

	sky.type = 0;
}

rc_stage::~rc_stage()
{
	idIsActive=false;
	clearStage();
}

void rc_stage::clearActorVector(std::vector<rc_actor>& actor_vector)
{
	for(int i = 0; i < actor_vector.size(); i++)
	{
		if(actor_vector[i].node)
		{
			actor_vector[i].node->remove();
			actor_vector[i].node = NULL;
		}

		if(actor_vector[i].icon_node)
		{
			actor_vector[i].icon_node->remove();
			actor_vector[i].icon_node = NULL;
		}
	}

	//actor_vector.clear();  I only want to remove the actor but leave all the info to reload the actor when needed
}

void rc_stage::clearStage()
{
	clearActorVector(actors);
}
