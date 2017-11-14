#include "Database.h"

Database::Database()
{

}

Database::~Database()
{

}

/* static */ Database& Database::getDatabase()
{
	static Database database;
	return database;
}

std::vector<CustomerManager::Customer>& Database::getCustomerTable() {
	return customerTable;
}

std::vector<ReservationManager::Reservation>& Database::getReservationTable()
{
	return reservationTable;
}

std::vector<VehicleManager::Vehicle>& Database::getVehicleTable() {
	return vehicleTable;
}

std::vector<paymentRow>& Database::getPaymentTable()
{
	return paymentTable;
}

std::vector<pricePerKmRow>& Database::getPricePerKmTable()
{
	return pricePerKmTable;
}

std::vector<VehicleManager::Location>& Database::getLocationTable()
{
	return locationTable;
}
