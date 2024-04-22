#include <kipr/wombat.h>

int main()
{
    
  
    enable_servos();   
    set_servo_position(3, 1000); 
    msleep(20000);
    disable_servos();

    return 0;
}
