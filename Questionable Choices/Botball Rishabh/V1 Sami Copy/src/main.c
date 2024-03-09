#include <kipr/wombat.h>
#include "rhoadesbotball2024.h"
int main()
{
    int rm=2;
    int lm=1;
    double lmt=1687;
    double rmt=1690;
    int rs=1;
    int ls=0;
    int bus=2;
    int bos=3;
    int bo=1550;
    int bc=2000;
    int bu=200;
    int bd=1550;
    int bs=2;
    int b_thresh=1500;
    double speed=100;
    int white=SC(ls);
    SS(bus, bu, 50);
    while(analog(rs)<white+300 || analog(ls)<white+300)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    

    
    freeze(rm);
    freeze(lm);
    msleep(100);
    int black=SC(ls);
    int thresh=black-(black-white)/2;
    SUW(rs,ls,rm,lm,speed/4,thresh);
    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    SUW(rs,ls,rm,lm,speed/2,thresh);
    freeze(rm);
    freeze(lm);
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
    SS(bos, bo, 10);
    SS(bus, bd, 10);
    SS(bos, bc, 10);
    SS(bus, bu, 10);
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
    while(analog(rs)>thresh)
    {
        motor(rm, -speed/4);
        motor(lm, -speed/4);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
	motor(rm, speed/20);
    motor(lm, speed/20);
    msleep(1000);
    freeze(rm);
    freeze(lm);
    msleep(100);
    return 0;
}
