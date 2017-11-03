#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H

#include "CalculationMethod.h"
#include "Car.h"

namespace ReservationManager
{
class CalculateCheckoutOnTime : public ReservationManager::CalculationMethod
{
public:
	unsigned long calculateTotalCosts(unsigned short subscriptionType, unsigned short paymentFrequency, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
