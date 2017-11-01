#include "ReservationDAO.h"

namespace ReservationManager
{

void ReservationDAO::createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime)
{
}

void ReservationDAO::addToDatabase(Reservation aReservation)
{
}

void ReservationDAO::processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime, unsigned short km)
{
}

Reservation ReservationDAO::getReservation(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime)
{
	return 0;
}
}  // namespace ReservationManager
