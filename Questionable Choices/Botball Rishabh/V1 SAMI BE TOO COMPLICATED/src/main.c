#include <kipr/wombat.h>

int main()
{
    //up 1 up: 248 down:1565 open 0 close:2047 open:1556
    int SERVOUP = get_servo_position(1);
    int SERVOOPEN = get_servo_position(0);
    enable_servos();
    while(SERVOUP<1565)
    {
        SERVOUP = SERVOUP+10;
        set_servo_position(1,SERVOUP);
        msleep(10);
    }
    while(SERVOOPEN<2047)
    {
        SERVOOPEN = SERVOOPEN+10;
        set_servo_position(0,SERVOOPEN);
        msleep(10);
    }
    return 0;
}
