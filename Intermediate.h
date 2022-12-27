//
// Created by smaranda on 12/9/2022.
//

#ifndef OOP_INTERMEDIATE_H
#define OOP_INTERMEDIATE_H
#include "Player.h"

class Intermediate : public Player {
private:
    int multiplyScore=10;
    int incrementScore=20;

public:
    Intermediate(std::string& name_, std::string& surname_);
    [[nodiscard]] std::shared_ptr<Player> clone() const override;
    void set_money() override;
    void increment_score() override;
    void updatePlayer() override;

};


#endif //OOP_INTERMEDIATE_H
