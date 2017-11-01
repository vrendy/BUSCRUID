#ifndef DESIGN CLASS_DATABASE_H
#define DESIGN CLASS_DATABASE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Sequence/CustomerManager.h"
#include "Sequence/ReservationManager.h"
#include "Sequence/VehicleManager.h"

namespace Design Class
{
class Database
{
private:
	Sequence::CustomerManager customerManager;
	Sequence::ReservationManager reservationManager;
	Sequence::VehicleManager vehicleManager;
};

}  // namespace Design Class
#endif
