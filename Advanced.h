//
// Created by smaranda on 12/9/2022.
//

#ifndef OOP_ADVANCED_H
#define OOP_ADVANCED_H
#include "Player.h"

class Advanced : public Player{
private:
   int multiplyScore=15;
    int incrementScore=30;

public:
    Advanced(std::string& name_, std::string& surname_);
    [[nodiscard]] std::shared_ptr<Player> clone() const override ;
    void set_money() override;
    void increment_score() override;
    void updatePlayer() override;
    [[nodiscard]] int get_level() const override;



};


#endif //OOP_ADVANCED_H
