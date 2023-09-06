# include "EntityList.h"

// Put the entity_list_obj into nullptr

EntityList* EntityList::entity_list_obj = nullptr;

/// @brief The singleton instance of the `EntityList`
/// @return The pointer to the `EntityList` instance
EntityList* EntityList::createEntityListInstance() {
    if (entity_list_obj == nullptr) {
        entity_list_obj = new EntityList();
    }
    return entity_list_obj;
}