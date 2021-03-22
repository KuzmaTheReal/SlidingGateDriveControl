
FUNCTION_BLOCK FB_DriveSM (*This function block implements state switching for motor control*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT; (*Frequency converter status*)
		enable : BOOL; (*Function block operation signal*)
	END_VAR
	VAR_OUTPUT
		command : UINT; (*Frequency converter command*)
		speed : INT; (*Set speed*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_LedSM (*This function block implements state switching to control indicators*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT; (*Gate condition*)
		led0 : BOOL; (*Function block operation signal*)
		led1 : BOOL; (*Function block operation signal*)
		led2 : BOOL; (*Function block operation signal*)
		led3 : BOOL; (*Function block operation signal*)
	END_VAR
	VAR_OUTPUT
		timer : INT; (*Set speed*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_DoorSM (*This function block implements state switching for door control*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT; (*Gate condition*)
		sw0 : BOOL; (*Limit switch signal 1*)
		sw1 : BOOL; (*Limit switch signal 2*)
		sw2 : BOOL; (*Limit switch signal 3*)
		sw3 : BOOL; (*Limit switch signal 4*)
		direction : BOOL; (*Frequency converter command*)
	END_VAR
	VAR_OUTPUT
		speed : INT; (*Set speed*)
	END_VAR
END_FUNCTION_BLOCK
