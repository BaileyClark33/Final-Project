//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "alarm.h"
#include "dryer.h"
#include "laundry.h"
#include "washer.h"

//=====[Declaration of private defines]========================================

#define SAMPLESIZE 10
#define DETERGENTINLEVEL 0.8

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn gasSensor(D14);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool gasState;
bool gasOveride;
float gasValues[SAMPLESIZE];

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void gasInit() {
  gasState = false;
  gasOveride = false;
}

bool gasStateRead() { return gasState; }

void gasStateOveride(bool state) {
  gasState = state;
  gasOveride = true;
}

void gasUpdate() {
  if (!gasOveride) {
    static int sensorReadingIndex = 0;
    float readingSum = 0;
    float readingAvg = 0;
    gasValues[sensorReadingIndex] = gasSensor.read();
    sensorReadingIndex = (sensorReadingIndex + 1) % SAMPLESIZE;

    for (int i = 0; i < SAMPLESIZE; i++) {
      readingSum += gasValues[i];
    }
    readingAvg = readingSum / float(SAMPLESIZE);
    gasState = readingAvg > DETERGENTINLEVEL;
  }
}

//=====[Implementations of private functions]==================================
