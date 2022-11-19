//
// Created by smaranda on 10/23/2022.
//

#include "Player.h"

Player::Player (const Player &other)
{
    name=other.name;
    surname=other.surname;
    job=other.job;
    score=other.score;
}



//int Player::get_score() const{ return score; }

std::ostream & operator << (std::ostream &out, const Player &p)
{
    out<<p.name;
    return out;
}


Player :: ~Player() {std::cout<<"Next player aka Destructor Player called"; }



Player& Player::operator=(const Player &p) {
    this->name = p.name;
    this->surname = p.surname;
    this->job = p.job;
    this->score=p.score;
    return *this;
}

Player::Player()=default;
