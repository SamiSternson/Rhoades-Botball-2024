#include <kipr/wombat.h>

void servo(int port, float targetangle, float time);

int main()
{
    create3_connect();
    create3_wait();
    create3_drive_straight(0.054 ,0.46);
    create3_wait();
    servo(0, 200, 2);
    msleep(1000);
    servo(0, 1800, 2);
    create3_drive_straight(0.475, 0.46);
    create3_wait();
    create3_rotate_degrees(-90, 162);
    create3_wait();
    create3_drive_straight(0.07, 0.46);
    create3_wait();
    create3_rotate_degrees(110, 162);
	create3_wait();
    create3_drive_straight(0.30, 0.46);
    create3_wait();
    create3_rotate_degrees(-80, 162);
    create3_wait();
    while (create3_sensor_bump(4) == 0) {create3_velocity_set_components(0.1, 0);}
    create3_execute_next_command_immediately();
    create3_drive_straight(-0.03, 0.46);
    create3_wait();
    create3_rotate_degrees(60, 162);
    create3_wait();
    create3_drive_straight(0.1, 0.46);
    create3_wait();
    create3_rotate_degrees(-90, 162);
    create3_wait();
    create3_drive_straight(0.035, 0.46);
    create3_wait();
    create3_rotate_degrees(90, 162);
    create3_wait();
    int repeat = 1;
    while (repeat == 1) {
    	int irsense = create3_sensor_ir(6);
        if (irsense > 1000) {repeat = 0;}
        create3_velocity_set_components(0.05, 0);
        msleep(10);
    }
    create3_execute_next_command_immediately();
    create3_drive_straight(-0.07, 0.46);
    create3_wait();
    create3_rotate_degrees(-8.5, 162);
    create3_wait();
    servo(0, 200, 2);
    servo(0, 1800, 2);
    create3_wait();
    return 0;
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

    float sleeptime = (time * 1000) / repeats;


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