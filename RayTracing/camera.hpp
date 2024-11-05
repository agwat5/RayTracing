#pragma once

#include "hittable.hpp"
#include "colour.hpp"
#include "common.hpp"

class Camera {

public:
	Camera() {}

	void render(const Hittable& world);

	int imageWidth;
	double aspectRatio;
	double focalLength;
	double sensorHeight;
	int samplesPerPixel = 10;   // Count of random samples for each pixel



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

	Ray getRay(int i, int j) const;



};
