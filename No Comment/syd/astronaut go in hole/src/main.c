#include <kipr/wombat.h>

int main()
{
int STEP=300;
motor(2,-30);
motor(0,-10);
msleep(500);
    ao();
    
   enable_servos();
    while(STEP < 1000)
    {
        set_servo_position(0,STEP);
        msleep(50);
        STEP=STEP+10;
    }
    disable_servos();
    
    motor(0,0);
    motor(2,30);
    msleep(300);
        return 0;
}
