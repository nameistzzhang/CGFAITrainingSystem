# ifndef ENTITYLIST_H
# define ENTITYLIST_H

# include <vector>
# include <unordered_map>
# include "../Info/Types.h"

class Entity;

class EntityList {
    public:
        static EntityList* createEntityListInstance();    // Create the EntityList instance
        ~EntityList() = default;    // TODO
    
    private:
        static EntityList* entity_list_obj;     // The EntityList instance

        // private all the function that can create the EntityList

        EntityList() = default;
        EntityList(const EntityList&) {};
        EntityList& operator=(const EntityList&) {};

    private:

        // This class is used to delete the EntityList instance when the program ends

        class DeleteEntityListInstance {
            public:
                ~DeleteEntityListInstance () {
                    if (EntityList::entity_list_obj != nullptr) {
                        delete EntityList::entity_list_obj;
                        EntityList::entity_list_obj = nullptr;
                    }
                }  
        };

        static DeleteEntityListInstance delete_entity_list_instance;    // The static variable will be destructed automatically when the program ends

    private:

        std::vector<Entity*> entity_list;    // The list of all the entities
        std::unordered_map<Name, int> entity_map;    // The map of all the entities

    public:
        // void clearList();
        // Entity* at(int _index);
        // Entity* at(Name _name);
        // void deleteEntity(int _index);
        // void deleteEntity(Name _name);
        // void addEntity(Entity* _entity);
};

# endif // ENTITYLIST_H