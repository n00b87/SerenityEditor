#include <vector>
#include <irrlicht.h>

#include "engine_base.h"
#include "rc_stage.h"

rc_stage::rc_stage()
{
	idIsActive=true;
}

rc_stage::~rc_stage()
{
	idIsActive=false;
}
