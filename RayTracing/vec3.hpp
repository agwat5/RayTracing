#pragma once

// class taken from https://raytracing.github.io/books/RayTracingInOneWeekend.html
#include <cmath>
#include <iostream>

class vec3 {

public:
	double e[3];

	vec3() : e{ 0,0,0 } {}
	vec3(double e0, double e1, double e2) : e{ e0, e1, e2}{}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }


	vec3& operator+=(const vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	vec3& operator*=(double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	vec3& operator/=(double t) {
		return *this *= 1 / t;
	}

	double length() const {
		return std::sqrt(length_squared());
	}

	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator+(const vec3& v, const vec3& t) {
	return vec3(t.e[0] + v.e[0], t.e[1] + v.e[1], t.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& v, const vec3& t) {
	return vec3(v.e[0] - t.e[0], v.e[1] - t.e[1], v.e[2] - t.e[2]);
}

inline vec3 operator/(const vec3& v, double t) {
	return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline vec3 calculateUnitVector(const vec3& vector) {
	return vector / vector.length();
}

inline auto dotProduct(const vec3& vector, const vec3& vector2) {
	return vector.e[0] * vector2.e[0] + vector.e[1] * vector2.e[1] + vector.e[2] * vector2.e[2];
}