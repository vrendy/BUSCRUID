#ifndef RESERVATIONMANAGER_CALCULATION_METHOD_H
#define RESERVATIONMANAGER_CALCULATION_METHOD_H

#include "Reservation.h"

namespace ReservationManager
{
class CalculationMethod
{
public:
	CalculationMethod();
	unsigned long calculateTotalCosts(CustomerManager::SubscriptionType subscriptionType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
