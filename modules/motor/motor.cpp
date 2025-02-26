//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor.h"

//=====[Declaration of private defines]========================================

#define MOTOR_UPDATE_TIME 3

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalInOut washerMotorM1Pin( PG_0 );
DigitalInOut washerMotorM2Pin( PG_1 );
DigitalInOut dryerMotorM1Pin( PF_1 );
DigitalInOut dryerMotorM2Pin( PF_2 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

washerState_t washerState;
dryerState_t dryerState;

//=====[Declaration and initialization of private global variables]============

static int washerRunTime = 0;
static int dryerRunTime = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void motorControlInit() {
    washerMotorM1Pin.mode(OpenDrain);
    washerMotorM2Pin.mode(OpenDrain);
    dryerMotorM1Pin.mode(OpenDrain);
    dryerMotorM2Pin.mode(OpenDrain);
    
    washerMotorM1Pin.input();
    washerMotorM2Pin.input();
    dryerMotorM1Pin.input();
    dryerMotorM2Pin.input();

    washerState = STOPPED;
    dryerState = STOPPED;
}

washerState_t washerStateRead() {
    return washerState;
}
dryerState_t dryerStateRead(); {
    return dryerState;
}

void washerMotorWrite( washerState_t direction ) {
    washerState = direction;
}
void dryerMotorWrite( dryerState_t direction ) {
    motorState = direction;
}

void washerMotorUpdate() {
    static int motorUpdateCounter = 0;
    
    motorUpdateCounter++;
    
    if ( motorUpdateCounter > MOTOR_UPDATE_TIME ) {
        
        motorUpdateCounter = 0;
        
        switch ( washerState ) {
            case RUNNING:
                if ( washerRunTime < 0 ) {
                    washerMotorM1Pin.input();
                    washerMotorM2Pin.input();
                    motorState = STOPPED;
                } else {
                    washerMotorM1Pin.output();
                    washerMotorM2Pin.input();
                }
            break;
    
            case STOPPED:
            default:
                washerMotorM1Pin.input();
                washerMotorM2Pin.input();
            break;
        }
    }        
}

void dryerMotorUpdate() {
    static int motorUpdateCounter = 0;
    
    motorUpdateCounter++;
    
    if ( motorUpdateCounter > MOTOR_UPDATE_TIME ) {
        
        motorUpdateCounter = 0;
        
        switch ( dryerState ) {
            case RUNNING:
                if ( dryerRunTime < 0 ) {
                    dryerMotorM1Pin.input();
                    dryerMotorM2Pin.input();
                    motorState = STOPPED;
                } else {
                    dryerMotorM1Pin.output();
                    dryerMotorM2Pin.input();
                }
            break;
    
            case STOPPED:
            default:
                dryerMotorM1Pin.input();
                dryerMotorM2Pin.input();
            break;
        }
    }        
}

//=====[Implementations of private functions]==================================