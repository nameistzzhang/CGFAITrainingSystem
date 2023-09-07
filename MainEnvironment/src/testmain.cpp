# include "./Repo/Repo.h"
# include "./Sensor/Sensor.h"
# include "./Actuator/Actuator.h"
# include "./Controller/Controller.h"
# include "./Entity/Entity.h"
# include "./Info/Info.h"
# include "./EntityList/EntityList.h"

# include <iostream>

int main () {
    Entity* entity1;
    entity1 = new Rafale();

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

    entity1->repo->main_repo.self_info = entity_info;

    entity_info.name = "Red Two";

    Entity* entity2;

    entity2 = new Rafale();

    entity2->repo->main_repo.self_info = entity_info;

    entity_info.name = "Red Three";

    Entity* entity3;

    entity3 = new Rafale();

    entity3->repo->main_repo.self_info = entity_info;



    EntityList* entity_list_instance = EntityList::createEntityListInstance();

    entity_list_instance->addEntity(entity1);
    entity_list_instance->addEntity(entity2);
    entity_list_instance->addEntity(entity3);

    Entity* tem_entity = entity_list_instance->at(1);

    std::cout << tem_entity->repo->main_repo.self_info.name << std::endl;

    tem_entity = entity_list_instance->at("Red Three");

    std::cout << tem_entity->repo->main_repo.self_info.name << std::endl;

    entity_list_instance->deleteEntity(1);

    tem_entity = entity_list_instance->at(1);

    std::cout << tem_entity->repo->main_repo.self_info.name << std::endl;

    entity2 = new Rafale();

    entity2->repo->main_repo.self_info.name = "Red Two";

    entity_list_instance->addEntity(entity2);
    entity_list_instance->deleteEntity("Red One");

    tem_entity = entity_list_instance->at(1);

    std::cout << tem_entity->repo->main_repo.self_info.name << std::endl;

    entity_list_instance->clearList();
}