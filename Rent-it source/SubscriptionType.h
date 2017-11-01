#ifndef CUSTOMERMANAGER_SUBSCRIPTION_TYPE_H
#define CUSTOMERMANAGER_SUBSCRIPTION_TYPE_H

#include "Subscription.h"

namespace CustomerManager
{
class SubscriptionType
{
private:
	int free;

	int paid;

	Subscription subscription;
};

}  // namespace CustomerManager
#endif
