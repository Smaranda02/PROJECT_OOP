//
// Created by smaranda on 1/29/2023.
//

#ifndef OOP_DECORATOR_H
#define OOP_DECORATOR_H
#include "SubmitButton.h"

class Decorator  {
    SubmitButton submitButton;
    sf::SoundBuffer soundBuffer;
    static sf::Sound sound;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;

public:
    Decorator()=default;
    Decorator(float x,float y, float width, float height, sf::Font& font, const std::string& text);

     SubmitButton &getSubmitButton() ;

     static sf::Sound &getSound() ;

    const sf::Sprite &getSprite() const;

    const sf::Text &getText() const;
};




#endif //OOP_DECORATOR_H
