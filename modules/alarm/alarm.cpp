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

DigitalInOut alarm( PD_7 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool alarmState = OFF;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void alarmInit() {
    alarm = OFF;
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
                alarm = !alarm;
        }
    } else {
        alarm = OFF;
    }
}

//=====[Implementations of private functions]==================================
