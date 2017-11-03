#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H

#include "CalculationMethod.h"

namespace ReservationManager
{
class CalculateCheckoutLate : public ReservationManager::CalculationMethod
{
public:
	unsigned long calculateTotalCosts(CustomerManager::SubscriptionType subscriptionType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
