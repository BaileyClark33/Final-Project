//=====[Libraries]=============================================================

#include "Washer_Dryer.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    washerDryerInit();
    while (true) {
        washerDryerUpdate();
    }
}
