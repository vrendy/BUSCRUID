#include "CalculateCheckoutLate.h"
#include "Database.h"
#include "Vehicle.h"

namespace ReservationManager
{

CalculateCheckoutLate::CalculateCheckoutLate() {}

CalculateCheckoutLate::~CalculateCheckoutLate() {}

unsigned long CalculateCheckoutLate::calculateTotalCosts(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId, unsigned short extraTime)
{
	// Get vehicle type from database
	VehicleManager::VehicleType vt = VehicleManager::VehicleType::uninitialized;
	for(VehicleManager::Vehicle v : Database::getDatabase().getVehicleTable())
	{
		if(v.getId() == vehicleId)
		{
			vt = v.getType();
		}
	}
	// Delegate calculations of total KM and total TIME
	return calculateTotalKmCost(sub, km, vt) + calculateFineCost(sub, paymentFrequency, timeToBePaidFor, vt) + calculateExtraTimeCost(sub, extraTime);
}

unsigned long CalculateCheckoutLate::calculateTotalKmCost(CustomerManager::subscription_ptr sub, unsigned short km, VehicleManager::VehicleType vt)
{
	unsigned short pricePerKm = 0;
	unsigned short kmFree = sub->getKmFree();
for(pricePerKmRow row : Database::getDatabase().getPricePerKmTable())
	{
		if(row.first == sub->getSubscriptionType() && row.second.first == vt)
		{
			pricePerKm = row.second.second;
		}
	}
	return (km - kmFree) * pricePerKm;
}

unsigned long CalculateCheckoutLate::calculateFineCost(CustomerManager::subscription_ptr sub, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, VehicleManager::VehicleType vt)
{
	unsigned short costPerTimeUnit = 0;

	// Get cost per time unit
	for(paymentRow row : Database::getDatabase().getPaymentTable())
	{
		if(row.first == sub->getSubscriptionType() && row.second.first == paymentFrequency && row.second.second.first == vt)
			costPerTimeUnit = row.second.second.second; // Top kek

	}

	// return totalTimeCost
	return (costPerTimeUnit * timeToBePaidFor) * fineMultiplier;
}

unsigned long CalculateCheckoutLate::calculateExtraTimeCost(CustomerManager::subscription_ptr sub, unsigned short extraTime)
{
	unsigned short costPerTimeUnit = 0;

	for(paymentRow row : Database::getDatabase().getPaymentTable())
	{
		if(row.first == sub->getSubscriptionType() && row.second.first == PaymentFrequency::hour)
			costPerTimeUnit = row.second.second.second; // Top kek
	}

	return costPerTimeUnit * extraTime;
}


}  // namespace ReservationManager
