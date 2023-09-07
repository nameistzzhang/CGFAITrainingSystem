# include "./Repo/Repo.h"
# include "./Sensor/Sensor.h"
# include "./Actuator/Actuator.h"
# include "./Controller/Controller.h"
# include "./Entity/Entity.h"
# include "./Info/Info.h"

# include <iostream>

int main () {
    Entity* entity;
    entity = new Rafale();

    SelfInfo entity_info;
    entity_info.name = "Red One";
    entity_info.type = "Rafale";
    entity_info.longitude = 131;
    entity_info.latitude = 32;
    entity_info.altitude = 10000;
    entity_info.pitch = 10;
    entity_info.roll = 10;
    entity_info.direction = 10;
    entity_info.speed = 200;
    entity_info.weaponlist = {"RattleSnake", "RattleSnake"};
    entity_info.fuel = 1;

    entity->repo->main_repo.self_info = entity_info;

    std::cout << entity->repo->main_repo.self_info.name << std::endl;

    delete entity;
}