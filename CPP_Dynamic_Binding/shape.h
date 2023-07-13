#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <string_view>

class Shape
{
    public:
    Shape() = default;
    Shape(const std::string_view description);
    virtual ~Shape();

    virtual void draw() const{
        std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
    }
    //creating pure virtual function; has no use in base class but will be used later
    //virtual double circumference() const=0; //this turns the class into an Abstract class and prevents you from creating objects of this class 
    //But can still use base pointers of this class despite becoming abstract
    
protected:
    std::string m_description{""};
};


#endif