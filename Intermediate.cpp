//
// Created by smaranda on 12/9/2022.
//

#include "Intermediate.h"

std::shared_ptr<Player> Intermediate:: clone() const  {
return std::make_shared<Intermediate>(*this);
}

Intermediate::Intermediate(std::string& name_, std::string& surname_) : Player(name_, surname_){
    this->level=2;
}
