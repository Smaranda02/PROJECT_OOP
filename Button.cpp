//
// Created by smaranda on 10/23/2022.
//

#include "Button.h"
#include "iostream"

void Button::update(const sf::Vector2f mousePos)
{
    //Idle
    //this->buttonState=BTN_IDLE;
    this->shape.setFillColor(this->idleColor);

    if(this->shape.getGlobalBounds().contains(mousePos))
    {

        //Hover
        //this->buttonState=BTN_HOVER;
        this->shape.setFillColor(this->hoverColor);

         //Pressed
         //if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            //this->buttonState=BTN_PRESSED;

    }
}

/*
 bool Button::isPressed() const {
    if(this->buttonState == BTN_PRESSED)
        return true;
    return false;
}
*/

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}

Button::Button() {
    //this->buttonState = BTN_IDLE;
    this->font = nullptr;
}

Button::Button(float x, float y, float width, float height, sf::Font *font, const std::string& text) :   font(font) {

    //this->buttonState = BTN_IDLE;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idleColor);
    this->text.setFont(*this->font);
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

