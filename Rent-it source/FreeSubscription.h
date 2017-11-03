#ifndef CUSTOMERMANAGER_FREE_SUBSCRIPTION_H
#define CUSTOMERMANAGER_FREE_SUBSCRIPTION_H

#include "Subscription.h"

namespace CustomerManager
{
class FreeSubscription : public Subscription
{
	FreeSubscription(unsigned short aKmFree);
private:
	unsigned short kmFree;
};
}  // namespace CustomerManager
#endif
