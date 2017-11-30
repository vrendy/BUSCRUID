/*
 * main.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#include "RentIt.h"
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

	// Add Locations to Database
	Database::getDatabase().getLocationTable().push_back(VehicleManager::Location("Arnhem"));
	Database::getDatabase().getLocationTable().push_back(VehicleManager::Location("Doetinchem"));

	//Add car(s) to Database
	Database::getDatabase().getVehicleTable().push_back(VehicleManager::Vehicle(VehicleManager::VehicleType::car, Database::getDatabase().getLocationTable().at(0)));
	Database::getDatabase().getVehicleTable().push_back(VehicleManager::Vehicle(VehicleManager::VehicleType::station, Database::getDatabase().getLocationTable().at(0)));
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

	//Maak een reservatie, maar gebruik de auto niet.
	ReservationManager::ReservationDAO::getReservationDAO().createReservation(1,1,100,200, ReservationManager::PaymentFrequency::hour);
	RentIt::getRentIt().processModuleData(Database::getDatabase().getCustomerTable().at(0).getCustomerId(), Database::getDatabase().getVehicleTable().at(0).getId(), 125, 175, 0);
	std::cout << "\nGeen incheck:\n" << ReservationManager::ReservationDAO::getReservationDAO().getReservation(1,1,100,200);

	//Maak een reservatie en gebruik de auto binnen deze tijden.
	ReservationManager::ReservationDAO::getReservationDAO().createReservation(1,1,300,400, ReservationManager::PaymentFrequency::hour);
	RentIt::getRentIt().processModuleData(Database::getDatabase().getCustomerTable().at(0).getCustomerId(), Database::getDatabase().getVehicleTable().at(0).getId(), 325, 375, 100);
	std::cout << "\nIncheck + uitcheck binnen reservatie:\n" << ReservationManager::ReservationDAO::getReservationDAO().getReservation(1,1,300,400);

	//Maak een reservatie, gebruik auto en lever te laat in
	ReservationManager::ReservationDAO::getReservationDAO().createReservation(1,1,500,600, ReservationManager::PaymentFrequency::hour);
	RentIt::getRentIt().processModuleData(Database::getDatabase().getCustomerTable().at(0).getCustomerId(), Database::getDatabase().getVehicleTable().at(0).getId(), 575, 625, 100);
	std::cout << "\nGeen incheck:\n" << ReservationManager::ReservationDAO::getReservationDAO().getReservation(1,1,500,600);

	/* Command line user interface niet afgemaakt
	RentIt::getRentIt().addCustomer();

	switch(RentIt::getRentIt().makeReservation())
	{
	case -1:
		std::cout << "No reservation created..." << std::endl;
		break;
	case 1:
		std::cout << "Reservation created!" << std::endl;
		break;
	}*/


	return 0;
}

// Deze applicatie moet Kan:
// - Reserveer auto
// - Rij weg met auto
// - Breng auto terug
// - Rekening wordt opgemaakt
// 		- Op tijd wegrijden en terugbrengen
//		- Als er niet wordt weggereden
//		- Als er te laat wordt terug gebracht

