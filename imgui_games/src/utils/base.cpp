
#include "base.h"

float get_distance(Point& p1, Point& p2)
{
    Vect v{p2.x - p1.x, p2.y - p1.y};
    return get_module(v);
}

float get_module_sqr(Vect & v)
{
    return v.x * v.x + v.y * v.y;
}

float get_module(Vect & v)
{
    float module_sqr = get_module_sqr(v);
    return my_sqrt(module_sqr);
}

float my_sqrt(float value)
{
    return sqrt(value);
}