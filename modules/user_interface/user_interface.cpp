//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "LED.h"
#include "user_interface.h"
#include "gas_sensor.h"

//=====[Declaration of private defines]========================================

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

DigitalIn gasOver(D15);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool washerButtonState;
bool dryerButtonState;
int washerDebounceTime;
int dryerDebounceTime;
bool hasSelected = false;

bool WdoorClosed;
bool DdoorClosed;

//=====[Declarations (prototypes) of private functions]========================

void washerSelect();
void dryerSelect();

//=====[Implementations of public functions]===================================

void userInterfaceInit() {
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
    if (WdoorClosed && hasSelected && washerStart == ON) {
        washerButtonState = true;
    }
    return washerButtonState;
}

bool getDryerButtonState() {
    if (DdoorClosed && hasSelected && dryerStart == ON) {
    dryerButtonState = true;
  }
    return dryerButtonState;
}

bool getWasherStart() {
    return washerStart == ON;
}

bool getDryerStart() {
    return dryerStart == ON;
}

void setWDoorClosedBool(bool state) {
    WdoorClosed = state;
}

void setDDoorClosedBool(bool state) {
    DdoorClosed = state;
}

bool getHasSelected() {
    return hasSelected;
}

//=====[Implementations of private functions]==================================

void washerSelect() {
  if (washerHot == ON) {
    setWasherHotOn();
    hasSelected = true;
  }
  if (washerWarm == ON) {
    setWasherWarmOn();
    hasSelected = true;
  }
  if (washerCold == ON) {
    setWasherColdOn();
    hasSelected = true;
  }

  if (gasOver == ON) {
    gasStateOveride(true);
  }
}

void startOn() {
    WstartLEDon();
}

void dryerSelect() {
  if (dryerHigh == ON) {
    setDryerHighOn();
    hasSelected = true;
  }
  if (dryerLow == ON) {
    setDryerLowOn();
    hasSelected = true;
  }
  if (dryerOff == ON) {
    setDryerOffOn();
    hasSelected = true;
  }
}