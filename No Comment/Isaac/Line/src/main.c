#include <kipr/wombat.h>

void weeblewobble();
void servo(int port, float targetangle, float time);

int main()
{
    //Main Servo Limit 1800
    //SETUP: 45 degree rotation left from robot facing toward large space opening, 8 in. from back table corner (underneath)
    //1550 O 750 C box servo
    create3_connect();
    create3_wait();
    create3_rotate_degrees(-45, 90);
    create3_wait();
    create3_drive_straight(0.645, 0.46);
    create3_wait();
    create3_rotate_degrees(-45, 45);
    create3_wait();
    create3_drive_straight(-0.09, 0.46);
    create3_wait();
    servo(2, 300, 3);
    msleep(1000);
    create3_drive_straight(0.035, 0.05);
    create3_wait();
    weeblewobble();
    create3_rotate_degrees(40, 45);
    servo(2, 600, 1);
    create3_drive_straight(0.15, 0.15);
    create3_wait();
    create3_rotate_degrees(-15, 45);
    create3_wait();
    while (create3_sensor_bump(4) != 1) {
    	create3_velocity_set_components(0.1, 0);
    }
    create3_execute_next_command_immediately();
    create3_rotate_degrees(20, 45);
    create3_wait();
    while (create3_sensor_bump(2) != 1) {
    	create3_velocity_set_components(0.1, 0);
    }
    create3_execute_next_command_immediately();
    create3_wait();
    /*
	servo(2, 800, 1);
    create3_rotate_degrees(30, 45);
    create3_wait();
    create3_drive_straight(0.55, 0.46);
    create3_wait();
    create3_rotate_degrees(15, 45);
    create3_wait();
    */
    /*
    ---PLACEMENT CODE (IMPROPER MEASUREMENTS)---
    create3_drive_straight(1, 0.46);
    create3_wait();
    //Drive up to edge of pipe area (Distance Not Measured)
    */

    /*
    ---SUDO CODE (NOT REAL CODE)---
    -Use servos to dump pipes in tubes; Requires bottom mechanism
    */
    return 0;
}

void weeblewobble(){
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151); 
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);
    create3_rotate_degrees(1,151);
    create3_rotate_degrees(-1,151);

    create3_wait();
}

void servo(int port, float targetangle, float time)
{
    float currentangle = get_servo_position(port);
    float angledistance;
    float repeats;
    int repeated = 0;

    if (currentangle < targetangle) {
        angledistance = targetangle - currentangle;
        repeats = angledistance / 1;
    }
    else if (currentangle > targetangle) {
        angledistance = currentangle - targetangle;
        repeats = angledistance / 1;
    }

    //time = angledistance * time;

    float sleeptime = (time / repeats);


    enable_servo(port);
    while (currentangle < targetangle) {
        currentangle = currentangle + 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    while (currentangle > targetangle) 
    {
        currentangle = currentangle - 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    disable_servo(port);
}