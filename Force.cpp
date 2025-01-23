#include "Force.h"


void Force::operator=(const Force& r) {
	this->copyVec(r);
}
Force Force::operator+( const Force& right) {
	Force retval{};
	retval = *this;
	retval.plus(right);
	return retval;
}

Force Force::operator/(const double right) {
	Force retval{};
	retval = *this;
	retval.div(right);
	return retval;
}


Force Force::operator*(const double right) {
	Force retval{};
	retval = *this;
	retval.mul(right);
	return retval;
}

Acceleration Force::operator/( const Weight& weight) const{
	Acceleration retval{};
	retval.copyVec(*this);
	retval.div(weight.get_val());
	return retval;
}
