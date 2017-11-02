#include "Reservation.h"

namespace ReservationManager
{

static unsigned long reservationCounter = 0;

Reservation::Reservation(unsigned long aCustomerId, unsigned short aVehicleId, unsigned short aStartTime, unsigned short anEndTime, unsigned short aPaymentFrequency)
	: reservationId(++reservationCounter), customerId(aCustomerId), vehicleId(aVehicleId), startTime(aStartTime), endTime(anEndTime), paymentFrequency(aPaymentFrequency), checkInTime(0), checkOutTime(0), distance(0), totalCosts(0)
{

}

void Reservation::calculateTotalCosts()
{
}

bool Reservation::checkoutOnTime()
{
	return checkOutTime <= endTime;
}

void Reservation::setKm(unsigned short aDistance)
{
	distance = aDistance;
}

void Reservation::setTotalCosts(unsigned long total)
{
	totalCosts = total;
}

void Reservation::setCheckInTime(unsigned short aCheckInTime)
{
	startTime = aCheckInTime;
}

void Reservation::setCheckOutTime(unsigned short aCheckOutTime)
{
	endTime = aCheckOutTime;
}
}  // namespace ReservationManager
