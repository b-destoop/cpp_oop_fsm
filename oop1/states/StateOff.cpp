//
// Created by bert on 18/06/24.
//

#include "StateOff.h"
#include "../Bulb.h"

State *StateOff::update(FSM *bulb) {
    if(bulb->voltage > 240){
        return new StateBroken;
    }
    else if(bulb->voltage == 240){
        return new StateOn;
    }
    return this;
}
