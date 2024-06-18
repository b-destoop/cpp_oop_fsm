//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_STATEOFF_H
#define FSM_OOP_STATEOFF_H


#include "State.h"

class StateOff : public State {
public:
    explicit StateOff() : State(TState::off, nullptr) {}

    State *update(FSM *bulb) override;
};


#endif //FSM_OOP_STATEOFF_H
