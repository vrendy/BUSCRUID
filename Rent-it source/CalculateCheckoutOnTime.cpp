#include "CalculateCheckoutOnTime.h"
#include "Database.h"

namespace ReservationManager
{

unsigned long CalculateCheckoutOnTime::calculateTotalCosts(unsigned short subscriptionType, unsigned short paymentFrequency, unsigned short km, unsigned short vehicleId)
{
	unsigned short costPerKm = 0;
	unsigned long totalKmCost = 0;
	for(paymentFreeRow free : Database::getDatabase().getPaymentFreeTable())
	{
		if(free.first == subscriptionType && free.second.first == paymentFrequency /*&& free.second.second.first == translate vehicleId to vehicleType*/)
			costPerKm = free.second.second.second; // Top kek

	}
	totalKmCost = costPerKm * km;

	return 0;
}
}  // namespace ReservationManager
