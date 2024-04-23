#include <kipr/wombat.h>

int main()
{
    enable_servos();
    set_servo_position(0, 1200);
    motor(0, 75);
    motor(2, 75);
    msleep(300);
    
    return 0;
}
