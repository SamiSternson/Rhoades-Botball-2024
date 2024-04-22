#include <kipr/wombat.h>

void servo(int port, float targetangle, float time);

int main()
{
    create3_connect();
    create3_wait();
    msleep(15000);
    create3_drive_straight(0.054 ,0.46);
    create3_wait();
    servo(0, 200, 2);
    msleep(1000);
    servo(0, 1800, 2);
    create3_drive_straight(1.05, 0.46);
    create3_wait();
    create3_drive_straight(-0.025, 0.46);
    create3_wait();
    create3_rotate_degrees(-90, 162);
    create3_wait();
	create3_drive_straight(0.0975, 0.46);
    create3_wait();
    while (create3_sensor_bump(1) == 0 && create3_sensor_bump(2) == 0 && create3_sensor_bump(3) == 0) {create3_velocity_set_components(0.01, 0);}
    create3_execute_next_command_immediately();
    create3_drive_straight(-0.005, 0.46);
    create3_wait();
    create3_rotate_degrees(90, 162);
    create3_wait();
    int state = 0;
    while (state == 0) {
    	int irsense = create3_sensor_ir(6);
        if (irsense > 1000) {state = 1;}
        if (irsense > 1035) {state = 2;}
        if (irsense > 1150) {state = 3;}
        create3_velocity_set_components(0.05, 0);
    }
    create3_execute_next_command_immediately();
    if (state == 1) {
        printf("1");
        create3_drive_straight(-0.0875, 0.46);
        create3_wait();
        create3_rotate_degrees(-9.5, 162);
        create3_wait();
    }
    if (state == 2) {
        printf("2");
        create3_drive_straight(-0.085, 0.46);
        create3_wait();
        create3_rotate_degrees(-9.5, 162);
        create3_wait();
    }
    if (state == 3) {
        printf("3");
        create3_drive_straight(-0.065, 0.46);
        create3_wait();
        create3_rotate_degrees(-8.75, 162);
        create3_wait();
    }
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