#ifndef DESTRUCTORS_H
#define DESTRUCTORS_H

#include <string_view>
#include <string>
#include <iostream>

class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_parm, int age_param);
    ~Dog();//Destructor declared

private:
    std::string dog_name;
    std::string dog_breed;
    int *dog_age; 
};

#endif