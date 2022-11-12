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

public:
    SignUp();
    void draw(sf::RenderWindow &window);

    sf::RenderWindow* getWindow();
    ~SignUp()=default;
    void SFMLevents();
};


#endif //OOP_SIGNUP_H
