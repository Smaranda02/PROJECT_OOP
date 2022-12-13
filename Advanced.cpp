//
// Created by smaranda on 12/9/2022.
//

#include "Advanced.h"

std::shared_ptr<Player> Advanced::clone() const  {
return std::make_shared<Advanced>(*this);
}


Advanced::Advanced(std::string& name_, std::string& surname_) : Player(name_, surname_){
    this->level = 3 ;
}


void Advanced::increment_score() {
    score+=30;
}
