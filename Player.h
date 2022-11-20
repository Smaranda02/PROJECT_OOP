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
    //std::string job;
    int score{};

public:
    Player();
    //Player (std::string& name_, std::string surname_, std::string& job_ ) : name{name_}, surname{std::move(surname_)}, job{job_}, score{0} {}
    [[maybe_unused]] Player (const Player &other)=default;
    //[[nodiscard]] int get_score() const;
    std::string get_name() {return name; }
    //std::string get_job() {return job;}
    ~Player();

    friend std::ostream & operator << (std::ostream &out, const Player &p);

    Player& operator=(const Player &p);
};


#endif //OOP_PLAYER_H
