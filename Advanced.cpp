//
// Created by smaranda on 12/9/2022.
//

#include "Advanced.h"

#include <utility>

std::shared_ptr<Player> Advanced::clone() const  {
return std::make_shared<Advanced>(*this);
}

int Advanced::get_level() const {
    return level;
}


void Advanced::updatePlayer(){
    ///if(answer == correct)
    this->increment_score();
    this->set_money();
    std::cout<<"The player has now "<<money<<" money \n";
}



Advanced::Advanced(std::string name_, std::string surname_) : Player(std::move(name_), std::move(surname_)){
    this->level = 3 ;
}

void Advanced::increment_score() {
    score+=incrementScore;
}


void Advanced::set_money() {
    money=multiplyScore*score;
}