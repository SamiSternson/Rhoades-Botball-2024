#include <kipr/wombat.h>
#include "RHOADESBOTBALL.h"
int rm=0;
int lm=1;
// Asigns motor tick variables
double lmt=1658.0;
double rmt=1659.0;
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
int rw=500;
int rc=2047;
int bo=1350;
int bc=2047;
int bu=200;
int bd=1585;
double speed=90.0;
void SENSOR_GET();
int white;
int main()
{ 
    wait_for_light(5);
    shut_down_in(119);
    // Asigns motor variables
    // Calculates average sensor value for white
    white=SC(ls);
    SS(bus, bu, 50);
    SS(rocwac, rw, 50);
    // Drives to first black line
    printf("%d",white);
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
    int thresh=(black-(black-white)/2);
    // Squares up
    SUW(rs,ls,rm,lm,speed/3, thresh);	
    // Drives to middle black line
    printf("hi\n");
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        DS(rm, lm, rmt, lmt, speed,0.5, 1.0);
    }
    printf("hi");
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
    SS(rocwac, rc, 10);
    SS(rocwac, rw,30);
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
    PA(lm, rm, lmt, speed/4, 1);
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Grabs astronauts
    SS(bos, bo, 10);
    SS(bus, bd, 10);
    SS(bos, 1700, 10);
    DS(rm, lm, rmt, lmt, 10,0.1, 15);
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
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -50);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(rocwac, rc, 10);
    motor(rm, 100);
    motor(lm, -100);
    msleep(800);
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
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -220);
    PA(lm, rm, lmt, speed/4, 45);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 60);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1535, 10);
    DS(rm, lm, rmt, lmt, speed/-4,0.1, -80);
    PA(lm, rm, lmt, speed/4,8);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 170);
    DS(rm, lm, rmt, lmt, -speed/4,0.1, -5);
    PA(rm, lm, rmt, speed/4, 5);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1000, 10);
    PA(lm, rm, lmt, speed/4, 9);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -220);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bos, bo, 20);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 40);
    SPA(rm,lm, rmt, speed/2, 89);
    SPA(rm,lm, rmt, speed/2, 45);
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        DS(rm, lm, rmt, lmt, 90,0.1, 1);
    }
    SUW(rs,ls,rm,lm,speed/-4,thresh);
    motor(rm, speed/2);
    motor(lm,-speed/2);
    msleep(1525);
    SUB(rs,ls,rm,lm,speed/-2,thresh);
    freeze(rm);
    freeze(lm);
    SS(bus, 1550, 10);
    SS(bos, bc, 10);
    SS(bus, bu, 10);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 20);
    while(analog(ls)<thresh)
    {
        motor(rm,0.1*speed);
        motor(lm,speed);
    }
    SUW(rs,ls,rm,lm,speed/-4,thresh);
    motor(rm, speed);
    motor(lm,speed);
    msleep(300);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SUB(rs,ls,rm,lm,speed/-4,thresh);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 570);
    motor(lm, -speed/2);
    motor(rm,speed/2);
    msleep(1550);
    SUB(rs,ls,rm,lm,speed/-4,thresh);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 140);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, bd,10);
    SS(bos, bo,10);
    SS(bus,bu,10);
    /*while(analog(ls)>thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    double start_time=seconds();
    SS(bus, bu, 20);
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
    while(analog(rs)<thresh)
    {
        motor(rm, -speed);
        motor(lm, 0);
    }
    SUB(rs,ls,rm,lm,speed/-2,thresh);
    SUW(rs,ls,rm,lm,speed/-2,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    DS(rm, lm, rmt, lmt, speed/-4,0.1, -50);
    PA(rm, lm, rmt, speed, 87);
    SUB(rs,ls,rm,lm,speed/2,thresh);
    SUW(rs,ls,rm,lm,speed/4,thresh);
    while(analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, -speed);
    }
    while (analog(ls)>thresh)
    {        
        motor(rm, speed);
        motor(lm, -speed);
    }
    while(analog(ls)<thresh)
    {
        motor(rm, 0);
        motor(lm, -speed);
    }
    while (analog(ls)>thresh)
    {        
        motor(rm, -speed);
        motor(lm, -speed);
    }
    while (analog(rs)>thresh)
    {        
        motor(rm, speed);
        motor(lm, speed);
    }
    while(analog(bs)<b_thresh)
    {
        motor(rm, speed/2);
        motor(lm, -speed/2);
    }

    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1630, 20);
    SS(bos, bc, 20);
    while(analog(3)<1250)
    {
        if (analog(bs)<b_thresh)
        {
            motor(rm, -speed*0.1);
            motor(lm, -speed/2);
        }
        else 
        {
            motor(lm, -speed*0.1);
            motor(rm, -speed/2);
        }
    }
    PA(lm, rm, lmt, speed/4, 10);
    motor(rm, -speed/10);
    motor(lm,-speed/10);
    msleep(1000);
    freeze(rm);
    freeze(lm);
    msleep(100);
    enable_servo(bus);
    set_servo_position(bus, 1600);
    msleep(100);
    int pos=get_servo_position(bus);
    while(1000<pos)
    {
        set_servo_position(bus, pos-20);
        msleep(10);
        pos=get_servo_position(bus);
        DS(rm, lm, rmt, lmt, speed,0.1, 5);
    }
    disable_servo(bus);
    DS(rm, lm, rmt, lmt, -speed,0.1, -130);
    freeze(rm);
    freeze(lm);
    msleep(100);*/
    return 0;
}
void SENSOR_GET()
{
    white=SC(ls);
}
