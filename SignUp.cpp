//
// Created by smaranda on 11/11/2022.
//

#include "SignUp.h"



SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);


    if (!font.loadFromFile("arial.ttf"))
        std::cout << "EROARE LA INCARACREA FONTULUI";

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setString("SignUp");
    text.setPosition(sf::Vector2f(width / 2, height / 2));

}


void SignUp::draw( sf::RenderWindow &window )
{
    window.draw(text);
}


sf::RenderWindow* SignUp::getWindow() { return this->windowSignUp; }

void SignUp::SFMLevents() {


    while (this->windowSignUp->isOpen()) {
        sf::Event event{};
        while (this->windowSignUp->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->windowSignUp->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    this->windowSignUp->close();
            }
        }
    }

}