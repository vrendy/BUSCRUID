/*
 * Subscription.h
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#ifndef CUSTOMERMANAGER_SUBSCRIPTION_H_
#define CUSTOMERMANAGER_SUBSCRIPTION_H_

#include <memory>

namespace CustomerManager
{
enum SubscriptionType {
	free, paid
};
class Subscription;
typedef std::shared_ptr<Subscription> subscription_ptr;
class Subscription
{
public:
	Subscription(SubscriptionType aType);
	Subscription(unsigned short aFee, SubscriptionType aType);
	Subscription(const Subscription& aSubscription);

	SubscriptionType getSubscriptionType() {
		return type;
	}

protected:
	SubscriptionType type;

private:
	unsigned short fee;
};
}  // namespace CustomerManager



#endif /* SUBSCRIPTION_H_ */
