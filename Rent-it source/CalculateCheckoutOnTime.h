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

	unsigned long calculateTotalCosts(CustomerManager::SubscriptionType subType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId);

	unsigned long calculateTotalKmCost(CustomerManager::SubscriptionType subType, unsigned short km, VehicleManager::VehicleType vt);

	unsigned long calculateTotalTimeCost(CustomerManager::SubscriptionType subType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, VehicleManager::VehicleType vt);

};

}  // namespace ReservationManager
#endif
