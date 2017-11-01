#ifndef CUSTOMERMANAGER_CUSTOMER_H
#define CUSTOMERMANAGER_CUSTOMER_H

#include "Subscription.h"
#include <string.h>
#include "CustomerManager.h"

namespace CustomerManager
{
class Customer
{
private:
	std::string name;
	std::string adress;
	std::string residence;
	std::string email;
	std::string bankNbr;

	CustomerManager customerManager;
	Subscription subscription;

public:
	void Customer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr);

};

}  // namespace CustomerManager
#endif
