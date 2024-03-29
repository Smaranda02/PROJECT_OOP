//
// Created by smaranda on 11/11/2022.
//

#ifndef OOP_SIGNUP_H
#define OOP_SIGNUP_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "PlayerInput.h"
//#include "Player/Player.h"
#include "Player.h"
#include "SubmitButton.h"
#include <utility> //pentru swap
#include "StartGameButton.h"
#include "Decorator.h"


class SignUp {

private:

    static const int maxPlayers=15;

    sf::Text textPrenume;
    sf::Text textNume;
    sf::Font font;
    bool pressedOnce=false;
    sf::Vector2i mousePosition;
    sf::RenderWindow* windowSignUp;
    sf::Event event{};
    PlayerInput<int>* nume;  //agregare
    PlayerInput<short>* prenume;  //agregare
    std::vector<std::shared_ptr<Player>> players;  //agregare
    StartGameButton playButton;  //agregare
    Decorator submitButton;   //agregare
    sf::RectangleShape boxName;
    sf::RectangleShape boxSurname;


public:
    SignUp();
    bool checkMaxPlayers();
    void updateMousePosition();
    sf::RenderWindow* getWindow();
    SignUp& operator=(SignUp other);
    void render();
    void draw(sf::RenderTarget* target);
    //SignUp(const SignUp& other);
    ~SignUp();
    //std::vector<std::shared_ptr<Player>> get_players();
    PlayerInput<short> & get_name() ;
    PlayerInput<int>& get_surname();
    void SFMLevents();
    void checkButtonState();
    friend void swap(SignUp& signUp1, SignUp& signUp2);
};



//#include "SignUp.cpp"
#endif //OOP_SIGNUP_H
