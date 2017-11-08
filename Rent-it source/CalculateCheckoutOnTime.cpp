#include "CalculateCheckoutOnTime.h"
#include "Database.h"
#include "Vehicle.h"

namespace ReservationManager
{

CalculateCheckoutOnTime::CalculateCheckoutOnTime() : CalculationMethod() {}

CalculateCheckoutOnTime::~CalculateCheckoutOnTime() {}

unsigned long CalculateCheckoutOnTime::calculateTotalCosts(CustomerManager::SubscriptionType subType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, unsigned short km, unsigned short vehicleId)
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
	return calculateTotalKmCost(subType, km, vt) + calculateTotalTimeCost(subType, paymentFrequency, timeToBePaidFor, vt);
}

unsigned long CalculateCheckoutOnTime::calculateTotalKmCost(CustomerManager::SubscriptionType subType, unsigned short km, VehicleManager::VehicleType vt)
{
	unsigned short pricePerKm = 0;
	unsigned short kmFree = 0;	//TODO: GET N FREE KM AND SUBSTRACT THEM BEFORE CALCULATING KM * COST
	for(pricePerKmRow row : Database::getDatabase().getPricePerKmTable())
	{
		if(row.first == subType && row.second.first == vt)
		{
			pricePerKm = row.second.second;
		}
	}
	//temp
	if(subType == CustomerManager::SubscriptionType::paid)
		kmFree = 100;
	return (km - kmFree) * pricePerKm;
}
// abonnementstype, type auto, geld in eurocent
//typedef std::pair<unsigned short, std::pair<unsigned short, unsigned short>> pricePerKmRow;
// first = abonnementstype
// second.first = type auto
// second.second = geld in eurocent

unsigned long CalculateCheckoutOnTime::calculateTotalTimeCost(CustomerManager::SubscriptionType subType, PaymentFrequency paymentFrequency, unsigned short timeToBePaidFor, VehicleManager::VehicleType vt)
{
	unsigned short costPerTimeUnit = 0;

	// Get cost per time unit
	for(paymentRow row : Database::getDatabase().getPaymentTable())
	{
		if(row.first == subType && row.second.first == paymentFrequency && row.second.second.first == vt)
			costPerTimeUnit = row.second.second.second; // Top kek

	}

	// return totalTimeCost
	return costPerTimeUnit * timeToBePaidFor;
}
}  // namespace ReservationManager


// abonnementstype, tijdseenheid, type auto, geld in eurocent
//typedef std::pair<unsigned short, std::pair<unsigned short, std::pair<unsigned short, unsigned short>>> paymentRow;
//first = abonnementstype
//second.first = tijdseenheid
//second.second.first = type auto
//second.second.second.first = eurocent
