#ifndef SEQUENCE_RESERVATION_H
#define SEQUENCE_RESERVATION_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DateTime.h"
#include "Location.h"
#include "Car.h"
#include "Subscription.h"
#include "Sequence/ReservationManager.h"
#include "Sequence/CalculationMethod.h"

namespace Sequence
{
class Reservation
{
private:
	DateTime startTime;

	DateTime endTime;

	Location location;

	Car car;

	unsigned short km;

	unsigned long totalCosts;

	ReservationManager reservationManager;
	Subscription subscription;
	CalculationMethod calculationMethod;

public:
	void Reservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime);

	void calculateTotalCosts();

	boolean checkoutOnTime();

	void setCar(Car car);

	void setKm(unsigned short km);

	void setTotalCosts(unsigned long total);

	void setLocation(Location location);

	void setStartTime(DateTime startTime);

	void setEndTime(DateTime endTime);

};

}  // namespace Sequence
#endif
