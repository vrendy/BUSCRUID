#ifndef RESERVATIONMANAGER_RESERVATION_H
#define RESERVATIONMANAGER_RESERVATION_H

#include "Car.h"
#include "Subscription.h"
#include <memory>
#include <iostream>



namespace ReservationManager
{
class CalculationMethod;
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

	unsigned short getCheckInTime() const {
		return checkInTime;
	}

	unsigned short getCheckOutTime() const {
		return checkOutTime;
	}

	unsigned long getTotalCosts() const {
		return totalCosts;
	}

	std::string PaymentFrequencyToString(PaymentFrequency aPaymentFrequency) const	{
		switch(aPaymentFrequency)
		{
		case PaymentFrequency::hour:
			return "hour";
			break;
		case PaymentFrequency::day:
			return "day";
			break;
		case PaymentFrequency::weekend:
			return "weekend";
			break;
		case PaymentFrequency::week:
			return "week";
			break;
		default:
			return "No paymentFrequency";
		}
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

	std::shared_ptr<ReservationManager::CalculationMethod> method;

};

std::ostream& operator<<(std::ostream& os, const Reservation& r);

}  // namespace ReservationManager
#endif
