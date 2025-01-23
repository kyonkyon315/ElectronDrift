#pragma once
#include <cmath>
#include "Coordinate.h"

class EarthMagneticField:public Vec
{
private:
	Coordinate place;
	//’n‹…‚ÌŽ¥‹C”\—¦
	const double M = 7.75e22;
	const double pi = 3.1415;
	const double myu0_div_pi = 4.e-7;

	//“§Ž¥—¦ = 4pi
	const double myu0 = myu0_div_pi * pi;

	//myu0*M/pi
	const double k = myu0_div_pi * M;
public:
	EarthMagneticField() {
		x = 0.; y = 0.; z = 0.;
	}
	void calc();
	void setPlace(const Coordinate& place) {
		this->place = place;
		
	}
	
};

