

#include <util/delay.h>
#include "UserDesign.h"

AutomatStates_t State;


void StateMachineInit(void)
{
    State = Init;
}

switch (State)
    {        case Z0_WaitForFallingEdge:                                                        // Z0        {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 0;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 0;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
          Actuators.Magnet                = 0;
                        if(!Sensors.UserSwitch && !Sensors.XAxisAtPositionXMinus && !Sensors.YAxisAtPositionYMinus)
                State = Z1_DriveXMinusYMinus;
            else if(!Sensors.UserSwitch && !Sensors.XAxisAtPositionXMinus && Sensors.YAxisAtPositionYMinus)
                State = Z2_DriveXMinus;
            else if(!Sensors.UserSwitch && Sensors.XAxisAtPositionXMinus && !Sensors.YAxisAtPositionYMinus)
                State = Z3_DriveYMinus;
            else if(!Sensors.UserSwitch && Sensors.XAxisAtPositionXMinus && Sensors.YAxisAtPositionYMinus)
                State = Z4_DriveYPlus;
 break;                        case Z1_DriveXMinusYMinus:                                                        // Z1        {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 1;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 1;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                        if (!Sensors.XAxisAtPositionXMinus && Sensors.YAxisAtPositionYMinus)
                State = Z2_DriveXMinus;
            else if (Sensors.XAxisAtPositionXMinus && !Sensors.YAxisAtPositionYMinus)
                State = Z3_DriveYMinus;
            else if (Sensors.XAxisAtPositionXMinus && Sensors.YAxisAtPositionYMinus)
                State = Z4_DriveYPlus;        
            break;        }
                case Z2_DriveXMinus:                                                               // Z2        {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 1;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 0;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                        if (Sensors.XAxisAtPositionXMinus)
                State = Z4_DriveYPlus;
        break;        }       {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 0;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 1;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                        if (Sensors.YAxisAtPositionYMinus)
                State = Z4_DriveYPlus;
                       break;        }                case Z4_DriveYPlus:                                                                // Z4        {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 0;
            Actuators.YAxisDriveToYPlus     = 1;
            Actuators.YAxisDriveToYMinus    = 0;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                        if (Sensors.YAxisAtPositionYPlus)
                State = Z5_DriveXPlus;
             break;        }        case Z5_DriveXPlus:                                                                // Z5        {            Actuators.XAxisDriveToXPlus     = 1;
            Actuators.XAxisDriveToXMinus    = 0;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 0;
            Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                        if (Sensors.XAxisAtPositionXPlus && Sensors.UserSwitch)
                State = Z0_WaitForFallingEdge;
            else if(Sensors.XAxisAtPositionXPlus && !Sensors.UserSwitch)
                State = Z6_WaitForUserSwich;
            //else
            //    State = Z5_DriveXPlus;
                        break;        }
        case Z6_WaitForUserSwich:                                                          // Z6        {            Actuators.XAxisDriveToXPlus     = 0;
            Actuators.XAxisDriveToXMinus    = 0;
            Actuators.YAxisDriveToYPlus     = 0;
            Actuators.YAxisDriveToYMinus    = 0;
                  Actuators.ZAxisDriveToZPlus     = 0;
            Actuators.ZAxisDriveToZMinus    = 0;
            Actuators.Magnet                = 0;
                  if (Sensors.UserSwitch)
                State = Z0_WaitForFallingEdge;                   break;        } 

}