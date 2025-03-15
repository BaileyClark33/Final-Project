//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "alarm.h"
#include "dryer.h"
#include "laundry.h"
#include "washer.h"

//=====[Declaration of private defines]========================================

#define SAMPLESIZE 10
#define DETERGENTINLEVEL 7

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn gasSensor(PB_11);

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
  for (int i = 0; i < SAMPLESIZE; i++) {
      gasValues[i] = false;
  }
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
    gasValues[sensorReadingIndex] = gasSensor;
    sensorReadingIndex = (sensorReadingIndex + 1) % SAMPLESIZE;

    int sampleCount = 0;

    for (int i = 0; i < SAMPLESIZE; i++) {
      if (gasValues[i]) {
          sampleCount++;
      }
    }
    gasState = (sampleCount >= DETERGENTINLEVEL);
  }
}

//=====[Implementations of private functions]==================================
