#include <iostream>
#include "playerposition.h"

int main()
{
    Person p0;
    std::cout << "Person : " << p0 << std::endl;

    Player p1("Basketball","Default","Player");
    p1.set_first_name("Ash");
    p1.set_last_name("Ketchum");
    std::cout << "Player : " << p1 << std::endl;

    Player p2("Soccer","John","Snow");//constructed with protected member
    std::cout << "Player : " << p2 << std::endl;

    //copy construction
    Player copy_p2(p2);
    std::cout << "Copy of Player2 : " << copy_p2 << std::endl;
   //reusing symbols
    p2.say_hello();

    PlayerPosition p3("Soccer","Goalie","Phil","Beaurad");
    std::cout << "PlayerPosition : " << p3 << std::endl; 
    //reusing symbols, same function but now called with the inherited class version
    p3.say_hello();
    p3.Player::say_hello();
}


//different type of access when inherited can be protected or private
// class Engineer : private Person
//can use "using" to bring them back into scope
// protected:
//      using Person::get_first_name