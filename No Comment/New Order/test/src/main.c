#include <kipr/wombat.h>

void servo(int port, int time, int finalpos);

int main()
{
    int repeat = 0;
    motor(0, -100);
    motor(2, 0);
    msleep(575);
    freeze(0);
    freeze(2);
    motor(0, 10);
    motor(2, 10);
    msleep(100);
    freeze(0);
    freeze(2);
    servo(3, 1500, 1500);
    servo(3, 1500, 400);
    servo(3, 1500, 1500);
    while (repeat < 5){
        msleep(100);
        servo(3, 1500, 400);
        servo(3, 750, 2000);
        repeat++;
    }
    servo(3, 1500, 400);

    return 0;
}

void servo(int port, int time, int finalpos)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    int round = 0;
    int time2drop = 0;
    if(pos<finalpos)
    {
        round = finalpos-pos;
        time2drop = time/round;
        while(pos<finalpos)
        {
            set_servo_position(port, pos);
            msleep(time2drop);
            pos = pos + 1;
        }
    }
    if(pos>finalpos)
    {
        round = pos - finalpos;
        time2drop = time/round;
        while(pos>finalpos)
        {
            set_servo_position(port, pos);
            msleep(time2drop);
            pos=pos-1;
        }
    }
    disable_servo(port);
}