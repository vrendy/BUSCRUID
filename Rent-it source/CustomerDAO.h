#ifndef CUSTOMERMANAGER_CUSTOMER_DAO_H
#define CUSTOMERMANAGER_CUSTOMER_DAO_H

#include <string>


#include "Customer.h"
#include "Database.h"
#include "SubscriptionType.h"
#include "PaymentFrequency.h"

namespace CustomerManager
{
class CustomerDAO
{
public:
	void createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr);

	Customer getCustomer(unsigned long customerId);

	SubscriptionType getSubscriptionType(unsigned long customerId);

	PaymentFrequency getSubscriptionPaymentFrequency(unsigned long customerId);

	bool customerHasLatePayments(unsigned long customerId);

	void deleteCustomer(unsigned long customerId);

	void addCustomer(std::string name, std::string adress, std::string residence, std::string mail, std::string bankNbr);

	void addToDatabase(Customer customer);
};

}  // namespace CustomerManager
#endif
