#ifndef CYLINDER_H
#define CYLINDER_H

#include <numbers>//from c++ 20 onwards

//Class declaration: syntax
//Classes are a blueprint/prototypes and the variables created from classes are Objects
//Classes members are private by default
class Cylinder {
public://members of a class are private by default, must use public to use outside
   //member variables, can be stack variables or pointers but not references
   //if no constructor is specified then the compiler will generate a constrctor for you called a default constructor
    double base_radius {1.0};
    double height {1.0};

public:
    double volume(){
        return std::numbers::pi * base_radius * base_radius * height;
    }
};

//Class constructors
class ConstructCylinder {
//properties
private:
    double base_radius {1.0};
    double height {1.0};

//Behaviors
public:
    ConstructCylinder(){
        base_radius = 2.0;
        height = 2.0;
    };
    //Default contructor syntax below
    //ConstructCylinder() = default;

    //following function will be implemented in cylinder.cpp
    ConstructCylinder(double radius_param, double height_param);
       
    double volume();
};

class GetSetCylinder{
private:
    double base_radius;
    double height;
public:
    //construcors
    GetSetCylinder() = default;
    GetSetCylinder(double rad_param, double height_param){
        base_radius = rad_param;
        height = height_param;
    }
    //Functions (methods)
    double volume(){
        return std::numbers::pi * base_radius * base_radius * height;
    }
    //Getters, seems very similar to useState
    double get_base_radius(){
        return base_radius;
    }
    double get_height(){
        return height;
    }

    //Setters, seems very similar to useState
    void set_base_radius(double radius_param){
        base_radius = radius_param;
    }
    void set_height(double height_param){
        height = height_param;
    }
    //other operations on the class object

};

#endif