//
// Created by smaranda on 11/26/2022.
//

#ifndef OOP_PLAYGAME_H
#define OOP_PLAYGAME_H
#include "SFML/Graphics.hpp"
#include "Button.h"
#include <map>

class PlayGame {
private:
    sf::RenderWindow windowPlayGame;
    sf::Event event{};
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;
    std::map<std::string, std::string> wordList;
public:
    PlayGame();
    void updateSFMLEvents();
    void render();
    void update();
    void playGame();
    //void draw();
};


#endif //OOP_PLAYGAME_H
