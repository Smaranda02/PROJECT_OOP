//
// Created by smaranda on 12/9/2022.
//

#include "Beginner.h"


int Beginner::get_level() const {
    return level;
}

std::shared_ptr<Player> Beginner::clone() const  {
    return std::make_shared<Beginner>(*this);
}



void Beginner::updatePlayer(){
    ///if(answer == correct)
    this->increment_score();
    this->set_money();
    std::cout<<"The player has now "<<money<<" money \n";
}


Beginner::Beginner(const std::string& name_, const std::string& surname_) : Player(name_, surname_){
    this->level=1;
}

void Beginner::increment_score() {
    score+=incrementScore;
}

void Beginner::set_money() {
    money=multiplyScore*score;
}