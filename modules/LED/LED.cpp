//=====[Libraries]=============================================================

#include "LED.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

DigitalOut washerHot(PE_15);
DigitalOut washerWarm(PB_10);
DigitalOut washerCold(PB_11);
DigitalOut dryerHigh(PA_0);
DigitalOut dryerLow(PB_0);
DigitalOut dryerOff(PE_0);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void washerLedInit() {
    washerHot = OFF;
    washerWarm = OFF;
    washerCold = OFF;
}

void dryerLedInit() {
    dryerHigh = OFF;
    dryerLow = OFF;
    dryerOff = OFF;
}

void setWasherWarmOn() {
    washerLedInit();
    washerWarm = ON;
}

void setWasherHotOn() {
    washerLedInit();
    washerHot = ON;
}

void setWasherColdOn() {
    washerLedInit();
    washerCold = ON;
}

void setDryerHighOn() {
    dryerLedInit();
    dryerHigh = ON;
}

void setDryerLowOn() {
    dryerLedInit();
    dryerLow = ON;
}

void setDryerOffOn() {
    dryerLedInit();
    dryerOff = ON;
}


//=====[Implementations of private functions]==================================
