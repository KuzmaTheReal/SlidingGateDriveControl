
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* This function block implements state switching for motor control */
void FB_DriveSM(struct FB_DriveSM* inst)
{
	if(inst->enable == 0) inst->command = CMD_SHUTDOWN;
	else
	{
		switch(inst->state & 0x6F)
		{
			case ST_DISABLE:
				inst->command = CMD_SHUTDOWN;
				break;	
			case ST_SWITCHED_ON:
				inst->command = CMD_SWITCH_ON;
				break;
			case ST_READY:
				inst->command = CMD_ENABLE;
				break;
		}
	}	
}
