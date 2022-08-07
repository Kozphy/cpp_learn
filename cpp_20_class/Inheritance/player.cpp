#include "player.h"


Player::Player(string_view game_param){
    m_game = game_param;
    other = "wjisoa";
}

ostream &operator<<(ostream &out, const Player &player){
    out << "Player : [ game : " << player.m_game
        << " names : " << player.get_first_name()
        << " " << player.get_last_name() << ", other: " << player.other << "]";
    return out;
}

Player::~Player(){}