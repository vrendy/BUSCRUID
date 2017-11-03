#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "CustomerDAO.h"
#include "ReservationDAO.h"
#include "VehicleDAO.h"


// abonnementstype, tijdseenheid, type auto, geld in eurocent
typedef std::pair<unsigned short, std::pair<unsigned short, std::pair<unsigned short, unsigned short>>> paymentRow;
// abonnementstype, type auto, geld in eurocent
typedef std::pair<unsigned short, std::pair<unsigned short, unsigned short>> pricePerKmRow;

class Database
{
	Database(Database& database) = delete;
public:
	Database();
	static Database& getDatabase();
	std::vector<CustomerManager::Customer>& getCustomerTable();
	std::vector<ReservationManager::Reservation>& getReservationTable();
	std::vector<VehicleManager::Vehicle>& getVehicleTable();
	std::vector<paymentRow>& getPaymentTable();
	std::vector<pricePerKmRow>& getPricePerKmTable();

private:
	~Database();

	std::vector<CustomerManager::Customer> customerTable;
	std::vector<ReservationManager::Reservation> reservationTable;
	std::vector<VehicleManager::Vehicle> vehicleTable;
	std::vector<paymentRow> paymentTable;
	std::vector<pricePerKmRow> pricePerKmTable;


};

#endif
