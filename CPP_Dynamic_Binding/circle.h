#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"

class Circle final : public Oval //restricts further sub-classing downstream from Circle
{
public:
    Circle() = default;
    Circle(double radius, const std::string_view description);
    virtual ~Circle();

    //using the "final" keyword prevents the draw() method from being overridden in any sublcass of Circle; further derived classes are forced to use the implementation in Circle
    virtual void draw() const override final{
        std::cout << "Circle::draw() called. Drawing " << m_description << " with radius : " << get_x_radius() << std::endl;
    }

   
};

#endif