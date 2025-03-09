//=====[Libraries]=============================================================

#include "washer.h"
#include "alarm.h"
#include "arm_book_lib.h"
#include "gas_sensor.h"
#include "laundry.h"
#include "light_sensor.h"
#include "mbed.h"
#include "motor.h"
#include "servo.h"
#include "user_interface.h"
#include "washer_display.h"

//=====[Declaration of private defines]========================================

#define STARTTIME 60000
#define ALARMTIME 30000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uart(USBTX, USBRX, 115200);

//=====[Declaration of external public global variables]=======================

DigitalOut test(LED1);
DigitalOut blue(LED2);

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool setup = false;
static bool alarmSetup = false;
static bool testDicipline = false;
static bool soundAlarm = false;
static bool running = false;
bool callRunning = false;
bool callDicipline = false;
bool settingUp = true;
int timer = 0;

//=====[Declarations (prototypes) of private functions]========================

void washerRunning();
void washerDicipline();
void displayTime(bool washing);

//=====[Implementations of public functions]===================================

void washerInit() {
  test = OFF;
  blue = OFF;
  gasInit();
  alarmInit();
  servoInit();
  sensorInit();
  displayInit();
  userInterfaceInit();
  motorControlInit();
  displayInit();
}

void washerUpdate() {
  if (settingUp) {
    static bool hello = false;
    if (!hello) {
      displayCharPositionWrite(0, 0);
      displayStringWrite("Hello: Put in");
      displayCharPositionWrite(0, 1);
      displayStringWrite("Detergent");
      hello = true;
    }
    gasUpdate();
    gasButtonUpdate();
    if (gasStateRead()) {
      displayCharPositionWrite(0, 0);
      displayStringWrite("Now Select Mode");
      displayCharPositionWrite(0, 1);
      displayStringWrite("and Close Door");
      if (washerDoorClosed()) {
        setWDoorClosedBool(true);
      } else {
        setWDoorClosedBool(false);
      }
      userInterfaceUpdate();
      WsensorUpdate();
      if (getHasSelected() && washerDoorClosed() && getWasherButtonState()) {
        test = ON;
        callRunning = true;
        settingUp = false;
      }
    } else if (getWasherStart()) {
      displayInit();
      displayCharPositionWrite(0, 0);
      displayStringWrite("Need Detergent");
      displayCharPositionWrite(0, 1);
      displayStringWrite("or Overide");
    }
  } else if (callRunning) {
    if (!setup) {
      startOn();
      washerMotorWrite(RUNNING);
      servoLock();
      timer = STARTTIME;
      setup = true;
    }
    washerRunning();
  } else if (callDicipline) {
    if (!alarmSetup) {
      washerMotorWrite(STOPPED);
      servoUnlock();
      timer = ALARMTIME;
      alarmSetup = true;
    }
    washerDicipline();
  } else if (soundAlarm) {
    displayCharPositionWrite(0, 0);
    displayStringWrite("You Failed!");
    displayCharPositionWrite(0, 1);
    displayStringWrite("Alarm On!             ");
    alarmStateWrite(true);
    alarmUpdate(100);
  }
}

//=====[Implementations of private functions]==================================

void washerDicipline() {
  displayTime(false);
  if (timer < 0) {
    soundAlarm = true;
    callDicipline = false;
  } else {
    timer -= SYSTEM_TIME_INCREMENT_MS + 90;
  }
}

void washerRunning() {
  running = true;
  displayTime(true);
  if (timer < 0) {
    callDicipline = true;
    washerMotorWrite(STOPPED);
    callRunning = false;
  } else {
    timer -= SYSTEM_TIME_INCREMENT_MS + 90;
  }
  washerMotorUpdate();
}

void displayTime(bool washing) {
  char buffer[20];
  int minutes = timer / 60000;
  int seconds = (timer - (minutes * 60000)) / (1000);
  displayCharPositionWrite(0, 0);
  displayStringWrite("Time Remaining: ");
  displayCharPositionWrite(0, 1);
  if (minutes < 10) {
    displayStringWrite("0");
    displayCharPositionWrite(1, 1);
    sprintf(buffer, "%d", minutes);
    displayStringWrite(buffer);
  } else {
    sprintf(buffer, "%d", minutes);
    displayStringWrite(buffer);
  }
  displayCharPositionWrite(2, 1);
  displayStringWrite(":");
  displayCharPositionWrite(3, 1);
  if (seconds < 10) {
    displayStringWrite("0");
    displayCharPositionWrite(4, 1);
    sprintf(buffer, "%d", seconds);
    displayStringWrite(buffer);
  } else {
    sprintf(buffer, "%d", seconds);
    displayStringWrite(buffer);
  }

  if (washing) {
    displayCharPositionWrite(5, 1);
    displayStringWrite("   Washing");
  } else {
    displayCharPositionWrite(5, 1);
    displayStringWrite("   Testing");
  }
}