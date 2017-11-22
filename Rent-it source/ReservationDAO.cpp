#include "ReservationDAO.h"

#include <vector>
#include <iostream>

namespace ReservationManager
{
void ReservationDAO::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, PaymentFrequency aPaymentFrequency)
{
	Reservation reservation(customerId, vehicleId, startTime, endTime, aPaymentFrequency);
	Database::getDatabase().getReservationTable().push_back(reservation);
}

void ReservationDAO::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime, unsigned short km)
{
	for(Reservation& r : Database::getDatabase().getReservationTable())
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
			else if(/*niet ingechecked en uitgechecked reservering verlopen*/0) // TODO check with current time from Rent-it if this is the reservation that has not been checked in or out and has finished
			{

				r.calculateTotalCosts();
			}
		}
	}
}

ReservationDAO& ReservationDAO::getReservationDAO() {
	static ReservationDAO rDAO;
	return rDAO;
}

Reservation ReservationDAO::getReservation(unsigned long customerId, unsigned short vehicleId, unsigned short checkInTime, unsigned short endTime)
{
	for (auto it = Database::getDatabase().getReservationTable().begin(); it != Database::getDatabase().getReservationTable().end(); ++it) {
		if (it->getCustomerId() == customerId && it->getVehicleId() == vehicleId && it->getStartTime() <= checkInTime) {
			return *it;
		}
	}
	throw("No Reservation with given parameters was found ");
}

}  // namespace ReservationManager
