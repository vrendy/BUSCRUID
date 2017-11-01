#ifndef RESERVATIONMANAGER_RESERVATION_H
#define RESERVATIONMANAGER_RESERVATION_H

#include "Car.h"
#include "Subscription.h"
#include "CalculationMethod.h"

namespace ReservationManager
{
class Reservation
{
public:
	Reservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime);
	void calculateTotalCosts();
	bool checkoutOnTime();
	void setCar(VehicleManager::Car car);
	void setKm(unsigned short km);
	void setTotalCosts(unsigned long total);
	void setStartTime(unsigned short startTime);
	void setEndTime(unsigned short endTime);

private:

	VehicleManager::Location 	location;
	VehicleManager::Car 		car;
	unsigned short 				startTime;
	unsigned short 				endTime;
	unsigned short 				km;
	unsigned long 				totalCosts;

};

}  // namespace ReservationManager
#endif
