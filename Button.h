//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>



class Button {
private:
    sf::Color idleColor = sf::Color::Black;
    sf::Color hoverColor = sf::Color::Blue ;
    sf::Text text;
    sf::Font* font;
    sf::RectangleShape shape;
    enum button_states{BTN_IDLE=0, BTN_HOVER, BTN_PRESSED};
    short unsigned buttonState;

public:
    Button();
    Button(float x,float y, float width, float height, sf::Font* font, std::string text,
           sf::Color idleColor, sf::Color hoverColor);

    ~Button();

    void update(const sf::Vector2f mousePos);
};



#endif //OOP_BUTTON_H
