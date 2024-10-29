#pragma once

#include "ray.hpp"
#include "interval.hpp"

#include <memory>
#include <vector>


using std::make_shared;
using std::shared_ptr;

class HitRecord {

	public:
		point3 hitPoint;
		vec3 normal;
		double t;
		bool frontFace;

		void setFaceNormal(const Ray& r, const vec3& outwardNormal) {

			frontFace = dotProduct(r.direction(), outwardNormal) < 0;
			normal = frontFace? outwardNormal: -outwardNormal;
		}

};

class Hittable {

	public:
		virtual ~Hittable() = default;

		virtual bool isHit(Ray ray, Interval t_range, HitRecord& rec) const = 0;
};

class HittableList: public Hittable {
public:
	HittableList() {}
	HittableList(shared_ptr<Hittable> object) { add(object);}

	std::vector<shared_ptr<Hittable>> objects;

	void clear() { objects.clear(); }


	bool isHit(Ray ray, Interval t_range, HitRecord& rec) const override{
		bool hitAnything = false;
		for (const auto& object : objects) {
			if (object->isHit(ray, t_range, rec)) {
				t_range.max = rec.t;
				hitAnything = true;
			}
		}
		return hitAnything;
	}

	void add(shared_ptr<Hittable> object){
		objects.push_back(object);
	}

};
