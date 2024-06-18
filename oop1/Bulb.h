//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_FSM_H
#define FSM_OOP_BULB_H

#include <iostream>
#include "TStateTypes.h"
#include "states/State.h"
#include "states/StateOn.h"
#include "states/StateOff.h"
#include "states/StateBroken.h"


class FSM {
private:
    State *currState;
public:
    int voltage = 0;

    explicit FSM() {
        currState = new StateOn;
    }

    void update() {
        State* new_state = currState->update(this);
        if(new_state != currState){
            delete currState;
            currState = new_state;
        }

        switch (currState->getState()) {
            case TState::on:
                std::cout << "currently on" << std::endl;
                break;
            case TState::off:
                std::cout << "currently off" << std::endl;
                break;
            case TState::broken:
                std::cout << "lamp is broken" << std::endl;
                break;
        }
    };
};


#endif //FSM_OOP_FSM_H
