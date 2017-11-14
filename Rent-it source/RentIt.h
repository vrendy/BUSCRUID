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
private:
	ReservationManager::ReservationDAO reservationManager;
	CustomerManager::CustomerDAO customerManager;
	VehicleManager::VehicleDAO vehicleManager;

public:
	std::vector<VehicleManager::Location>& getLocations();

	void addCustomer(std::string name, std::string address, std::string city, std::string email, std::string bankNbr, CustomerManager::SubscriptionType subType);

	std::vector<VehicleManager::Vehicle>& getAvailableVehicles(VehicleManager::Location location, unsigned short startTime, unsigned short endTime);

	void chooseCar(VehicleManager::Car car);

	void chooseSubscriptionType(CustomerManager::Subscription subscriptionType);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkinTime, unsigned short endTime, unsigned short km);

	void createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, std::string paymentFrequency);

};
#endif
