//
// Created by smaranda on 11/6/2022.
//

#include "Rules.h"
#include "SFML/Graphics.hpp"

Rules::Rules(float width, float height) {
    if (!font.loadFromFile("arial.ttf"))
        std::cout << "EROARE LA INCARACREA FONTULUI";

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setString("SignUp");
    text.setPosition(sf::Vector2f(width / 2, height / 2));
}


void Rules::draw( sf::RenderWindow &window )
{
        window.draw(text);
}

