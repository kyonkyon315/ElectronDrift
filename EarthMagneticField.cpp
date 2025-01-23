#include "EarthMagneticField.h"

void EarthMagneticField::calc() {
	double px = place.get_x();
	double py = place.get_y();
	double pz = place.get_z();
	double r = sqrt(px * px + py * py + pz * pz);
	x =  k / 4.*3. * px * pz / pow(r, 5.);
	y =  k / 4.*3. * py * pz / pow(r, 5.);
	z =  k / 4.*(3. * pz * pz -pow(r,2.))/ pow(r, 5.);
}



