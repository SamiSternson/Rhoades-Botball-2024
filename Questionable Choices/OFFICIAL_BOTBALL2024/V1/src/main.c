#include <kipr/wombat.h>
#include "rhoadesbotball2024.h"
int main()
{
    int rm=2;
    int lm=1;
    int lmt;
    int rmt;
    int rs=1;
    int ls=0;
    int bus=2;
    int bos=3;
    int bo=1500;
    int bc=2047;
    int bu=200;
    int bd=1600;
    int bs=2;
    int b_thresh=3200;
    int white=SC(ls);
    SS(bus, bu,50);
    int speed=100;
    while(analog(rs)<white+500 && analog(ls)<white+500)
    {
        DS(rm, lm, rmt, lmt, speed, 0.9, 1);   
    }
    int black=SC(ls);
    int thresh=(black-white)/2;
    SUW(rs, ls, rm, lm, speed/4, thresh);
    cmpc(rm);
    cmpc(lm);
    while(analog(rs)<thresh && analog(ls)<thresh)
    {
        motor(rm, speed/4);
        motor(lm, speed/4);
    }
    printf("%d, %d", gmpc(rm), gmpc(lm));
    return 0;
}
