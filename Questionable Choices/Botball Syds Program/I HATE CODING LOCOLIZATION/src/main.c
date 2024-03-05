#include <kipr/wombat.h>

int main()
{
    while(analog(0)>??)||(analog(1)>??); 
    {
        if(analog(0)>??)&&(analog(1)>??);     // when analog 0 sees the black tape, turn on motor 2
        {
            motor(1,0);
            motor(2,100);
        }
        else if(analog(0)>??)&&(analog(1)>??); // when analog 0 doesn't see the black, turn on motor 1
        {
            motor(1,100);
            motor(2,0);
        }
        else          //if neither analogs see the black, go strait
        {
            motor(1,100);
            motor(2,100);
        }
        return 0;
        
