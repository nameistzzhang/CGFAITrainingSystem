# include "Actuator.h"

# include <iostream>



/// @brief The constructor of `Actuator`
Actuator::Actuator() {
    repo = nullptr;
}

/// @brief The destructor of `Actuator`
Actuator::~Actuator() {
    if (repo != nullptr) {
        repo = nullptr;
    }
}