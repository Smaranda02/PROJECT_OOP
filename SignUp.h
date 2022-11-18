//
// Created by smaranda on 11/11/2022.
//

#ifndef OOP_SIGNUP_H
#define OOP_SIGNUP_H

#include "SFML/Graphics.hpp"
#include "iostream"
#include "PlayerInput.h"
#include "Player.h"

class SignUp {

private:
    sf::Font font;
    sf::RenderWindow* windowSignUp;
    sf::Event event{};
    PlayerInput* nume;
    PlayerInput* prenume;
    Player player;


public:
    SignUp();
    //void draw();
    sf::RenderWindow* getWindow();
    void render();
    ~SignUp()=default;
    void SFMLevents();
};


#endif //OOP_SIGNUP_H
