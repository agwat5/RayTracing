#pragma once

#include "common.hpp"

class Interval {


public:
	double min;
	double max;

	Interval() : min(infinity), max(-infinity) {}
	Interval(double min, double max) : min{ min }, max{ max } {}

	bool isInside_inclusive(double t) {
		return (t >= min) and (t <= max);
	}
	bool isInside_exclusive(double t) {
		return (t > min) and (t < max);
	}

	static const Interval empty, universe;

};
