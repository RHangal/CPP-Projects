#include <iostream>
//for code readability
#include "shape.h"
#include "oval.h"
#include "circle.h"


void draw_shape(Shape *s){
    s->draw();
}

void draw_shape_ref(const Shape& r){
    r.draw();
}

int main()
{
    Shape shape1("Shape1");
    shape1.draw();

    Oval oval1(2.0,3.5,"Oval1");
    oval1.draw();

    Circle circle1(3.3,"Circle1");
    circle1.draw();

    //Slicing
    //Shape shape2 = circle1 ; this will "slice" off the circle and oval object parts and leave only the shape

    //Base pointers
    Shape *shape_ptr = &shape1;
    shape_ptr->draw();

    shape_ptr = &oval1;
    shape_ptr->draw();//Dynamic binding

    shape_ptr = &circle1;
    shape_ptr->draw();//Dynamic binding

    //Base references
    Shape& shape_ref = circle1;
    shape_ref.draw();//This will work as it's dynamic binding

    // shape_ref = oval1;//Doesn't work ,can't re-assign reference
    // shape_ref.draw();//Doesn't work, can't re-assign reference

    //Drawing shapes with pointers
    draw_shape(&oval1);
    draw_shape(&shape1);
    draw_shape(&circle1);

    //Drawing shapes with reference
    draw_shape_ref(oval1);
    draw_shape_ref(shape1);
    draw_shape_ref(circle1);
    draw_shape_ref(shape_ref);

    //Shapes stored in collections
    Shape* shape_collection[]{&shape1, &oval1, &circle1, shape_ptr};

    //basically a for in loop
    for(Shape* shape_ptr : shape_collection){
        shape_ptr->draw();
    }
    //standard for loop; it works!
    for(int i=0; i <  std::size(shape_collection); i++){
        shape_collection[i]->draw();
    }

    //Comparing object sizes; apparently using dynamic binding increases size of objects but it's not showing in sizeof??
    std::cout << "sizeof(Shape) : " << sizeof(Shape) << std::endl;//32, dynamc 40
    std::cout << "sizeof(Oval) : " << sizeof(Oval) << std::endl;//48, dynamic 56
    std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl;//48, dynamic 56

    //Storing in smart pointers
    std::shared_ptr<Shape> shapes4[] {std::make_shared<Circle>(12.2,"Circle4"), std::make_shared<Oval>(10.0,18.0,"Oval4")};
    for(auto& s : shapes4){
        s->draw();
    }

    //Virtual destructors; because "virtual" keyword was added to destructors, deleting a base class pointer will call the destructors of downstream classes as well allowing for full/proper deletion
    Shape* sp = new Circle(10.0,"Yeah?");
    sp->draw();
    delete sp;

    //Dynamic cast with pointer
    Oval* circ_ptr = dynamic_cast<Oval*>(shape_ptr);
    circ_ptr->hello();
    //can check with if statement
    if(circ_ptr){
        circ_ptr->hello();
    }else{
        std::cout << "couldn't cast Oval pointer, r.i.p" << std::endl;
    }

    //Dynamic cast with reference
    Oval circ_ref {dynamic_cast<Oval&>(shape_ref)};
    circ_ref.hello();
    //cast as pointer then test
    Oval* circ_ptr2 {dynamic_cast<Oval*>(&shape_ref)};
    if(circ_ptr2){
        circ_ptr2->hello();
    }else{
        std::cout << "Couldn't cast to Oval reference, r.i.p" << std::endl;
    }

    return 0;

}
