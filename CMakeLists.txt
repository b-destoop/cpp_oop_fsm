cmake_minimum_required(VERSION 3.28)
project(FSM_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(FSM_NOOP main_noop.cpp)
add_executable(FSM_OOP1 oop1/main_oop1.cpp
        oop1/Bulb.cpp
        oop1/Bulb.h
        oop1/states/State.h
        oop1/TStateTypes.h
        oop1/states/StateOn.cpp
        oop1/states/StateOn.h
        oop1/states/StateOff.cpp
        oop1/states/StateOff.h
        oop1/states/StateBroken.cpp
        oop1/states/StateBroken.h)

add_executable(FSM_OOP2 oop2/main_oop2.cpp
        oop2/classes/FSM.cpp
        oop2/classes/FSM.h
        oop2/classes/State.h
        oop2/TStateTypes.h
        oop2/classes/Transition.cpp
        oop2/classes/Transition.h
        oop2/classes/State.cpp
)
