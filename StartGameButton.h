//
// Created by smaranda on 12/27/2022.
//

#ifndef OOP_STARTGAMEBUTTON_H
#define OOP_STARTGAMEBUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "iostream"
#include "Player.h"

class StartGameButton {
private:
    sf::Color idleColor = sf::Color::Red ;
    sf::Color hoverColor = sf::Color::Blue;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;


public:
    StartGameButton()=default;
    StartGameButton& operator=(const StartGameButton& other)=default;
    StartGameButton(float x,float y, float width, float height, sf::Font& font, const std::string& text);
    ~StartGameButton();
    void render(sf::RenderTarget *target);
    void update( sf::Vector2f mousePos, const std::shared_ptr<Player>& player, bool playersEmpty);
    StartGameButton(const StartGameButton& other);


};


#endif //OOP_STARTGAMEBUTTON_H
