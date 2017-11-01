#ifndef RESERVATIONMANAGER_CALCULATION_METHOD_H
#define RESERVATIONMANAGER_CALCULATION_METHOD_H

#include "Reservation.h"
#include "PaymentFrequency.h"
#include "Car.h"

namespace ReservationManager
{
class CalculationMethod
{
private:
	Reservation reservation;

public:
	unsigned long calculateTotalCosts(unsigned long subscriptionPrice, CustomerManager::PaymentFrequency paymentFrequency, unsigned short km, VehicleManager::Car car);

};

}  // namespace ReservationManager
#endif
