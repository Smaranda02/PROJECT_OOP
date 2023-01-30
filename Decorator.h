//
// Created by smaranda on 1/29/2023.
//

#ifndef OOP_DECORATOR_H
#define OOP_DECORATOR_H
#include "SubmitButton.h"

class Decorator  {
    SubmitButton submitButton;
    sf::SoundBuffer soundBuffer;
    sf::SoundBuffer soundBuffer2;
    static sf::Sound sound;
    static sf::Sound sound2;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;

public:
    Decorator()=default;
    Decorator& operator=(Decorator&& other) noexcept ;

    Decorator(float x, float y, float width, float height, sf::Font& font, const std::string& text);

    void construct();

     SubmitButton &getSubmitButton() ;

     static sf::Sound &getSound() ;
     static sf::Sound &getSound2() ;


    const sf::Sprite &getSprite() const;

    const sf::Text &getText() const;
};




#endif //OOP_DECORATOR_H
