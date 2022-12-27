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
        Menu* menu;  //agregare
        Game();

    public:
    void start_game();
    void initWindow();
    static Game& get_game();
    Game& operator=(const Game &other)=delete;
    Game(const Game& other)=delete;
    void updateSFMLEvents();
    void render();
    ~Game();
    };




#endif //OOP_GAME_H
