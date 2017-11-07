#include "PaidSubscription.h"
#include <iostream>

namespace CustomerManager
{
static unsigned short kmFree = 100;

PaidSubscription::PaidSubscription() : Subscription(SubscriptionType::paid)
{
}

unsigned short PaidSubscription::getKmFree()
{
	return kmFree;
}

}  // namespace CustomerManager
