//
// Created by smaranda on 10/23/2022.
//

#include "Button.h"

void Button::update(const sf::Vector2f mousePos)
{
    this->buttonState=BTN_IDLE;

    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState=BTN_HOVER;

//Pressed
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->buttonState=BTN_PRESSED;

    }
}

Button::Button() {
    this->buttonState = BTN_IDLE;
    this->font = nullptr;
}

Button::Button(float x, float y, float width, float height, sf::Font *font, std::string text, sf::Color idleColor,
               sf::Color hoverColor) : idleColor(idleColor), hoverColor(hoverColor), font(font) {

    this->buttonState = BTN_IDLE;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idleColor);
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
            this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f -
            this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f -
            this->text.getGlobalBounds().height / 2.f
    );
};

Button::~Button() {}