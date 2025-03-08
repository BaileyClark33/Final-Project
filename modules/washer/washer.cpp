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
#define ALARMTIME 10000

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
  displayCharPositionWrite(0, 0);
  displayStringWrite("Hello: Put in");
  displayCharPositionWrite(0, 1);
  displayStringWrite("Detergent");
}

void washerUpdate() {
  if (!callRunning) {
    if (!testDicipline) {
      gasUpdate();
      if (gasStateRead()) {
        if (!running) {
          displayCharPositionWrite(0, 0);
          displayStringWrite("Now Select Mode");
          displayCharPositionWrite(0, 1);
          displayStringWrite("and Close Door");
          userInterfaceUpdate();
          WsensorUpdate();
        }
        if (washerDoorClosed()) {
          setWDoorClosedBool(true);
        } else {
          setWDoorClosedBool(false);
        }
        if (getHasSelected() && washerDoorClosed() && getWasherButtonState()) {
          test = ON;
          if (!setup) {
            startOn();
            washerMotorWrite(RUNNING);
            timer = STARTTIME;
            setup = true;
            servoLock();
          }
          callRunning = true;
        } else if (getWasherStart()) {
          displayInit();
          displayCharPositionWrite(0, 0);
          displayStringWrite("Select Mode and");
          displayCharPositionWrite(0, 1);
          displayStringWrite("Close Door");
        }
      } else if (getWasherStart()) {
        displayInit();
        displayCharPositionWrite(0, 0);
        displayStringWrite("Need Detergent");
        displayCharPositionWrite(0, 1);
        displayStringWrite("or Overide");
      }
    } else {
        if (!alarmSetup) {
          washerMotorWrite(STOPPED);
          timer = ALARMTIME;
          alarmSetup = true;
          servoUnlock();
        }
        callDicipline = true;
    }
  } else if (callDicipline) {
    washerDicipline();
  } else if (callRunning) {
    washerRunning();
  } else if (soundAlarm) {
        displayInit();
        displayCharPositionWrite(0, 0);
        displayStringWrite("You Failed!");
        displayCharPositionWrite(0, 1);
        displayStringWrite("Alarm On!");
        alarmStateWrite(true);
        alarmUpdate(1000);
      }
}

//=====[Implementations of private functions]==================================

void washerDicipline() {
  displayTime(false);
  if (timer < 0) {
    soundAlarm = true;
    washerMotorWrite(STOPPED);
    callDicipline = false;
  } else {
    timer -= SYSTEM_TIME_INCREMENT_MS + 90;
  }
  washerMotorUpdate();
}

void washerRunning() {
  running = true;
  displayTime(true);
  if (timer < 0) {
    testDicipline = true;
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
    displayCharPositionWrite(7, 1);
    displayStringWrite("Washing");
  } else {
      displayCharPositionWrite(7, 1);
    displayStringWrite("Discipline");
  }
}