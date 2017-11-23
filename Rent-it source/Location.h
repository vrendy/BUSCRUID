/*
 * Location.h
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#ifndef VEHICLEMANAGER_LOCATION_H_
#define VEHICLEMANAGER_LOCATION_H_

#include <string>

namespace VehicleManager
{
class Location
{
public:
	Location(std::string aName);
	bool operator==(const Location& l);

	unsigned short getId() const {
		return id;
	}

	std::string getName() const {
		return name;
	}
private:
	unsigned short 	id;
	std::string 	name;
};

std::ostream& operator<<(std::ostream& os, const Location& l);

}



#endif /* VEHICLEMANAGER_LOCATION_H_ */
