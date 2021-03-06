#ifndef CUSTOMERMANAGER_CUSTOMER_DAO_H
#define CUSTOMERMANAGER_CUSTOMER_DAO_H

#include <string>


#include "Customer.h"
#include "Database.h"

namespace CustomerManager
{

class CustomerDAO
{
	CustomerDAO(const Customer& aCustomer) = delete;
//	~CustomerDAO() = delete;
public:
	CustomerDAO();
	~CustomerDAO(); // Deze moet toch private? maar geeft error wanneer private
	static CustomerDAO getCustomerDAO();

	void createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr, SubscriptionType subType);

	Customer getCustomer(unsigned long customerId);

	SubscriptionType getSubscriptionType(unsigned long customerId);

	bool customerHasLatePayments(unsigned long customerId);

	void deleteCustomer(unsigned long customerId);

	std::string SubscriptionTypeToString(SubscriptionType st);
};

}  // namespace CustomerManager
#endif
