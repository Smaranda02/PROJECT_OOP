//
// Created by smaranda on 12/11/2022.
//

#include "SendAnswer.h"



void SendAnswer::update(const sf::Vector2f mousePos)  {
    this->shape.setFillColor(this->idleColor);

    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        //Hover
        //this->buttonState=BTN_HOVER;
        this->shape.setFillColor(this->hoverColor);

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //this->buttonState=BTN_PRESSED;
            incrementPressed();

        }

    }
}


std::shared_ptr<Button> SendAnswer::clone() const {
    return std::make_shared<SendAnswer>(*this);
}
