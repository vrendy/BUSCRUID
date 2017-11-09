/*
 * Location.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */


#include "Location.h"

namespace VehicleManager
{
static unsigned long locationCounter = 0;
Location::Location() : id(++locationCounter)
{

}

bool Location::operator==(const Location& l)
{
	return id == l.id;
}

} // namespace VehicleManager
