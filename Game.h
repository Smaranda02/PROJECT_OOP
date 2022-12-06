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
        Menu* menu;  //agregare

    public:
        Game();
        void start_game();
        void initWindow();

    Game& operator=(const Game &other);
    [[maybe_unused]] Game(const Game& other);
    void updateSFMLEvents();
        void update();
        void render();
        virtual ~Game();
    };




#endif //OOP_GAME_H
