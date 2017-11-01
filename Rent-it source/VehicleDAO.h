#ifndef VEHICLEMANAGER_VEHICLE_MANAGER_H
#define VEHICLEMANAGER_VEHICLE_MANAGER_H

#include <vector>

#include "Car.h"
#include "Location.h"
#include "Vehicle.h"
#include "Database.h"

namespace VehicleManager
{
class VehicleDAO
{
public:
	std::vector<Location> getAllLocations();

	std::vector<Car> getVehicles(Location location, unsigned short startTime, unsigned short endTime);

	bool isAvailable(int vechicleId);

};

}  // namespace VehicleManager
#endif
