#include <kipr/wombat.h>
#include "rhoadesbotball2024.h"
int main()
{
    int rm=2;
    int lm=1;
    double lmt=1683;
    double rmt=1686;
    int rs=1;
    int ls=0;
    int bus=2;
    int bos=3;
    int bo=1500;
    int bc=2047;
    int bu=200;
    int bd=1600;
    int bs=2;
    int b_thresh=1500;
    int white=SC(ls);
    double speed=100;
    while(analog(rs)<white+300 && analog(ls)<white+300)
    {
        motor(rm, speed/2);
        motor(lm, speed/2);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    int black=SC(ls);
    int thresh=black-(black-white)/2;
    SUW(rs, ls, rm, lm, speed/4, thresh);


    while(analog(rs)<thresh || analog(ls)<thresh)
    {
        motor(rm, speed);
        motor(lm, speed);
    }
    SUW(rs, ls, rm, lm, speed/2, thresh);
    while( analog(rs)<thresh)
    {
        motor(rm, speed);
        motor(lm, -speed);
    }
    while( analog(rs)>thresh)
    {
        motor(rm, speed);
        motor(lm, -speed);
    }
    while(analog(bs)<b_thresh)
    {
        DS(rm,lm, rmt, lmt, speed/4,0.5, 1);   
    }
    while(analog(bs)>b_thresh)
    {
        DS(rm,lm, rmt, lmt, speed/4,0.5, 1);   
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bos, bo, 10);
    SS(bus, bd, 10);
    SS(bos, bc, 10);
    SS(bus, bu, 10);
    while( analog(rs)<thresh)
    {
        motor(lm, speed);
        motor(rm, -speed);
    }
    while( analog(rs)>thresh)
    {
        motor(lm, speed);
        motor(rm, -speed);
    }
    while( analog(bs)<b_thresh)
    {
        motor(rm, speed);
        motor(lm, -speed);
    }
    while( analog(bs)>b_thresh)
    {
        motor(rm, speed);
        motor(lm, -speed);
    }
    while(analog(rs)<thresh)
    {
        DS(rm,lm, rmt, lmt, speed/2,0.5, 1); 
    }
    DS(rm,lm, rmt, lmt, speed/2,0.5, 10); 
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bos, 1300, 10);
    DS(rm,lm, rmt, lmt, speed/2,0.5, -5);
        return 0;
}
