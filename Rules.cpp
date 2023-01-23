//
// Created by smaranda on 11/6/2022.
//

#include "Rules.h"
#include <SFML/Graphics.hpp>

Rules::Rules() {

    this->windowRules = new sf::RenderWindow(sf::VideoMode(800,600), "Rules Window");

    //float width = windowRules->getSize().x;
    //float height = windowRules->getSize().y;

    if (!font.loadFromFile("arial.ttf"))
        std::cout << "EROARE LA INCARACREA FONTULUI";

    rules.setString(" \n"
                    "- The game starts when the player hits the PLAY button. \n"
                    "- If the player wants to stop the game he/she can press\n"
                    " the STOP button.\n"
                    "- In order to exit the game press Escape key or click the\n"
                    " X button in the top-right bar.\n"
                    "- The allocated time for 1 round is 2 minutes in which the\n"
                    " players has to guess as many word\n"
                    "as possible. \n"
                    "- In order to get a hint press the HINT button. One player\n"
                    " has a maximum of 3 hints per word. Every hint requested\n"
                    "decrements the score with 10 points.\n"
                    "- Every letter in the word has the value of 10 points.\n"
                    " Therefore the longer the word the bigger the reward. "
    );


    rules.setFont(font);
    rules.setFillColor(sf::Color::Red);
    rules.setCharacterSize(24); // in pixels, not points!
    rules.setStyle(sf::Text::Bold | sf::Text::Italic);
    //rules.setPosition(sf::Vector2f(width / 2, height / 2));
    this->draw();
    this->windowRules->draw(rules);
}


void Rules::draw( )
{
    this->windowRules->draw(rules);
}


sf::RenderWindow* Rules::getWindow() { return this->windowRules; }

void Rules::SFMLevents() {

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



void Rules::render() {

    this->windowRules->clear();
    this->windowRules->draw(this->rules);
    //this->draw();
    this->windowRules->display();

}


Rules& Rules::operator=(const Rules &other ) {
    if(this==&other)
        return *this;

    this-> font=other.font;
    this-> windowRules=other.windowRules;
    this->rules=other.rules;
    this->event=other.event;
    return *this;
}


[[maybe_unused]] Rules::Rules(const Rules &other) {
    this-> font=other.font;
    this-> windowRules=new sf::RenderWindow;
    this->rules=other.rules;
    this->event=other.event;
}
