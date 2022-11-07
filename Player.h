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
    int age;
    std::string job;
    int score;

public:
    Player()=default;
    Player (std::string name_, int age_, std::string job_ ) : name{name_}, age{age_}, job{job_}, score{0} {}
    Player (const Player &other);

    int get_score();
    std::string get_name() {return name; }

    ~Player();

    friend std::ostream & operator << (std::ostream &out, const Player &p);

    Player& operator=(const Player &p);
};


#endif //OOP_PLAYER_H
