#include <kipr/wombat.h>

void servo(int port, int targetangle);
void oldservo(int port, float targetangle, float time);

int main()
{
    //7.5 | 1.5
    //int test = 1;
    
    create3_connect();
    
    //while (test == 1) {printf("%d\n", digital(1)); msleep(1000);}
    while (digital(1) == 0) {create3_velocity_set_components(0.1, 0);} //Astronaut Flag Station
    create3_execute_next_command_immediately();
    create3_rotate_degrees(-90, 90);
    create3_wait();
    create3_drive_straight(-0.0085, 0.46);
    create3_wait();
    create3_rotate_degrees(90, 90);
    create3_wait();
    create3_drive_straight(-0.2525, 0.46);
    create3_wait();
    servo(3, 300);
    create3_drive_straight(-0.04, 0.10);
    create3_wait();
    servo(3, 1000);
    return 0;
}

void servo(int port, int targetposition) {
	enable_servo(port);
    int Servo = get_servo_position(port);
    while(Servo<targetposition)
    {    
        Servo=Servo+10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    while(Servo>targetposition)
    {
        Servo=Servo-10;
        set_servo_position(3, Servo);
        msleep(10);
    }
    disable_servo(port);
}

void oldservo(int port, float targetangle, float time)
{
    float currentangle = get_servo_position(port);
    float angledistance;
    float repeats;
    int repeated = 0;

    if (currentangle < targetangle) {
        angledistance = targetangle - currentangle;
        repeats = angledistance / 10;
    }
    else if (currentangle > targetangle) {
        angledistance = currentangle - targetangle;
        repeats = angledistance / 10;
    }

    //time = angledistance * time;

    float sleeptime = (time * 1000) / repeats;


    enable_servo(port);
    while (currentangle < targetangle) {
        currentangle = currentangle + 10;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    while (currentangle > targetangle) 
    {
        currentangle = currentangle - 10;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    disable_servo(port);
}