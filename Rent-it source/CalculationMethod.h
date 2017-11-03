#ifndef RESERVATIONMANAGER_CALCULATION_METHOD_H
#define RESERVATIONMANAGER_CALCULATION_METHOD_H

#include "Reservation.h"
#include "Car.h"

namespace ReservationManager
{
class CalculationMethod
{
public:
	CalculationMethod();
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, unsigned short paymentFrequency, unsigned short km, unsigned short vehicleId);

};

}  // namespace ReservationManager
#endif
