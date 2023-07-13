#include "cylinder.h"

ConstructCylinder::ConstructCylinder(double radius_param, double height_param){
        base_radius = radius_param;
        height = height_param;
    };

double ConstructCylinder::volume(){
        return std::numbers::pi * base_radius * base_radius * height;
    };