#include "RentIt.h"

#include "Database.h"

#include <iostream>

RentIt& RentIt::getRentIt() {
	static RentIt rIt;
	return rIt;
}

signed short RentIt::makeReservation()
{
	signed short locationChoice = -1;
	signed short vehicleChoice	= -1;
	signed short startTime 		= -1;
	signed short endTime		= -1;
	unsigned short failOption	= -1;

start:;

	locationChoice = chooseLocation();
	std::cout << "Choose the start time of your reservation (Number of hours from now): " << std::endl; // Has to be made dynamic, choose time and payment frequency, make it make sense
	std::cout << "> ";std::cin >> startTime;
	std::cout << "Choose the end time of your reservation (Number of hours from now): " << std::endl;
	std::cout << "> ";std::cin >> endTime;
	vehicleChoice = chooseCar(locationChoice, startTime, endTime);
	switch(vehicleChoice)
	{
	case -1: // Change location
		std::cout << "This type of vehicle is unavailable at the chosen time...\n Type 0 to quit, anything else to choose type of vehicle and time again!" << std::endl;
		std::cout << "> ";std::cin >> failOption;
		if(failOption)
			goto start;
		break;
	default: // No errors
		reservationManager.createReservation(0, vehicleChoice, startTime, endTime, ReservationManager::PaymentFrequency::hour);
		return 1;
	}
	return -1;
}

std::vector<VehicleManager::Location>& RentIt::getLocations()
{
	return Database::getDatabase().getLocationTable();
}

void RentIt::addCustomer(std::string name, std::string address, std::string city, std::string email, std::string bankNbr, CustomerManager::SubscriptionType subType)
{
	customerManager.createCustomer(name, address, city, email, bankNbr, subType);
}

std::vector<VehicleManager::Vehicle> RentIt::getAvailableVehicles(VehicleManager::Location location, unsigned short startTime, unsigned short endTime)
{
	return vehicleManager.getVehicles(location, startTime, endTime);
}





void RentIt::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkinTime, unsigned short endTime, unsigned short km)
{
	// get reservation op basis van customer id, vehicle id, checkintime en checkouttime, roep op said reservation calculateMethod aan
}

signed short RentIt::chooseCar(unsigned short locationId, unsigned short startTimeStamp, unsigned short endTimeStamp)
{
	// Geef typen auto's om uit te kiezen
	signed short chosenType = -1;
	std::cout << "Choose of the following Vehicle Types: " << std::endl;
	std::string vt;
	for(int i = 0; i < 99; ++i)
	{
		vt = vehicleManager.VehicleTypeToString(VehicleManager::VehicleType(i));
		if(vt != "No type")
		{
			std::cout << i << "\t" << vt << std::endl;
		}
	}
	std::cout << "> ";std::cin >> chosenType;
	std::cout << "Type chosen: " << vehicleManager.VehicleTypeToString(VehicleManager::VehicleType(chosenType)) << std::endl;

	// How to write SQL in C++
	for(auto vehicle : Database::getDatabase().getVehicleTable())																// Loop through Vehicles
	{
		if((vehicle.getLocation().getId() == locationId) && (vehicle.getType() == VehicleManager::VehicleType(chosenType))) 	// Vehicle on given Location and chosen Type
		{
			//TODO Moet dit niet verplaatst worden naar "getAvailableVehicles(location, startTime, endTime)" in vehicleDAO ?
			for(auto reservation : Database::getDatabase().getReservationTable())												// Loop through all Reservations
			{
				if(((vehicleManager.getVehicle(reservation.getVehicleId()).getType() == chosenType) &&							// Chosen Type == Reservation Vehicle Type
						((startTimeStamp >= reservation.getStartTime() && startTimeStamp <= (reservation.getEndTime() + 30))	// Chosen startTime ! overlap reservation time
								|| (endTimeStamp >= reservation.getStartTime() && endTimeStamp <= reservation.getEndTime()))))	// Chosen endTime 	! overlap reservation time
				{
					goto endLoop;																								// Reservation on VehicleType within chosen Time, try next vehicle
				}

			}
			return vehicle.getId();
		}
		endLoop:;
	}
	return -1;
}

unsigned short RentIt::chooseLocation()
{
	signed short locationChoice = -1;
start:;
	// Show Locations
	std::cout << "Choose of the following locations: " << std::endl;
	for(auto location : getLocations())
		std::cout << location;

	// Choose Location
	std::cout << "> ";std::cin >> locationChoice;

	// Verify input, save input if correct
	for(auto location : getLocations())
	{
		if(location.getId() == locationChoice)
		{
			// Goto endloop if found
			return locationChoice;
		}
	}
	// Redo Location choosing
	std::cout << "No valid location chosen..." << std::endl;
goto start;
}

void RentIt::chooseSubscriptionType(CustomerManager::Subscription subscriptionType)
{
	// idem choose car
}

void RentIt::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, ReservationManager::PaymentFrequency aPaymentFrequency)
{
	reservationManager.createReservation(customerId, vehicleId, startTime, endTime, aPaymentFrequency);
}
