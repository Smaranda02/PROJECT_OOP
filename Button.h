//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "iostream"
#include "Rectangle.h"

class Button {
protected:
    static int pressedNumber;
    sf::Color idleColor = sf::Color::Red ;
    sf::Color hoverColor = sf::Color::Blue;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;
    //Rectangle rectangle;
    std::string type="buton de baza";
    //enum button_states{BTN_IDLE=0, BTN_HOVER, BTN_PRESSED};
    //short unsigned buttonState;

public:
    Button()=default;
    Button& operator=(const Button& other)=default;
    Button(float x,float y, float width, float height, sf::Font& font, const std::string& text);
    virtual ~Button();
    void render(sf::RenderTarget *target);
    virtual void update( sf::Vector2f mousePos)=0;
    virtual std::shared_ptr<Button> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Button& button) ;
    static void incrementPressed();
    Button(const Button& other);

protected:
    virtual void afisare(std::ostream& os) const;
};



#endif //OOP_BUTTON_H
