//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Game {
    private:
        void initWindow();
        sf::RenderWindow window;
        sf::Text text;
        sf::Font font;
        sf::Event event;

    public:
        Game();

        void updateSFMLEvents();
        void update();
        void render();
        void run();

        ~Game();
    };



#endif //OOP_GAME_H
