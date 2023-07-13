#include <iostream>
#include <string>

int main(){
    std::string word;

    // std::cout print stuff to the terminal
    std::cout << "print stuff with std::cout" << std::endl;

    //std::cin input stuff into the terminal, will automatcially print to terminal
    std::cin >> word;

    //std::cerr print errors to the console
    std::cerr << "something went wrong" << std::endl;

    //std::clog prints a log message to the console
    std::clog << "this is a log message" << std::endl;

    //using input/out put for a sentence
    int age;
    std::string name; // the ; after the variable indicates it will be assigned a value later
    
    std::cout << "Please input your name : " << std::endl;
    std::cin >> name;

    
    std::cout << "Please input your age" << std::endl;
    std::cin >> age;
    std::cin.ignore(1, '\n'); // IMPORTANT: used to ignore the escape character after an int so that the std::getline in the next part can work without assuming a blank string 

    std::cout << "Hello " << name << ", you are " << age << " years old" << std::endl; 


    // Data the spaces

    std::string fullName;
    int age2;

    std::getline(std::cin,fullName);

    std::cin >> age2;

    std::cout << "Hello " << fullName 
    << " you are " << age2 
    << " years old!" << std::endl;

    return 0;
}
