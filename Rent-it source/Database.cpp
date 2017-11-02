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
