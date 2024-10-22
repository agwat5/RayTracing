// RayTracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "colour.hpp"

#include <iostream>

int main()
{
    int imageWidth = 256;
    int imageHeight = 256;

    int r;
    int g;
    int b;

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    
    for (int i = 0; i < imageHeight; i++) {
        std::clog << "\rScanlines remaining: " << (imageHeight - i) << std::flush;
        for (int j = 0; j < imageWidth; j++) {
            auto pixel = colour(double(j) / (imageWidth - 1), double(i) / (imageHeight - 1), 0);
            write_colour(std::cout, pixel);
        }
    }
    std::clog << "\rDone.                   \n";
}
