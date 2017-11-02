/*
 * Subscription.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */




#include "Subscription.h"

namespace CustomerManager
{
	Subscription::Subscription()
	{

	}

	Subscription::Subscription(unsigned short aFee, SubscriptionType aType, PaymentFrequency aFrequency)
		: fee(aFee), type(aType), paymentFrequency(aFrequency) {
	}
}


