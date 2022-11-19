//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Player {
private:
    std::string name;
    std::string surname;
    std::string job;
    int score;

public:
    Player();
    Player (std::string& name_, std::string surname_, std::string& job_ ) : name{name_}, surname{surname_}, job{job_}, score{0} {}
    Player (const Player &other);

    //[[nodiscard]] int get_score() const;
    std::string get_name() {return name; }

    ~Player();

    friend std::ostream & operator << (std::ostream &out, const Player &p);

    Player& operator=(const Player &p);
};


#endif //OOP_PLAYER_H
