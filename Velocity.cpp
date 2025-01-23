#include "Force.h"

Velocity Velocity ::operator+( const Velocity& right) {
	Velocity retval{};
	retval = *this;
	retval.plus(right);
	return retval;
}

Velocity Velocity ::operator/(const double right) {
	Velocity retval{};
	retval = *this;
	retval.div(right);
	return retval;
}

Velocity Velocity ::operator*(const double right) {
	Velocity retval{};
	retval = *this;
	retval.mul(right);
	return retval;
}

Coordinate Velocity::operator*(const Time& right) {
	Coordinate retval;
	retval.copyVec(*this);
	retval.mul(right.get_val());
	return retval;
}

//“d‰×q‚Í•Ê“rŒã‚ÅŠ|‚¯‚Ä‚­‚¾‚³‚¢
Force Velocity ::operator*(const EarthMagneticField& magnetField) const{
	Force retval;
	retval.mul(*this, magnetField);
	return retval;
}


