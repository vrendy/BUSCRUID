#ifndef RESERVATIONMANAGER_RESERVATION_H
#define RESERVATIONMANAGER_RESERVATION_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DateTime.h"
#include "Car.h"
#include "Subscription.h"
#include "CalculationMethod.h"
#include "ReservationDAO.h"

namespace ReservationManager
{
class Reservation
{
private:
	DateTime startTime;

	DateTime endTime;

	VehicleManager::Location location;

	VehicleManager::Car car;

	unsigned short km;

	unsigned long totalCosts;

public:
	void Reservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime);

	void calculateTotalCosts();

	bool checkoutOnTime();

	void setCar(VehicleManager::Car car);

	void setKm(unsigned short km);

	void setTotalCosts(unsigned long total);

	void setStartTime(DateTime startTime);

	void setEndTime(DateTime endTime);

};

}  // namespace ReservationManager
#endif
