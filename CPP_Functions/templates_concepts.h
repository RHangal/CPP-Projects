#include <iostream>
#include <string>

//FUNCTION TEMPLATES must have definition and declaration in one place so either the main.cpp or headerfile.h
//FUNCTION TEMPLATES, used to avoid code repitition
//function blue print, not real c++ code its a blueprint the compiler uses to generate a function based on arguments passed
template <typename T>
T funcTemp(T a, T b){
    std::cout << "template function called" << std::endl;
    return (a>b)? a : b;//creates copy of value at different address
}

//function blue print; template type with paramters by reference
template <typename T> const T& refTemp(const T& a, const T& b){
     std::cout << "template function by reference called" << std::endl;
    return (a>b)? a : b; //uses reference to value meaning values inside and outside function share the same address
}

//template specialization, used to overide default way template function is set up
template <>
const char* funcTemp<const char*> (const char* a, const char* b){
    return (std::strcmp(a,b)>0)? a : b;
}

//CONCEPTS are used to restrict function templates
template <typename T>
requires std::integral<T>
T add (T a, T b) {
    return a + b;
}

//concepts can also be used in the following syntax
template <std::integral T>
T add (T a, T b) {
    return a + b;
};

//concept with auto
auto minus (std::integral auto a, std::integral auto b){
    return a + b;
}

//CUSTOM CONCEPTS, checks if valid syntax only, doesn't actually evalutate the function given in the concept to true or false
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

template <typename T>
concept Multipliable = requires(T a, T b){
    a*b;//just makes sure the syntax is valid
};

template <typename T>
concept Incrementable = requires (T a) {
    a+=1;
    ++a;
    a++;
};

//concepts with nested requirements
template <typename T>
concept TinyType = requires (T t) {
    sizeof(T) <=4;//simple requirment: only checks syntax
    requires sizeof(T) <=4;//Nested requirement: checks if the expression is true or false
};

//compound requirement
template <typename T>
concept Addable = requires (T a, T b){
    //noexcept is optional
    {a + b} noexcept -> std::convertible_to<int>;//Compound requirement
    //checks if a+b is valid syntax, doesn't throw excepions(optional), and the result is convertible to int(optional)
};

//Logical operators can combine concepts
template <typename T>
requires TinyType<T> || Incrementable<T>
T fusion(T t){
std::cout << "Value : " << t << std::endl;
return (2*t);
};

