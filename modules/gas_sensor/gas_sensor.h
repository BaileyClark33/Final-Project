//=====[#include guards - begin]===============================================

#ifndef _GAS_SENSOR_H_
#define _GAS_SENSOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void gasInit();
void gasUpdate();
void gasStateOveride(bool state);
bool gasStateRead();

//=====[#include guards - end]=================================================

#endif // 