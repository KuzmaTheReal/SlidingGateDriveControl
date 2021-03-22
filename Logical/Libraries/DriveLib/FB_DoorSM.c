
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* This function block implements state switching for door control */
void FB_DoorSM(struct FB_DoorSM* inst)
{
	switch(inst->state)
	{
		case ST_INIT:
			{
				if(inst->sw0 == 0 && inst->sw1 == 0 && inst->sw2 == 0 && inst->sw3 == 0) inst->state = ST_UNKNOWN;
				break;
			}
		case ST_UNKNOWN:
			{
				if(inst->direction == 0 && inst->sw0 == 1) inst->state = ST_OPEN;
				if(inst->direction == 1 && inst->sw3 == 1) inst->state = ST_CLOSE;
				break;
			}
		case ST_OPEN:
			{
				inst->speed = 0;
				if(inst->direction == 0) inst->state = ST_ACC_POS;
				break;
			}
		case ST_CLOSE:
			{
				inst->speed = 0;
				if(inst->direction == 1) inst->state = ST_ACC_NEG;
				break;
			}
		case ST_ACC_POS:
			{
				inst->speed = 200;
				if(inst->sw1 == 1) inst->state = ST_POS;
				if(inst->direction == 1) inst->state = ST_DEC_NEG;
				break;
			}
		case ST_ACC_NEG:
			{
				inst->speed = -200;
				if(inst->sw2 == 1) inst->state = ST_NEG;
				if(inst->direction == 0) inst->state = ST_DEC_POS;
				break;
			}
		case ST_POS:
			{
				inst->speed = 400;
				if(inst->sw2 == 1) inst->state = ST_DEC_POS;
				if(inst->direction == 1) inst->state = ST_NEG;
				break;
			}
		case ST_NEG:
			{
				inst->speed = -400;
				if(inst->sw1 == 1) inst->state = ST_DEC_NEG;
				if(inst->direction == 0) inst->state = ST_POS;
				break;
			}
		case ST_DEC_POS:
			{
				inst->speed = 100;
				if(inst->sw3 == 1) inst->state = ST_CLOSE;
				break;
			}
		case ST_DEC_NEG:
			{
				inst->speed = -100;
				if(inst->sw0 == 1) inst->state = ST_OPEN;
				break;
			}
	}
}
