//
// Created by smaranda on 11/6/2022.
//

#include "Rules.h"
#include "SFML/Graphics.hpp"

Rules::Rules() {

    this->windowRules = new sf::RenderWindow(sf::VideoMode(800,600), "Rules Window");

    float width = windowRules->getSize().x;
    float height = windowRules->getSize().y;

    if (!font.loadFromFile("arial.ttf"))
        std::cout << "EROARE LA INCARACREA FONTULUI";

    rules.setString(" \n"
                        "The game starts when the player hits the PLAY button. \n"
                        "If the player wants to stop the game he/she can press the STOP button.\n"
                        "In order to exit the game press Escape key or click the X button in the top-right bar.\n"
                        "The allocated time for 1 round is 2 minutes in which the players has to guess as many word\n"
                        "as possible. \n"
                        "In order to get a hint press the HINT button. One player has a maximum of 3 hints\n"
                        "per word. Every hint requested decrements the score with 10 points.\n"
                        "Every letter in the word has the value of 10 points. Therefore the longer the word the bigger \n"
                        "the reward. ");


    rules.setFont(font);
    rules.setFillColor(sf::Color::Black);
    rules.setCharacterSize(1000); // in pixels, not points!
    rules.setStyle(sf::Text::Bold | sf::Text::Underlined);
    rules.setPosition(sf::Vector2f(width / 2, height / 2));
    this->draw();
    //this->windowRules->draw(rules);
}


void Rules::draw( )
{
        this->windowRules->draw(rules);
}


sf::RenderWindow* Rules::getWindow() { return this->windowRules; }

void Rules::SFMLevents() {


    while (this->windowRules->isOpen()) {
        sf::Event event{};
        while (this->windowRules->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->windowRules->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    this->windowRules->close();
            }
        }
    }

}