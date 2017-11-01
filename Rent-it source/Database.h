#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "CustomerDAO.h"
#include "ReservationDAO.h"
#include "VehicleDAO.h"


class Database
{
private:
	std::vector<CustomerManager::Customer> customerTable;
	std::vector<ReservationManager::Reservation> reservationTable;
	std::vector<VehicleManager::Vehicle> vehicleTable;
};

#endif
