#include "CustomerDAO.h"
#include <iostream>

namespace CustomerManager
{

CustomerDAO::CustomerDAO()
{}

void CustomerDAO::createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr)
{
	Customer c(name, adress, residence, email, bankNbr);
	Database::getDatabase().getCustomerTable().push_back(c);
}

Customer CustomerDAO::getCustomer(unsigned long customerId)
{
	try {
		for(Customer c : Database::getDatabase().getCustomerTable())  {
			if(c.getCustomerId() == customerId) {
				return c;
			}
		}
	}
	catch(int e) {
		std::cout << "customerId is invalid\n" << "Exception: " + e << std::endl;
	}
}

SubscriptionType CustomerDAO::getSubscriptionType(unsigned long customerId)
{
	return getCustomer(customerId).getSubscription().getSubscriptionType();
}

bool CustomerDAO::customerHasLatePayments(unsigned long customerId)
{
	return 0;
}


}  // namespace Sequence
