/*
 * main.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#include "Database.h"
#include "CustomerDAO.h"

#include <string>
#include <iostream>

void initDatabase()
{
	// Fill Database payment data
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::car, 600))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::station, 750))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::car, 5000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::station, 6000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::car, 7000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::station, 9000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::car, 15000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::station, 18000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::car, 400))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::station, 550))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::car, 4000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::station, 5000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::car, 6000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::station, 8000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::car, 14000))));
	Database::getDatabase().getPaymentTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::station, 17000))));

	// Fill Database price per km
	Database::getDatabase().getPricePerKmTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(VehicleManager::VehicleType::car, 30)));
	Database::getDatabase().getPricePerKmTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(VehicleManager::VehicleType::station, 35)));
	Database::getDatabase().getPricePerKmTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(VehicleManager::VehicleType::car, 25)));
	Database::getDatabase().getPricePerKmTable().push_back(std::make_pair(CustomerManager::SubscriptionType::paid, std::make_pair(VehicleManager::VehicleType::station, 30)));

}

int main(int argc, char **argv) {
	initDatabase();
	CustomerManager::CustomerDAO cusManager;
	cusManager.createCustomer(std::string("Chris van Uffelen"), std::string("Ruitenberglaan 69"), std::string("Arnhem"), std::string("Chris.vanUffelen@han.nl"), std::string("NL69FIETS012345678"), CustomerManager::SubscriptionType::paid);
	std::cout << "Customer with ID: " << Database::getDatabase().getCustomerTable().at(0).getCustomerId() << " and SubscriptionType (0 for free, 1 for paid): " << Database::getDatabase().getCustomerTable().at(0).getSubscription()->getSubscriptionType() << std::endl;
	return 0;
}

