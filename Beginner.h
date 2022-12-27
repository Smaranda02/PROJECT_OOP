//
// Created by smaranda on 12/9/2022.
//

#ifndef OOP_BEGINNER_H
#define OOP_BEGINNER_H
#include "Player.h"

class Beginner : public Player{
private:
    int multiplyScore = 5; ///money received per word guessed = 5$
    int incrementScore=10;
public:
    Beginner(std::string& name_, std::string& surname_);
    [[nodiscard]] std::shared_ptr<Player> clone() const override;
    void set_money() override;
    void increment_score() override;
    void updatePlayer() override;

};


#endif //OOP_BEGINNER_H
