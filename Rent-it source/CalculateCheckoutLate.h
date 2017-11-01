#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H

#include "CalculationMethod.h"
#include "PaymentFrequency.h"
#include "Car.h"

namespace ReservationManager
{
class CalculateCheckoutLate : public ReservationManager::CalculationMethod
{
public:
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, CustomerManager::PaymentFrequency paymentFrequency, unsigned short km, VehicleManager::Car car);

};

}  // namespace ReservationManager
#endif
