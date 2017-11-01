#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ReservationManager.h"

namespace Sequence
{

void ReservationManager::createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime)
{
}

void ReservationManager::setReservationLocationAndTime(Location location, dateTime startTime, dateTime endTime)
{
}

void ReservationManager::setReservationCar(Car car)
{
}

std::vector<Subscription> ReservationManager::getSubscriptionTypes()
{
	return 0;
}

void ReservationManager::setReservationSubscriptionType(Subscription subscriptionType)
{
}

void ReservationManager::addToDatabase(Reservation aReservation)
{
}

void ReservationManager::processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime, unsigned short km)
{
}

Reservation ReservationManager::getReservation(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime)
{
	return 0;
}
}  // namespace Sequence
