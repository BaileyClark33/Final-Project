//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "laundry.h"

//=====[Main function, the program entry point after power on or reset]========

int main() {
    laundryInit();
    while (true) {
        laundryUpdate();
        delay(10);
    }
}