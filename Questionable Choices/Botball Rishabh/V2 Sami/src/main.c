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
void DS(int rm, int lm, int rt, int lt, double speed,double t_c, double dist)
{
    int w_c=207;
    int l_dist=0;
    int r_dist=0;
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
            r_dist = gmpc(rm) * (w_c / rt);
            printf("%d,%d",l_dist,r_dist);
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

void SS(int port, int end, int speed)
{
    enable_servo(port);
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
#include <kipr/wombat.h>
int main()
{ 
    // Asigns motor variables
    int rm=0;
    int lm=3;
    // Asigns motor tick variables
   int lmt=1658;
    int rmt=1659;
    // Asigns sensor variables
    int rs=0;
    int ls=1;
    int bs=2;
    int fb=0;
    int b_thresh=1700;
    // Asigns servo variables
    int bus=1;
    int bos=0;
    int rocwac=2;
    int rw=700;
    int rc=2047;
    int bo=1350;
    int bc=2040;
    int bu=200;
    int bd=1595;
    double speed=90;
    // Calculates average sensor value for white
    int white=SC(ls);
    SS(bus, bu, 50);
    SS(rocwac, rw, 50);
    // Drives to first black line
    while(analog(rs)<white+500 || analog(ls)<white+500)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Calculates threshold value
    int black=SC(ls);
    int thresh=(black-(black-white)/2)+300;
    // Squares up
    SUW(rs,ls,rm,lm,speed/4, thresh);	
    // Drives to middle black line
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        DS(rm, lm, rmt, lmt, 90,0.5, 1);
    }
    motor(rm, speed);
    motor(lm, speed);
    msleep(200);
    // Squares up
    SUW(rs,ls,rm,lm,speed/4,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    DS(rm, lm, rmt, lmt, speed/2,0.1, 50);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(rocwac, rc, 50);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -50);
    //Turns to get astronauts
    motor(rm, speed/2);
    motor(lm,-speed/2);
    msleep(400);
    while (analog(rs)<thresh)
    {
        motor(rm, speed/2);
        motor(lm,-speed/2);
    }
    motor(rm, speed/2);
    motor(lm,-speed/2);
    msleep(100);
    while (analog(rs)<thresh)
    {
        motor(rm, speed/2);
        motor(lm,-speed/2);
    }
    while (analog(rs)>thresh)
    {
        motor(rm, speed/2);
        motor(lm,-speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(50);
    while(analog(bs)<b_thresh)
    {
        motor(rm, speed/4);
        motor(lm, speed/4);
    }
    while(analog(bs)>b_thresh)
    {
        motor(rm, speed/4);
        motor(lm, speed/4);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    //PA(rm, lm, rmt, speed/4, 4.5);
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Grabs astronauts
    SS(bos, bo, 10);
    SS(bus, bd, 10);
    DS(rm, lm, rmt, lmt, 10,0.1, 10);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bos, bc, 10);
    SS(bus, bu, 10);
    while(analog(ls)<thresh)
    {
        motor(rm, speed*0.3);
        motor(lm, speed);
    }
    PA(rm, lm, rmt, speed/4, 25);
    while (digital(fb)==0)
    {
        motor(rm, speed/2);
        motor(lm, speed/2);
    }
    motor(rm, speed);
    motor(lm, -speed);
    msleep(1000);
    motor(rm, -speed);
    motor(lm, -speed);
    msleep(500);
    SUB(rs,ls,rm,lm,speed/-2,thresh);
    SUW(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, 90,0.9, 625);
    SUB(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -200);
    PA(rm, lm, rmt, speed/2, 85);
    SUB(rs,ls,rm,lm,speed/2,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -10);
    SUB(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -200);
    PA(lm, rm, lmt, speed/4, 41);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 60);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1560, 10);
    DS(rm, lm, rmt, lmt, speed/-4,0.1, -80);
    PA(lm, rm, lmt, speed/4, 6);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 170);
    PA(rm, lm, rmt, speed/4, 5);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1000, 10);
    PA(lm, rm, lmt, speed/4, 6);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -220);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bos, bo, 20);
    SPA(rm,lm, rmt, speed/2, 89);
    SPA(rm,lm, rmt, speed/2, 43);
    while(analog(rs)<thresh ||analog(ls)<thresh)
    {
        DS(rm, lm, rmt, lmt, 90,0.1, 1);
    }
    while(analog(ls)>thresh)
    {
        motor(rm, 0);
        motor(lm, speed);
    }
    double start_time=seconds();
    while (seconds()-start_time<5)
    {
        if (analog(ls)>thresh)
        {
            motor(rm, speed*0.5);
            motor(lm, speed);
        }
        else
        {
            motor(lm, speed*0.5);
            motor(rm, speed);
        }
    }
    while(analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, 0);
    }
    while(analog(ls)>thresh)
    {
        motor(rm, speed);
        motor(lm, 0);
    }
    while(analog(ls)<thresh)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while(analog(ls)>thresh)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while(analog(rs)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    while(analog(rs)<thresh||analog(ls)<thresh)
    {
        if (analog(rs)<thresh && analog(ls)<thresh)
        {
            motor(rm, speed);
            motor(lm, speed);
        }
        else if (analog(rs)>thresh && analog(ls)<thresh)
        {
            motor(rm, speed*0.5);
            motor(lm, speed);
        }
        else if (analog(rs)<thresh && analog(ls)<thresh)
        {
            motor(lm, speed*0.5);
            motor(rm, speed);
        }
    }

    freeze(rm);
    freeze(lm);
    msleep(100);

    return 0;
}
