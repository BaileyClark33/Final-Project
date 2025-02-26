//=====[#include guards - begin]===============================================

#ifndef _MOTOR_H_
#define _MOTOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    RUNNING,
    STOPPED
} washerState_t;

typedef enum {
    RUNNING,
    STOPPED
} dryerState_t;

//=====[Declarations (prototypes) of public functions]=========================

void motorControlInit();
void washerMotorWrite( washerState_t direction );
void dryerMotorWrite( dryerState_t direction );

washerState_t washerStateRead();
dryerState_t dryerStateRead();

void washerMotorUpdate();
void dryerMotorUpdate();

//=====[#include guards - end]=================================================

#endif // _MOTOR_H_