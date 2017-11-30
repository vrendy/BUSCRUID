#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_ON_TIME_H

#include "CalculationMethod.h"
#include "Car.h"

namespace ReservationManager
{
class CalculateCheckoutOnTime : public CalculationMethod
{
public:
	CalculateCheckoutOnTime();
	virtual ~CalculateCheckoutOnTime();

	unsigned long calculateTotalCosts(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId, unsigned short extraTime);

	unsigned long calculateTotalKmCost(CustomerManager::subscription_ptr sub, unsigned short km, VehicleManager::VehicleType vt);

	unsigned long calculateTotalTimeCost(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, VehicleManager::VehicleType vt);

};

}  // namespace ReservationManager
#endif
