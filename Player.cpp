//
// Created by smaranda on 10/23/2022.
//

#include "Player.h"

/*
[[maybe_unused]] Player::Player (const Player &other) : name{other.name}, surname{other.surname}, score{other.score} {
}
*/


//int Player::get_score() const{ return score; }

std::ostream & operator << (std::ostream &out, const Player &p)
{
    out<<p.name;
    return out;
}


Player :: ~Player() {std::cout<<"Next player aka Destructor Player called"; }


Player& Player::operator=(const Player &p) = default;

Player::Player()=default;
