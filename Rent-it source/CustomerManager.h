#ifndef SEQUENCE_CUSTOMER_MANAGER_H
#define SEQUENCE_CUSTOMER_MANAGER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "std::string.h"
#include "Sequence/RentIt.h"
#include "Sequence/Customer.h"
#include "Design Class/Database.h"
#include "Design Class/SubscriptionType.h"
#include "Design Class/PaymentFrequency.h"

namespace Sequence
{
class CustomerManager
{
private:
	RentIt rentIt;
	Customer customer[];
	Design Class::Database database;

public:
	void createCustomer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr);

	Customer getCustomer(unsigned long customerId);

	Design Class::SubscriptionType getSubscriptionType(unsigned long customerId);

	Design Class::PaymentFrequency getSubscriptionPaymentFrequency(unsigned long customerId);

	boolean customerHasLatePayments(unsigned long customerId);

	void deleteCustomer(unsigned long customerId);

	void addCustomer(std::string name, std::string adress, std::string residence, std::string mail, std::string bankNbr);

};

}  // namespace Sequence
#endif
