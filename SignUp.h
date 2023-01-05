//
// Created by smaranda on 11/11/2022.
//

#ifndef OOP_SIGNUP_H
#define OOP_SIGNUP_H

#include "SFML/Graphics.hpp"
#include "iostream"
#include "PlayerInput.h"
//#include "Player/Player.h"
#include "Player.h"
#include "SubmitButton.h"
#include "StartGameButton.h"
#include "utility" //pentru swap
#include "StartGameButton.h"

class SignUp {

private:
    sf::Text textPrenume;
    sf::Text textNume;
    sf::Font font;
    bool pressedOnce=false;
    sf::Vector2i mousePosition;
    sf::RenderWindow* windowSignUp;
    sf::Event event{};
    PlayerInput* nume;  //agregare
    PlayerInput* prenume;  //agregare
    std::vector<std::shared_ptr<Player>> players;  //agregare
    StartGameButton playButton;  //agregare
    SubmitButton submitButton;   //agregare
    sf::RectangleShape boxName;
    sf::RectangleShape boxSurname;


public:
    SignUp();
    void updateMousePosition();
    sf::RenderWindow* getWindow();
    SignUp& operator=(SignUp other);
    void render();
    void draw(sf::RenderTarget* target);
    SignUp(const SignUp& other);
    ~SignUp();
    //std::vector<std::shared_ptr<Player>> get_players();
    PlayerInput& get_name() ;
    PlayerInput& get_surname();
    void SFMLevents();
    void checkButtonState();
    friend void swap(SignUp& signUp1, SignUp& signUp2);
};



#endif //OOP_SIGNUP_H
