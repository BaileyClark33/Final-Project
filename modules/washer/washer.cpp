//=====[Libraries]=============================================================

#include "washer.h"
#include "alarm.h"
#include "gas_sensor.h"
#include "light_sensor.h"
#include "motor.h"
#include "servo.h"
#include "user_interface.h"
#include "washer_display.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void washerRunning();

//=====[Implementations of public functions]===================================

void washerInit() {
  gasInit();
  alarmInit();
  servoInit();
  sensorInit();
  userInterfaceInit();
  motorControlInit();
}

void washerUpdate() {
  gasUpdate();
  if (gasStateRead()) {
      washerSelect();
      sensorUpdate();
      if (washerDoorClosed() && getWasherButtonState()) {
          washerRunning();
      }
  }
}

//=====[Implementations of private functions]==================================

void washerRunning() {

}