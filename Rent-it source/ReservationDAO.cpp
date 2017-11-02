#include "ReservationDAO.h"

#include <vector>

namespace ReservationManager
{
void ReservationDAO::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, unsigned short paymentFrequency)
{
	Reservation reservation(customerId, vehicleId, startTime, endTime, paymentFrequency);
	Database::getDatabase().getReservationTable().push_back(reservation);
}

void ReservationDAO::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime, unsigned short km)
{
	for(Reservation r : Database::getDatabase().getReservationTable())
	{
		// Get customer from db where customer checkInTime is within reservation begin and end time, for that customer, calculate totalcosts
		if(r.getCustomerId() == customerId && r.getVehicleId() == vehicleId) // Customer checked in with car
		{
			if(checkInTime >= r.getStartTime() && checkInTime <= r.getEndTime())
			{
				r.setCheckInTime(checkInTime);
				r.setCheckOutTime(endTime);
				r.setKm(km);
				r.calculateTotalCosts();
			}
			else if(/*niet ingechecked en uitgechecked reservering verlopen*/) // TODO check with current time from Rent-it if this is the reservation that has not been checked in or out and has finished
			{

				r.calculateTotalCosts();
			}
		}
	}
}

Reservation ReservationDAO::getReservation(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime)
{
}
}  // namespace ReservationManager
