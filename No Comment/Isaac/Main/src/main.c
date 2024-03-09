#include <kipr/wombat.h>

void servo(int port, float targetangle, float time);

int main()
{
    create3_connect();
    create3_wait();
    create3_drive_straight(0.09, 0.46);
    create3_wait();
    create3_rotate_degrees(45, 141);
    create3_wait();
    /*
    servo(3, 0, 1);
    servo(3, 1400, 2);
    create3_rotate_degrees(-45, 141);
    create3_wait();
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