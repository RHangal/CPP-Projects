#include <iostream>

int main(){
    char character1 {'a'}; //single qutoes for char
    char character2 {'r'}; 
    char character3 {'r'}; 
    char character4 {'o'}; 
    char character5 {'w'}; 

    std::cout << character1 << std::endl;
    std::cout << character2 << std::endl;
    std::cout << character3 << std::endl;
    std::cout << character4 << std::endl;
    std::cout << character5 << std::endl;

    //one byte in memory : 2^8 = 256 diff values (0 ~ 255)
    std::cout << std::endl;

    char value = 65 ; // ASCII character code for 'A'
    std::cout << "Value : " << value << std::endl;
    std::cout << "Value(int) : " << static_cast<int>(value) << std::endl;

    return 0;
}
