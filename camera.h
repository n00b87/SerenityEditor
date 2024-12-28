#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED


#include <irrlicht.h>

#include <iostream>

// use all irrlicht namespaces
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


/*
  ==========
    rotateNode -- rotate a scene node locally
  ==========
*/
void rotateNode(irr::scene::ISceneNode *node, irr::core::vector3df rot);
void translateNode(ISceneNode *node, vector3df vel);

void translateNodeW(ISceneNode *node, vector3df vel);



/* camera framework */
class Camera
{
public:

    irr::scene::ISceneManager* Scene;

  irr::scene::ICameraSceneNode *camera;  // the actual camera
  ISceneNode       *top;     // above camera
  ISceneNode       *front;   // in front of camera

  f32 rx,ry,rz;
  f32 x,y,z;

  vector3df direction;


  // initialize a camera at 0,0,0 or the location passed in
  void init(irr::scene::ISceneManager* smgr, float x=0, float y=0, float z=0);

  void re_init();


  // locally translate the camera
  void translate(float x, float y, float z);
  void translateW(float x, float y, float z);


  // locally rotate the camera
  void rotate(float x, float y, float z);

  // update the camera, should be called at the end of mainloop
  void update(void);

  // sets the global rotation of the camera
  void setRotation(float x, float y, float z);

  // sets the global position of the camera
  void setPosition(float x, float y, float z);

  // gets the global position of camera
  void getPosition(f32 &x, f32 &y, f32 &z);
};


#endif // CAMERA_H_INCLUDED
