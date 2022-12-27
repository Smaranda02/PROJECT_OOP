//
// Created by smaranda on 11/26/2022.
//

#ifndef OOP_PLAYGAME_H
#define OOP_PLAYGAME_H
#include "SFML/Graphics.hpp"
#include <map>
#include "SendAnswer.h"
//#include "Player/Player.h"
//#include "Player/Beginner.h"
//#include "Player/Intermediate.h"
//#include "Player/Advanced.h"
#include "Player.h"
#include "Beginner.h"
#include "Intermediate.h"
#include "Advanced.h"
#include "PlayerInput.h"
class PlayGame {
private:
    sf::RenderWindow windowPlayGame;
    sf::Event event{};
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;
    //std::string currentWord;
    std::map<std::string, std::string> wordList;
    SendAnswer sendButton;
    sf::Vector2i mousePosition;

public:
    PlayGame()=default;
    explicit PlayGame(const std::shared_ptr <Player>& player);
    void updateSFMLEvents();
    void render();
    void playGame();
    //void draw(sf::RenderTarget* target);
    void updateMousePosition();
    sf::RenderWindow& getWindow();
};


#endif //OOP_PLAYGAME_H
