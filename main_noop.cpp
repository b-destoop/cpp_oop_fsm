#include <iostream>

enum class TState {
    on, off, broken
};

class FSM {
private:
    TState curr_state = TState::off;
    int voltage = 0;
public:
    void update();

    void set_voltage(int voltage) { this->voltage = voltage; };
};

void FSM::update() {
    TState next_state = curr_state;
    switch (curr_state) {
        case TState::on:
            if (voltage > 240)
                next_state = TState::broken;
            else if (voltage < 240)
                next_state = TState::off;
            break;
        case TState::off:
            if (voltage > 240)
                next_state = TState::broken;
            else if (voltage == 240)
                next_state = TState::on;
            break;
        case TState::broken:
            next_state = TState::broken;
            break;
    }

    curr_state = next_state;

    switch (curr_state) {
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
}

int main() {
    FSM bulb;

    bulb.update();

    bulb.set_voltage(240);
    bulb.update(); // on
    bulb.update(); // still on

    bulb.set_voltage(0);
    bulb.update(); // off

    bulb.set_voltage(9001);
    bulb.update(); // broken

    bulb.set_voltage(0);
    bulb.update(); // still broken


    bulb.set_voltage(240);
    bulb.update(); // still broken
}
