//
// Created by smaranda on 10/23/2022.
//

#include "Button.h"

void Button::update(const sf::Vector2f mousePos)
{
    this->buttonState=BTN_IDLE;

    if(this->button.getGlobalBounds().contains(mousePos))
    {
        this->buttonState=BTN_HOVER;

//Pressed
if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
this->buttonState=BTN_PRESSED;
}
    }
}