/*
 * main.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#include "Database.h"
//#include "CustomerDAO.h"
//#include "ReservationDAO.h"

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

	//Add car(s) to Database
	Database::getDatabase().getVehicleTable().push_back(VehicleManager::Vehicle(VehicleManager::VehicleType::car));
	Database::getDatabase().getVehicleTable().push_back(VehicleManager::Vehicle(VehicleManager::VehicleType::station));
}

void useCar(unsigned long customerId, unsigned short vehicleId, unsigned short startTimeStamp, unsigned short endTimeStamp, unsigned short nKm) {
	ReservationManager::ReservationDAO::getReservationDAO().processModuleData(customerId, vehicleId, startTimeStamp, endTimeStamp, nKm);
}

class CustomerDAO;
class ReservationDAO;

int main(int argc, char **argv) {
	initDatabase();

	//---------- [Voorbeeld data] ----------//
	CustomerManager::CustomerDAO::getCustomerDAO().createCustomer(std::string("Chris van Uffelen"), std::string("Ruitenberglaan 69"), std::string("Arnhem"), std::string("Chris.vanUffelen@han.nl"), std::string("NL69FIETS012345678"), CustomerManager::SubscriptionType::paid);
	std::cout << "Customer with ID: " << Database::getDatabase().getCustomerTable().at(0).getCustomerId() << " and SubscriptionType (0 for free, 1 for paid): " << Database::getDatabase().getCustomerTable().at(0).getSubscription()->getSubscriptionType() << std::endl;
	std::cout << "Vehicle 1 ID: " << Database::getDatabase().getVehicleTable().at(0).getId() << "\nVehicle 2 ID: " << Database::getDatabase().getVehicleTable().at(1).getId() << std::endl;



	//---------- [Test Cases] ----------//

	//Maak een reservatie en gebruik de auto binnen deze tijden.
	ReservationManager::ReservationDAO::getReservationDAO().createReservation(1,1,50,200, ReservationManager::PaymentFrequency::hour);
	useCar(Database::getDatabase().getCustomerTable().at(0).getCustomerId(), Database::getDatabase().getVehicleTable().at(0).getId(), 100, 165, 95);
	std::cout << "\nIncheck + uitcheck binnen reservatie:\n" << ReservationManager::ReservationDAO::getReservationDAO().getReservation(1,1,100,165);

	//Maak een reservatie, maar gebruik de auto niet.
	ReservationManager::ReservationDAO::getReservationDAO().createReservation(1,1,250,300, ReservationManager::PaymentFrequency::day);
	useCar(Database::getDatabase().getCustomerTable().at(0).getCustomerId(), Database::getDatabase().getVehicleTable().at(0).getId(), 260, 290, 0);
	std::cout << "\nGeen incheck:\n" << ReservationManager::ReservationDAO::getReservationDAO().getReservation(1,1,250,300);

	return 0;
}

