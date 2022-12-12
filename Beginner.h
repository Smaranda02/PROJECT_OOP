//
// Created by smaranda on 12/9/2022.
//

#ifndef OOP_BEGINNER_H
#define OOP_BEGINNER_H
#include "Player.h"

class Beginner : public Player{

public:
    Beginner(std::string& name_, std::string& surname_);
    [[nodiscard]] std::shared_ptr<Player> clone() const override;

};


#endif //OOP_BEGINNER_H
