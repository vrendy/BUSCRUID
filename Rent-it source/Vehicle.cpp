#include "Vehicle.h"

namespace VehicleManager
{

static unsigned short vehicleCounter = 0;

//Vehicle::Vehicle() : id(0), type(uninitialized)
//{
//
//}

Vehicle::Vehicle(VehicleType aType) : id(++vehicleCounter), type(aType), available(1)
{

}

//Vehicle& Vehicle::operator=(const Vehicle& aVehicle)
//{
//	if(this != &aVehicle)
//	{
//		id = aVehicle.id;
//		type = aVehicle.type;
//		location = aVehicle.location;
//	}
//	return *this;
//}

unsigned short Vehicle::getId()
{
	return id;
}

VehicleType Vehicle::getType()
{
	return type;
}

Location Vehicle::getLocation() {
	return location;
}

bool Vehicle::isAvailable()
{
	return available;
}

}  // namespace Design Class
