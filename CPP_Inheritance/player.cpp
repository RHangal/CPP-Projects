#include "person.h"
#include "player.h"

Player::Player(){
    std::cout << "Player Constructor Called" << std::endl;
}

Player::Player(std::string_view game_param, std::string_view fist_name_param, std::string_view last_name_param){
    m_game = game_param;
    first_name = fist_name_param;
    last_name = last_name_param;
    std::cout << "Non Default Constructor Called for Player " << std::endl;
}

//Proper copy constructor
Player::Player(const Player& source)
    : Person(source), m_game{source.m_game}
    {
        std::cout << "Player copy constructor called..." << std::endl;
    }

std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player : [ game : " << player.m_game << " name : " << player.get_first_name() << " " << player.get_last_name() << "]"; 
    return out;
}

