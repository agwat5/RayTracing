#pragma once

#include "hittable.hpp"
#include "colour.hpp"

class Camera {

public:
	Camera() {}

	void render(const Hittable& world);

	int imageWidth;
	double aspectRatio;
	double focalLength;
	double sensorHeight;


private:
	int imageHeight;
	double sensorWidth;
	point3 sensorCentre;
	point3 sensor_00;
	vec3 pixelDelta_u;
	vec3 pixelDelta_v;
	vec3 cameraPin;

	void initialize();

	Colour rayColour(const Ray& r, const Hittable& world) const;



};
