#include "Customer.h"
#include "FreeSubscription.h"
#include "PaidSubscription.h"

#include <iostream>

namespace CustomerManager
{

static unsigned long customerCounter = 0;

Customer::Customer(std::string aName, std::string anAddress, std::string aResidence, std::string anEmail, std::string aBankNbr, SubscriptionType subType)
	: customerId(++customerCounter), name(aName), address(anAddress), residence(aResidence), email(anEmail), bankNbr(aBankNbr)
{
	switch(subType)
	{
	case SubscriptionType::free:
	{
		subscription = FreeSubscription();
		break;
	}
	case SubscriptionType::paid:
		subscription = PaidSubscription();
		break;
	}
	std::cout << __PRETTY_FUNCTION__ << " " << name << " Subscription type: " << subscription.getSubscriptionType() << std::endl;
}

unsigned long Customer::getCustomerId() {
	return customerId;
}

Subscription& Customer::getSubscription() {
	return subscription;
}


}  // namespace CustomerManager

