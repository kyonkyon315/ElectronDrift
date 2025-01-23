#pragma once
class Weight
{
private:
	double weigth;
public:
	Weight() :weigth(0.) {}
	Weight(const double weigth) :weigth(weigth) {}

	double get_val()const { return weigth; }
	void set_val(double weigth) {
		this->weigth = weigth;
	}

	void operator=(const Weight& other) { weigth = other.weigth; }

	friend Weight operator*(Weight left, double right) {
		Weight retval(left.get_val() * right);
		return retval;
	}
	friend Weight operator*(double left, Weight right) {
		Weight retval(right.get_val() * right);
		return retval;
	}
};

