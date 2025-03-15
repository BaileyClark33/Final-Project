//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "alarm.h"

#include "laundry.h"
#include "washer.h"
#include "dryer.h"

//=====[Declaration of private defines]========================================

#define SAMPLESIZE 10
#define DOORCLOSEDLEVEL 0.8

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn washerLightSensor( A0 );
AnalogIn dryerLightSensor( );

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
    washerSensorState = false;
    dryerSensorState = false;
    for (int i = 0; i < SAMPLESIZE; i++) {
        washerLightValues[i] = 0.0;
        dryerLightValues[i] = 0.0;
  }
}

bool washerDoorClosed() {
    return washerSensorState;
}

bool dryerDoorClosed() {
    return dryerSensorState;
}

void WsensorUpdate() {
    // Averages multiple readings to increase consistency
  static int sensorReadingIndex = 0;
  float readingSum = 0;
  float readingAvg = 0;
  washerLightValues[sensorReadingIndex] = washerLightSensor.read();
  sensorReadingIndex = (sensorReadingIndex + 1) % SAMPLESIZE;

  for (int i = 0; i < SAMPLESIZE; i++) {
    readingSum += washerLightValues[i];
  }
  readingAvg = readingSum / float(SAMPLESIZE);
  washerSensorState = readingAvg < DOORCLOSEDLEVEL;
}


//=====[Implementations of private functions]==================================
