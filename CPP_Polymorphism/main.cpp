#include <iostream>
//for code readability
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main()
{
    Shape shape1("Shape1");
    shape1.draw();

    Oval oval1(2.0,3.5,"Oval1");
    oval1.draw();

    Circle circle1(3.3,"Circle1");
    circle1.draw();

    //Base pointers
    Shape *shape_ptr = &shape1;
    shape_ptr->draw();

    shape_ptr = &oval1;
    shape_ptr->draw();//not working as expected (static binding) as compiler is looking at the type of pointer which is Shape

    //Base references
    Shape& shape_ref = shape1;
    shape_ref.draw();

    shape_ref = oval1;
    shape_ref.draw();// same as above, not working(static binding) as compiler is looking at the type of reference which is Shape


    return 0;

}
