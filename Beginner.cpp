//
// Created by smaranda on 12/9/2022.
//

#include "Beginner.h"


std::shared_ptr<Player> Beginner::clone() const  {
    return std::make_shared<Beginner>(*this);
}


Beginner::Beginner(std::string& name_, std::string& surname_) : Player(name_, surname_){
    this->level=1;
}