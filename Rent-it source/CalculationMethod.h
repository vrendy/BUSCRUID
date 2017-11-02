#ifndef RESERVATIONMANAGER_CALCULATION_METHOD_H
#define RESERVATIONMANAGER_CALCULATION_METHOD_H

#include "Reservation.h"
#include "PaymentFrequency.h"
#include "Car.h"

namespace ReservationManager
{
class CalculationMethod
{
public:
	CalculationMethod();
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, CustomerManager::PaymentFrequency paymentFrequency, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
