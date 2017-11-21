#include "Reservation.h"
#include "CalculationMethod.h"
#include "CalculateCheckoutOnTime.h"
#include "CalculateCheckoutLate.h"
#include "Database.h"
#include "CustomerDAO.h"
#include "Subscription.h"
#include <cstddef>

namespace ReservationManager
{
static unsigned long reservationCounter = 0;

Reservation::Reservation(unsigned long aCustomerId, unsigned short aVehicleId, unsigned short aStartTime, unsigned short anEndTime, PaymentFrequency aPaymentFrequency)
	: reservationId(++reservationCounter), customerId(aCustomerId), vehicleId(aVehicleId), startTime(aStartTime), endTime(anEndTime), paymentFrequency(aPaymentFrequency), checkInTime(0), checkOutTime(0), distance(0), totalCosts(0)
{
	std::shared_ptr<ReservationManager::CalculationMethod> defaultStrategy = std::make_shared<ReservationManager::CalculateCheckoutOnTime>();
	method = defaultStrategy;
}

void Reservation::calculateTotalCosts()
{
	// When calling CalculateCheckoutOnTime, pass time which is sum of the time that has to be paid
	unsigned short timeToBePaidFor = 0;
	if(checkoutOnTime())
	{
		std::shared_ptr<CalculateCheckoutOnTime> defaultStrategy = std::make_shared<CalculateCheckoutOnTime>();
		method = defaultStrategy;
		timeToBePaidFor = (endTime - startTime); // Duration of reservation
	}
	else
	{
		std::shared_ptr<CalculateCheckoutLate> lateStrategy = std::make_shared<CalculateCheckoutLate>();
		method = lateStrategy;
		timeToBePaidFor = ((endTime - startTime) + (checkOutTime - endTime)); // Duration of reservation + duration of extra time
	}

	CustomerManager::subscription_ptr sub = CustomerManager::CustomerDAO::getCustomerDAO().getCustomer(customerId).getSubscription();
	method->calculateTotalCosts(sub, paymentFrequency, timeToBePaidFor , distance, vehicleId);
}

bool Reservation::checkoutOnTime()
{
	return checkOutTime != 0 && checkOutTime <= endTime;
}

void Reservation::setKm(unsigned short aDistance)
{
	distance = aDistance;
}

void Reservation::setTotalCosts(unsigned long total)
{
	totalCosts = total;
}

void Reservation::setCheckInTime(unsigned short aCheckInTime)
{
	checkInTime = aCheckInTime;
}

void Reservation::setCheckOutTime(unsigned short aCheckOutTime)
{
	checkOutTime = aCheckOutTime;
}

std::ostream& operator<<(std::ostream& os, const Reservation& r) {
	os << "----------"<< "\ncustomerId: " << r.getCustomerId() << "\nvehicleId: " << r.getVehicleId() << "\nstartTime: " << r.getStartTime() << "\nendTime: " << r.getEndTime() << "\ncheckInTime: " << r.getCheckInTime() << "\ncheckOutTime: " << r.getCheckOutTime() << "\n----------" << std::endl;
	return os;
}
}  // namespace ReservationManager
