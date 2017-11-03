#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H

#include "CalculationMethod.h"
#include "Car.h"

namespace ReservationManager
{
class CalculateCheckoutLate : public ReservationManager::CalculationMethod
{
public:
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, unsigned short paymentFrequency, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
