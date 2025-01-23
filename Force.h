#pragma once

#include "Weight.h"

#include "EarthMagneticField.h"


class Velocity;
class Acceleration;


class Force:public Vec
{
public:
	Force() {
		x = 0.; y = 0.; z = 0.;
	}
	void operator=(const Force& r);
	Force operator+(const Force& right);
	Force operator/(const double right);
	Force operator*(const double right);
	Acceleration operator/( const Weight& weight)const;

};

class Acceleration :public Vec
{
public:
	Acceleration() {
		x = 0.; y = 0.; z = 0.;
	}
	void operator=(const Acceleration& other) {
		this->copyVec(other);
	}
	Acceleration operator+(const Acceleration& right);
	
	Velocity operator*(const Time& right)const;
};

class Velocity :public Vec
{
public:
	Velocity() {
		x = 0.; y = 0.; z = 0.;
	}
	Velocity(double vx,double vy,double vz) {
		x = vx;
		y = vy;
		z = vz;
	}
	void operator=(const Velocity& other) {
		this->copyVec(other);
	}
	Velocity operator+(const Velocity& right);

	Velocity operator/(const double right);

	Velocity operator*(const double right);

	Coordinate operator*(const Time& right);

	Force operator*(const EarthMagneticField& magnetField)const;
};




