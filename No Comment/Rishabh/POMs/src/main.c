#include <kipr/wombat.h>
void servo(int port, int time, int finalpos);
int main()
{
    //claw in 1450
    // claw up 900
    servo(3, 2000, 900);
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
    motor(0,-70);
    motor(2,-70);       // lower claw to scoop the poms
    msleep(300);
    motor(0,70);
    motor(2,-70);       // lower claw to scoop the poms
    msleep(930);
    while(digital(1)==0 || digital(2)==0)
    {
        motor(0,40);
        motor(2,40);
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
    motor(0,-70);
    motor(2,-30);
    msleep(1250);
    while(digital(1)==0)
    {
        motor(0,40);
        motor(2,40);
    }	
    //put servo code here!!
    freeze(0);
    freeze(2);
    msleep(100);
    servo(3, 2000, 1450);
    int POMs = 0;
    while(POMs < 10)
    {
        motor(0,100);
        motor(2,0);
        msleep(100);
        motor(0,-100);
        motor(2,0);
        msleep(100);
        motor(0,100);
        motor(2,0);
        msleep(100);
        motor(0,-100);
        motor(2,0);
        msleep(100);
        POMs = POMs + 1;
    }
    freeze(0);
    freeze(2);
    msleep(100);
    servo(3, 2000, 900);
    motor(0,0);
    motor(2,-30);
    msleep(1800);
    while(analog(0)<2500)
    {
        motor(0,-40);
        motor(2,-40);
    }
    motor(0,70);
    motor(2,0);
    msleep(1500);
    motor(0,40);
    motor(2,40);
    msleep(1300);
    double line_follow_time = seconds();
    while(seconds() - line_follow_time < 3) //:) 
    {
        while(analog(0)<2500)
        {
            motor(0,70);
            motor(2,30);
        }
        while(analog(0)>2500)
        {
            motor(0,30);
            motor(2,70);
        }
    }
    while(digital(1)==0 || digital(2)==0)
    {
        motor(0,40);
        motor(2,40);
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