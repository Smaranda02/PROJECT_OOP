//
// Created by smaranda on 10/23/2022.
//

#include "Player.h"

/*
[[maybe_unused]] Player::Player (const Player &other) : name{other.name}, surname{other.surname}, score{other.score} {
}
*/


//int Player::get_score() const{ return score; }



int Player::get_level() const{
    return level;
}


std::ostream & operator << (std::ostream &out, const Player &p)
{
    out<<p.name<<" "<<p.surname;
    return out;
}


Player :: ~Player() {std::cout<<"Next player aka Destructor Player called";}


Player& Player::operator=(const Player &p) = default;

Player::Player (std::string& name_, std::string& surname_) : name{name_}, surname{std::move(surname_)} {
    std::cout<<this->name<<" "<<this->surname;
}

std::string Player::get_name() { return name;}

std::string Player::get_surname() { return surname;}