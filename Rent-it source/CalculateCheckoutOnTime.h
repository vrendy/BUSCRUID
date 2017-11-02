#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H

#include "CalculationMethod.h"
#include "PaymentFrequency.h"
#include "Car.h"

namespace ReservationManager
{
class CalculateCheckoutOnTime : public ReservationManager::CalculationMethod
{
public:
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, CustomerManager::PaymentFrequency paymentFrequency, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
