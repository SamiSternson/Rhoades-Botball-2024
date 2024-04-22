#include <kipr/wombat.h>
#include <math.h>
#define PI 3.14159265359
void PA(int am, int om, int at, double speed, double angle)
{
    cmpc(am);
    double r=170;
    double circ=2*r*PI;
    double w_c=207;
    double frac=angle/360;
    printf("%f", frac);
    while (gmpc(am)*w_c/at<circ*frac)
    {
        motor(am, speed);
        motor(om, 0);
    }
}
void PANEG(int am, int om, int at, double speed, double angle)
{
    cmpc(am);
    double r=170;
    double circ=2*r*PI;
    double w_c=207;
    double frac=angle/360;
    printf("%f", frac);
    while (gmpc(am)*w_c/at>circ*frac)
    {
        motor(am, speed);
        motor(om, 0);
    }
}
void SPA(int am, int om, int at, double speed, double angle)
{
    cmpc(am);
    double r=170;
    double circ=2*r*PI;
    double w_c=207;
    double frac=angle/720;
    printf("%f", frac);
    while (gmpc(am)*w_c/at<circ*frac)
    {
        motor(am, speed);
        motor(om, -speed);
    }
}
void DS(int rm,int lm, double rt, double lt, double speed,double t_c, double dist)
{
    double w_c=207.0;
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
            r_dist = gmpc(rm) * (w_c / rt);
            l_dist = gmpc(lm) * (w_c / lt);

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
        }
    }
}
void DECELL(int rm, int lm, double rt, double lt, double speed,double t_c, double dist)
{
    double w_c=207;
    int l_dist=0;
    int r_dist=0;
    if (dist>0)
    {
        cmpc(rm);
        cmpc(lm);
        while (l_dist < dist || r_dist < dist)
        {
            speed=(80/(1+exp(10/dist-5)))+20;
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
            r_dist = gmpc(rm) * (w_c / rt);
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

void SSU(int port, int end, int speed)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(end>pos)
    {
        set_servo_position(port, pos+speed);
        msleep(20);
        pos=get_servo_position(port);

    }
    disable_servos();
}

void SSD(int port, int end, int speed)
{
    enable_servo(port);
    int pos=get_servo_position(port);
    while(end<pos)
    {
        set_servo_position(port, pos-speed);
        msleep(20);
        pos=get_servo_position(port);
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
void CRC(int rm, int lm, double rmt, double lmt, int servo, int end_pos, int speed)
{
    enable_servos();
    int pos=get_servo_position(servo);
    double r=290;
    double keep_dist=r*cos((PI/180)*(pos-875)*0.0861328125);
    double delta=keep_dist-r*cos((PI/180)*(pos-875)*0.0861328125);
    double prev_delta=delta;
    while(end_pos>pos)
    {
        printf("%f\n", delta);
        set_servo_position(servo, pos+speed);
        msleep(10);
        pos=get_servo_position(servo);
        delta=keep_dist-r*cos((PI/180)*(pos-650)*0.0861328125)-prev_delta;
        prev_delta=keep_dist-r*cos((PI/180)*(pos-650)*0.0861328125);
        /*if (delta<0)
        {
            DS(rm, lm, rmt, lmt, -speed, 0.1, delta);
        }
        else
        {
            DS(rm, lm, rmt, lmt, speed, 0.1, delta); 
        }*/
    }
    disable_servos();
}