# include "Controller.h"

# include <iostream>



/// @brief The constructor of `RafaleController`
/// @param _repo The input pointer of `Repo`
RafaleController::RafaleController(Repo* _repo) {
    repo = _repo;
}

/// @brief The control method of `RafaleController`
void RafaleController::control() {
    std::cout << "Controller control\n";

    // TODO
}