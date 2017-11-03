/*
 * main.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#include "Database.h"

void initDatabase()
{
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::car, 600))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::hour, std::make_pair(VehicleManager::VehicleType::station, 750))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::car, 5000))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::day, std::make_pair(VehicleManager::VehicleType::station, 6000))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::car, 7000))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::weekend, std::make_pair(VehicleManager::VehicleType::station, 9000))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::car, 15000))));
	Database::getDatabase().getPaymentFreeTable().push_back(std::make_pair(CustomerManager::SubscriptionType::free, std::make_pair(ReservationManager::PaymentFrequency::week, std::make_pair(VehicleManager::VehicleType::station, 18000))));

}

int main(int argc, char **argv) {
	initDatabase();
	return 0;
}

