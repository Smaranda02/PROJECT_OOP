//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <utility>


class Player {
private:
    std::string name;
    std::string surname;


public:
    Player()=default;
    Player (std::string& name_, std::string& surname_) ;
    [[maybe_unused]] Player (const Player &other)=default;
    //[[nodiscard]] int get_score() const;
    std::string get_name();
    std::string get_surname();

    ~Player();

    friend std::ostream & operator << (std::ostream &out, const Player &p);

    Player& operator=(const Player &p);
};


#endif //OOP_PLAYER_H
