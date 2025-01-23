#include "Coordinate.h"
#include <cmath>

Coordinate Coordinate::operator+(const Coordinate& right) {
	Coordinate retval = *this;
	retval.plus(right);
	return retval;
}

Coordinate Coordinate::operator/(const double right) {
	Coordinate retval=*this;
	retval.div(right);
	return retval;
}

void Coordinate::operator=(const Coordinate& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}


