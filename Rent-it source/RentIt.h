#ifndef RENT_IT_H
#define RENT_IT_H


#include <string>
#include <vector>

#include "Location.h"
#include "Car.h"
#include "CustomerDAO.h"
#include "Subscription.h"
#include "ReservationDAO.h"
#include "VehicleDAO.h"

class RentIt
{
public:
	RentIt(){};

	static RentIt& getRentIt();

	signed short makeReservation();

	std::vector<VehicleManager::Location>& getLocations();

	void addCustomer(std::string name, std::string address, std::string city, std::string email, std::string bankNbr, CustomerManager::SubscriptionType subType);

	std::vector<VehicleManager::Vehicle> getAvailableVehicles(VehicleManager::Location location, unsigned short startTime, unsigned short endTime);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkinTime, unsigned short endTime, unsigned short km);

private:
	unsigned short chooseLocation();
	signed short chooseCar(unsigned short locationId, unsigned short startTimeStamp, unsigned short endTimeStamp);
	void chooseSubscriptionType(CustomerManager::Subscription subscriptionType);
	void createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, ReservationManager::PaymentFrequency aPaymentFrequency);


	ReservationManager::ReservationDAO reservationManager;
	CustomerManager::CustomerDAO customerManager;
	VehicleManager::VehicleDAO vehicleManager;


};
#endif
