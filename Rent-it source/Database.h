#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "CustomerDAO.h"
#include "ReservationDAO.h"
#include "VehicleDAO.h"


// tijdseenheid, type auto, geld in eurocent
typedef std::pair<unsigned short, std::pair<unsigned short, std::pair<unsigned short, unsigned short>>> paymentFreeRow;

class Database
{
	Database(Database& database) = delete;
public:
	Database();
	static Database& getDatabase();
	std::vector<CustomerManager::Customer>& getCustomerTable();
	std::vector<ReservationManager::Reservation>& getReservationTable();
	std::vector<VehicleManager::Vehicle>& getVehicleTable();
	std::vector<paymentFreeRow>& getPaymentFreeTable();

private:
	~Database();

	std::vector<CustomerManager::Customer> customerTable;
	std::vector<ReservationManager::Reservation> reservationTable;
	std::vector<VehicleManager::Vehicle> vehicleTable;
	std::vector<std::pair<unsigned short, std::pair<unsigned short, unsigned short>>> paymentTable;


};

#endif
