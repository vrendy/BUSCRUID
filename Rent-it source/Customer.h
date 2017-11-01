#ifndef CUSTOMERMANAGER_CUSTOMER_H
#define CUSTOMERMANAGER_CUSTOMER_H

#include "Subscription.h"
#include <string.h>

#include "CustomerDAO.h"

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

	Subscription subscription;

public:
	void Customer(std::string name, std::string adress, std::string residence, std::string email, std::string bankNbr);

};

}  // namespace CustomerManager
#endif
