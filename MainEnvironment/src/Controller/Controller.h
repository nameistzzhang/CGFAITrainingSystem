# ifndef CONTROLLER_H
# define CONTROLLER_H

class Repo;

/// @brief `Controller` is the base class of all the Controllers
class Controller {
    public:
        Repo* repo;

    public:
        Controller();
        ~Controller();

    public:
        virtual void control() = 0;
};

/// @brief `RafaleController` is the controller of the Rafale Fighter
class RafaleController : public Controller {
    public:
        RafaleController(Repo* _repo);
    
    public:
        void control();
};

# endif CONTROLLER_H