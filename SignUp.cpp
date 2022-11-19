//
// Created by smaranda on 11/11/2022.
//

#include "SignUp.h"



SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);

    this->nume = new PlayerInput(15, sf::Color::White, true);
    this->prenume = new PlayerInput(15, sf::Color::White, true);
    this->playButton = new Button(600,400,150,50, &this->font, "Start Game");

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



void SignUp::updateMousePosition() {
    this->mousePosition = sf::Mouse::getPosition(*this->getWindow());
}


/*
sf::Vector2f SignUp::getWindowSize() const {
    return sf::Vector2f(this->windowSignUp->getSize());
}
*/


void SignUp::SFMLevents() {

     {

        while (this->windowSignUp->pollEvent(event)) {

            this->updateMousePosition();
            this->playButton->update(static_cast<sf::Vector2f>(this->mousePosition));

             if (event.type == sf::Event::Closed) {
                this->windowSignUp->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    this->windowSignUp->close();
            }

            ///if(event.type = mouseclicked
            if(event.type == sf::Event::TextEntered)
                nume->typedOn(event);


        }
    }

}

void SignUp:: render() {


    this->windowSignUp->clear();
    //this->windowSignUp->draw(this->rules);
    //this->draw();
    this->nume->drawTo(*windowSignUp);
    this->prenume->drawTo(*windowSignUp);

    sf::RenderTarget* target = this->windowSignUp;
    this->playButton->render(target);

    this->windowSignUp->display();

}

SignUp::~SignUp(){
    delete this->nume;
    delete this->prenume;
    delete this->playButton;
}


SignUp::SignUp(const SignUp &other) {
    font=other.font;
    mousePosition=other.mousePosition;
    windowSignUp=other.windowSignUp;
    event=other.event;
    nume=other.nume;
    prenume=other.prenume;
    player=other.player;
    playButton=other.playButton;


}


