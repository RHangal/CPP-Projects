#ifndef CAT_H
#define CAT_H

#include <string_view>
#include <string>
#include <iostream>

class Cat
{
public:
    Cat() = default;
    Cat(std::string_view name_param, std::string_view breed_parm, int age_param);
    ~Cat();//Destructor declared

    void print_info(){
        std::cout << "Cat (" << this << ") : [ name : " << cat_name << " breed : " << cat_breed << " age : " << *cat_age << "]" << std::endl; 
    }

    //Setters with pointers
    Cat* set_cat_name(std::string_view cat_name){
        this->cat_name = cat_name;
        return this;
    }
    Cat* set_cat_breed(std::string_view cat_breed){
        this->cat_breed = cat_breed;
        return this;
    }

    Cat* set_cat_age(int cat_age){
        *(this->cat_age) = cat_age;
        return this;
    }

    /*Setters with references
    Cat& set_cat_name(std::string_view cat_name){
        this->cat_name = cat_name;
        return *this;
    }
    Cat& set_cat_breed(std::string_view cat_breed){
        this->cat_breed = cat_breed;
        return *this;
    }

    Cat& set_cat_age(int cat_age){
        *(this->cat_age) = cat_age;
        return *this;
    }
    */

private:
    std::string cat_name;
    std::string cat_breed;
    int *cat_age{nullptr}; 
};



#endif