//
// Created by smaranda on 11/6/2022.
//


#ifndef OOP_RULES_H
#define OOP_RULES_H


#include "SFML/Graphics.hpp"
#include <iostream>


class Rules {
private:
    sf::Font font;
    sf::RenderWindow* windowRules;
    sf::Text rules;
    sf::Event event{};

public:
    Rules();
    Rules& operator=(const Rules& other);

    [[maybe_unused]] Rules(const Rules& other);
    //Rules(float width, float height);
    void draw();
    void render();
    sf::RenderWindow* getWindow();
    ~Rules()=default;
    void SFMLevents();
};
#endif //OOP_RULES_H
