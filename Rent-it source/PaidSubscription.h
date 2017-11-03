#ifndef CUSTOMERMANAGER_PAID_SUBSCRIPTION_H
#define CUSTOMERMANAGER_PAID_SUBSCRIPTION_H

#include "Subscription.h"

namespace CustomerManager
{
class PaidSubscription : public Subscription
{
public:
	PaidSubscription();
	PaidSubscription(const PaidSubscription& aPaidSubscription);

	unsigned short getKmFree();

	SubscriptionType getSubscriptionType() {
		return type;
	}
private:
	SubscriptionType type;
};

}  // namespace CustomerManager
#endif
