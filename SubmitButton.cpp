//
// Created by smaranda on 12/3/2022.
//

#include "SubmitButton.h"
#include "Decorator.h"

void SubmitButton::afisare(std::ostream& os) const{
    Button::afisare(os);
    os << "\t" << "stare apasare buton " << isPressed;
}

void SubmitButton::set_ButtonState() {
    isPressed=false;
}


bool SubmitButton::get_buttonState() const { return isPressed; }

std::shared_ptr<Button> SubmitButton::clone() const {return std::make_shared<SubmitButton>(*this); }

SubmitButton::SubmitButton(Button& button) : Button(button) {
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(5.f);
}


int SubmitButton::update(const sf::Vector2f mousePos)
{
    this->shape.setFillColor(this->idleColor);

    if(this->shape.getGlobalBounds().contains(mousePos))
    {

        this->shape.setFillColor(this->hoverColor);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->isPressed= true;
            Decorator::getSound2().play();
            incrementPressed();
        }

    }
    return 0;
}