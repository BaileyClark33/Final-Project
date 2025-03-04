//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "LED.h"
#include "user_interface.h"
#include "gas_sensor.h"

//=====[Declaration of private defines]========================================

#define DEBOUNCETIME 10
#define TIMEINCREMENT 1

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn washerHot(/* ENTER NUCLEO PIN */);
DigitalIn washerWarm(/* ENTER NUCLEO PIN */);
DigitalIn washerCold(/* ENTER NUCLEO PIN */);
DigitalIn washerStart(/* ENTER NUCLEO PIN */);

DigitalIn dryerHigh(/* ENTER NUCLEO PIN */);
DigitalIn dryerLow(/* ENTER NUCLEO PIN */);
DigitalIn dryerOff(/* ENTER NUCLEO PIN */);
DigitalIn dryerStart(/* ENTER NUCLEO PIN */);

DigitalIn gasOveride(/* ENTER NUCLEO PIN */);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool washerButtonState;
bool dryerButtonState;
int washerDebounceTime;
int dryerDebounceTime;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void userInterfaceInit() {
    washerDebounceTime = 0;
    dryerDebounceTime = 0;
  washerLedInit();
  dryerLedInit();
}

void userInterfaceUpdate() {
  washerSelect();
  dryerSelect();
}

bool getWasherButtonState() {
    return washerButtonState;
}

bool getDryerButtonState() {
    return dryerButtonState;
}

//=====[Implementations of private functions]==================================

void washerSelect() {
  if (washerHot) {
    washerLedInit();
    setLEDon(washerHot);
  }
  if (washerWarm) {
    washerLedInit();
    setLEDon(washerWarm);
  }
  if (washerCold) {
    washerLedInit();
    setLEDon(washerCold);
  }

  if (washerStart) {
      washerDebounceTime += TIMEINCREMENT;
      if (washerDebounceTime > DEBOUNCETIME) {  
          washerButtonState = true;
          washerDebounceTime = 0;
      } else {
          washerButtonState = false;
      }
  }

  if (gasOveride) {
    gasOveride(true);
  }
}

void dryerSelect() {
  if (dryerHigh) {
    dryerLedInit();
    setLEDon(dryerHigh);
  }
  if (dryerLow) {
    dryerLedInit();
    setLEDon(dryerLow);
  }
  if (dryerOff) {
    dryerLedInit();
    setLEDon(dryerOff);
  }

  if (dryerStart) {
      dryerDebounceTime += TIMEINCREMENT;
    if (dryerDebounceTime > DEBOUNCETIME) {  
          dryerButtonState = true;
          dryerDebounceTime = 0
      } else {
          dryerButtonState = false;
      }
  }
}