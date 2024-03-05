#include <kipr/wombat.h>

int main()
{
    enable_servos();
    motor(1,0);
    motor(2,90);
    msleep(1500);
    //Left:1 R:0
    while((analog(1)<300)||(analog(0)<300))
    {
        if((analog(1)<300)&&(analog(0)>300))
        {
            motor(1,90);
            motor(2,45);
        }
        else if((analog(1)>300)&&(analog(0)<300))
        {
            motor(1,45);
            motor(2,90);
        }
        else
        {
            motor(1,90);
            motor(2,90);
        }
    }
    motor(1,-90);
    motor(2,0);
    msleep(500);
    set_servo_position(2,1550);
    motor(1,90);
    motor(2,45);
    msleep(200);
    disable_servos();
    return 0;
}
