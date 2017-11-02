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
	Reservation(unsigned long aCustomerId, unsigned short aVehicleId, unsigned short aStartTime, unsigned short anEndTime);
	void calculateTotalCosts();
	bool checkoutOnTime();
	void setKm(unsigned short km);
	void setTotalCosts(unsigned long total);
	void setCheckInTime(unsigned short aCheckInTime);
	void setCheckOutTime(unsigned short aCheckOutTime);

private:
	unsigned long				reservationId;
	unsigned long				customerId;
	unsigned short				vehicleId;
	unsigned short 				startTime;
	unsigned short 				endTime;
	unsigned short				checkInTime;
	unsigned short				checkOutTime;
	unsigned short 				distance;		// Distance in Kilo meter
	unsigned long 				totalCosts;

};

}  // namespace ReservationManager
#endif
