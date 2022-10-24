//
// Created by smaranda on 10/23/2022.
//

#include "Player.h"

Player::Player (Player const &other)
{
    name=other.name;
    age=other.age;
    job=other.job;
}


int Player::get_score() { return score; }

std::ostream & operator << (std::ostream &out, const Player &p)
{
    out<<p.name;
    return out;
}


Player :: ~Player() {std::cout<<"Next player"; }



Player Player::operator=(const Player &p) {
    this->name = p.name;
    this->age = p.age;
    this->job = p.job;
    return p;
}

