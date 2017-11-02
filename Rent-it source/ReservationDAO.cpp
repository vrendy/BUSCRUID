#include "ReservationDAO.h"

#include <vector>

namespace ReservationManager
{
void ReservationDAO::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime)
{
	Reservation reservation(customerId, vehicleId, startTime, endTime);
	Database::getDatabase().getReservationTable().push_back(reservation);
}

void ReservationDAO::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime, unsigned short km)
{
	for(Reservation r : Database::getDatabase().getReservationTable())
	{
		if(r.customerId == customerId && r.vehicleId == vehicleId && checkInTime >= r.startTime && checkInTime <= r.endTime) // Customer checked in with car
		{
			r.setCheckInTime(checkInTime);
			r.setCheckOutTime(endTime);
			r.setKm(km);
			r.calculateTotalCosts();
		}
	}
	//get reservation from db (loop through) (if chekcInTime !=0 check for reservation with checkintime between start and end, where customerId and vehicleId is same)
	// set alles
	//calculatetotalcost
}

Reservation ReservationDAO::getReservation(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime)
{
}
}  // namespace ReservationManager
