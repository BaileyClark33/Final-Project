//change servo so that slow has a slower slope
//fast needs higher slope
//both use the same delay between periods
//intermittent uses low mode but delay between cycles changes

//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"
#include "servo.h"

//=====[Declaration of private defines]========================================

#define PERIOD 0.02
#define STOP_PERIOD 1.5
#define DUTY_STOP 0.075

#define DUTY_ZERO 0.025//25
#define DUTY_90 0.0625//68

#define SERVO_INCREMENT 1

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut servo( /* ENTER NUCLEO PIN */ );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

int angle_increment;
int time_incrament = 0;
bool went_down = false;
bool went_up = false;

int servo_update_time;
float angle;

//=====[Declarations (prototypes) of private functions]========================

void servoLock();
void servoUnlock();

//=====[Implementations of public functions]===================================

void servoInit() {
   servo.period(PERIOD);
   servo.write(DUTY_ZERO);
   servo_update_time = 0;
   angle = DUTY_ZERO;
}

int getAngle() {
    return angle;
}

void servoLock() {
   servo.write(DUTY_90);
   delay(1000);
}

void servoUnlock() {
    servo.write(DUTY_ZERO);
    delay(1000);
}
//=====[Implementations of private functions]==================================


