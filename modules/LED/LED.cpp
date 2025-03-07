//=====[Libraries]=============================================================

#include "LED.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

DigitalOut washerHotLight(PE_15);
DigitalOut washerWarmLight(PB_10);
DigitalOut washerColdLight(PB_11);
DigitalOut washerStart(PE_14);
DigitalOut dryerHighLight(PA_0);
DigitalOut dryerLowLight(PB_0);
DigitalOut dryerOffLight(PE_0);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void washerLedInit() {
    washerHotLight = OFF;
    washerWarmLight = OFF;
    washerColdLight = OFF;
}

void dryerLedInit() {
    dryerHighLight = OFF;
    dryerLowLight = OFF;
    dryerOffLight = OFF;
}

void setWasherWarmOn() {
    washerLedInit();
    washerWarmLight = ON;
}

void setWasherHotOn() {
    washerLedInit();
    washerHotLight = ON;
}

void setWasherColdOn() {
    washerLedInit();
    washerColdLight = ON;
}

void WstartLEDon() {
    washerStart = On;
}

void setDryerHighOn() {
    dryerLedInit();
    dryerHighLight = ON;
}

void setDryerLowOn() {
    dryerLedInit();
    dryerLowLight = ON;
}

void setDryerOffOn() {
    dryerLedInit();
    dryerOffLight = ON;
}


//=====[Implementations of private functions]==================================
