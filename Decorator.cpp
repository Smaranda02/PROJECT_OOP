//
// Created by smaranda on 1/29/2023.
//

#include "Decorator.h"


Decorator &Decorator::operator=(Decorator &&other)  noexcept {
    if(this!=&other){
        submitButton=other.submitButton;
        soundBuffer=other.soundBuffer;
        texture=other.texture;
        sprite=other.sprite;
        text=other.text;

       construct();
    }

    return *this;
}



void Decorator::construct() {


    if(!soundBuffer.loadFromFile("startGame.wav"))
    {
        std::cout<<"EROARE LA INCARCARE SUNET";
    }

    sound.setBuffer(soundBuffer);

    if(!soundBuffer2.loadFromFile("click.mp3"))
    {
        std::cout<<"EROARE LA INCARCARE SUNET 2";
    }

    sound2.setBuffer(soundBuffer2);

    if(!texture.loadFromFile("stars.jpg"))
    {
        std::cout<<"EROARE LA INCARCARE IMAGINE";
    }



    this->text.setFont(submitButton.getFont());
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setOutlineThickness(1.f);
    this->text.setStyle(sf::Text::Italic);
    this->text.setFillColor(sf::Color::White);
    this->text.setString("Submit");
    this->text.setPosition(sf::Vector2f(645, 315));
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

sf::Sound &Decorator::getSound2() {
    return sound2;
}


Decorator::Decorator(float x, float y, float width, float height, sf::Font& font, const std::string& text) : submitButton(x,y,width,height,font,text){}

sf::Sound Decorator::sound;
sf::Sound Decorator::sound2;