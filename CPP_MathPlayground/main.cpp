#include <iostream>

int addNumbers(int first_num, int second_num){
    int sum = first_num + second_num;
    return sum;
}

int main(int argc, char **argv){
    int firstNum = 12;
    int secondNum = 6;
    int thirdNum {80}; // different way to assign variable

    int sum = firstNum + secondNum;
    int min = firstNum - secondNum;
    int mult = firstNum * secondNum;
    int div = firstNum / secondNum;
    // float frac = secondNum / firstNum; this doesn't work, will return 0
    float frac2 =  1.0 / 2.0; // this works

    sum = addNumbers(4,18); // redeclaring the int sum variable
    int sum2 = addNumbers(firstNum, secondNum);
    int sum3 = addNumbers(thirdNum, firstNum);

    std::cout 
    << sum << std:: endl
    << min << std:: endl 
    << div << std:: endl 
    << sum2 << std:: endl 
    << sum3 << std:: endl 
    << frac2 << std:: endl 
    << mult << std::endl;

    return 0;
}
