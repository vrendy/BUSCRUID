/*
 * Location.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */


#include "Location.h"
#include <iostream>

namespace VehicleManager
{
static unsigned long locationCounter = 0;
Location::Location(std::string aName) : id(++locationCounter), name(aName)
{

}

bool Location::operator==(const Location& l)
{
	return id == l.id;
}

std::ostream& operator<<(std::ostream& os, const Location& l) {
	os << l.getId() << "\t" << l.getName() << std::endl;
	return os;
}

} // namespace VehicleManager
