#ifndef CUSTOMERMANAGER_PAID_SUBSCRIPTION_H
#define CUSTOMERMANAGER_PAID_SUBSCRIPTION_H

#include "Subscription.h"

namespace CustomerManager
{
class PaidSubscription : public Subscription
{
	PaidSubscription(unsigned short aKmFree);
private:
	unsigned short kmFree;
};

}  // namespace CustomerManager
#endif
