#include "camera.hpp"


vec3 randomOffset(void) {
    return vec3(random_double(-0.5, 0.5), random_double(-0.5, 0.5), 0);

}

void Camera::render(const Hittable& world) {
    initialize();
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    for (int j = 0; j < imageHeight; j++) {
        std::clog << "\rScanlines remaining: " << (imageHeight - j) << std::flush;
        for (int i = 0; i < imageWidth; i++) {
            auto colour = Colour();
            for (int sample = 0; sample < samplesPerPixel; sample++) {
                colour += rayColour(getRay(i, j), maxDepth, world);
            }
            write_colour(std::cout, (1.0/samplesPerPixel)*colour);
        }
    }
    std::clog << "\rDone.                   \n";
}

void Camera::initialize() {
    imageHeight = int(imageWidth / aspectRatio);
    sensorWidth = sensorHeight * (float(imageWidth) / imageHeight);
    cameraPin = point3(0, 0, 0);

    vec3 viewport_u(sensorWidth, 0, 0);
    vec3 viewport_v(0, -sensorHeight, 0);
    pixelDelta_u = viewport_u / imageWidth;
    pixelDelta_v = viewport_v / imageHeight;

    sensorCentre = point3(0, 0, -focalLength);
    point3 sensorOrigin = sensorCentre - (viewport_u + viewport_v) / 2;
    sensor_00 = sensorOrigin + (pixelDelta_u + pixelDelta_u) / 2.0;

}

Ray Camera::getRay(int i, int j) const {
    auto offset = randomOffset();
    point3 sensor_ij = sensor_00 + ((i + offset.x())*pixelDelta_u + (j + offset.y()) * pixelDelta_v);
    vec3 to_ij = sensor_ij - cameraPin;
    return Ray(cameraPin, to_ij);
}


Colour Camera::rayColour(const Ray& r, int rayHitLives, const Hittable& world) const {

    if (rayHitLives <= 0) {
        return Colour(0, 0, 0);
    }

    HitRecord rec;
    Interval interval(0, infinity);
    if (world.isHit(r, interval, rec)) {
        auto direction = randomOnHemisphere(rec.normal);
        return 0.5 * rayColour(Ray(rec.hitPoint, direction), rayHitLives-1, world);
    }
    vec3 unit_direction = calculateUnitVector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * Colour(1.0, 1.0, 1.0) + a * Colour(0.5, 0.7, 1.0);
}
