#ifndef RENT_IT_H
#define RENT_IT_H


#include <string.h>

#include "Location.h"
#include "Car.h"
#include "CustomerDAO.h"
#include "Subscription.h"
#include "DateTime.h"
#include "ReservationDAO.h"
#include "VehicleDAO.h"

class RentIt
{
private:
	ReservationManager::ReservationDAO reservationManager;
	CustomerManager::CustomerDAO customerManager;
	VehicleManager::VehicleDAO vehicleManager;

public:
	void getLocations();

	void addCustomer(std::string name, std::string address, std::string city, std::string email, std::string bankNbr);

	void getAvailableVehicles(VerhicleManager::Location location, dateTime startTime, dateTime endTime);

	void chooseCar(VehicleManager::Car car);

	void chooseSubscriptionType(CustomerManager::Subscription subscriptionType);

	void processModuleData(unsigned long customerId, unsigned short vehicleId, DateTime checkinTime, DateTime endTime, unsigned short km);

	void createReservation(unsigned long customerId, unsigned short vehicleId, DateTime startTime, DateTime endTime, std::string paymentFrequency);

};
#endif
