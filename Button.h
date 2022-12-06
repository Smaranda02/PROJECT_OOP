//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>


class Button {
protected:
    sf::Color idleColor = sf::Color::Red ;
    sf::Color hoverColor = sf::Color::Blue;
    sf::Text text;
    sf::Font* font;
    sf::RectangleShape shape;
    //enum button_states{BTN_IDLE=0, BTN_HOVER, BTN_PRESSED};
    //short unsigned buttonState;

public:
    Button();
    Button(float x,float y, float width, float height, sf::Font* font, const std::string& text);
    //bool isPressed() const;
    virtual ~Button();
    void render(sf::RenderTarget *target);
    virtual void update( sf::Vector2f mousePos)=0;
    virtual std::shared_ptr<Button> clone() const = 0;
    //void virtual function()=0;
};



#endif //OOP_BUTTON_H
