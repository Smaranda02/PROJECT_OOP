//
// Created by smaranda on 11/11/2022.
//

#ifndef OOP_SIGNUP_H
#define OOP_SIGNUP_H

#include "SFML/Graphics.hpp"
#include "iostream"
#include "PlayerInput.h"
#include "Player.h"
#include "Button.h"

class SignUp {

private:
    sf::Font font;
    sf::Vector2i mousePosition;
    sf::RenderWindow* windowSignUp;
    sf::Event event{};
    PlayerInput* nume;  //agregare
    PlayerInput* prenume;  //agregare
    Player player;  //agregare
    Button* playButton;  //agregare


public:
    SignUp();
    //void draw();
    void updateMousePosition();
    //sf::Vector2f getWindowSize() const;
    sf::RenderWindow* getWindow();
    void render();
    ~SignUp();
    void SFMLevents();
};


#endif //OOP_SIGNUP_H
