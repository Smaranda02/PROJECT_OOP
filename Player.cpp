//
// Created by smaranda on 10/23/2022.
//

#include "Player.h"

Player::Player (const Player &other)
{
    name=other.name;
    age=other.age;
    job=other.job;
}



int Player::get_score() const{ return score; }

std::ostream & operator << (std::ostream &out, const Player &p)
{
    out<<p.name;
    return out;
}


Player :: ~Player() {std::cout<<"Next player aka Destructor Player called"; }



Player& Player::operator=(const Player &p) {
    this->name = p.name;
    this->age = p.age;
    this->job = p.job;
    return *this;
}

Player::Player()=default;
