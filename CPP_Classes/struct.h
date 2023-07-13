#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>

//struct members public by default
//common use for members that only need public variables
struct Bird{
    std::string name;
};

//Size of object
//usually the sum of the member variables
//size might be slightly off due to boundary alignment
//boundary alignment changes where variables are stored in memory based on size

#endif