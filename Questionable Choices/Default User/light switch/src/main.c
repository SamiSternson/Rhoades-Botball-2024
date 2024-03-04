#include <kipr/wombat.h>

int main()
{
    while((analog(0)>??)||(analog(3)>??))
    {
        if((analog(0)>??)&&(analog(3)>??))             //makes your robot veer when one sensor sees the line
        {
            //Make your motor veer, pivot, ot spin depending on what you want to have happen
        }
        else if((/*Left Sensor DOES SEE Black*/)&&(/*RIght sensor DOES NOT SEE Black*/))
        {
            //Make you rmotor veer, pivot, or spin the opposite way
        } 
        else
}

        {
             //Make your motors Drive straight
        }
    }
    ao(); //This turns all your motors OFF
    return 0;