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

AnalogIn washerLightSensor( PA_3 );
AnalogIn dryerLightSensor( PC_0 );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool washerSensorState;
static bool dryerSensorState;
float washerLightValues[SAMPLESIZE];
float dryerLightValues[SAMPLESIZE];

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sensorInit() {
    washerSensorState = OFF;
    dryerSensorState = OFF;
}

bool washerDoorClosed() {
    return washerSensorState;
}

bool dryerDoorClosed() {
    return dryerSensorState;
}

void sensorUpdate() {
    float temp1 = washerLightSensor.read();
    float temp2 = dryerLightSensor.read();
    for (int i = SAMPLESIZE - 1; i >= 0; i--) {
        if (i == 0) {
            washerLightValues[i] = temp1;
            dryerLightValues[i] = temp2;
        } else {
            washerLightValues[i] = washerLightValues[i-1];
            dryerLightValues[i] = dryerLightValues[i-1];
        }
    }

    int total1 = 0;
    int total2 = 0;
    for (int i = 0; i < SAMPLESIZE; i++) {
        total1 += washerLightValues[i];
        total2 += dryerLightValues[i];
    }

    int average1 = total1/SAMPLESIZE;
    if (average1 < DOORCLOSEDLEVEL) {
        washerSensorState = ON;
    } else {
        washerSensorState = OFF;
    }

    int average2 = total2/SAMPLESIZE;
    if (average2 < DOORCLOSEDLEVEL) {
        dryerSensorState = ON;
    } else {
        dryerSensorState = OFF;
    }
}


//=====[Implementations of private functions]==================================