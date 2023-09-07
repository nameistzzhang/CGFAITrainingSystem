# include "../EntityList/EntityList.h"
# include "../Repo/Repo.h"
# include "Sensor.h"

# include <iostream>



/// @brief The constructor of the `Sensor`
Sensor::Sensor() {
    repo = nullptr;
    entity_list_instance = EntityList::createEntityListInstance();
}

/// @brief The destructor of the `Sensor`
Sensor::~Sensor() {
    if (repo != nullptr) {
        repo = nullptr;
    }
}