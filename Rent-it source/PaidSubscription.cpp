#include "PaidSubscription.h"

namespace CustomerManager
{
static unsigned short kmFree = 100;

PaidSubscription::PaidSubscription() : type(SubscriptionType::paid)
{

}

PaidSubscription::PaidSubscription(const PaidSubscription& aPaidSubscription)
	: type(aPaidSubscription.type) // Kan dit ook type(SubscriptionType::paid) maken
{
}

unsigned short PaidSubscription::getKmFree()
{
	return kmFree;
}

}  // namespace CustomerManager
