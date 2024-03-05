#include <kipr/wombat.h>

void servo(int port, float targetangle, float time);

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
    servo(3, 1000, 2);
    /*
    int repeat = 0;
    while (repeat < 5){
    	servo(3, 200, 1.5);
        servo(3, 1000, 2);
        repeat++;
    }
    */
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