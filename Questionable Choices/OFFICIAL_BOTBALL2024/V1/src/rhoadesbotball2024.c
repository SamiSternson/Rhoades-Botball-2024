#include <kipr/wombat.h>
void DS(int rm, int lm, double rmt, double lmt, double speed,double tc, double dist)
{
    double w_d=207;
    double lmd=0;
    double rmd=0;
    if (dist>0)
    {
        while(lmd<dist && rmd<dist)  
        {
            if (lmd>dist && rmd<dist)
            {
                motor(lm, 0);
                motor(rm, speed);
            }
            else if (lmd<dist && rmd>dist)
            {
                motor(rm, 0);
                motor(lm, speed);
            }
            else if (lmd>rmd)
            {
                motor(lm, speed*tc);
                motor(rm, speed);
            }
            else if (rmd>lmd)
            {
                motor(rm, speed*tc);
                motor(lm, speed);
            }
            lmd=gmpc(lmd*w_d/lmt);
            rmd=gmpc(rmd*w_d/rmt);
        }
    }  
}

int SC(int port)
{
    int start_time=seconds();
    int i=0;
    int num=0;
    while (seconds()-start_time<100)
    {
        num+=analog(port);
        i+=1;
    }
    int avg=num/i;
    return avg;
}

void SS(int port, int end, int speed)
{
    enable_servos();
    int pos=get_servo_position(port);
    if(end>pos)
    {
        while(end>pos)
        {
            set_servo_position(port, pos+speed);
            msleep(10);
            pos=get_servo_position(port);
        }
    }
    else
    {
        while(end<pos)
        {
            set_servo_position(port, pos-speed);
            msleep(10);
            pos=get_servo_position(port);
        }
    }
}
void SUW(int rs, int ls, int rm, int lm, int speed, int thresh)
{
    while (analog(rs) > thresh || analog(ls)>thresh)
    {
        if (analog(rs) > thresh && analog(ls)>thresh)
        {
         motor(rm, speed);
            motor(lm, speed);
        }
        else if (analog(rs) > thresh || analog(ls)<thresh)
        {
         motor(rm, speed);
            motor(lm, -speed);
        }
        else
        {
            motor(rm, -speed);
            motor(lm, speed);
        }
    }
}