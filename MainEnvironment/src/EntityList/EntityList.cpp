# include "EntityList.h"
# include "../Entity/Entity.h"
# include "../Repo/Repo.h"
# include "../Info/Types.h"

// Put the entity_list_obj into nullptr

EntityList* EntityList::entity_list_obj = nullptr;

// Put the delete_entity_list_instance into the static variable so that it can be constructed

EntityList::DeleteEntityListInstance EntityList::delete_entity_list_instance;

/// @brief The singleton instance of the `EntityList`
/// @return The pointer to the `EntityList` instance
EntityList* EntityList::createEntityListInstance() {
    if (entity_list_obj == nullptr) {
        entity_list_obj = new EntityList();
    }
    return entity_list_obj;
}

/// @brief The clearList method of the `EntityList`
void EntityList::clearList() {

    // clear the entity_list

    for (auto & i : entity_list) {

        // if the pointer is not nullptr, delete it

        if (i != nullptr) {
            delete i;
            i = nullptr;
        }
    }

    // swap the list

    std::vector<Entity*>().swap(entity_list);

    // clear the entity_map

    entity_map.clear();

    // swap the map

    std::unordered_map<Name, int>().swap(entity_map);
}

/// @brief The at method of the `EntityList`
/// @param _index the index of the Entity* object
/// @return the pointer to the Entity object
Entity* EntityList::at(int _index) {
    return entity_list[_index];
}

/// @brief The at method of the `EntityList`
/// @param _name the name of the Entity* object
/// @return the pointer to the Entity object
Entity* EntityList::at(Name _name) {
    return entity_list[entity_map[_name]];
}

/// @brief The deleteEntity method of the `EntityList`
/// @param _index the index of the Entity* object
void EntityList::deleteEntity(int _index) {

    // Copy the pointer

    Entity* target_ptr = entity_list[_index];

    // update the map

    Name name = target_ptr->repo->main_repo.self_info.name;

    for (auto & i : entity_map) {
        if (i.second > _index) {
            i.second--;
        }
    }

    entity_map.erase(name);

    // update the vector

    entity_list.erase(entity_list.begin() + _index);

    // release the memory

    delete target_ptr;
}

/// @brief The deleteEntity method of the `EntityList`
/// @param _name the name of the Entity* object
void EntityList::deleteEntity(Name _name) {

    // Copy the pointer

    Entity* target_ptr = entity_list[entity_map[_name]];

    // Update the map

    for (auto & i : entity_map) {
        if (i.second > entity_map[_name]) {
            i.second--;
        }
    }

    entity_map.erase(_name);

    // Update the vector

    entity_list.erase(entity_list.begin() + entity_map[_name]);

    // Release the memory

    delete target_ptr;
}

/// @brief The addEntity method of the `EntityList`
/// @param _entity the pointer to the Entity object
void EntityList::addEntity(Entity* _entity) {

    // Update the vector

    entity_list.push_back(_entity);

    // Get the index

    int index = (int)entity_list.size() - 1;

    // Get the name

    Name name = _entity->repo->main_repo.self_info.name;

    // Update the map

    entity_map[name] = index;
}

/// @brief The destructor of the `EntityList`
EntityList::~EntityList() {
    for (auto & i : entity_list) {
        if (i != nullptr) {
            delete i;
            i = nullptr;
        }
    }
}

/**
 * Since all the `Entity` are newed outside any class's constructors, so there will be no destructor managing these Entities. 
 * Thus, we rather put a `Entity` inside the `EntityList` to manage it or delete it manually.
*/