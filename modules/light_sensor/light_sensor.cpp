//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"

#include "laundry.h"
#include "washer.h"
#include "dryer.h"

//=====[Declaration of private defines]========================================

#define SAMPLESIZE 10
#define DOORCLOSEDLEVEL 0.5

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn lightSensor( PA_3 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool sensorState;
float lightValues[SAMPLESIZE];

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sensorInit() {
    sensorState = OFF;
}

bool doorClosed() {
    return sensorState;
}

void sensorUpdate() {
    float temp = lightSensor.read();
    for (int i = 0; i < SAMPLESIZE; i++) {
        if (i == 0) {
            lightSensor[i] = temp;
        } else {
            lightSensor[i] = lightSensor[i-1];
        }
    }

    int total = 0;
    for (int i = 0; i < SAMPLESIZE; i++) {
        total += lightSensor[i];
    }

    int average = total/SAMPLESIZE;
    if (average < DOORCLOSEDLEVEL) {
        sensorState = ON;
    } else {
        sensorState = OFF;
    }
}


//=====[Implementations of private functions]==================================