#include <kipr/wombat.h>
#include "rhoadesbotball.h"
int main()
{ 
    // Asigns motor variables
    int rm=1;
    int lm=2;
    // Asigns motor tick variables
    double lmt=1697;
    double rmt=1699;
    // Asigns sensor variables
    int rs=0;
    int ls=1;
    int bs=2;
    int fb=0;
    int b_thresh=1700;
    // Asigns servo variables
    int bus=1;
    int bos=0;
    int bo=1350;
    int bc=2047;
    int bu=200;
    int bd=1570;
    double speed=100;
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
    int thresh=(black-(black-white)/2)+250;
    // Squares up
    SUW(rs,ls,rm,lm,speed/4,thresh);
    cmpc(rm);
    cmpc(lm);
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm,speed);
        motor(lm, speed);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
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
    SUW(rs,ls,rm,lm,speed/4,thresh);
    freeze(rm);
    freeze(lm);
    msleep(100);
    DS(rm, lm, rmt, lmt, speed/2,0.1, 50);
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
    PA(rm, lm, rmt, speed/4, 5);
    freeze(rm);
    freeze(lm);
    msleep(100);
    //Grabs astronauts
    SS(bos, bo, 10);
    SS(bus, bd, 10);
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
    while(analog(bs)<b_thresh)
    {
        motor(rm, speed/2);
        motor(lm, -speed/2);
    }
    while(analog(ls)<thresh)
    {
        motor(rm, 0);
        motor(lm, -speed/2);
    }
    SUW(rs,ls,rm,lm,speed/4,thresh);
    DECELL(rm, lm, rmt, lmt, 100.0,0.9, 625);
    SUB(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -200);
    PA(rm, lm, rmt, speed/2, 85);
    SUB(rs,ls,rm,lm,speed/2,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -10);
    SUB(rs,ls,rm,lm,speed/4,thresh);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -200);
    PA(lm, rm, lmt, speed/4, 42);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 60);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1560, 10);
    DS(rm, lm, rmt, lmt, speed/-4,0.1, -80);
    PA(lm, rm, lmt, speed/4, 5);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 170);
    PA(rm, lm, rmt, speed/4, 5);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1000, 10);
    PA(lm, rm, lmt, speed/4, 5);
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -200);
    freeze(rm);
    freeze(lm);
    msleep(100);
    int i=0;
    while (i<5)
    {
        SS(bos, bo, 30);
        msleep(100);
        SS(bus, 1300, 30);
        msleep(100);
        SS(bos, bc, 30);
        msleep(100);
        SS(bus, 1000, 30);
        msleep(100);
        i+=1;
    }
    return 0;
}
