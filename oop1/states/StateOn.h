//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_STATEON_H
#define FSM_OOP_STATEON_H


#include "State.h"
#include "../TStateTypes.h"


class StateOn : public State {
public:
    explicit StateOn() : State(TState::on, nullptr) {}


    State *update(FSM *bulb) override;
};


#endif //FSM_OOP_STATEON_H
