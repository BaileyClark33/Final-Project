//=====[Libraries]=============================================================

#include "dryer.h"
#include "dryer_display.h"
#include "alarm.h"
#include "light_sensor.h"
#include "user_interface.h"
#include "motor.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============
/*
DigitalOut test(LED1);
DigitalOut blue(LED2);

bool setup = false;
bool alarmSetup = false;
bool testDicipline = false;
bool soundAlarm = false;
bool running = false;
bool callRunning = false;
bool callDicipline = false;
bool settingUp = true;
bool successMode = false;
bool dryerTestSuccess = false;
int timer = 0;
*/

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void dryerInit() {
    /*
    test = OFF;
    blue = OFF;
    alarmInit();
    sensorInit();
    displayInit();
    userInterfaceInit();
    motorControlInit();
    */
}

void dryerUpdate() {
    /*
   if (settingUp) {
    static bool hello = false;
      displayCharPositionWrite(0, 0);
      displayStringWrite("Select Mode");
      displayCharPositionWrite(0, 1);
      displayStringWrite("and Close Door");
      if (dryerDoorClosed()) {
        setWDoorClosedBool(true);
      } else {
        setWDoorClosedBool(false);
      }
      userInterfaceUpdate();
      DsensorUpdate();
      if (getHasSelected() && dryerDoorClosed() && getDryerButtonState()) {
        callRunning = true;
        settingUp = false;
      }
  } else if (callRunning) {
    if (!setup) {
      startOn();
      dryerMotorWrite(RUNNING);
      servoLock();
      timer = STARTTIME;
      setup = true;
    }
    dryerRunning();
  } else if (callDicipline) {
    if (!alarmSetup) {
      dryerMotorWrite(STOPPED);
      timer = ALARMTIME;
      alarmSetup = true;
    }
    dryerDicipline();
  } else if (soundAlarm) {
    displayCharPositionWrite(0, 0);
    displayStringWrite("You Failed!       ");
    displayCharPositionWrite(0, 1);
    displayStringWrite("Alarm On!             ");
    alarmStateWrite(true);
    alarmUpdate(100);
  } else if (successMode) {
    displayCharPositionWrite(0, 0);
    displayStringWrite("You Got Back!         ");
    displayCharPositionWrite(0, 1);
    displayStringWrite("Success!              ");
    dryerTestSuccess = true;
  }
  */
}

//=====[Implementations of private functions]==================================
