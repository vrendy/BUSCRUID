#ifndef VEHICLEMANAGER_VEHICLE_H
#define VEHICLEMANAGER_VEHICLE_H

#include "Location.h"

namespace VehicleManager
{

enum VehicleType
{
	car, station, uninitialized = 99
};

class Vehicle
{
public:
	Vehicle(VehicleType aType, Location aLocation);
	bool operator==(unsigned short anId);

	unsigned short getId() const {
		return id;
	}

	VehicleType getType() const {
		return type;
	}

	Location getLocation() const {
		return location;
	}

	bool isAvailable() const {
		return available;
	}

//	std::string VehicleTypeToString() const	{
//		switch(type)
//		{
//		case VehicleType::car:
//			return "Car";
//			break;
//		case VehicleType::station:
//			return "Station";
//			break;
//		case VehicleType::uninitialized:
//			return "Uninitialized";
//			break;
//		default:
//			return "No type";
//		}
//	}
private:
	unsigned short 		id;
	VehicleType 		type;
	Location 			location;
	bool available;
};

//std::ostream& operator<<(std::ostream& os, const Vehicle& v);



}  // namespace VehicleManager
#endif
