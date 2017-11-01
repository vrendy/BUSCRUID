#ifndef SEQUENCE_RESERVATION_MANAGER_H
#define SEQUENCE_RESERVATION_MANAGER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DateTime.h"
#include "Location.h"
#include "dateTime.h"
#include "Car.h"
#include "std::vector.h"
#include "Subscription.h"
#include "Sequence/RentIt.h"
#include "Sequence/Reservation.h"
#include "Design Class/Database.h"

namespace Sequence
{
class ReservationManager
{
private:
	RentIt rentIt;
	Reservation reservation[];
	Design Class::Database database;

public:
	void createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime);

	void setReservationLocationAndTime(Location location, dateTime startTime, dateTime endTime);

	void setReservationCar(Car car);

	std::vector<Subscription> getSubscriptionTypes();

	void setReservationSubscriptionType(Subscription subscriptionType);

	void addToDatabase(Reservation aReservation);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime, unsigned short km);

	Reservation getReservation(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime);

};

}  // namespace Sequence
#endif
