# include "Info.h"
# include "Types.h"

/// @brief The copy constructor of the `SelfInfo` class.
/// @param _selfinfo 
SelfInfo::SelfInfo(const SelfInfo& _selfinfo) {
    this->name = _selfinfo.name;
    this->type = _selfinfo.type;
    this->longitude = _selfinfo.longitude;
    this->latitude = _selfinfo.latitude;
    this->altitude = _selfinfo.altitude;
    this->pitch = _selfinfo.pitch;
    this->roll = _selfinfo.roll;
    this->direction = _selfinfo.direction;
    this->speed = _selfinfo.speed;
    this->fuel = _selfinfo.fuel;
    this->weaponlist = _selfinfo.weaponlist;
}

/// @brief The operator = of the `SelfInfo` class.
/// @param _selfinfo 
/// @return 
SelfInfo& SelfInfo::operator = (const SelfInfo& _selfinfo) {
    this->name = _selfinfo.name;
    this->type = _selfinfo.type;
    this->longitude = _selfinfo.longitude;
    this->latitude = _selfinfo.latitude;
    this->altitude = _selfinfo.altitude;
    this->pitch = _selfinfo.pitch;
    this->roll = _selfinfo.roll;
    this->direction = _selfinfo.direction;
    this->speed = _selfinfo.speed;
    this->fuel = _selfinfo.fuel;
    this->weaponlist = _selfinfo.weaponlist;
    return *this;
}

/// @brief The copy constructor of the `TaskInfo` class.
/// @param _taskinfo
TaskInfo::TaskInfo(const TaskInfo& _taskinfo) {
    this->tasklist = _taskinfo.tasklist;
}

/// @brief The operator = of the `TaskInfo` class.
/// @param _taskinfo
/// @return
TaskInfo& TaskInfo::operator = (const TaskInfo& _taskinfo) {
    this->tasklist = _taskinfo.tasklist;
    return *this;
}

/// @brief The copy constructor of the `RadarInfo` class.
/// @param _radarinfo
RadarInfo::RadarInfo(const RadarInfo& _radarinfo) {
    this->name = _radarinfo.name;
    this->type = _radarinfo.type;
    this->longitude = _radarinfo.longitude;
    this->latitude = _radarinfo.latitude;
    this->altitude = _radarinfo.altitude;
    this->speed = _radarinfo.speed;
}

/// @brief The operator = of the `RadarInfo` class.
/// @param _radarinfo
/// @return
RadarInfo& RadarInfo::operator = (const RadarInfo& _radarinfo) {
    this->name = _radarinfo.name;
    this->type = _radarinfo.type;
    this->longitude = _radarinfo.longitude;
    this->latitude = _radarinfo.latitude;
    this->altitude = _radarinfo.altitude;
    this->speed = _radarinfo.speed;
    return *this;
}