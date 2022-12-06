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
#include "SubmitButton.h"
#include "StartGameButton.h"

class SignUp {

private:
    sf::Font font;
    bool pressedOnce=false;
    sf::Vector2i mousePosition;
    sf::RenderWindow* windowSignUp;
    sf::Event event{};
    PlayerInput* nume;  //agregare
    PlayerInput* prenume;  //agregare
    Player player;  //agregare
    StartGameButton playButton;  //agregare
    SubmitButton submitButton;
    sf::RectangleShape boxName;
    sf::RectangleShape boxSurname;



public:
    SignUp();
    //[[maybe_unused]] SignUp(const SignUp& other);
    void updateMousePosition();
    sf::RenderWindow* getWindow();
    SignUp& operator=(const SignUp& other);
    void render();
    void draw(sf::RenderTarget* target);
    SignUp(const SignUp& other);
    ~SignUp();
    PlayerInput& get_name() ;
    PlayerInput& get_surname();
    void SFMLevents();
    void checkButtonState();
};



#endif //OOP_SIGNUP_H
