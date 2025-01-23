#pragma once
class Time
{
private:
	double time;
public:
	Time() :time() {}
	Time(const double time) :time(time) {}

	double get_val()const { return time; }
	void set_val(double time) {
		this->time = time;
	}

	void operator=(const Time& other) { time = other.time; }
};

