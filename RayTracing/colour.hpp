#pragma once

#include "vec3.hpp"

#include <iostream>


using Colour = vec3;

void write_colour(std::ostream& out, const Colour& pixel_colour);
