#include <iostream>
#include <iomanip> // for precision doubles/floats, etc

int main(){
    int number1 = 15; //Decimal
    int number2 = 017; //Octal
    int number3 = 0x0f; //Hexadecimal
    int number4 = 0b00001111; //Binary - C++14 and up

    std::cout << "Number1 is : " << number1 << std::endl;
    std::cout << "Number2 is : " << number2 << std::endl;
    std::cout << "Number3 is : " << number3 << std::endl;
    std::cout << "Number4 is : " << number4 << std::endl;

    //check size of variables with sizeof
    long count = 100200000367; // 8 bytes or 64 bits
    std::cout << "sizeof int: " << sizeof(int) << std::endl;
    std::cout << "sizeof long int: " << sizeof(count) << " display the variable : " << count << std::endl;

    // you can specify the range of your int with singed vs unsigned
    //unsigned will only be positive and signed will be both postive and negative
    //unsighned int with 4 bytes or 32 bits will have range: 0, 4,294,967,295
    //signed int with 4 bytes or 2 bitd will have range: -2,147,483,648 - 2,147,483,648

    // you can use scientific notation in flaots/doubles
    double number5 {192400000}; // doubles will auto default to be x.xxe+0n in the console
    double number6 {1.924e8}; // doubles take of 8 bytes or 64 bits
   
    std::cout << "Number5 is : " << number5 << std::endl;
    std::cout << "Number6 is : " << number6 << std::endl;

    //Declare and initialize the variables (SUFFIXES ARE IMPORTANT)
    float number7 {1.234567890123456789f}; // f suffix for float
    double number8 {1.234567890123456789}; // no suffix for double as it is assumed value by c++
    long double number9 {1.234567890123456789L}; // L suffix for long double
    //precision

    std::cout << std::setprecision(20); // control the precision from std::cout
    std::cout << "number 7 is : " << number7 << std::endl; // float precision : 7
    std::cout << "number 8 is : " << number8 << std::endl; // double precision : 15
    std::cout << "number 9 is : " << number9 << std::endl; // precision 15+

    return 0;
}
