#ifndef RC_STAGE_H_INCLUDED
#define RC_STAGE_H_INCLUDED

#include <vector>
#include <irrlicht.h>

struct rc_texture
{
	std::string file;
	irr::video::ITexture* texture;
};

struct rc_material
{
	std::string id_name;
	std::string file;
	std::vector<rc_texture> texture;
	irr::video::SMaterial material;
};

struct rc_animation
{
	std::string name;
	int start_frame = 0;
	int end_frame = 0;
	float speed = 0;
};

struct rc_mesh
{
	std::string file;
	irr::scene::IAnimatedMesh* mesh;
	std::vector<int> material_index;
	std::vector<rc_animation> animation;
};

struct rc_object
{
	std::string name;
	rc_mesh mesh;
	irr::scene::ISceneNode* node; //cast to object type
	irr::core::vector3df position;
	irr::core::vector3df rotation;
	irr::core::vector3df scale;
};

struct rc_waypoint
{
	irr::core::vector3df position;

};

struct rc_path
{
};

class rc_stage
{
	public:
		std::vector<int> material;
		std::vector<int> texture;
		std::vector<int> mesh;

		bool idIsActive;

		rc_stage();
		~rc_stage();


};


#endif // RC_STAGE_H_INCLUDED
