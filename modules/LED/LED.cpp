//=====[Libraries]=============================================================

#include "LED.h"
#include "mbed.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

DigitalOut washerHot( /* ENTER NUCLEO PIN */ );
DigitalOut washerWarm( /* ENTER NUCLEO PIN */ );
DigitalOut washerCold( /* ENTER NUCLEO PIN */ );
DigitalOut dryerHigh( /* ENTER NUCLEO PIN */ );
DigitalOut dryerLow( /* ENTER NUCLEO PIN */ );
DigitalOut dryerOff( /* ENTER NUCLEO PIN */ );

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void ledInit() {

}

void setLEDon(DigitalOut light) {
    light = On;
}

//=====[Implementations of private functions]==================================
