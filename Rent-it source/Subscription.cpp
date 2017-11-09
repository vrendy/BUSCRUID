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
	Subscription::Subscription(SubscriptionType aType) : type(aType), fee(0), kmFree(0)
	{
	}

	Subscription::Subscription(SubscriptionType aType, unsigned short aFee)
		: type(aType), fee(aFee), kmFree(0)
	{

	}

	Subscription::Subscription(const Subscription& aSubscription)
		: type(aSubscription.type), fee(aSubscription.fee), kmFree(aSubscription.kmFree)
	{

	}

	unsigned short Subscription::getKmFree()
	{
		return kmFree;
	}
}


