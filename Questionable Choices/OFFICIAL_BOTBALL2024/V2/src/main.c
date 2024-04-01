#include <kipr/wombat.h>
#include "rhoadesbotball.h"
int main()
{ 
    // Asigns motor variables
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
    int rw=700;
    int rc=2047;
    int bo=1350;
    int bc=2040;
    int bu=200;
    int bd=1585;
    double speed=90.0;
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
    PA(rm, lm, rmt, speed/4, 2);
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
    motor(rm, 100);
    motor(lm, -100);
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
    DS(rm, lm, rmt, lmt, speed/-2,0.1, -220);
    PA(lm, rm, lmt, speed/4, 45);
    DS(rm, lm, rmt, lmt, speed/4,0.1, 60);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SS(bus, 1555, 10);
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
    DS(rm, lm, rmt, lmt, speed/4,0.1, 40);
    SPA(rm,lm, rmt, speed/2, 89);
    SPA(rm,lm, rmt, speed/2, 45);
    while(analog(rs)<thresh ||analog(ls)<thresh)
    {
        DS(rm, lm, rmt, lmt, 90,0.1, 1);
    }
    while(analog(ls)>thresh)
    {
        motor(rm, speed*0.5);
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
    PA(rm, lm, rmt, speed/2, 87);
    SUB(rs,ls,rm,lm,speed/4,thresh);
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
    SS(bus, 1700, 20);
    SS(bos, bc, 20);
    PA(lm, rm, lmt, speed/2, 45);
    while(analog(3)<1375)
    {
        if (analog(ls)<thresh)
        {
            motor(rm, 0);
            motor(lm, -speed/2);
        }
        else 
        {
            motor(lm, 0);
            motor(rm, -speed/2);
        }
    }
    
    freeze(rm);
    freeze(lm);
    msleep(100);
    return 0;
}
