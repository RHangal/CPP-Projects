#include <iostream>
#include "cylinder.h"
#include "destructors.h"
#include "cat.h"


//Destructors after function call
void some_func(){
    Dog my_dog1("Bill","Shepherd",2);
}

int main(int argc, char *argv[])
{
    //Classes
    Cylinder cylinder1;//variables from classes are called Objects
    std::cout << "Volume c1 : " << cylinder1.volume() << std::endl;

    cylinder1.base_radius = 6.0;
    cylinder1.height = 10;
    std::cout << "Volume c1 modified : " << cylinder1.volume() << std::endl;

    Cylinder cylinder2;
    std::cout << "Volume c2 : " << cylinder2.volume() << std::endl;


    //Class constructors
    ConstructCylinder constructCylinder1;// Object
    std::cout << "Volume constructCylinder1 : " << constructCylinder1.volume() << std::endl;
    
    ConstructCylinder constructCylinder2(10,4);// Object
    std::cout << "Volume constructCylinder2(10,4) : " << constructCylinder2.volume() << std::endl;

    //Setter and Getters
    GetSetCylinder getsetcylinder1(10,10);
    std::cout << "volume : " << getsetcylinder1.volume() << std::endl;

    //Modify our objects
    getsetcylinder1.set_base_radius(100);
    getsetcylinder1.set_height(100);
    std::cout << "volume : " << getsetcylinder1.volume() << std::endl;


    //Using pointers
    //Managing a stack object through pointers
    GetSetCylinder* p_getsetcylinder1 = &getsetcylinder1;
    std::cout << "Volume through p_getsetcylinder1 : " << p_getsetcylinder1->volume() << std::endl;

    //create a cylinder heap object through the new operator
    GetSetCylinder* c1 = new GetSetCylinder(11,20);//create object on heap
    std::cout << "Volume c1 through dereference () : " << (*c1).volume() << std::endl;
    std::cout << "Volume c1 through arrow notation -> : " << c1->volume() << std::endl;
    std::cout << "Getting base_radius c1 : " << c1->get_base_radius() << std::endl;
    delete c1;//Remember to release from heap.

    //Seeing Destructors in action
    Dog my_dog("Fluffy", "Lab", 6);

    //Seeing Destructors after fuction call
    some_func();

    //This pointer
    Cat cat1("Whiskers", "Tomcat", 12);//constructor
    cat1.print_info();

    cat1.set_cat_name("Doof");
    cat1.set_cat_breed("Tabby-cat");
    cat1.set_cat_age(29);
    cat1.print_info();

    //chained calls using pointers
    cat1.set_cat_name("Felix")->set_cat_breed("Australian")->set_cat_age(1);
    cat1.print_info();

    //chained calls using references
    /*
    cat1.set_cat_name("test").set_cat_breed("test2").set_cat_age(8);
    */

    std::cout << "Done!" << std::endl;
    return 0;
}
