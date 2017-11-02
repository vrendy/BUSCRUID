#include "Customer.h"

namespace CustomerManager
{

static unsigned long customerCounter = 0;

Customer::Customer(std::string aName, std::string anAddress, std::string aResidence, std::string anEmail, std::string aBankNbr)
	: customerId(++customerCounter), name(aName), address(anAddress), residence(aResidence), email(anEmail), bankNbr(aBankNbr)
{
}

unsigned long Customer::getCustomerId() {
	return customerId;
}

Subscription& Customer::getSubscription() {
	return subscription;
}


}  // namespace CustomerManager

