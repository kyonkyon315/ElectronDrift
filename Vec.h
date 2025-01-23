#pragma once
#include <iostream>
class Vec
{
protected:
	double x, y, z;
	
public:
	void mul(const Vec& left, const Vec& right) {

		x = left.y * right.z - left.z * right.y;
		y = left.z * right.x - left.x * right.z;
		z = left.x * right.y - left.y * right.x;
	}

	void mul(double right) {
		x *= right;
		y *= right;
		z *= right;
	}

	void div(double right) {
		x /= right;
		y /= right;
		z /= right;
	}

	void plus(const Vec& other) {
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void copyVec(const Vec& r) {
		x = r.x;
		y = r.y;
		z = r.z;
	}
	friend std::ostream& operator<<(std::ostream& ostm, const Vec& vec) {
		ostm << vec.x << ' ' << vec.y << ' ' << vec.z;
		return ostm;
	}
};

