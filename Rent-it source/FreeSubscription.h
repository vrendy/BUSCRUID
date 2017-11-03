#ifndef CUSTOMERMANAGER_FREE_SUBSCRIPTION_H
#define CUSTOMERMANAGER_FREE_SUBSCRIPTION_H

#include "Subscription.h"

namespace CustomerManager
{
class FreeSubscription : public Subscription
{
public:
	FreeSubscription();
//	FreeSubscription(unsigned short aFee, SubscriptionType type, unsigned short aKmFree);

	unsigned short getKmFree();

	SubscriptionType getSubscriptionType() {
		return type;
	}
private:
	SubscriptionType type;
};
}  // namespace CustomerManager
#endif
