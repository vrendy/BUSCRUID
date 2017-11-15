#include "RentIt.h"

#include "Database.h"

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

void RentIt::chooseCar(VehicleManager::Car car)
{
	// Wat willen we hiermee? we kunnen niet even een car zetten in rent it en later een reservation van maken
}

void RentIt::chooseSubscriptionType(CustomerManager::Subscription subscriptionType)
{
	// idem choose car
}

void RentIt::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkinTime, unsigned short endTime, unsigned short km)
{
	// get reservation op basis van customer id, vehicle id, checkintime en checkouttime, roep op said reservation calculateMethod aan
}

void RentIt::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, ReservationManager::PaymentFrequency aPaymentFrequency)
{
	reservationManager.createReservation(customerId, vehicleId, startTime, endTime, aPaymentFrequency);
}
