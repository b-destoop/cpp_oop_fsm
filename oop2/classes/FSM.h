//
// Created by bert on 18/06/24.
//

#ifndef FSM_OOP_FSM_H
#define FSM_OOP_FSM_H

#include <iostream>
#include <vector>
#include "../TStateTypes.h"
#include "State.h"


class FSM {
private:
    State *currState;
    int voltage_rating = 240;
    std::vector<State *> states; // keep track to be able to dealloc
public:
    int voltage = 0;

    explicit FSM() {
        State *on = new State{TState::on, this};
        State *off = new State{TState::off, this};
        State *broken = new State{TState::broken, this};

        on->addTransition(off, &FSM::on_to_off);
        on->addTransition(broken, &FSM::to_broken);
        off->addTransition(on, &FSM::off_to_on);
        off->addTransition(broken, &FSM::to_broken);

        currState = on;
    }

    // transition conditions
    bool on_to_off() {
        return voltage == 0;
    }

    bool off_to_on() {
        return voltage == voltage_rating;
    }

    bool to_broken() {
        return voltage > voltage_rating;
    }

    // some more functions

    virtual ~FSM() {
        delete currState;
        for (State *state: states) {
            delete state;
        }
    }

    void update() {
        State *new_state = currState->update();
        if (new_state != currState) {
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
