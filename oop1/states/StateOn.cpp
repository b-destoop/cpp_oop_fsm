//
// Created by bert on 18/06/24.
//

#include "StateOn.h"
#include "../Bulb.h"
#include "StateOff.h"
#include "StateBroken.h"

State *StateOn::update(FSM *bulb) {
    if (bulb->voltage > 240) {
        return new StateBroken();
    }
    if (bulb->voltage == 0) {
        return new StateOff();
    }
    return this;
}
