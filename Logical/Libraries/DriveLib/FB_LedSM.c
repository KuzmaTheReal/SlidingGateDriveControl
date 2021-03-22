
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* This function block implements state switching to control indicators */
void FB_LedSM(struct FB_LedSM* inst)
{
	switch(inst->state)
	{
		case ST_INIT:
			{
				break;
			}
		case ST_UNKNOWN:
			{
				if(inst->timer%10 == 9)
				{
					inst->led0 = !inst->led0;
					inst->led1 = !inst->led1;
					inst->led2 = !inst->led2;
					inst->led3 = !inst->led3;
				}
				break;
			}
		case ST_OPEN:
			{
				inst->led0 = 0;
				inst->led1 = 0;
				inst->led2 = 0;
				inst->led3 = 0;
				break;
			}
		case ST_CLOSE:
			{
				inst->led0 = 1;
				inst->led1 = 1;
				inst->led2 = 1;
				inst->led3 = 1;
				break;
			}
		case ST_ACC_POS:
			{
				if(inst->timer%10 == 4) inst->led0 = 1;
				inst->led1 = 0;
				inst->led2 = 0;
				inst->led3 = 0;
				break;
			}
		case ST_ACC_NEG:
			{
				inst->led0 = 1;
				inst->led1 = 1;
				inst->led2 = 1;
				if(inst->timer%10 == 4) inst->led3 = 0;
				break;
			}
		case ST_POS:
			{
				inst->led0 = 1;
				if(inst->timer%10 == 9) inst->led1 = 1;
				inst->led2 = 0;
				inst->led3 = 0;
				break;
			}
		case ST_NEG:
			{
				inst->led0 = 1;
				inst->led1 = 1;
				if(inst->timer%10 == 9) inst->led2 = 0;
				inst->led3 = 0;
				break;
			}
		case ST_DEC_POS:
			{
				inst->led0 = 1;
				inst->led1 = 1;
				if(inst->timer%10 == 4) inst->led2 = 1;
				inst->led3 = 0;
				break;
			}
		case ST_DEC_NEG:
			{
				inst->led0 = 1;
				if(inst->timer%10 == 4) inst->led1 = 0;
				inst->led2 = 0;
				inst->led3 = 0;
				break;
			}
	}
}
