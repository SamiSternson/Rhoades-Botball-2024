#include <kipr/wombat.h>
#include "rhoadesbotball2024.h"
int main()
{  /* INSTRUCTIONS TO RUN THIS ROBOT:
1) Line robot upto orange/green lines. 
2)Make sure every thing is plugged in correctly. Right front analog sensor: port 1, Left Front analog sensor: Port 0
Back Sensor: port 2
Front claw servo: port 1
back up-down servo: port2
back open-close servo:port3
right motor: port 2
left motor: port 1
*/
    // Asigns motor variables
    motor(3, 100);
    motor(0, 100);
    msleep(1000);
    return 0;
}

