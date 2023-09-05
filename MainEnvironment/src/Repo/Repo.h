# ifndef REPO_H
# define REPO_H

# include "../Info/Info.h"
# include "../Info/Types.h"

# include <iostream>

/// @brief `MainRepo` is an element of the `Repo` class
class MainRepo {
    public:
        SelfInfo self_info;
        TaskInfo task_info;
    
    public:
        MainRepo() = default;    // The default constructor
        ~MainRepo() = default;   // The default destructor

        MainRepo(const MainRepo&) = delete; // Ban copy constructor
};

/// @brief `RadarRepo` is an element of the `Repo` class
class RadarRepo {
    public:
        std::vector<RadarInfo> self_radar_info;
        std::vector<RadarInfo> net_radar_info;

    public:
        RadarRepo() = default;    // The default constructor
        ~RadarRepo() = default;   // The default destructor

        RadarRepo(const RadarRepo&) = delete; // Ban copy constructor
};

/// @brief `ActuatorRepo` is an element of the `Repo` class
class ActuatorRepo {
    public:
        std::vector<Movement> movement_list;
    
    public:
        ActuatorRepo() = default;    // The default constructor
        ~ActuatorRepo() = default;   // The default destructor

        ActuatorRepo(const ActuatorRepo&) = delete; // Ban copy constructor
};

/// @brief `ActionRepo` is the Base class of the ActionRepos
class ActionRepo {
    public:
        
};

/// @brief `RafaleActionRepo` is the ActionRepo of Rafale Fighter
class RafaleActionRepo : public ActionRepo {
    public:

};

/// @brief `Repo` is the Base class of the Repos
class Repo {
    public:
        MainRepo main_repo;    // The main repo
        RadarRepo radar_repo;  // The radar repo
        ActuatorRepo actuator_repo; // The actuator repo
        ActionRepo* action_repo; // The action repo

    public:
        Repo() {action_repo = nullptr;}   // The constructor
        virtual ~Repo() {delete action_repo;}  // The virtual destructor

        Repo(const Repo&) = delete; // Ban copy constructor
};

/// @brief `RafaleRepo` is the Repo of Rafale Fighter
class RafaleRepo : public Repo {
    public:
        RafaleRepo() {action_repo = new RafaleActionRepo;}   // The constructor
        ~RafaleRepo() = default;   // The default destructor

        RafaleRepo(const RafaleRepo&) = delete; // Ban copy constructor
};


# endif // REPO_H