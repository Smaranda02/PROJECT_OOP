//
// Created by smaranda on 12/3/2022.
//

#include "SubmitButton.h"

bool SubmitButton::get_buttonState() const { return isPressed; }

std::shared_ptr<Button> SubmitButton::clone() const {return std::make_shared<SubmitButton>(*this); }

SubmitButton::SubmitButton(Button& button) : Button(button) {}


void SubmitButton::update(const sf::Vector2f mousePos)
{
    this->shape.setFillColor(this->idleColor);

    if(this->shape.getGlobalBounds().contains(mousePos))
    {

        this->shape.setFillColor(this->hoverColor);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->isPressed= true;
        }

    }
}