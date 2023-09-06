# ifndef SENSOR_H
# define SENSOR_H

class EntityList;    // forward declaration
class Repo;

/// @brief `Sensor` is the Base class of the Sensors
class Sensor {
    public:
        virtual void sense () = 0;

    public:
        Sensor ();   // The constructor
        virtual ~Sensor ();   // The destructor

        /**
         * Here we can only delete repo because the EntityList is a singleton
         * and it will be deleted by its own destructor when the program ends.
        */

    public:
        EntityList* entity_list_instance;
        Repo* repo;
};

class AirBorneRadar : public Sensor {
    public:
        void sense () override;    // sense function

    public:
        AirBorneRadar (Repo* _repo);
};

# endif // SENSOR_H