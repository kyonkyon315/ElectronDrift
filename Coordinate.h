#pragma once
#include "Vec.h"
#include "Time.h"

class Coordinate:public Vec
{
public:
	Coordinate()
	{}
	Coordinate(double x,double y,double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	void operator=(const Coordinate& other);
	Coordinate operator+(const Coordinate& right);
	Coordinate operator/(const double right);

	double get_x()const { return x; }
	double get_y()const { return y; }
	double get_z()const { return z; }
	
};
