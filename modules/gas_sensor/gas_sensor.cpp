//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "alarm.h"
#include "dryer.h"
#include "laundry.h"
#include "washer.h"

//=====[Declaration of private defines]========================================

#define SAMPLESIZE 10
#define DETERGENTINLEVEL 0.5

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn gasSensor(PE_0);

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
    float temp = gasSensor.read();
    for (int i = SAMPLESIZE - 1; i >= 0; i--) {
      if (i == 0) {
        gasValues[i] = temp;
      } else {
        gasValues[i] = gasValues[i - 1];
      }
    }

    int total;
    for (int i = 0; i < SAMPLESIZE; i++) {
      total += gasValues[i];
    }

    int average = total / SAMPLESIZE;
    if (average > DETERGENTINLEVEL) {
      gasState = true;
      gasOveride = true;
    } else {
      gasState = false;
    }
  }
}

//=====[Implementations of private functions]==================================
