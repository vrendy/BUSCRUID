#ifndef CUSTOMERMANAGER_PAYMENT_FREQUENCY_H
#define CUSTOMERMANAGER_PAYMENT_FREQUENCY_H

#include "Subscription.h"

namespace CustomerManager
{
class PaymentFrequency
{
private:
	int hour;

	int day;

	int weekend;

	int week;

	Subscription subscription;
};

}  // namespace CustomerManager
#endif
