//
// Created by smaranda on 12/11/2022.
//

#include "SendAnswer.h"
#include "Beginner.h"

SendAnswer::SendAnswer(float x, float y, float width, float height, sf::Font& font, const std::string& text) :
        Button(x, y, width,  height, font, text)  {}

int SendAnswer::update(const sf::Vector2f mousePos)  {
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
            return 1;
        }

    }
    return 0;
}


std::shared_ptr<Button> SendAnswer::clone() const {
    return std::make_shared<SendAnswer>(*this);
}
