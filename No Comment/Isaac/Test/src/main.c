#include <kipr/wombat.h>
//#include <kipr/console/console.hpp>

int main()
{
    int active = 1;
    create3_connect();
    
    while (active == 1) {
        // BUMP SENSORS
        int bumpsensorfarleft = create3_sensor_bump(0);
        int bumpsensorleft = create3_sensor_bump(1);
    	int bumpsensorcenter = create3_sensor_bump(2);
        int bumpsensorright = create3_sensor_bump(3);
        int bumpsensorfarright = create3_sensor_bump(4);
        // IR SENSORS
        int irsensorfarleft = create3_sensor_ir(0);
        int irsensorleft = create3_sensor_ir(1);
        int irsensorslightleft = create3_sensor_ir(2);
        int irsensorcenter = create3_sensor_ir(3);
        int irsensorslightright = create3_sensor_ir(4);
        int irsensorright = create3_sensor_ir(5);
        int irsensorfarright = create3_sensor_ir(6);
        
        printf("Bumper Sensors | IR Sensors\n\n");
        printf("               | Far Left: %d\n", irsensorfarleft);
        printf("Far Left: %d    | Left: %d\n", bumpsensorfarleft, irsensorleft);
        printf("Left: %d        | Slight Left: %d\n", bumpsensorleft, irsensorslightleft);
        printf("Center: %d      | Center: %d\n", bumpsensorcenter, irsensorcenter);
        printf("Right: %d       | Slight Right: %d\n", bumpsensorright, irsensorslightright);
        printf("Far Right: %d   | Right: %d\n", bumpsensorfarright, irsensorright);
        printf("               | Far Right: %d\n", irsensorfarright);
        msleep(500);
        console_clear();
    }
    /*
    ---Velocity---
    int repeat = 0;
    
    create3_connect();
    
    while (repeat <= 100) {
		create3_velocity_set_components(0.1, 0);
        repeat++;
    }
    */
    return 0;
}
