#include <irrlicht.h>

#include <iostream>

#include "camera.h"

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
void rotateNode(irr::scene::ISceneNode *node, irr::core::vector3df rot)
{
    irr::core::matrix4 m;
    m.setRotationDegrees(node->getRotation());
    irr::core::matrix4 n;
    n.setRotationDegrees(rot);
    m *= n;
    node->setRotation( m.getRotationDegrees() );
    node->updateAbsolutePosition();
}


/*
  ==========
    translateNode -- translate a scene node locally
  ==========
*/
void translateNode(ISceneNode *node, vector3df vel)
{
    irr::core::matrix4 m;
    m.setRotationDegrees(node->getRotation());
    m.transformVect(vel);
    node->setPosition(node->getPosition() + vel);
    node->updateAbsolutePosition();
}

void translateNodeW(ISceneNode *node, vector3df vel)
{
    node->setPosition(node->getPosition() + vel);
    node->updateAbsolutePosition();
}





  // initialize a camera at 0,0,0 or the location passed in
  void Camera::init(irr::scene::ISceneManager* smgr, float x, float y, float z)
  {
    Scene = smgr;

	// create camera scene node
    camera = Scene->addCameraSceneNode(NULL, vector3df(x,y,z));

    // empty reference nodes
    top   = Scene->addEmptySceneNode();
    front = Scene->addEmptySceneNode();

    // parent the reference nodes
    camera->addChild(top);
    camera->addChild(front);

    // put the reference nodes in place
    front->setPosition(vector3df(0,0,1));
    top->setPosition(vector3df(0,1,0));

    // set lookat
    camera->setUpVector(top->getAbsolutePosition() - camera->getAbsolutePosition());
    camera->setTarget(front->getAbsolutePosition() - camera->getAbsolutePosition());

    direction = vector3df(0,0,1);

    //camera = Scene->addCameraSceneNodeFPS();

    rx=ry=rz=0;
    x=y=z=0;
  }


    // initialize a camera at 0,0,0 or the location passed in
  void Camera::re_init()
  {

    //Scene = smgr;

	// create camera scene node
    //camera = Scene->addCameraSceneNode(NULL, vector3df(x,y,z));

    // empty reference nodes
    //top   = Scene->addEmptySceneNode();
    //front = Scene->addEmptySceneNode();

    // parent the reference nodes
    //camera->addChild(top);
    //camera->addChild(front);

    // put the reference nodes in place
    front->setPosition(vector3df(0,0,1));
    top->setPosition(vector3df(0,1,0));

    // set lookat
    camera->setUpVector(top->getAbsolutePosition() - camera->getAbsolutePosition());
    camera->setTarget(front->getAbsolutePosition() - camera->getAbsolutePosition());

    direction = vector3df(0,0,1);

    //camera = Scene->addCameraSceneNodeFPS();

    rx=ry=rz=0;
    x=y=z=0;
  }

  // locally translate the camera
  void Camera::translate(float x, float y, float z)
  {
	// translate the camera locally
	translateNode(camera, vector3df(x,y,z));

	// update reference nodes
	front->updateAbsolutePosition();
	top->updateAbsolutePosition();
  }

  // locally translate the camera
  void Camera::translateW(float x, float y, float z)
  {
	// translate the camera locally
	translateNodeW(camera, vector3df(x,y,z));

	// update reference nodes
	front->updateAbsolutePosition();
	top->updateAbsolutePosition();
  }

  // locally rotate the camera
  void Camera::rotate(float x, float y, float z)
  {
    rotateNode(camera, vector3df(x, y, z));

    rx += x;
    ry += y;
    rz += z;
  }

  // update the camera, should be called at the end of mainloop
  void Camera::update(void)
  {
    camera->updateAbsolutePosition();

    camera->setTarget(front->getAbsolutePosition());
    camera->setUpVector(top->getAbsolutePosition() - camera->getAbsolutePosition());

    vector3df pos;
    pos = camera->getAbsolutePosition();
    x=pos.X;
    y=pos.Y;
    z=pos.Z;

    pos = camera->getRotation();

    //rx=pos.X;
    //ry=pos.Y;
    //rz=pos.Z;
  }

  // sets the global rotation of the camera
  void Camera::setRotation(float x, float y, float z)
  {
    camera->setRotation(vector3df(x,y,z));
    camera->updateAbsolutePosition();

    front->updateAbsolutePosition();
	top->updateAbsolutePosition();

    this->rx=x;
    this->ry=y;
    this->rz=z;
  }

  // sets the global position of the camera
  void Camera::setPosition(float x, float y, float z)
  {
    camera->setPosition(vector3df(x,y,z));
    camera->updateAbsolutePosition();

    this->x = x;
    this->y = y;
    this->z = z;

	front->updateAbsolutePosition();
	top->updateAbsolutePosition();
  }

  // gets the global position of camera
  void Camera::getPosition(f32 &x, f32 &y, f32 &z)
  {
    vector3df pos;
    pos = camera->getAbsolutePosition();

    x=pos.X;
    y=pos.Y;
    z=pos.Z;
  }

