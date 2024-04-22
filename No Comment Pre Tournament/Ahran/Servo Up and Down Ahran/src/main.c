#include <kipr/wombat.h>

int main()
{
    enable_servos();
    set_servo_position(3,1900);
    msleep(2000);
    return 0;
}
