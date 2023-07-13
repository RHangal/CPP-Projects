#include <iostream>
#include "compare.h" //Preprocessor
#include "templates_concepts.h"
#include <string>

//Variable : Declaration and definition can :: only one time
int ex = 13;
// int ex = 13; this is not allowed a second time

//void will prevent a function from returning a value
void funct(int a){
    if(a>18){
        std::cout << "You are an adult\n"; 
    }else{
        std::cout << "\nYou are a kid, dork";
    }//can return; from void
};

//function OVERLOADING, allows you to use multiple functions of the same
int func(int a, int b){
    std::cout << "Int overload called" << std::endl;
    return (a>b)? a : b;
}

double func(double a, double b){
    std::cout << "Double overload called" << std::endl;
    return (a<b)? a : b;
}

std::string func(const std::string& a, const std::string& b){
    std::cout << "String overload called" << std::endl;
    return (a==b)? a : b;
}


//LAMBDA FUNCTION SIGNATURE
//[capture list] (parameters) -> return type{//Function body}
auto funt = [](){
    std::cout << "Hello World!" << std::endl;
};



int main(int argc, char **argv){

//calling template function with 2 concepts using the || operator
fusion(18);

//can explicitly call template functions
auto testing = funcTemp<double>(6, 12.8);


[](){
    std::cout << "Hello World!" << std::endl;
}();//LAMBDA function called directly aftet definition

[](double a, double b){
    std::cout << "lambda function with params: " <<
    (a+b) << std::endl;
    return (a+b);
}(12.7,15.8);


    int x{4};
    int y{9};
    double a{5.4};
    double b{7.4};

    auto result = func(x,y);

    //(this might be wrong!)you can have multiple definitions of a class but must be in diff translation units or files
    struct Point{
        double m_x;
        double m_y;
    };

funct(19);

//CAPTURE LISTS with lambda functions, used to grab data/variables outside of scope
[x,y](){
    std::cout << "x * y : " << (x*y) << std::endl;
}();

//capturing everything by value in lambda function
auto f1 = [=](){
    std::cout << "capturing all by value : " << a << std::endl; 
};
f1();

auto f2 = [&](){
    std::cout << "capturing all by reference : " << a << std::endl; 
};
f2();

//calling the max function
int maximum = max(34,56);
std::cout << "Max : " << maximum << std::endl;

int minimum = min(145,378);
std::cout << "Min : " << minimum << std::endl;

//getting data out of function using reference param and not return
std::string out_str;
std::string string1("Alabama");
std::string string2("Bellevue");

max_Str(string1, string2, out_str);
std::cout << "max_str : " << out_str << std::endl;





    return 0;
}

