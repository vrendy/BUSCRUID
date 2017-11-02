#ifndef VEHICLEMANAGER_VEHICLE_H
#define VEHICLEMANAGER_VEHICLE_H

#include "Location.h"

namespace VehicleManager
{
class Vehicle
{
public:
	Vehicle();

	Location getLocation();
private:
	unsigned short vehicleId;

	Location location;
};

}  // namespace VehicleManager
#endif
