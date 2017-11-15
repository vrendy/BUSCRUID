#include "VehicleDAO.h"
#include <iostream>

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
	std::vector<Vehicle> vehicles;
	for(Vehicle v : Database::getDatabase().getVehicleTable()) {
		if(v.getLocation() == location && v.isAvailable()) // We hebben nog niks bedacht hoe we startTime en endTime gebruiken om availableVehicles op te halen
			vehicles.push_back(v);
	}
	return vehicles;
}

bool VehicleDAO::isAvailable(int vehicleId)
{
	for(Vehicle v : Database::getDatabase().getVehicleTable()) {
		if(v.getId() == vehicleId)
			return v.isAvailable();
	}
	return 0;
}

Vehicle VehicleDAO::getVehicle(unsigned long vehicleId)
{
	try {
		for(Vehicle v : Database::getDatabase().getVehicleTable())  {
			if(v.getId() == vehicleId) {
				return v;
			}
		}
	}
	catch(int e) {
		std::cout << "vehicleId is invalid\n" << "Exception: " + e << std::endl;
	}
}


}  // namespace VehicleManager
