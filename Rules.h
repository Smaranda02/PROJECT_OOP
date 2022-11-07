//
// Created by smaranda on 11/6/2022.
//

#ifndef OOP_RULES_H
#define OOP_RULES_H

#include "SFML/Graphics.hpp"
#include "iostream"


class Rules {
private:
    sf::Text text;
    sf::Font font;
    std::string GameRules = " \n"
                        "The game starts when the player hits the PLAY button. \n"
                        "If the player wants to stop the game he/she can press the STOP button.\n"
                        "In order to exit the game press Escape key or click the X button in the top-right bar.\n"
                        "The allocated time for 1 round is 2 minutes in which the players has to guess as many word\n"
                        "as possible. \n"
                        "In order to get a hint press the HINT button. One player has a maximum of 3 hints\n"
                        "per word. Every hint requested decrements the score with 10 points.\n"
                        "Every letter in the word has the value of 10 points. Therefore the longer the word the bigger \n"
                        "the reward. ";


public:
    Rules()=default;
    Rules(float width, float height);
    void draw(sf::RenderWindow &window);
    ~Rules()=default;
};


#endif //OOP_RULES_H
