# include "Repo.h"

# include <iostream>



/// @brief constructor of `Repo`
Repo::Repo() {
    action_repo = nullptr;
}

/// @brief constructor of `RafaleRepo`
RafaleRepo::RafaleRepo() {
    action_repo = new RafaleActionRepo();
}

/// @brief destructor of `RafaleRepo`
RafaleRepo::~RafaleRepo() {
    if (action_repo != nullptr) {
        delete action_repo;
        action_repo = nullptr;
    }
}