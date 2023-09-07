# include "Entity.h"
# include "../Repo/Repo.h"
# include "../Sensor/Sensor.h"
# include "../Controller/Controller.h"
# include "../Actuator/Actuator.h"

# include <iostream>

/// @brief The constructor of `Rafale`
Rafale::Rafale() {
    repo = new RafaleRepo();

    sensor_list.push_back(new AirBorneRadar(repo));

    actuator_list.push_back(new RafaleActuator(repo));

    controller = new RafaleController(repo);
}

/// @brief The destructor of `Rafale`
Rafale::~Rafale() {
    if (repo != nullptr) {
        delete repo;
        repo = nullptr;
    }

    if (controller != nullptr) {
        delete controller;
        controller = nullptr;
    }

    for (auto & sensor: sensor_list) {
        if (sensor != nullptr) {
            delete sensor;
            sensor = nullptr;
        }
    }
    std::vector<Sensor*>().swap(sensor_list);

    for (auto & actuator: actuator_list) {
        if (actuator != nullptr) {
            delete actuator;
            actuator = nullptr;
        }
    }
    std::vector<Actuator*>().swap(actuator_list);
}

/// @brief tick function of `Rafale`
void Rafale::tick() {
    std::cout << "tick\n";

    // TODO
}

/// @brief halfTick function of `Rafale`
void Rafale::halfTick() {
    std::cout << "half tick\n";

    // TODO
}