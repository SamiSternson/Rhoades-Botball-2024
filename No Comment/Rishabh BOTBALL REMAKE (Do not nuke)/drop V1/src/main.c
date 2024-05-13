#include <kipr/wombat.h>
void servo(int port, float targetangle, float time);
int main()
{
    motor(0,-20);
    motor(2,-20);
    msleep(500);
    freeze(0);
    freeze(2);
    servo(0, 2047, 3);
    motor(0,0);
    motor(2,20);
    msleep(500);
    servo(0, 1700, 3);
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