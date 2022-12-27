//
// Created by smaranda on 10/23/2022.
//

#include "Button.h"
#include "iostream"

int Button::pressedNumber=0;





Button::Button(const  Button& other) : idleColor{other.idleColor}, hoverColor{other.idleColor},
                                       text{other.text}, font{other.font} , shape{other.shape}{}


void Button::incrementPressed() {
    pressedNumber++;
    std::cout<<"The button was pressed "<<pressedNumber<<" times\n";
}

std::ostream& operator<<(std::ostream& os, const Button& button) {
    button.afisare(os);
    return os;
}


void Button:: afisare(std::ostream& os) const {
    os << type << "\n";
}


void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}


Button::Button(float x, float y, float width, float height, sf::Font& font, const std::string& text) :   font(font) {

    //this->buttonState = BTN_IDLE;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idleColor);
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(15);
    this->text.setPosition(
            this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f -
            this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f -
            this->text.getGlobalBounds().height / 2.f
    );
}


Button::~Button() { std::cout<<"Destructor for Button called"; }

