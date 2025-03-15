//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "motor.h"

//=====[Declaration of private defines]========================================

#define MOTOR_UPDATE_TIME 3

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalInOut washerMotorM1Pin(PF_2);
DigitalInOut washerMotorM2Pin(PH_1);   
DigitalInOut dryerMotorM1Pin( );
DigitalInOut dryerMotorM2Pin( );

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

motorState_t washerState;
motorState_t dryerState;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void motorControlInit() {
  washerMotorM1Pin.mode(OpenDrain);
  washerMotorM2Pin.mode(OpenDrain);
  dryerMotorM1Pin.mode(OpenDrain);
  dryerMotorM2Pin.mode(OpenDrain);


  washerMotorM1Pin.input();
  washerMotorM2Pin.input();
  dryerMotorM1Pin.input();
  dryerMotorM2Pin.input();

  washerState = STOPPED;
  dryerState = STOPPED;
}

motorState_t washerStateRead() { return washerState; }
motorState_t dryerStateRead() { return dryerState; }

void washerMotorWrite(motorState_t direction) { washerState = direction; }
void dryerMotorWrite(motorState_t direction) { dryerState = direction; }

void washerMotorUpdate() {
  static int motorUpdateCounter = 0;

  motorUpdateCounter++;

  if (motorUpdateCounter > MOTOR_UPDATE_TIME) {

    motorUpdateCounter = 0;

    switch (washerState) {
    case RUNNING:
      washerMotorM1Pin.output();
      washerMotorM2Pin.input();
      break;
    case STOPPED:
    default:
      washerMotorM1Pin.input();
      washerMotorM2Pin.input();
      break;
    }
  }
}

void dryerMotorUpdate() {
  static int motorUpdateCounter = 0;

  motorUpdateCounter++;

  if (motorUpdateCounter > MOTOR_UPDATE_TIME) {

    motorUpdateCounter = 0;

    switch (dryerState) {
    case RUNNING:
      dryerMotorM1Pin.output();
      dryerMotorM2Pin.input();
      break;
    case STOPPED:
    default:
      dryerMotorM1Pin.input();
      dryerMotorM2Pin.input();
      break;
    }
  }
}

//=====[Implementations of private functions]==================================
