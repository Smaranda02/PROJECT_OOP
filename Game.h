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
        void initWindow();
        sf::RenderWindow MENU;
        sf::Text text;
        sf::Font font;
        sf::Event event;
        sf::Color colour;

        Button button; //agregare

    public:
        Game()=default;

        void start_game();

        void updateSFMLEvents();
        void update();
        void render();
        void run();

        ~Game()=default;
    };






#endif //OOP_GAME_H
