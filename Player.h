//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>  ///pentru std::shared_ptr<>


class Player {
protected:
    std::string name;
    std::string surname;
    int level=0;
public:
    Player()=default;
    Player (std::string& name_, std::string& surname_) ;
    //[[nodiscard]] int get_score() const;
    std::string get_name();
    std::string get_surname();
    [[nodiscard]] int get_level() const;
    //virtual void set_nivel()=0;

    [[nodiscard]] virtual std::shared_ptr<Player> clone() const = 0;
    ~Player();

    friend std::ostream & operator << (std::ostream &out, const Player &p);

protected:
    Player& operator=(const Player &p);
    [[maybe_unused]] Player (const Player &other)=default;
};


#endif //OOP_PLAYER_H
