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

	std::vector<Vehicle> getVehicles(Location location, unsigned short startTime, unsigned short endTime);

	bool isAvailable(int vehicleId);

	Vehicle getVehicle(unsigned long vehicleId);

	std::string VehicleTypeToString(VehicleType t);

};

}  // namespace VehicleManager
#endif
