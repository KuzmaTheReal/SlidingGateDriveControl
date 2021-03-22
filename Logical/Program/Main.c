
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	driveSM.enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	FB_DoorSM(&doorSM);
	
	driveSM.speed = doorSM.speed;
	FB_DriveSM(&driveSM);
	
	ledSM.state = doorSM.state;
	FB_LedSM(&ledSM);
	ledSM.timer++;
}

void _EXIT ProgramExit(void)
{
	
}

