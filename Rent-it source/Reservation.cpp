#include "Reservation.h"

namespace ReservationManager
{

static unsigned long reservationCounter = 0;

Reservation::Reservation(unsigned long aCustomerId, unsigned short aVehicleId, unsigned short aStartTime, unsigned short anEndTime) : reservationId(++reservationCounter), customerId(aCustomerId), vehicleId(aVehicleId), startTime(aStartTime), endTime(anEndTime), distance(0), totalCosts(0)
{

}

void Reservation::calculateTotalCosts()
{
}

bool Reservation::checkoutOnTime()
{
	return 0;
}

void Reservation::setKm(unsigned short aDistance)
{
	distance = aDistance;
}

void Reservation::setTotalCosts(unsigned long total)
{
	totalCosts = total;
}

void Reservation::setStartTime(unsigned short aStartTime)
{
	startTime = aStartTime;
}

void Reservation::setEndTime(unsigned short anEndTime)
{
	endTime = anEndTime;
}
}  // namespace ReservationManager
