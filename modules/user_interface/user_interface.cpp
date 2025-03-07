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

DigitalIn washerHot(D12);
DigitalIn washerWarm(D11);
DigitalIn washerCold(D10);
DigitalIn washerStart(D13);

DigitalIn dryerHigh(PB_1);
DigitalIn dryerLow(PC_2);
DigitalIn dryerOff(PF_4);
DigitalIn dryerStart(PB_6);

DigitalIn gasOver(PB_2);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool washerButtonState;
bool dryerButtonState;
int washerDebounceTime;
int dryerDebounceTime;
static bool hasSelected = false;

//=====[Declarations (prototypes) of private functions]========================

void washerSelect();
void dryerSelect();

//=====[Implementations of public functions]===================================

void userInterfaceInit() {
  washerDebounceTime = 0;
  dryerDebounceTime = 0;
  washerLedInit();
  dryerLedInit();

  washerHot.mode(PullDown);
  washerWarm.mode(PullDown);
  washerCold.mode(PullDown);
  washerStart.mode(PullDown);

  dryerHigh.mode(PullDown);
  dryerLow.mode(PullDown);
  dryerOff.mode(PullDown);
  dryerStart.mode(PullDown);

  gasOver.mode(PullDown);
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

bool getHasSelected() {
    return hasSelected;
}

//=====[Implementations of private functions]==================================

void washerSelect() {
  if (washerHot) {
    setWasherHotOn();
    hasSelected = true;
  }
  if (washerWarm) {
    setWasherWarmOn();
    hasSelected = true;
  }
  if (washerCold) {
    setWasherColdOn();
    hasSelected = true;
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

  if (gasOver) {
    gasStateOveride(true);
  }
}

void startOn() {
    WstartLEDon();
}

void dryerSelect() {
  if (dryerHigh) {
    setDryerHighOn();
    hasSelected = true;
  }
  if (dryerLow) {
    setDryerLowOn();
    hasSelected = true;
  }
  if (dryerOff) {
    setDryerOffOn();
    hasSelected = true;
  }

  if (dryerStart) {
      dryerDebounceTime += TIMEINCREMENT;
    if (dryerDebounceTime > DEBOUNCETIME) {  
          dryerButtonState = true;
          dryerDebounceTime = 0;
      } else {
          dryerButtonState = false;
      }
  }
}