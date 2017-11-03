#ifndef RESERVATIONMANAGER_RESERVATION_H
#define RESERVATIONMANAGER_RESERVATION_H

#include "Car.h"
#include "Subscription.h"
//#include "CalculationMethod.h"

namespace ReservationManager
{

enum PaymentFrequency
{
	hour, day, weekend, week
};

class Reservation
{
public:
	Reservation(unsigned long aCustomerId, unsigned short aVehicleId, unsigned short aStartTime, unsigned short anEndTime, PaymentFrequency aPaymentFrequency);
	void calculateTotalCosts();
	bool checkoutOnTime();
	void setKm(unsigned short km);
	void setTotalCosts(unsigned long total);
	void setCheckInTime(unsigned short aCheckInTime);
	void setCheckOutTime(unsigned short aCheckOutTime);

	unsigned long getCustomerId() const {
		return customerId;
	}

	unsigned short getEndTime() const {
		return endTime;
	}

	unsigned short getStartTime() const {
		return startTime;
	}

	unsigned short getVehicleId() const {
		return vehicleId;
	}

private:
	unsigned long				reservationId;
	unsigned long				customerId;
	unsigned short				vehicleId;
	unsigned short 				startTime;
	unsigned short 				endTime;
	PaymentFrequency			paymentFrequency;
	unsigned short				checkInTime;
	unsigned short				checkOutTime;
	unsigned short 				distance;		// Distance in Kilo meter
	unsigned long 				totalCosts;

};

}  // namespace ReservationManager
#endif
