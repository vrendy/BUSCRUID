/*
 * Subscription.h
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#ifndef CUSTOMERMANAGER_SUBSCRIPTION_H_
#define CUSTOMERMANAGER_SUBSCRIPTION_H_

#include "PaymentFrequency.h"

namespace CustomerManager
{

enum SubscriptionType {
	free, paid
};

class Subscription
{
public:
	Subscription();
	Subscription(unsigned short aFee, SubscriptionType type, PaymentFrequency aFrequency);

	SubscriptionType getSubscriptionType() {
		return type;
	}

private:
	unsigned short fee;
	SubscriptionType type;
	PaymentFrequency paymentFrequency;
};
}  // namespace CustomerManager



#endif /* SUBSCRIPTION_H_ */
