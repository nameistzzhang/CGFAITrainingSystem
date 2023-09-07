# include "Actuator.h"

# include <iostream>



/// @brief The constructor of `RafaleActuator`
/// @param _repo The input of the target repo
RafaleActuator::RafaleActuator(Repo* _repo) {
    repo = _repo;
}

/// @brief The actuate function for `RafaleActuator`
void RafaleActuator::actuate () {
    std::cout << "actuator actuate\n";

    // TODO
}