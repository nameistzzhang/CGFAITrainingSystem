# include "Controller.h"

# include <iostream>



/// @brief The constructor of `Controller`
Controller::Controller() {
    repo = nullptr;
}

/// @brief The destructor of `Controller`
Controller::~Controller() {
    if (repo != nullptr) {
        repo = nullptr;
    }
}