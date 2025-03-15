//=====[Libraries]=============================================================

#include "LED.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

DigitalOut washerHotLight(PF_4);
DigitalOut washerWarmLight(PB_6);
DigitalOut washerColdLight(PB_2);
DigitalOut washerStartLight(PD_13);
DigitalOut dryerHighLight();
DigitalOut dryerLowLight();
DigitalOut dryerOffLight();

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
    washerStartLight = OFF;
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
    washerStartLight = ON;
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
