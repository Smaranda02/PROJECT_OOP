//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "iostream"
#include "Button.h"


class Game {
    private:

        sf::RenderWindow* windowMenu;
        sf::Text text;
        sf::Font font;
        sf::Event event{};
        //sf::Color colour;
        Button button; //agregare
        Menu* menu;  //agregare

        ///std::stack<State *> states;


    public:
        Game();
        void start_game();
        void initWindow();
        void updateSFMLEvents();
        void update();
        void render();
        virtual ~Game();
    };






#endif //OOP_GAME_H
