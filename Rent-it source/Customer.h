#ifndef CUSTOMERMANAGER_CUSTOMER_H
#define CUSTOMERMANAGER_CUSTOMER_H

#include "Subscription.h"
#include <string>

namespace CustomerManager
{
class Customer
{
public:
	Customer(std::string aName, std::string anAdress, std::string aResidence, std::string anEmail, std::string aBankNbr, SubscriptionType subType);

	unsigned long getCustomerId();
	Subscription& getSubscription();

private:
	unsigned long customerId;
	std::string name;
	std::string address;
	std::string residence;
	std::string email;
	std::string bankNbr;

	Subscription subscription;
};

}  // namespace CustomerManager
#endif
