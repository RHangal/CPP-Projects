#include "shape.h"

Shape::Shape(const std::string_view description)
    : m_description(description)
    {

    }

Shape::~Shape()
{
    std::cout << "Destructor called for Shape" << std::endl;
}