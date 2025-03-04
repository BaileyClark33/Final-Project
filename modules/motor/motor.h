//=====[#include guards - begin]===============================================

#ifndef _MOTOR_H_
#define _MOTOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    RUNNING,
    STOPPED
} motorState_t;

//=====[Declarations (prototypes) of public functions]=========================

void motorControlInit();
void washerMotorWrite( motorState_t direction );
void dryerMotorWrite( motorState_t direction );

motorState_t washerStateRead();
motorState_t dryerStateRead();

void washerMotorUpdate();
void dryerMotorUpdate();

//=====[#include guards - end]=================================================

#endif // _MOTOR_H_