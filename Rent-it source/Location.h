/*
 * Location.h
 *
 *  Created on: Nov 1, 2017
 *      Author: vrendy
 */

#ifndef VEHICLEMANAGER_LOCATION_H_
#define VEHICLEMANAGER_LOCATION_H_

namespace VehicleManager
{
class Location
{
public:
	Location();
	bool operator==(const Location& l);
private:
	unsigned short id;
};
}



#endif /* VEHICLEMANAGER_LOCATION_H_ */
