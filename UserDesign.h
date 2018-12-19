// ######################################################################################
// #                                                                                    #
// #  This module implements the users design                                           #
// #                                                                                    #
// ######################################################################################

#ifndef _USERDESIGN_H
    #define _USERDESIGN_H

    #include "../Main.h"
    extern void StateMachineInit(void);                                                     // This function initializes the state machine
    extern void StateMachineUpdate(void);                                                   // This function updated the state machine

// ######################################################################################
// #  Add a new state for state machine here                                            #
// ######################################################################################
     
     type enum {
	     Init,
	     Drive_Right,
	     Cran_Down_1,
	     Cran_Down_2,
	     Cran_Up_1,
	     Cran_Up_2,
	     Go_Back
     }

     AutomatStates_t;

#endif 