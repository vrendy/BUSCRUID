#ifndef SEQUENCE_RENT_IT_H
#define SEQUENCE_RENT_IT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "std::string.h"
#include "Location.h"
#include "dateTime.h"
#include "Car.h"
#include "Subscription.h"
#include "DateTime.h"
#include "Sequence/ReservationManager.h"
#include "Sequence/CustomerManager.h"
#include "Sequence/VehicleManager.h"

namespace Sequence
{
class RentIt
{
private:
	ReservationManager reservationManager;
	CustomerManager customerManager;
	VehicleManager vehicleManager;

public:
	void getLocations();

	void addCustomer(std::string NAW, std::string email, std::string bankNbr);

	void getAvailableVehicles(Location location, dateTime startTime, dateTime endTime);

	void chooseCar(Car car);

	void chooseSubscriptionType(Subscription subscriptionType);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkinTime, DateTime endTime, unsigned short km);

	void createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime, std::string paymentFrequency);

};

}  // namespace Sequence
#endif
