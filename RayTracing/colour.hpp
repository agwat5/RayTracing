#pragma once

#include "vec3.hpp"

#include <iostream>


using colour = vec3;

void write_colour(std::ostream& out, const colour& pixel_colour);
