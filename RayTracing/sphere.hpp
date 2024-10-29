#pragma once
#include "hittable.hpp"


class Sphere : public Hittable {

public:
	Sphere(const point3& sphereCentre, float sphereRadius) : centre(sphereCentre), radius(sphereRadius) {}
	
    bool isHit(Ray r, Interval t_range, HitRecord& rec) const override {

        auto a = dotProduct(r.direction(), r.direction());
        auto originToSphereCenter = centre - r.origin();
        auto b = -2 * dotProduct(r.direction(), originToSphereCenter);
        auto c = dotProduct(originToSphereCenter, originToSphereCenter) - radius * radius;
        auto determinant = b * b - 4 * a * c;

        if (determinant < 0) { return false; }

        auto t = (-b - std::sqrt(determinant)) / (2 * a);
        if (!t_range.isInside_exclusive(t)) {
            t = (-b + std::sqrt(determinant)) / (2 * a);
            if (!t_range.isInside_exclusive(t)) {
                return false;
            }

        }
        rec.hitPoint = r.atTime(t);
        rec.setFaceNormal(r, (rec.hitPoint - centre) / (radius));
        rec.t = t;
        return true;
    }


private:
	point3 centre;
	float radius;


};


