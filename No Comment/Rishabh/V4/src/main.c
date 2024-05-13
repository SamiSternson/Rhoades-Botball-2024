#include <kipr/wombat.h>
void SSU(int port, int speed, int final);
void SSD(int port, int speed, int final);
void servo(int port, int time, int finalpos);
int main()
{

    int DROP = 0;
    /*wait_for_light(1);
    shut_down_in(119);
    msleep(17000);*/ // lower claw to the astronaut to pick it up
    servo(0, 2000, 2047);
    servo(0, 1000, 500);
    servo(0, 2200, 2247);
    while(analog(0)<2500)
    {
        motor(0,72);
        motor(2,70);
    }
    double start_time = seconds();
    while(seconds() - start_time < 3)
    {
        while(digital(1)==0)   // wall follow to get to the purple pool noodles
        {
            motor(0,40);
            motor(2,70);
        }
        if(digital(1)==1)
        {
            motor(0,72);
            motor(2,0);
            msleep(100);
        }
    }
    while(analog(0)<1700)    // use the black line to see were you are
    {
        motor(0,72);
        motor(2,70);
    }
    motor(0,70);
    motor(2,70);
    msleep(500);
    freeze(0);
    freeze(2);
    msleep(100);

    while(digital(1)==0)       //wall follow to get to the pvc
    {
        motor(0,40);
        motor(2,80);
    }
    // straiten out after the bump sensor  hits the p
    motor(0,90);
    motor(2,0);
    msleep(300);
    freeze(0);
    freeze(2);
    msleep(100);
    servo(0, 2000, 943);
    motor(0,90);
    motor(2,90);
    msleep(2000);
    /*int POMS = 0;
    while(POMS < 24)         // shake the astronaut into the hole
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
        POMS = POMS + 1;
    }

    printf("WHY IS IT STOPPING WORKING?");
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
    motor(0,-70);
    motor(2,-70);       // lower claw to scoop the poms
    msleep(300);
    motor(0,70);
    motor(2,-70);       // lower claw to scoop the poms
    msleep(900);
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
    /*motor(0,70);
    motor(2,0);  
    msleep(500);
    freeze(0);
    freeze(2);
    while(DROP<5)
    {
        freeze(0);
        freeze(2);
        servo(3, 2000, 2047);
        motor(0,-100);
        motor(2,-100);
        msleep(1300);
        freeze(0);
        freeze(2);
        servo(3, 2000, 1070);
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
        motor(0,0);
        motor(2,20);
        msleep(50);
        DROP = DROP + 1;
    }
    motor(0,-70);
    motor(2,-70);
    msleep(300);
    motor(0,70);
    motor(2,-70);
    msleep(900);*/
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
