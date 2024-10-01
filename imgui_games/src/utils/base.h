
#pragma once

#include <mathfu/vector.h>

using Point = mathfu::Vector<float, 2>;
using Vect = mathfu::Vector<float, 2>;

float get_distance(Point& p1, Point& p2);

float get_module_sqr(Vect & v);

float get_module(Vect & v);


// math
float my_sqrt(float value);