#include "destructors.h"

Dog::Dog(std::string_view name_param, std::string_view breed_parm, int age_param){
    dog_name = name_param;
    dog_breed = breed_parm;
    dog_age = new int;//Memory allocated on the heap
    *dog_age = age_param;
        std::cout << "Dog constructor called for : " << dog_name << std::endl;
        std::cout << "Dog : " << dog_name << " constructed at " << this << std::endl;
}

Dog::~Dog(){
    delete dog_age;
    std::cout << "Dog destructor called for : " << dog_name << std::endl;
};