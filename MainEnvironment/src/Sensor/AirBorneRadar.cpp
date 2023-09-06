# include "../EntityList/EntityList.h"
# include "../Repo/Repo.h"
# include "Sensor.h"

# include <iostream>



/// @brief The sense function of the `AirBorneRadar`
void AirBorneRadar::sense () {

    std::cout << "Sensor working\n";
    
    // TODO
}

/// @brief The constructor of the `AirBorneRadar`
/// @param _repo The input info of the repo
AirBorneRadar::AirBorneRadar (Repo* _repo) {
    repo = _repo;
}