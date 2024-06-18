#include <iostream>
#include "Bulb.h"


int main() {
    FSM bulb;

    bulb.update(); // off

    bulb.voltage = (240);
    bulb.update(); // on
    bulb.update(); // still on

    bulb.voltage = (0);
    bulb.update(); // off

    bulb.voltage = (9001);
    bulb.update(); // broken

    bulb.voltage = (0);
    bulb.update(); // still broken


    bulb.voltage = (240);
    bulb.update(); // still broken
}
