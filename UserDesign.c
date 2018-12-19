// ######################################################################################
// #                                                                                    #
// #  This module implements the users design                                           #
// #                                                                                    #
// ######################################################################################

#include <util/delay.h>
#include "UserDesign.h"

AutomatStates_t State;


// ######################################################################################
// #  This function initializes the finite state machine with start state               #
// ######################################################################################
void StateMachineInit(void)
{
    State = Init;
}

// ######################################################################################
// #  This function updates the current state of the finite state machine               #
// ######################################################################################
void StateMachineUpdate(void)
{
    switch (State)
     {
         case Init:
         {
             Actuators.XAxisDriveToXPlus     = 0;
             Actuators.XAxisDriveToXMinus    = 0;
             Actuators.YAxisDriveToYPlus     = 0;
             Actuators.YAxisDriveToYMinus    = 0;
             Actuators.ZAxisDriveToZPlus     = 0;
             Actuators.ZAxisDriveToZMinus    = 0;
             Actuators.Magnet                = 0;
             
             if (!Sensors.XAxisAtPositionXMinus)
                State = DriveXMinus;
             else if(Sensors.XAxisAtPositionXMinus)
                State = DriveXPlus;
             
             break;
         }
         
         case DriveXMinus:
         {
             Actuators.XAxisDriveToXPlus     = 0;
             Actuators.XAxisDriveToXMinus    = Sensors.UserSwitch;
             Actuators.YAxisDriveToYPlus     = 0;
             Actuators.YAxisDriveToYMinus    = 0;
             Actuators.ZAxisDriveToZPlus     = 0;
             Actuators.ZAxisDriveToZMinus    = 0;
             Actuators.Magnet                = 0;
             
             if (Sensors.XAxisAtPositionXMinus)
                State = DriveXPlus;
             else if(!Sensors.XAxisAtPositionXMinus)
                 State = DriveXMinus;
             
             break;
         }
         
         case DriveXPlus:
         {
             Actuators.XAxisDriveToXPlus     = Sensors.UserSwitch;
             Actuators.XAxisDriveToXMinus    = 0;
             Actuators.YAxisDriveToYPlus     = 0;
             Actuators.YAxisDriveToYMinus    = 0;
             Actuators.ZAxisDriveToZPlus     = 0;
             Actuators.ZAxisDriveToZMinus    = 0;
             Actuators.Magnet                = 0;
             
             if (!Sensors.XAxisAtPositionXPlus)
                State = DriveXMinus;
             else if(!Sensors.XAxisAtPositionXPlus)
                State = DriveXPlus;
             
             break;
         }
     }
}