#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Reservation.h"

namespace Sequence
{

void Reservation::Reservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime)
{
}

void Reservation::calculateTotalCosts()
{
}

boolean Reservation::checkoutOnTime()
{
	return 0;
}

void Reservation::setCar(Car car)
{
}

void Reservation::setKm(unsigned short km)
{
}

void Reservation::setTotalCosts(unsigned long total)
{
}

void Reservation::setLocation(Location location)
{
}

void Reservation::setStartTime(DateTime startTime)
{
}

void Reservation::setEndTime(DateTime endTime)
{
}
}  // namespace Sequence
