#include "VehicleDAO.h"

namespace VehicleManager
{

std::vector<Location> VehicleDAO::getAllLocations()
{
	std::vector<Location> locations;
	for(Vehicle v : Database::getDatabase().getVehicleTable()) {
		locations.push_back(v.getLocation());
	}
	return locations;
}

std::vector<Vehicle> VehicleDAO::getVehicles(Location location, unsigned short startTime, unsigned short endTime)
{
	return Database::getDatabase().getVehicleTable();
}

bool VehicleDAO::isAvailable(int vechicleId)
{
	//TO DO
	return 1;
}


}  // namespace VehicleManager
