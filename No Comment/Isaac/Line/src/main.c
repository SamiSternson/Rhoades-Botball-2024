#include <kipr/wombat.h>

void weeblewobble();
void servo(int port, float targetangle, float time);

int main()
{
    //Main Servo Limit 1800
    //3/10 successes
    create3_connect();
    create3_wait();
	servo(3, 0, 1000);
    servo(3, 1400, 2000);
    create3_rotate_degrees(-45, 90);
    create3_wait();
    create3_drive_straight(0.645, 0.46);
    create3_wait();
    create3_rotate_degrees(-50, 45);
    create3_wait();
    create3_drive_straight(-0.09, 0.46);
    create3_wait();
	servo(2, 400, 3);
    msleep(1000);
    create3_drive_straight(0.05, 0.05);
    create3_wait();
    weeblewobble();
    /*
	servo(2, 800, 1);
    create3_rotate_degrees(30, 45);
    create3_wait();
    create3_drive_straight(0.55, 0.46);
    create3_wait();
    create3_rotate_degrees(15, 45);
    create3_wait();
    */
    /*
    ---PLACEMENT CODE (IMPROPER MEASUREMENTS)---
    create3_drive_straight(1, 0.46);
    create3_wait();
    //Drive up to edge of pipe area (Distance Not Measured)
    */
    
    /*
    ---SUDO CODE (NO REAL CODE)---
    -Use servos to dump pipes in tubes; Requires bottom mechanism
    */
    return 0;
}

void weeblewobble(){
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);    
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,0.46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,46);
    create3_rotate_degrees(2,151);
    create3_rotate_degrees(-2,151);
    create3_drive_straight(-0.000636,0.46);
    create3_drive_straight(0.000635,46);
    
    create3_wait();
}

void servo(int port, float targetangle, float time)
{
    float currentangle = get_servo_position(port);
    float angledistance;
    float repeats;
    int repeated = 0;

    if (currentangle < targetangle) {
        angledistance = targetangle - currentangle;
        repeats = angledistance / 1;
    }
    else if (currentangle > targetangle) {
        angledistance = currentangle - targetangle;
        repeats = angledistance / 1;
    }

    //time = angledistance * time;

    float sleeptime = (time / repeats);


    enable_servo(port);
    while (currentangle < targetangle) {
        currentangle = currentangle + 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    while (currentangle > targetangle) 
    {
        currentangle = currentangle - 1;
        set_servo_position(port, currentangle);
        repeated++;
        msleep(sleeptime);
    }
    disable_servo(port);
}