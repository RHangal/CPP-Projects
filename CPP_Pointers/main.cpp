#include <iostream>

int main(){
    //Initializing pointers and assigning them data

    //we know pointers store adresses of variables
    int int_var {43};
    int *p_int{&int_var}; //the address of operator (&);

    std::cout << "Int var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl;
    std::cout << "p_int (initialized value) : " << *p_int << std::endl;

    //you can also change the address stored in a pointer at any time
    int int_var1 {65};

    int_var1 = 126;

    p_int = &int_var1;

    std::cout << "p_int (with different address in memory) : " << p_int << std::endl;

    //Declare and initialize pointer
    int *p_number {}; // will inititialize with nullptr but BAD PRACTICE
    //expilicitly initialize with nullptr, GOOD PRACTICE
    int *p_number1{nullptr};

    //pointers will always have same amount of space in memory regardless of type
    std::cout << "size of int* pointer : " << sizeof(p_number) << std::endl;
    std::cout <<"size of int : " << sizeof(int_var) << std::endl;

    //Declaring pointers to char
    char *p_char_var {nullptr};
    char char_var {'A'};
    p_char_var = &char_var;

    std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;
    std::cout << "The memory location of p_char_var is : " << p_char_var << std::endl;

    //initializing with string literal, may not work based on compiler
    const char *p_message {"Hello World"};// using const prevents compilar error but can't modify

    std::cout << *p_message << std::endl << p_message[2] << std::endl
    << p_message << std::endl;

    //can modify the pure array initialized with string literal
    char message2[] {"Hello there"};
    message2[0] = 'T';

    std::cout << "message2 : " << message2 << std::endl;

    //Heap
    //Allocate dynamic memory through 'new' 
    int *p_number2{nullptr};
    p_number2 = new int; // dynamically allocate space for a single int on the heap

    *p_number2 = 77;//writting into dynamically allocated memory
    std::cout << std::endl;
    std::cout << "Dynamically allocating memory : " << p_number2 << std::endl;
    std::cout << "*p_number2 : " << *p_number2 << std::endl;

    //stack vs heap lifetime

    {
        int local_var{33};//lifetime lives and ends with the scope, aka the curly braces
        int *p_ptr_var = new int;//can be accessed outside the scope because it is allocated to the heap
        //but potential memory leak??
        delete p_ptr_var;
    }

    //releasing and resetting 
    int *p_number3{nullptr};
    p_number3 = new int;

    delete p_number3;// use the 'delete' keyword to reset dynamic memory allocation
    p_number3 = nullptr;//resetting to nullptr so program doesn't break 

    //initalize with 'new' upon pointer declaration
    int *p_number4{new int}; //memory location contains junk value
    int *p_number5{new int (22) }; // use direct initialization
    int *p_number6{new int {23} }; // use uniform initialization

    std::cout << std::endl;
    std::cout << "Initialize with valid memory address at declaration: " << std::endl;
    std::cout << "p_number4: " << p_number4 << std::endl;
    std::cout << "*p_number4: " << *p_number4 << std::endl;//junk value
    
    std::cout << "p_number5: " << p_number5 << std::endl;
    std::cout << "*p_number5: " << *p_number5 << std::endl;
    
    std::cout << "p_number6: " << p_number6 << std::endl;
    std::cout << "*p_number6: " << *p_number6 << std::endl;

    //remember to release the memory
    delete p_number4;
    p_number4 = nullptr;

    delete p_number5;
    p_number5 = nullptr;

    delete p_number6;
    p_number6 = nullptr;


    //array dynamic allocation
    size_t size{10};

    double *p_salaries {new double[size]};//salaries array will contain garbage values

    int *p_students {new(std::nothrow) int[size]{} };//all values initialized to 0

    int *p_scores {new(std::nothrow) int[size]{1,2,3,4,5,} };//allocating memory space for an array of size double vars.
    //first 5 will be initialized with the numbers in {}, rest will be 0's

    //nullptr check and use the allocated array
    if(p_scores){
        //print out elements.
        for(size_t i{}; i < size; ++i){
            std::cout << "Value: " << p_scores[i] << " : " << *(p_scores +i) << std::endl;
        }
    }

    //resetting memory [array version]
    delete[] p_scores;
    p_scores = nullptr;

    //pointers and arrays are different
    //pointer arrays wont work with std::size and don't support range based for loops
    //array decay into pointers

    //References and pointers
    double double_value {12.34};

    double& ref_double_value {double_value};

    double* p_double_value {&double_value};

    //Reading
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    //references are somewhat like const pointers

    return 0;
}