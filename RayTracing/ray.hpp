#pragma once

#include "vec3.hpp"


class Ray {

	public:
	
		Ray(const point3 origin, const vec3 direction) : orig{ origin }, dire{ direction } {}

		const point3& origin() const { return orig; }
		const vec3& direction() const { return dire; }

		point3 atTime(double t) const {
			return orig + (dire * t);
		}

	private:
		point3 orig;
		vec3 dire;
};

