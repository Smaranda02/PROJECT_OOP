//
// Created by smaranda on 11/11/2022.
//

#ifndef OOP_SIGNUP_H
#define OOP_SIGNUP_H

#include "SFML/Graphics.hpp"
#include "iostream"



class SignUp {

private:
    sf::Font font;
    sf::Text text;
    sf::RenderWindow* windowSignUp;
    sf::Event event;

public:
    SignUp();
    void draw();
    sf::RenderWindow* getWindow();
    void render();
    ~SignUp()=default;
    void SFMLevents();
};


#endif //OOP_SIGNUP_H
