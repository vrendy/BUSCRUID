/*
 * Subscription.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */




#include "Subscription.h"

namespace CustomerManager
{
	Subscription::Subscription() : fee(0)//, type(SubscriptionType::paid) // Kan dit geen kwaad dat hier free standaard staat?
	{

	}

	Subscription::Subscription(unsigned short aFee, SubscriptionType aType)
		: fee(aFee), type(aType) {
	}

	Subscription::Subscription(const Subscription& aSubscription)
		: fee(aSubscription.fee), type(aSubscription.type)
	{
	}
}


