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
	sky.node = NULL;
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

	if(sky.node)
		sky.node->remove();

	sky.node = NULL;
}

int rc_stage::addActor(std::string actor_id, int actor_type)
{
	rc_actor p_actor;

	p_actor.id_name = actor_id;
	p_actor.type = actor_type;
	p_actor.group_name = "";
	p_actor.mesh_index = -1; //project index
	p_actor.node = NULL; //cast to object type
	p_actor.icon_node = NULL;
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
	p_actor.use_normal_mod = false;

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
	p_actor.physics.mass = 1;
	p_actor.physics.shape = SN_PHYSICS_SHAPE_BOX;

	int actor_index = actors.size();

	actors.push_back(p_actor);

	return actor_index;
}
