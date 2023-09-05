# ifndef TYPES_H
# define TYPES_H

# include <string>
# include <vector>

typedef std::string Name;    // The Name type represents the entity's name e.g. "Red One"

typedef std::string Type;    // The Type type represents the entity's type e.g. "F15"s

typedef std::string Mode;    // The Mode type represents the entity's mode e.g. "Attak", "Hover", "Land"

typedef double Longitude;    // The Longitude type represents the entity's longitude [east > 0 while west < 0]

typedef double Latitude;    // The Latitude type represents the entity's latitude [norht > 0 while south < 0]

typedef double Altitude;    // The Altitude type represents the entity's altitude [above sea level]

typedef float Pitch;    // The Pitch type represents the entity's pitch [heading to the sky > 0 while heading to the ground < 0] (-180, 180)

typedef float Roll;    // The Roll type represents the entity's roll [rollinh to the right > 0 while rolling to the left < 0] (-180, 180)

typedef float Direction;    // The Direction type represents the entity's direction [heading north = 0 heading east > 0 while heading west < 0] (-180, 180)

typedef double Speed;    // The speed type represents the entity's speed [meters per second]

typedef float Fuel;    // The Fuel type represents the entity's fuel [%]

typedef std::vector<Type> WeaponList;    // The WeaponList type represents the entity's weapon list



/// @brief `Task` class is the container used to store the info of the task
typedef struct {
    public:
        Mode taskmode;    // The mode of the task

        // The destination of the Task

        Longitude tasklongitude;
        Latitude tasklatitude;
        Altitude taskaltitude;
} Task;

/// @brief `Movement` class is the container used to store the info of the movement
typedef struct {
    public:
        Longitude movelongitude;
        Latitude movelatitude;
        Altitude movealtitude;
        Pitch movepitch;
        Roll moveroll;
        Direction movedirection;
        Speed movespeed;
} Movement;

# endif // TYPES_H