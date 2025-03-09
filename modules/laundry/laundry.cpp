//=====[Libraries]=============================================================

#include "laundry.h"
#include "washer.h"
#include "dryer.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool washerMode = true;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void laundryInit() {
    washerInit();
    //dryerInit();
}

void laundryUpdate() {
    if (washerMode) {
    washerUpdate();
    } else {
    //dryerUpdate();
    }
    washerMode = !getWasherSuccess();
}

//=====[Implementations of private functions]==================================
