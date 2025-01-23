#include "Force.h"

Acceleration Acceleration::operator+(const Acceleration& right) {
	Acceleration retval{};
	retval = *this;
	retval.plus(right);
	return retval;
}

Velocity Acceleration::operator*(const Time& time)const {
	Velocity retval;
	retval.copyVec(*this);
	retval.mul(time.get_val());
	return retval;
}
