//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_STATEBROKEN_H
#define FSM_OOP_STATEBROKEN_H


#include "State.h"

class StateBroken : public State {
public:
    explicit StateBroken() : State(TState::broken, nullptr) {}

    State *update(FSM *bulb) {
        return this;
    };
};


#endif //FSM_OOP_STATEBROKEN_H
