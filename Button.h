//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


enum button_states{BTN_IDLE=0, BTN_HOVER, BTN_PRESSED};

class Button {
private:
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape button;
    bool pressed;
    bool hover;
    short unsigned buttonState;

public:
    Button()=default;
    Button(float x,float y, float width, float height, sf::Font* font, std::string text,
           sf::Color idleColor, sf::Color hoverCOlor, sf::Color activeColor); /*{
        this->idleColor=idleColor;
    }
    */

    ~Button()=default;

    void update(const sf::Vector2f mousePos);
};



#endif //OOP_BUTTON_H
