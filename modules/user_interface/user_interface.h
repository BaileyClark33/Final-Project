//=====[#include guards - begin]===============================================

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void userInterfaceInit();
void userInterfaceUpdate();
bool getWasherButtonState();
bool getDryerButtonState();
bool getHasSelected(); 

//=====[#include guards - end]=================================================

#endif // _USER_INTERFACE_H_