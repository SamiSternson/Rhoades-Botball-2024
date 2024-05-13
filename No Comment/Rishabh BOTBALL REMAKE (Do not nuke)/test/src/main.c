#include <kipr/wombat.h>
void servo(int port, int time, int finalpos);
int main()
{
    servo(3, 2000, 1070);
    servo(0, 2000, 2047);
    motor(2,70);
    motor(0,0);       // lower claw to scoop the poms
    msleep(300);
    while(digital(1)==0 || digital(2)==0)
    {
        motor(0,40);
        motor(2,40);
        while(digital(1)==0 && digital(2) == 1)
        {
            motor(2,0);
            motor(0,20);
        }
        while(digital(1) == 1 && digital(2) == 0)            // locilize with the pom pvc
        {
            motor(2,20);
            motor(0,0);
        }
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
    disable_servo(port);
}