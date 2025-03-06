//=====[#include guards - begin]===============================================

#ifndef _WASHER_DISPLAY_H_
#define _WASHER_DISPLAY_H_

#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void displayInit();
 
void displayCharPositionWrite( uint8_t charPositionX, uint8_t charPositionY );

void displayStringWrite( const char * str );

//=====[#include guards - end]=================================================

#endif // _DISPLAY_H_