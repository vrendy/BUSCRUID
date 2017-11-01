#ifndef RESERVATIONMANAGER_RESERVATION_DAO_H
#define RESERVATIONMANAGER_RESERVATION_DAO_H

#include "DateTime.h"
#include "dateTime.h"
#include "Reservation.h"
#include "Database.h"

namespace ReservationManager
{
class ReservationDAO
{
public:
	void createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime);

	void addToDatabase(Reservation aReservation);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime, unsigned short km);

	Reservation getReservation(unsigned long customerId, unsigned short vehicleId, DateTime checkInTime, DateTime endTime);

};

}  // namespace ReservationManager
#endif
