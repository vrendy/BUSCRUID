#ifndef VEHICLEMANAGER_VEHICLE_MANAGER_H
#define VEHICLEMANAGER_VEHICLE_MANAGER_H

#include <vector>

#include "Car.h"
#include "Location.h"
#include "dateTime.h"
#include "Vehicle.h"
#include "Database.h"

namespace VehicleManager
{
class VehicleDAO
{
public:
	std::vector<Location> getAllLocations();

	std::vector<Car> getVehicles(Location location, dateTime startTime, dateTime endTime);

	bool isAvailable(int vechicleId);

};

}  // namespace VehicleManager
#endif
