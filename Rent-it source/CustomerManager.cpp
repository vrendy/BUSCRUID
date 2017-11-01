#include "CustomerManager.h"

namespace CustomerManager
{

void CustomerManager::createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr)
{
}

Customer CustomerManager::getCustomer(unsigned long customerId)
{
	return 0;
}

CustomerManager::SubscriptionType CustomerManager::getSubscriptionType(unsigned long customerId)
{
	return 0;
}

CustomerManager::PaymentFrequency CustomerManager::getSubscriptionPaymentFrequency(unsigned long customerId)
{
	return 0;
}

boolean CustomerManager::customerHasLatePayments(unsigned long customerId)
{
	return 0;
}

void CustomerManager::deleteCustomer(unsigned long customerId)
{
}

void CustomerManager::addCustomer(std::string name, std::string adress, std::string residence, std::string mail, std::string bankNbr)
{
}
}  // namespace Sequence
