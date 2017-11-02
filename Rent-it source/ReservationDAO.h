#ifndef RESERVATIONMANAGER_RESERVATION_DAO_H
#define RESERVATIONMANAGER_RESERVATION_DAO_H

#include "Reservation.h"
#include "Database.h"

namespace ReservationManager
{

enum PaymentFrequency
{
	hour, day, weekend, week
};

class ReservationDAO
{
public:
	ReservationDAO();

	void createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, unsigned short paymentFrequency);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime, unsigned short km);

	Reservation getReservation(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime);

};

}  // namespace ReservationManager
#endif
