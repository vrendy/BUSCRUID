#include "Vehicle.h"

namespace VehicleManager
{

static unsigned short vehicleCounter = 0;

Vehicle::Vehicle() : vehicleId(++vehicleCounter)
{

}

Location Vehicle::getLocation() {
	return location;
}

}  // namespace Design Class
