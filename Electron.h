#pragma once

#include "Force.h"
#include <functional>
#include <iostream>
#include <iomanip>
class Electron
{
private:
	Coordinate place;
	Velocity velocity;
	Weight m;

public:
	Electron(const Coordinate& place,const Velocity& velocity,const Weight& m);
	void upDate(std::function< Force(const Coordinate&, const Velocity&) >, const Time& dt);
	friend std::ostream& operator<<(std::ostream& ostm, const Electron& electron) {
		ostm <<std::setprecision(15)<< electron.place.get_x() << ' ' 
			<< std::setprecision(15) << electron.place.get_y() << ' '
			<< std::setprecision(15) << electron.place.get_z() ;
		return ostm;
	}
};

