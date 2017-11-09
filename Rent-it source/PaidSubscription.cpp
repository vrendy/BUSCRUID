#include "PaidSubscription.h"
#include <iostream>

namespace CustomerManager
{
PaidSubscription::PaidSubscription() : Subscription(SubscriptionType::paid), kmFree(100)
{
}

unsigned short PaidSubscription::getKmFree()
{
	return kmFree;
}

}  // namespace CustomerManager
