#ifndef RC_STAGE_H_INCLUDED
#define RC_STAGE_H_INCLUDED

#include <vector>
#include <irrlicht.h>
#include "an8parser.h"

struct rc_texture
{
	std::string id_name;
	std::string file;
	irr::video::ITexture* texture;
	bool use_colorKey;
	irr::video::SColor colorkey;
};

struct rc_material
{
	std::string id_name;
	std::string file;
	std::vector<int> texture_id; //in project
	irr::video::SMaterial material;
};

struct rc_animation
{
	std::string id_name;
	int start_frame = 0;
	int end_frame = 0;
	float speed = 0;

	irr::scene::EMD2_ANIMATION_TYPE md2_animation;
};

struct rc_an8
{
	std::string id_name;
	std::string file;
	an8::an8_project project;
};

struct rc_mesh
{
	std::string id_name;
	std::string file;
	irr::scene::IAnimatedMesh* mesh;
	std::vector<int> material_index; //in project
	int an8_index; //in project
	std::string an8_scene;
	bool isAN8Scene;
	std::vector<rc_animation> animation;
	bool isZipped;
	std::string zip_file;
	std::string ani_file;
	bool isMD2;

	std::vector<std::string> ref_material_id; //this is only used as a place holder when loading meshes but material_index should be used everywhere else
	std::string ref_an8_id; //same as ref_material_id
};

#define SN_LIGHT_TYPE_POINT			0
#define SN_LIGHT_TYPE_SPOT			1
#define SN_LIGHT_TYPE_DIRECTIONAL	2
#define SN_LIGHT_TYPE_COUNT			3

#define SN_PARTICLE_TYPE_POINT		0
#define SN_PARTICLE_TYPE_BOX		1
#define SN_PARTICLE_TYPE_SPHERE		2
#define SN_PARTICLE_TYPE_CYLINDER	3
#define SN_PARTICLE_TYPE_MESH		4
#define SN_PARTICLE_TYPE_RING		5
#define SN_PARTICLE_TYPE_COUNT		6


#define SN_ACTOR_TYPE_ANIMATED	0
#define SN_ACTOR_TYPE_OCTREE	1
#define SN_ACTOR_TYPE_LIGHT		2
#define SN_ACTOR_TYPE_BILLBOARD	3
#define SN_ACTOR_TYPE_TERRAIN	4
#define SN_ACTOR_TYPE_WATER		5
#define SN_ACTOR_TYPE_PARTICLE	6
#define SN_ACTOR_TYPE_CUBE		7
#define SN_ACTOR_TYPE_SPHERE	8
#define SN_ACTOR_TYPE_PLANE		9

struct rc_actor
{
	std::string id_name;
	int type;
	std::string group_name;
	int mesh_index; //project index
	irr::scene::ISceneNode* node; //cast to object type
	irr::scene::ISceneNode* icon_node; //mainly for a physical representation of lights
	irr::core::vector3df position;
	irr::core::vector3df rotation;
	irr::core::vector3df scale;
	int override_material_index; //if less than 0 then mesh material is used
	int animation_index; //if less than 0 then frame 0 is set
	int num_loops;
	bool visible;
	bool hasShadow;
	bool isCastingShadow; //LIGHTS ONLY
	bool auto_culling;
	double cube_size;
	double radius;
	int texture_index; //in project
	int light_type;
	double angle;
	double falloff;
	double inner_cone;
	double outer_cone;
	irr::core::vector3df attenuation;
	irr::video::SColor ambient;
	irr::video::SColor emissive;
	irr::video::SColor diffuse;
	irr::video::SColor specular;
	std::string terrain_hmap_file;
	double wave_height;
	double wave_length;
	double wave_speed;
	int particle_type;
	irr::scene::IParticleEmitter* particle_emitter;
	irr::core::vector3df normal;
	irr::core::vector3df direction;
	irr::core::aabbox3df box;
	irr::core::vector3df center;

	bool use_every_vertex;
	bool use_normal_direction;
	bool use_normal_mod;

	double cylinder_length;
	bool use_outline_only;

	double ring_thickness;

	double min_width;
	double min_height;

	double max_width;
	double max_height;

	double min_per_sec;
	double max_per_sec;

	irr::video::SColor min_start_color;
	irr::video::SColor max_start_color;

	double min_life;
	double max_life;
};

struct rc_waypoint
{
	irr::core::vector3df position;

};

struct rc_group
{
	std::string label;
};

struct rc_path
{
};

#define SN_SKY_TYPE_NONE	0
#define SN_SKY_TYPE_BOX		1
#define SN_SKY_TYPE_DOME	2


struct rc_sky
{
	int type;

	int dome_texture_index;

	int left_texture_index;
	int right_texture_index;
	int top_texture_index;
	int bottom_texture_index;
	int front_texture_index;
	int back_texture_index;

	irr::u32 hRes;
	irr::u32 vRes;
	double txPCT;
	double spherePCT;
	double dome_radius;
};

struct rc_material_keyval_pair
{
	std::string key;
	irr::video::E_MATERIAL_TYPE val;
};

struct rc_anti_alias_keyval_pair
{
	std::string key;
	irr::video::E_ANTI_ALIASING_MODE val;
};

struct rc_blendmode_keyval_pair
{
	std::string key;
	irr::video::E_BLEND_OPERATION val;
};

struct rc_colormask_keyval_pair
{
	std::string key;
	irr::video::E_COLOR_PLANE val;
};

struct rc_colormode_keyval_pair
{
	std::string key;
	irr::video::E_COLOR_MATERIAL val;
};



std::vector<rc_material_keyval_pair> rc_material_types_list;
std::vector<rc_anti_alias_keyval_pair> rc_anti_alias_types_list;
std::vector<rc_blendmode_keyval_pair> rc_blendmode_types_list;
std::vector<rc_colormask_keyval_pair> rc_colormask_types_list;
std::vector<rc_colormode_keyval_pair> rc_colormode_types_list;

void rc_addMaterialType(std::string rc_mat_val, irr::video::E_MATERIAL_TYPE irr_mat_val);
void rc_addAntiAliasType(std::string rc_aa_val, irr::video::E_ANTI_ALIASING_MODE irr_aa_val);
void rc_addBlendModeType(std::string rc_bmode_val, irr::video::E_BLEND_OPERATION irr_bmode_val);
void rc_addColorMaskType(std::string rc_cmask_val, irr::video::E_COLOR_PLANE irr_cmask_val);
void rc_addColorModeType(std::string rc_cmode_val, irr::video::E_COLOR_MATERIAL irr_cmode_val);

class rc_stage
{
	public:
		std::string id_name;
		std::string file;

		bool wireframe = false; //this will be applied to all actors in the stage

		std::vector<rc_actor> actors;

		std::vector<rc_group> groups;

		rc_sky sky;

		irr::video::ITexture* light_icon;


		bool idIsActive;

		rc_stage();
		~rc_stage();

		void clearStage();

		void clearActorVector(std::vector<rc_actor>& actor_vector);

};


#endif // RC_STAGE_H_INCLUDED
