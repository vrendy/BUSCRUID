#ifndef DESIGN CLASS_PAYMENT_FREQUENCY_H
#define DESIGN CLASS_PAYMENT_FREQUENCY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Subscription.h"

namespace Design Class
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

}  // namespace Design Class
#endif
