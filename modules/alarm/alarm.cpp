//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"

#include "laundry.h"
#include "washer.h"
#include "dryer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalInOut alarm(PE_10);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool alarmState = false;
static bool sound = false;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmInit() {
    alarm.mode(OpenDrain);
    alarm.input();
}

bool alarmStateRead() {
    return alarmState;
}

void alarmStateWrite( bool state ) {
    alarmState = state;
}

void alarmUpdate( int strobeTime ) {
    static int accumulatedTimeAlarm = 0;
    accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    
    if( alarmState ) {
        if( accumulatedTimeAlarm >= strobeTime ) {
                accumulatedTimeAlarm = 0;
                if (sound) {
                    alarm.input();
                    sound = false;
                } else {
                    alarm.output();
                    sound = true;
                }
        }
    } else {
        alarm.input();
        sound = false;
    }
}

//=====[Implementations of private functions]==================================
