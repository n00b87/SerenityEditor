#ifndef RC_FX_MATERIALS_H_INCLUDED
#define RC_FX_MATERIALS_H_INCLUDED

#include <irrlicht.h>
//don't forget to include the CShader source
#include "CShader.h"
#include "rc_fx_shaders.h"
#include "rc_stage.h"

#define RC_FX_MATERIAL_BASE_INDEX	128

irr::core::array<rc_shader_material_obj> rc_shader_materials;
core::array<scene::ISceneNode*> scenenodes_for_rtt_view;
video::ITexture* tex_rtt_view = 0;

void registerSceneNodeForRTT(irr::video::IVideoDriver* rtt_driver, irr::scene::ISceneNode* node, S_RTT_Info* rtt_info);
void init_refraction1();
void init_refraction2();
void init_gooch();
void init_style();
void init_normalShade();
void init_outline();
void init_plastic();
void init_tangent();
void init_speaker();
void init_phong();
void init_style2();
void init_style3();
void init_style4();
void initFXMaterials();
int rc_numMaterialConstants(int material_type);
std::string rc_getMaterialConstantName(int material_type, int index);
//void rc_setMaterialConstant(int material_id, std::string m_constant, double n1, double n2, double n3, double n4);
//void rc_getMaterialConstant(int material_id, std::string m_constant, double* n1, double* n2, double* n3, double* n4);
int createShaderMaterial(irr::IrrlichtDevice* s_device, rc_material* base_material, int fx_material_type);


//Set Actor Material Type
//void rc_setActorMaterial(int actor, int material_num, int material_id);

#endif // RC_FX_MATERIALS_H_INCLUDED
