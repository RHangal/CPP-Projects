#ifndef OVAL_H
#define OVAL_H
#include "shape.h"
class Oval : public Shape
{
public:
    Oval() = default;
    Oval(double x_radius, double y_radius, const std::string_view description);
    virtual ~Oval();

    //overrides will hide any overloaded functions from the base class and so you must explicitly override each function in the new class
    //dynamic binding with the "virutal" keyword and explicitly caling an override with the "override" keyword
    virtual void draw() const override{
        std::cout << "Oval::draw() called. Drawing " << m_description << " with m_x_radius : " << m_x_radius << " and m_y_radius : " << m_y_radius << std::endl;
    }

     void hello() const{
        std::cout << "Hello i'm an Oval with " << m_description << std::endl;
    }


protected:
    double get_x_radius() const{
        return m_x_radius;
    }

    double get_y_radius() const{
        return m_y_radius;
    }

private:
double m_x_radius{0.0};
double m_y_radius{0.0};

};


#endif