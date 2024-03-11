#include <kipr/wombat.h>
#include "rhoadesbotball2024.h"
int main()
{
    // Asigns motor variables
    int rm=2;
    int lm=1;
    // Asigns motor tick variables
    double lmt=1687;
    double rmt=1690;
    // Asigns sensor variables
    int rs=1;
    int ls=0;
    int bs=2;
    int b_thresh=1700;
    // Asigns servo variables
    int bus=2;
    int bos=3;
    int bo=1550;
    int bc=2047;
    int bu=200;
    int bd=1575;
    int fus=1;
    int fd=300;
    int fdm=700;
    double speed=100;
    SS(fus,fd, 10);
    // Calculates average sensor value for white
    int white=SC(ls);
    SS(bus, bu, 50);
    // Drives to first black line
    while(analog(rs)<white+300 || analog(ls)<white+300)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Calculates threshold value
    int black=SC(ls);
    int thresh=(black-(black-white)/2)+150;
    // Squares up
    SUW(rs,ls,rm,lm,speed/4,thresh);
    // Drives to middle black line
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    motor(rm, speed);
    motor(lm, speed);
    msleep(200);
    // Squares up
    SUW(rs,ls,rm,lm,speed/2,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Turns to get astronauts
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
    //Grabs astronauts
    SS(bos, bo, 10);
    SS(fus,fd, 10);
    SS(bus, bd, 10);
    SS(bos, bc, 10);
    SS(bus, bu, 10);
    // Turns around to flip switch
    while (analog(rs)<thresh)
    {
        motor(lm, speed/2);
        motor(rm,-speed/2);
    }
    while (analog(rs)>thresh)
    {
        motor(lm, speed/2);
        motor(rm,-speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(fus, fdm, 50);
    while (analog(bs)<b_thresh)
    {
        motor(lm, speed/2);
        motor(rm,-speed/2);
    }
    while (analog(bs)>b_thresh)
    {
        motor(lm, speed/2);
        motor(rm,-speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    while(analog(rs)<thresh+300)
    {
        motor(rm, speed);
        motor(lm, speed);
    }

    while(analog(rs)>thresh+300)
    {
        motor(rm, speed/2);
        motor(lm, speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1300, 10);
    motor(rm, -speed/4);
    motor(lm, -speed/4);
    msleep(100);
    // Flips switch
    while(analog(rs)>thresh)
    {
        motor(rm, -speed/4);
        motor(lm, -speed/4);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    motor(rm, -speed/10);
    motor(lm, -speed/10);
    msleep(2000);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1250, 10);
    while(analog(rs)<3600)
    {
        motor(rm, speed/2);
        motor(lm, speed/2);
    }
    DS(rm,lm, rmt, lmt, speed/4,0.1, 20);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, bu, 10);
    while(analog(rs)>thresh)
    {
        motor(rm, speed/1.5);
        motor(lm, speed/2);
    }
    SUW(rs,ls,rm,lm,speed/4,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm, -speed/2);
        motor(lm, -speed/2);
    }
    while(analog(rs)>thresh || analog(ls)>thresh)
    {
        motor(rm, -speed/2);
        motor(lm, -speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    motor(rm, -speed);
    motor(lm, 0);
    msleep(1800);
    while(analog(rs)<thresh)
    {
        motor(rm, -speed/2);
        motor(lm, 0);
    }
    while(analog(rs)>thresh)
    {
        motor(rm, speed/2);
        motor(lm, 0);
    }
    while(analog(ls)<thresh)
    {
        motor(lm, -speed/2);
        motor(rm, 0);
    }
    SUW(rs,ls,rm,lm,speed/4,thresh);
    motor(rm, speed);
    motor(lm, speed);
    msleep(1000);
    while(analog(rs)<thresh && analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    SUW(rs,ls,rm,lm,speed/4,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm, -speed/2);
        motor(lm, -speed/2);
    }
    while(analog(rs)>thresh || analog(ls)>thresh)
    {
        motor(rm, -speed/2);
        motor(lm, -speed/2);
    }
    SUB(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, -speed/2,0.5, -200);
    while(analog(rs)<thresh)
    {
        motor(rm, speed/2);
        motor(lm, 0);

    }
    while(analog(ls)>thresh)
    {
        motor(rm, 0);
        motor(lm, -speed/2);
    }
    SUB(rs,ls,rm,lm,speed/4,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    DS(rm, lm, rmt, lmt, -speed/2,0.5, -200);
    freeze(rm);
    freeze(lm);
    msleep(100);
    PA(lm, rm, lmt, speed/4, 45);
    return 0;
}

