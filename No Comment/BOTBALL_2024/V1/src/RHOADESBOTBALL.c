#include <kipr/wombat.h>
#include "RHOADESBOTBALL.h"
void SLOW_SERVO(int port, int speed, int final)
{
    enable_servos();
    int pos=get_servo_position(port);
    if (pos>final)
    {
        while(pos>final)
        {
            set_servo_position(port, pos-speed);
            msleep(50);
            pos=get_servo_position(port);
        }
    }
    else
    {
        while(pos<final)
        {
            set_servo_position(port, pos+speed);
            msleep(50);
            pos=get_servo_position(port);
        }
    }
    set_servo_position(port, final);
    disable_servos();

}