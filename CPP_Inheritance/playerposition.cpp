#include "playerposition.h"


PlayerPosition::PlayerPosition(){
    std::cout << "PlayerPosition Constructor Called" << std::endl;
}

// PlayerPosition::PlayerPosition(std::string_view game_param, std::string_view position_param, std::string_view fist_name_param, std::string_view last_name_param){
//     m_game = game_param;
//     first_name = fist_name_param;
//     last_name = last_name_param;
//     position = position_param;
// }

//Using custom constructors to inherit members (even private) through initialized lists
PlayerPosition::PlayerPosition(std::string_view game_param, std::string_view position_param, std::string_view first_name, std::string_view last_name)
: Player(game_param,first_name,last_name),position(position_param)
{  
    std::cout << "Custom Constructor Called for PlayerPosition" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PlayerPosition& playerposition){
    out << "Player : [ game : " << playerposition.get_player_game() << " position : " << playerposition.position << " name : " << playerposition.get_first_name() << " " << playerposition.get_last_name() << "]"; 
    return out;
}