#include "RentIt.h"

void RentIt::getLocations()
{
}

void RentIt::addCustomer(std::string name, std::string address, std::string city, std::string email, std::string bankNbr)
{
}

void RentIt::getAvailableVehicles(VehicleManager::Location location, unsigned short startTime, unsigned short endTime)
{
}

void RentIt::chooseCar(VehicleManager::Car car)
{
}

void RentIt::chooseSubscriptionType(CustomerManager::Subscription subscriptionType)
{
}

void RentIt::processModuleData(unsigned long customerId, unsigned short vehicleId, unsigned short checkinTime, unsigned short endTime, unsigned short km)
{
}

void RentIt::createReservation(unsigned long customerId, unsigned short vehicleId, unsigned short startTime, unsigned short endTime, std::string paymentFrequency)
{
}
