#include <kipr/wombat.h>
#include <math.h>
void DS(int rm, int lm, double rt, double lt, double speed,double t_c, double dist)
{
    double w_c=207;
    double l_dist=0;
    double r_dist=0;
    if (dist>0)
    {
        cmpc(rm);
        cmpc(lm);
        while (l_dist < dist || r_dist < dist)
        {
            if (l_dist < dist && r_dist < dist)
            {
                motor(lm, speed);
                motor(rm, speed);
            }
            else if (l_dist >= dist && r_dist < dist)
            {
                motor(lm, 0);
                motor(rm, speed);
            }
            else if (l_dist < dist && r_dist >= dist)
            {
                motor(lm, speed);
                motor(rm, 0);
            }
            else if (l_dist - 5 > r_dist)
            {
                motor(lm, speed * t_c);
                motor(rm, speed);
            }
            else if (l_dist < r_dist - 5)
            {
                motor(rm, speed * t_c);
                motor(lm, speed);
            }
            else
            {
                freeze(rm);
                freeze(lm);
                msleep(100);
            }
            l_dist = gmpc(lm) * (w_c / lt);
            r_dist = gmpc(lm) * (w_c / lt);
        }
    }
    else
    {
        cmpc(rm);
        cmpc(lm);
        while (l_dist > dist || r_dist > dist)
        {
            if (l_dist > dist && r_dist > dist)
            {
                motor(lm, speed);
                motor(rm, speed);
            }
            else if (l_dist <= dist && r_dist > dist)
            {
                motor(lm, 0);
                motor(rm, speed);
            }
            else if (l_dist > dist && r_dist <= dist)
            {
                motor(lm, speed);
                motor(rm, 0);
            }
            else if (l_dist - 5 < r_dist)
            {
                motor(lm, speed * t_c);
                motor(rm, speed);
            }
            else if (l_dist > r_dist - 5)
            {
                motor(rm, speed * t_c);
                motor(lm, speed);
            }
            else
            {
                freeze(rm);
                freeze(lm);
                msleep(100);
            }
            l_dist = gmpc(lm) * (w_c / lt);
            r_dist = gmpc(rm) * (w_c / rt);
            printf("%d, %d\n", l_dist, r_dist);
        }
    }
}
void DECELL(int rm, int lm, double rmt, double lmt, double speed,double tc, double dist)
{
    double w_d=207;
    double lmd=0;
    double rmd=0;
    if (dist>0)
    {
        speed=(80/(1+exp(10/dist-5)))+20;
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
            lmd=gmpc(lmd)*w_d/lmt;
            rmd=gmpc(rmd)*w_d/rmt;
        }
    }
}

int SC(int port)
{
    int start_time=seconds();
    int i=0;
    int num=0;
    while (seconds()-start_time<1)
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
            if (get_servo_position(port)==pos)

                break;

            pos=get_servo_position(port);

        }
    }
    else
    {
        while(end<pos)
        {
            set_servo_position(port, pos-speed);
            msleep(10);
            if (get_servo_position(port)==pos)

                break;

            pos=get_servo_position(port);
        }
    }
    disable_servos();
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
void SUB(int rs, int ls, int rm, int lm, int speed, int thresh)
{
    while (analog(rs) < thresh || analog(ls)<thresh)
    {
        if (analog(rs) < thresh && analog(ls)<thresh)
        {
            motor(rm, speed);
            motor(lm, speed);
        }
        else if (analog(rs) > thresh || analog(ls)<thresh)
        {
            motor(rm, -speed);
            motor(lm, speed);
        }
        else
        {
            motor(rm, speed);
            motor(lm, -speed);
        }
    }
}

void LFA2(int rs, int ls, int rm, int lm, double speed, double thresh)
{
    while (analog(rs)<thresh || analog(ls)<thresh)
    {
        if (analog(rs)<thresh && analog(ls)<thresh)  
        {
            motor(rm, speed);
            motor(lm, speed);
        }
        else if (analog(rs)>thresh && analog(ls)<thresh) 
        {
            motor(rm, speed*thresh);
            motor(lm, speed);
        }
        else if (analog(rs)<thresh && analog(ls)>thresh) 
        {
            motor(lm, speed*thresh);
            motor(rm, speed);
        }
        else
        {
            freeze(rm);
            freeze(lm);
            msleep(100);
        }
    }

}