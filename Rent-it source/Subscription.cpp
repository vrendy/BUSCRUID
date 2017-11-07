/*
 * Subscription.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */




#include "Subscription.h"
#include <iostream>

namespace CustomerManager
{
	Subscription::Subscription(SubscriptionType aType) : fee(0), type(aType)
	{
	}

	Subscription::Subscription(unsigned short aFee, SubscriptionType aType)
		: fee(aFee), type(aType)
	{

	}

	Subscription::Subscription(const Subscription& aSubscription)
		: fee(aSubscription.fee), type(aSubscription.type)
	{

	}
}


