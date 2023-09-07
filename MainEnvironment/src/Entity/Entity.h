# ifndef ENTITY_H
# define ENTITY_H

# include <vector>

class Repo;
class Sensor;
class Actuator;
class Controller;

/// @brief `Entity` is the base class of all the Entities
class Entity {
    public:
        Repo* repo;
        std::vector<Sensor*> sensor_list;
        std::vector<Actuator*> actuator_list;
        Controller* controller;

    public:
        virtual void tick() = 0;
        virtual void halfTick() = 0;
    
    public:
        Entity();
        virtual ~Entity() = default;
};

/// @brief `Rafale` is the Entity of the Rafale Fighter
class Rafale : public Entity {
    public:
        Rafale();
        ~Rafale();

    public:
        void tick();
        void halfTick();
};

# endif // ENTITY_H