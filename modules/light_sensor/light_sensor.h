//=====[#include guards - begin]===============================================

#ifndef _LIGHT_SENSOR_H_
#define _LIGHT_SENSOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void sensorInit();
bool washerDoorClosed();
bool dryerDoorClosed();
void WsensorUpdate();
void DsensorUpdate();

//=====[#include guards - end]=================================================

#endif // 