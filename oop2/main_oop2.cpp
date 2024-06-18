#include <iostream>
#include <functional>
#include "classes/FSM.h"

/*
 * HOW TO STORE A REFERENCE TO A FUNCTION
 *
    Bulb *bulb;
    void (Bulb::*func_ptr)(int) = &Bulb::updateVoltage;

    (*bulb.*func_ptr)(3);
    std::cout << "bulb voltage: " << bulb->voltage;
 */

int main() {
    FSM *bulb = new FSM;

    bulb->update(); // off

    bulb->voltage = (240);
    bulb->update(); // on
    bulb->update(); // still on

    bulb->voltage = (0);
    bulb->update(); // off

    bulb->voltage = (9001);
    bulb->update(); // broken

    bulb->voltage = (0);
    bulb->update(); // still broken


    bulb->voltage = (240);
    bulb->update(); // still broken

    delete bulb;
}
