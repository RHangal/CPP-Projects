#ifndef PLAYERPOS_H
#define PLAYERPOS_H

#include <iostream>
#include <string>
#include <string_view>
#include "player.h"

class PlayerPosition : public Player
{
    //inherited constructor syntax below
    // using Player::Player; // this will inherit from Player class but has no PlayerPosition member attributes =(
    friend std::ostream& operator<<(std::ostream& out, const PlayerPosition& playerposition);
public:
    PlayerPosition();
    PlayerPosition(std::string_view game_param, std::string_view position_param, std::string_view fist_name_param, std::string_view last_name_param);
    //~PlayerPosition();

    //reusing symbols
    void say_hello(){
        std::cout << "Hello, my name is " << this->get_first_name() << this->first_name << " " << this->get_last_name() << " and I play " << this->get_player_game() << ", But now i'm reusing this function(symbol) with the same name! isn't that cool?" << std::endl;
    }

private:
    std::string position{"None"};
};

#endif