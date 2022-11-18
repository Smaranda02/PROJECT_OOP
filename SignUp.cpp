//
// Created by smaranda on 11/11/2022.
//

#include "SignUp.h"



SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);

    nume = new PlayerInput(15, sf::Color::White, true);
    prenume = new PlayerInput(15, sf::Color::White, true);


    if (!font.loadFromFile("arial.ttf"))
        std::cout << "EROARE LA INCARACREA FONTULUI";

    nume->setFont(font);
    prenume ->setFont(font);
    //input->setFillColor(sf::Color::Red);
    //text.setString("SignUp");
    nume->setPosition(sf::Vector2f(width/3, height / 3));
    prenume->setPosition(sf::Vector2f(width*2/3, height * 2 / 3));


}


sf::RenderWindow* SignUp::getWindow()
{ return this->windowSignUp; }

void SignUp::SFMLevents() {

     {

        while (this->windowSignUp->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->windowSignUp->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    this->windowSignUp->close();
            }
            if(event.type == sf::Event::TextEntered)
                nume->typedOn(event);
        }
    }

}

void SignUp:: render() {


    this->windowSignUp->clear();
    //this->windowSignUp->draw(this->rules);
    //this->draw();
    nume->drawTo(*windowSignUp);
    prenume->drawTo(*windowSignUp);
    this->windowSignUp->display();

}