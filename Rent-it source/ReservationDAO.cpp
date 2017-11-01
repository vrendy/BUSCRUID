#include "ReservationDAO.h"

namespace ReservationManager
{
void ReservationDAO::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime)
{
}

void ReservationDAO::addToDatabase(Reservation& reservation)
{
}

void ReservationDAO::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime, unsigned short km)
{
}

Reservation ReservationDAO::getReservation(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime)
{
}
}  // namespace ReservationManager
