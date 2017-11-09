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
//	PaidSubscription operator=(const PaidSubscription& ps);

	unsigned short getKmFree();
private:
	unsigned short kmFree;
};

}  // namespace CustomerManager
#endif
