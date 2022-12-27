//
// Created by smaranda on 12/9/2022.
//

#include "Intermediate.h"

std::shared_ptr<Player> Intermediate:: clone() const  {
return std::make_shared<Intermediate>(*this);
}


void Intermediate::updatePlayer(){
    ///if(answer == correct)
    this->increment_score();
    this->set_money();
    std::cout<<"The player has now "<<money<<" money \n";
}

Intermediate::Intermediate(std::string& name_, std::string& surname_) : Player(name_, surname_){
    this->level=2;
}

void Intermediate::increment_score() {
    score+=incrementScore;
}


void Intermediate::set_money() {
    money=multiplyScore*score;
}