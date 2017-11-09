#ifndef VEHICLEMANAGER_VEHICLE_H
#define VEHICLEMANAGER_VEHICLE_H

#include "Location.h"

namespace VehicleManager
{

enum VehicleType
{
	uninitialized = 99, car, station
};

class Vehicle
{
public:
//	Vehicle();
	Vehicle(VehicleType aType);
//	Vehicle& operator=(const Vehicle& aVehicle);

	unsigned short getId();
	VehicleType getType();
	Location getLocation();
	bool isAvailable();
private:
	unsigned short 		id;
	VehicleType 		type;
	Location 			location;
	bool available;
};

}  // namespace VehicleManager
#endif
