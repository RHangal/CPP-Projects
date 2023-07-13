#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <string_view>
#include "person.h"


class Player : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player();
    Player(std::string_view game_param, std::string_view fist_name_param, std::string_view last_name_param);
    Player(const Player& source);
    // ~Player();

    //Getter
    std::string get_player_game() const{
        return m_game;
    }

    //reusing symbols
    void say_hello(){
        std::cout << "Hello, my name is " << this->get_first_name() << " " << this->get_last_name() << " and I play " << this->get_player_game() << std::endl;
    }

private:
    std::string m_game{"None"};

};

#endif