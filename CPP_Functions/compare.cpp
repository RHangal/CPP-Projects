//Definition
//File name doesn't have to match the header
#include <string>
#include <iostream>

int max( int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int min( int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

//input and output function params
void max_Str(const std::string& input1, const std::string& input2, std::string& output)
{
    if(input1>input2){
        output=input1;
    }else{
        output=input2;
    }
};