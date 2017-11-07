#include "Customer.h"
#include "FreeSubscription.h"
#include "PaidSubscription.h"

#include <iostream>
#include <memory>

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
		subscription = std::make_shared<FreeSubscription>();
		break;
	}
	case SubscriptionType::paid:
		subscription = std::make_shared<PaidSubscription>();
		break;
	}
}

Customer::Customer(const Customer& c) : customerId(c.customerId), name(c.name), address(c.address), residence(c.residence), email(c.email), bankNbr(c.bankNbr), subscription(c.subscription)
{
}

unsigned long Customer::getCustomerId() {
	return customerId;
}

subscription_ptr Customer::getSubscription() {
	return subscription;
}


}  // namespace CustomerManager

