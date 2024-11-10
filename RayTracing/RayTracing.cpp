// RayTracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "common.hpp"
#include "hittable.hpp"
#include "sphere.hpp"
#include "camera.hpp"




int main()
{
    // image definition
    auto camera = Camera();
    camera.imageWidth = 256;
    camera.aspectRatio = 16.0 / 9.0;
    camera.focalLength = 1.0;
    camera.sensorHeight = 2.0;
    camera.samplesPerPixel = 100;
    camera.maxDepth = 50;
 
    // world definition
    HittableList world;
    world.add(make_shared<Sphere>(point3(0.0, 0.0, -1.0), 0.5));
    world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100.0f));
    camera.render(world);
}
