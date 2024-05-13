#include <kipr/wombat.h>
void servo(int port, float targetangle, float time);
    
int main()
{
    msleep(100);
    servo(0, 1500, 2);
    servo(0, 5, 2);
    servo(0, 1500, 2);
    motor(0,80);
    motor(2,80);
    msleep(1000);
    motor(0,75);
    motor(2,75);
    msleep(500);
    while(analog(0)<2000)
    {
        motor(0,80);
        motor(2,80);
    }
    printf("line detect");
    double start_time = seconds();
    while(seconds() - start_time < 0.5)
    {
        while(analog(0)>2000)
        {
            motor(0,30);
            motor(2,75);
        }
        while(analog(0)<2000)
        {
            motor(0,75);
            motor(2,30);
        }
    }
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
