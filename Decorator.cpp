//
// Created by smaranda on 1/29/2023.
//

#include "Decorator.h"

Decorator::Decorator(float x, float y, float width, float height, sf::Font &font, const std::string &text) : submitButton( x, y,  width,  height, font,  text) {

    if(!soundBuffer.loadFromFile("startGame.wav"))
    {
        std::cout<<"EROARE LA INCARCARE SUNET";
    }

    sound.setBuffer(soundBuffer);

    if(!texture.loadFromFile("submitPhoto.jpg"))
    {
        std::cout<<"EROARE LA INCARCARE IMAGINE";
    }

    sound.play();

    this->text.setFont(submitButton.getFont());
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setOutlineThickness(1.f);
    this->text.setStyle(sf::Text::Underlined);
    this->text.setFillColor(sf::Color::Cyan);
    this->text.setString("Submit");
    this->text.setPosition(sf::Vector2f(600, 300));
    this->text.setCharacterSize(15); // in pixels, not points!


    sprite.setTexture(texture);
    sprite.setPosition(600,300);
    sprite.setTextureRect(sf::IntRect(600,300,150,50));
    sprite.setColor(sf::Color::Red);

}

 SubmitButton &Decorator::getSubmitButton()  {
    return submitButton;
}

 sf::Sound &Decorator::getSound()  {
    return sound;
}

const sf::Sprite &Decorator::getSprite() const {
    return sprite;
}

const sf::Text &Decorator::getText() const {
    return text;
}

sf::Sound Decorator::sound;