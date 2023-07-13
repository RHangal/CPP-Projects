#include "cat.h"

Cat::Cat(std::string_view name_param, std::string_view breed_parm, int age_param){
    cat_name = name_param;
    cat_breed = breed_parm;
    cat_age = new int;//Memory allocated on the heap
    *cat_age = age_param;
        std::cout << "Cat constructor called for : " << cat_name << std::endl;
        std::cout << "Cat : " << cat_name << " constructed at " << this << std::endl;
}

Cat::~Cat(){
    delete cat_age;
    std::cout << "Cat destructor called for : " << cat_name << " at " << this << std::endl;
};