#ifndef RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H
#define RESERVATIONMANAGER_CALCULATE_CHECKOUT_LATE_H

#include "CalculationMethod.h"

namespace ReservationManager
{
class CalculateCheckoutLate : public ReservationManager::CalculationMethod
{
public:
	CalculateCheckoutLate();
	virtual ~CalculateCheckoutLate();
	unsigned long calculateTotalCosts(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId, unsigned short extraTime);
	unsigned long calculateTotalKmCost(CustomerManager::subscription_ptr sub, unsigned short km, VehicleManager::VehicleType vt);
	unsigned long calculateFineCost(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, VehicleManager::VehicleType vt);
	unsigned long calculateExtraTimeCost(CustomerManager::subscription_ptr sub, unsigned short extraTime);

private:
	const unsigned char fineMultiplier = 2;

};

}  // namespace ReservationManager
#endif
