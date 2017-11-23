#include "Vehicle.h"

#include <iostream>

namespace VehicleManager
{

static unsigned short vehicleCounter = 0;

Vehicle::Vehicle(VehicleType aType, Location aLocation) : id(++vehicleCounter), type(aType), location(aLocation), available(1)
{

}

bool Vehicle::operator==(unsigned short anId)
{
	return id == anId;
}

//std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
//	os << (int)v.getType() << "\t" << VehicleTypeToString(v.getType()) << std::endl;
//	return os;
//}

}  // namespace VehicleManager
