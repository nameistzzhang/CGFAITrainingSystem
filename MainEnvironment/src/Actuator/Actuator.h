# ifndef ACTUATOR_H
# define ACTUATOR_H

class Repo;

/// @brief `Actuator` is the Base class of all the Actuators
class Actuator {
    public:
        Repo* repo;
    
    public:
        Actuator();
        virtual ~Actuator();

    public:
        virtual void actuate() = 0;
};

/// @brief `RafaleActuator` is the actuator of the Rafale Fighter
class RafaleActuator : public Actuator {
    public:
        RafaleActuator(Repo* _repo);
    
    public:
        void actuate();
};

# endif // ACTUATOR_H