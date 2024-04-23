#include <kipr/wombat.h>

void servo(int port, float targetangle, float time);

int main()
{
    int black = 2500;
    msleep(100);
    servo(0, 5, 2);
    msleep(500);
    servo(0, 1500, 2);
    motor(0, 100);
    motor(2, 100);
    msleep(750);
    while (analog(0) < black){msleep(1);}
    freeze(0);
    freeze(2);
    msleep(100);
    motor(0, -100);
    motor(2, -100);
    msleep(500);
    motor(0, 100);
    motor(2, 25);
    msleep(500);
    motor(2, 100);
    msleep(500);
    motor(0, 25);
    //500 normal
    msleep(1500);
    servo(0, 300, 1.5);
    motor(0, 100);
    msleep(750);
    motor(2, 25);
    msleep(1250);
    motor(2, 100);
    msleep(250);
    motor(0, 25);
    msleep(250);
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