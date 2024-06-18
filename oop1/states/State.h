//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_STATE_H
#define FSM_OOP_STATE_H

#include "../TStateTypes.h"

class FSM;

class State {
protected:
    TState state;
public:
    explicit State(TState state, FSM *fsm) { this->state = state; }

    TState getState() { return state; };

    virtual State *update(FSM *bulb) = 0;

};


#endif //FSM_OOP_STATE_H
