#ifndef DESIGN CLASS_VEHICLE_H
#define DESIGN CLASS_VEHICLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Location.h"
#include "Sequence/VehicleManager.h"

namespace Design Class
{
class Vehicle
{
private:
	int vehicleId;

	Sequence::VehicleManager vehicleManager;
	Location location;
};

}  // namespace Design Class
#endif
