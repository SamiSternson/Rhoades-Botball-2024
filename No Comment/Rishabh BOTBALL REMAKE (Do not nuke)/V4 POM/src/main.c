#include <kipr/wombat.h>
void SSU(int port, int speed, int final);
void SSD(int port, int speed, int final);
void servo(int port, int time, int finalpos);
int main()
{
    int DROP = 0;
    servo(3, 2000, 1070);
    servo(0, 2000, 2047);
    motor(0,70);
    motor(2,0);       // lower claw to scoop the poms
    msleep(500);
    while(digital(1)==0 && digital(2)==0)
    {
        motor(0,20);
        motor(2,20);
        while(digital(1)==0 && digital(2) == 1)
        {
            motor(0,20);
            motor(2,0);
        }
        while(digital(1) == 1 && digital(2) == 0)
        {
            motor(0,0);
            motor(2,20);
        }
    }
    /*motor(0,70);
    motor(2,0);       // lower claw to scoop the poms
    msleep(500);*/
    freeze(0);
    freeze(2);
    while(DROP<10)
    {
        freeze(0);
        freeze(2);
        servo(3, 2000, 1990);
        motor(0,-100);
        motor(2,-100);
        msleep(1500);
        while(digital(1)==0 && digital(2)==0)
        {
            motor(0,20);
            motor(2,20);
            while(digital(1)==0 && digital(2) == 1)
            {
                motor(0,0);
                motor(2,20);
            }
            while(digital(1) == 1 && digital(2) == 0)
            {
                motor(0,20);
                motor(2,0);
            }
        }
        motor(0,0);
        motor(2,20);
        msleep(50);
        DROP = DROP + 1;
    }
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
}
void SSU(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos<final)
    {
        pos+=10;
        set_servo_position(port, pos);
        msleep(20);
    }
    disable_servo(port);
}
void SSD(int port, int speed, int final)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(pos>final)
    {
        pos-=10;
        set_servo_position(port, pos);
        msleep(20);
    }
    disable_servo(port);
}