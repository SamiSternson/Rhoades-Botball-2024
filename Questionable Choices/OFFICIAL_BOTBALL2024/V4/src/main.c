#include <kipr/wombat.h>
#include "RHOADESBOTBALL.h"

int main()
{ 
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
    int bu=10;
    int bd=1585;
    double speed=90.0;
    //wait_for_light(5);
    shut_down_in(119);
    // Asigns motor variables
    // Calculates average sensor value for white
    int white=SC(ls);
    SSD(bos, bo, 50);
    SSU(bus, bd, 10);
    SSU(bos, 1700, 10);
    DS(rm, lm, rmt, lmt, speed/4, 0.1, 10);
    freeze(rm);
    freeze(lm);
    msleep(100);
    SSU(bos, bc, 10);
    SSD(bus, bu, 30);
    while(analog(rs)<white+500|| analog(ls)<white+500)
    {
        motor(rm, -speed);
        motor(lm, -speed);
    }
    freeze(rm);
    freeze(lm);
    msleep(100);
    int black=SC(ls);
    int thresh=black-(black-white)/2;
    SUB(rs, ls, rm, lm, -speed/4, thresh);
    SUW(rs, ls, rm, lm, speed/-4, thresh);
    PANEG(rm, lm, rmt, -speed/4, 90);
    SUB(rs, ls, rm, lm, speed/2, thresh);
    SUW(rs, ls, rm, lm, speed/4, thresh);
    return 0;
}
