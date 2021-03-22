
TYPE
	ER_State : 
		( (*Motor states*)
		ST_READY := 33, (*Ready to work*)
		ST_DISABLE := 64, (*Disable*)
		ST_SWITCHED_ON := 35 (*Switching states*)
		);
	ER_DoorState : 
		( (*Door states*)
		ST_INIT, (*Initialization of parameters and waiting for switching on of the frequency converter*)
		ST_UNKNOWN, (*Gate in an unknown position*)
		ST_OPEN, (*The gate is open*)
		ST_CLOSE, (*The gate is close*)
		ST_ACC_POS, (*Gate acceleration towards opening*)
		ST_ACC_NEG, (*Gate acceleration towards closing*)
		ST_POS, (*Movement towards opening*)
		ST_NEG, (*Movement towards closing*)
		ST_DEC_POS, (*Slowdown of the gate towards the opening*)
		ST_DEC_NEG (*Slowdown of the gate towards the closing*)
		);
	ER_Command : 
		( (*Motor commands*)
		CMD_SWITCH_ON := 7, (*Switching motor*)
		CMD_ENABLE := 15, (*Turning on the motor*)
		CMD_SHUTDOWN := 6, (*Motor shutdown*)
		CMD_DISABLE := 0 (*Motor disable*)
		);
END_TYPE
