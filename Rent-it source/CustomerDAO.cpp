#include "CustomerDAO.h"
#include <iostream>

namespace CustomerManager
{

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

CustomerManager::SubscriptionType CustomerDAO::getSubscriptionType(unsigned long customerId)
{
	getCustomer(customerId).getSubscription();
}

CustomerManager::PaymentFrequency CustomerDAO::getSubscriptionPaymentFrequency(unsigned long customerId)
{
}

bool CustomerDAO::customerHasLatePayments(unsigned long customerId)
{
	return 0;
}

void CustomerDAO::deleteCustomer(unsigned long customerId)
{
}

void CustomerDAO::addCustomer(std::string name, std::string adress, std::string residence, std::string mail, std::string bankNbr)
{
}

void CustomerDAO::addToDatabase(Customer customer)
{

}
}  // namespace Sequence
