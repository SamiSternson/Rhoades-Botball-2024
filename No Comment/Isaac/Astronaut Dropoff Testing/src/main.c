#include <kipr/wombat.h>

int main()
{
    //7.5 | 1.5
    //int test = 1;
    
    create3_connect();
    
    //while (test == 1) {printf("%d\n", digital(1)); msleep(1000);}
    while (digital(1) == 0) {create3_velocity_set_components(0.1, 0);} //Astronaut Flag Station
    create3_rotate_degrees(-90, 90);
    create3_wait();
    create3_drive_straight(-0.016, 0.46);
    create3_wait();
    create3_rotate_degrees(90, 90);
    create3_wait();
    create3_drive_straight(-0.25, 0.46);
    create3_wait();
    //weeble_wooble(Servo incorporated)
    return 0;
}
