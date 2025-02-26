//=====[#include guards - begin]===============================================

#ifndef _ALARM_H_
#define _ALARM_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void alarmInit();
bool alarmStateRead();
void alarmStateWrite( bool state );
void alarmUpdate( int strobeTime );

//=====[#include guards - end]=================================================

#endif // 