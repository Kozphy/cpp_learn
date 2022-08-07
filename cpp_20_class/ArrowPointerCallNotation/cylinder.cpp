#include "cylinder.h"
#include "constants.h"

Cylinder::Cylinder(double radius_param, double height_param){
    base_radius = radius_param;
    height = height_param;
}

double Cylinder::volume()
{
    return PI * base_radius * base_radius * height;
}

double Cylinder::get_radius()
{
    return base_radius;
}

double Cylinder::get_height()
{
    return height;
}

void Cylinder::set_radius(double radius){
    base_radius = radius;
}


void Cylinder::set_height(double height_param){
    height = height_param;
}