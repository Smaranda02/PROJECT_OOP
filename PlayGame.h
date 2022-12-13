//
// Created by smaranda on 11/26/2022.
//

#ifndef OOP_PLAYGAME_H
#define OOP_PLAYGAME_H
#include "SFML/Graphics.hpp"
#include <map>
#include "SendAnswer.h"
#include "Player.h"

class PlayGame {
private:
    sf::RenderWindow windowPlayGame;
    sf::Event event{};
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;
    std::map<std::string, std::string> wordList;
    SendAnswer sendButton;
    sf::Vector2i mousePosition;
    static std::shared_ptr<Player> playerInGame;



public:
    PlayGame();
    void updateSFMLEvents();
    void render();
    void update();
    void playGame();
    //void draw(sf::RenderTarget* target);
    void updateMousePosition();
    sf::RenderWindow& getWindow();
    static void updatePlayer();



};


#endif //OOP_PLAYGAME_H
