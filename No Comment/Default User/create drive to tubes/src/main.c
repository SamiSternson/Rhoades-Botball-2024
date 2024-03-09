#include <kipr/wombat.h>
void MIXED_WOBBLE();
int main()
{
    create3_connect();
    
    create3_rotate_degrees(-47,45);
    create3_wait();
    
    create3_drive_straight(1.0107,0.18);
        
    create3_wait();
    msleep(3000);
    
     MIXED_WOBBLE();
    create3_wait();
    
    //insert code for getting purple noodles
   
    
    create3_drive_straight(0.508,0.46);
    
    create3_wait();
    msleep(3000);
    
    //insert code for dropping astronaut
 
    create3_drive_straight(0.14628,0.46);
    
    create3_wait();
    msleep(3000);
    
    printf("BEEP BOOP BEEP WE HAVE ARRIVED AT THE LAVA TUBES \n");
    
    MIXED_WOBBLE();
    create3_wait();
    
    
    return 0;
}
void MIXED_WOBBLE()
{ int i=0;
    while (i<15)
    {
      create3_rotate_degrees(2,45);
    create3_rotate_degrees(-2,45);
    create3_drive_straight(-0.000635,0.46);
    create3_drive_straight(0.000635,0.46);   
        i+=1;
    }
}
