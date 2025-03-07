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

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool setup = false;
static bool alarmSetup = false;
static bool testDicipline = false;
static bool soundAlarm = false;
static bool running = false;
int timer = 0;

//=====[Declarations (prototypes) of private functions]========================

void washerRunning();
void washerDicipline();
void displayTime();

//=====[Implementations of public functions]===================================

void washerInit() {
  test = OFF;
  gasInit();
  alarmInit();
  servoInit();
  sensorInit();
  displayInit();
  userInterfaceInit();
  motorControlInit();
  displayInit();
  displayCharPositionWrite(0, 0);
  displayStringWrite("Start");
  displayCharPositionWrite(0, 1);
  displayStringWrite("Begin");
}

void washerUpdate() {
  if (!testDicipline) {
    gasUpdate();
    if (gasStateRead()) {
      if (!running) {
        userInterfaceUpdate();
        sensorUpdate();
      }
      if (getHasSelected() && washerDoorClosed() && getWasherButtonState()) {
        if (!setup) {
          startOn();
          servoLock();
          washerMotorWrite(RUNNING);
          timer = STARTTIME;
          setup = true;
        }
        washerRunning();
      } else if (!getWasherButtonState()) {
        displayInit();
        displayCharPositionWrite(0, 0);
        displayStringWrite("Can't start yet:");
        displayCharPositionWrite(0, 1);
        displayStringWrite("Select or close Door");
      }
    } else {
      if (!getWasherButtonState()) {
        displayInit();
        displayCharPositionWrite(0, 0);
        displayStringWrite("Can't start yet:");
        displayCharPositionWrite(0, 1);
        displayStringWrite("Select or close Door");
      }
    }
  } else {
    if (!soundAlarm) {
      if (!alarmSetup) {
        servoUnlock();
        washerMotorWrite(STOPPED);
        timer = ALARMTIME;
        alarmSetup = true;
      }
      washerDicipline();
    } else {
      displayInit();
      displayCharPositionWrite(0, 0);
      displayStringWrite("You Failed!");
      displayCharPositionWrite(0, 1);
      displayStringWrite("Alarm On!");
      alarmStateWrite(true);
      alarmUpdate(1000);
    }
  }
}

//=====[Implementations of private functions]==================================

void washerDicipline() {
  displayTime();
  if (timer < 0) {
    soundAlarm = true;
    washerMotorWrite(STOPPED);
  } else {
    timer -= SYSTEM_TIME_INCREMENT_MS;
  }
  washerMotorUpdate();
}

void washerRunning() {
  running = true;
  displayTime();
  if (timer < 0) {
    testDicipline = true;
    washerMotorWrite(STOPPED);
  } else {
    timer -= SYSTEM_TIME_INCREMENT_MS;
  }
  washerMotorUpdate();
}

void displayTime() {
  char buffer[20];
  int minutes = timer / 60000;
  int seconds = timer / 1000 - minutes * 60;
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
  if (seconds < 10) {
    displayStringWrite("0");
    displayCharPositionWrite(3, 1);
    sprintf(buffer, "%d", seconds);
    displayStringWrite(buffer);
  } else {
    sprintf(buffer, "%d", minutes);
    displayStringWrite(buffer);
  }
}