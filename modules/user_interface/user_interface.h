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
void startOn();
void startOff();
void setWDoorClosedBool(bool state);
void setDDoorClosedBool(bool state);
bool getWasherStart();
bool getDryerStart();
void gasButtonUpdate();

//=====[#include guards - end]=================================================

#endif // _USER_INTERFACE_H_
