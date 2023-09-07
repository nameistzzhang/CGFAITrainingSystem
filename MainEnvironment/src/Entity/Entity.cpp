# include "Entity.h"

# include <iostream>

/// @brief The constructor of `Entity`
Entity::Entity() {
    repo = nullptr;
    controller = nullptr;
    sensor_list.clear();
    actuator_list.clear();
}