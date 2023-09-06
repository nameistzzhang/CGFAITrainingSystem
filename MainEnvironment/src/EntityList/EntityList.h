# ifndef ENTITYLIST_H
# define ENTITYLIST_H

class EntityList {
    public:
        static EntityList* createEntityListInstance();    // Create the EntityList instance
        ~EntityList() = default;    // TODO
    
    private:
        static EntityList* entity_list_obj;     // The EntityList instance

        // private all the function that can create the EntityList

        EntityList() = default;    // TODO
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

};

# endif // ENTITYLIST_H