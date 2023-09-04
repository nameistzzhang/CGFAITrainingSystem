# ifndef INFO_H
# define INFO_H

# include "Types.h"

/// @brief `SelfInfo` class is the container used to store the info of the entity itself.
class SelfInfo {
    public:
        Name name;    // The name of the entity
        Type type;    // The type of the entity
        Longitude longitude;    // The longitude of the entity
        Latitude latitude;    // The latitude of the entity
        Altitude altitude;    // The altitude of the entity
        Pitch pitch;    // The pitch of the entity
        Roll roll;    // The roll of the entity
        Direction direction;    // The direction of the entity
        Speed speed;    // The speed of the entity
        Fuel fuel;    // The fuel of the entity
        WeaponList weaponlist;    // The missile list of the entity
    
    public:
        SelfInfo() = default;    // The default constructor of the `SelfInfo` class
        ~SelfInfo() = default;    // The default destructor of the `SelfInfo` class

        SelfInfo(const SelfInfo&);    // The copy constructor of the `SelfInfo` class

        SelfInfo& operator=(const SelfInfo&);    // The copy assignment operator of the `SelfInfo` class
};

# endif // INFO_H