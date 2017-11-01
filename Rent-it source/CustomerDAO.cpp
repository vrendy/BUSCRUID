#include "CustomerDAO.h"

namespace CustomerManager
{

void CustomerDAO::createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr)
{
}

Customer CustomerDAO::getCustomer(unsigned long customerId)
{
}

CustomerManager::SubscriptionType CustomerDAO::getSubscriptionType(unsigned long customerId)
{
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
