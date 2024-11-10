#pragma once

#include "hittable.hpp"
#include "colour.hpp"
#include "ray.hpp"

class Camera {

public:
	Camera() {}

	void render(const Hittable& world);

	int imageWidth = 100; // rendered image width
	double aspectRatio = 16.0/9; // rendered image aspect ratio
	double focalLength = 1; // focal length of camera
	double sensorHeight = 10;
	int samplesPerPixel = 10;   // Count of random samples for each pixel
	int maxDepth = 10; // maximum number of ray bounces into scene



private:
	int imageHeight;
	double sensorWidth;
	point3 sensorCentre;
	point3 sensor_00;
	vec3 pixelDelta_u;
	vec3 pixelDelta_v;
	vec3 cameraPin;

	void initialize();

	Colour rayColour(const Ray& r, int rayHitLives, const Hittable& world) const;

	Ray getRay(int i, int j) const;



};
