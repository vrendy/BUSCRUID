#ifndef CUSTOMERMANAGER_CUSTOMER_H
#define CUSTOMERMANAGER_CUSTOMER_H

#include "Subscription.h"
#include <string>

namespace CustomerManager
{
class Customer
{
public:
	Customer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr);

private:
	std::string name;
	std::string adress;
	std::string residence;
	std::string email;
	std::string bankNbr;

	Subscription subscription;
};

}  // namespace CustomerManager
#endif
