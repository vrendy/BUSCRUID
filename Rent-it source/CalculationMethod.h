#ifndef RESERVATIONMANAGER_CALCULATION_METHOD_H
#define RESERVATIONMANAGER_CALCULATION_METHOD_H

#include "Reservation.h"

namespace ReservationManager
{
class CalculationMethod
{
public:
	CalculationMethod();
	virtual ~CalculationMethod();
	virtual unsigned long calculateTotalCosts(CustomerManager::SubscriptionType subType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId) = 0;

};

}  // namespace ReservationManager
#endif
