#ifndef SEQUENCE_VEHICLE_MANAGER_H
#define SEQUENCE_VEHICLE_MANAGER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Car.h"
#include "std::vector.h"
#include "Location.h"
#include "dateTime.h"
#include "Sequence/RentIt.h"
#include "Design Class/Vehicle.h"
#include "Design Class/Database.h"

namespace Sequence
{
class VehicleManager
{
private:
	RentIt rentIt;
	Car car[];
	Design Class::Vehicle vehicle[];
	Design Class::Database database;

public:
	std::vector<Location> getAllLocations();

	std::vector<Car> getVehicles(Location location, dateTime startTime, dateTime endTime);

	boolean isAvailable(int vechicleId);

};

}  // namespace Sequence
#endif
