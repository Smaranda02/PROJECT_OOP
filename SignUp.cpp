//
// Created by smaranda on 11/11/2022.
//

#include "SignUp.h"
#include "Exceptions.h"
#include "SubmitButton.h"
#include "Player.h"
#include "StartGameButton.h"

 PlayerInput& SignUp::get_name() {return *(this->prenume); }
 PlayerInput& SignUp::get_surname() {return *(this->nume); }


SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);

    this->nume = new PlayerInput(15, sf::Color::White, false);
    this->prenume = new PlayerInput(15, sf::Color::White, false);

    this->playButton =   StartGameButton(600,400,150,50, &this->font, "Start Game");
    this->submitButton = SubmitButton(600,300,150,50, &this->font, "Submit");

    this->boxName.setPosition(sf::Vector2f(100,200));
    this->boxName.setSize(sf::Vector2f(static_cast<float>(width/2.5), static_cast<float>(height/18)));
    this->boxName.setFillColor(sf::Color::Transparent);
    this->boxName.setOutlineColor(sf::Color::White);
    this->boxName.setOutlineThickness(1);

    this->boxSurname.setPosition(sf::Vector2f(100,300));
    this->boxSurname.setSize(sf::Vector2f(static_cast<float>(width/2.5), static_cast<float>(height/18)));
    this->boxSurname.setFillColor(sf::Color::Transparent);
    this->boxSurname.setOutlineColor(sf::Color::White);
    this->boxSurname.setOutlineThickness(1);

    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
                                           throw eroare_font();
                                         }


    this->nume->setFont(font);
    this->nume->setPosition(sf::Vector2f(100, 200));
    this->prenume->setFont(font);
    this->prenume->setPosition(sf::Vector2f(100, 300));

    this->player = Player();

}


sf::RenderWindow* SignUp::getWindow()
{ return this->windowSignUp; }



void SignUp::updateMousePosition() {
    this->mousePosition = sf::Mouse::getPosition(*this->getWindow());
}



void SignUp::SFMLevents() {

        while (this->windowSignUp->pollEvent(event)) {

            this->updateMousePosition();
            this->playButton.update(static_cast<sf::Vector2f>(this->mousePosition));
            this->submitButton.update(static_cast<sf::Vector2f>(this->mousePosition));


             if (event.type == sf::Event::Closed) {
                this->windowSignUp->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    this->windowSignUp->close();
            }


            if(this->boxName.getGlobalBounds().contains(static_cast<sf::Vector2f>(this->mousePosition)))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::cout<<"OK";
                    this->nume->setSelected(true);
                    }
                if(event.type == sf::Event::TextEntered)
                    nume->typedOn(event);

                this->prenume->setSelected(false);
            }


            if(this->boxSurname.getGlobalBounds().contains(static_cast<sf::Vector2f>(this->mousePosition)))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::cout<<"OK";
                    this->prenume->setSelected(true);
                }

                if(event.type == sf::Event::TextEntered)
                    prenume->typedOn(event);

                this->nume->setSelected(false);

            }

            checkButtonState();

        }

    }



void SignUp:: render() {


    this->windowSignUp->clear();
    this->nume->drawTo(*windowSignUp);
    this->prenume->drawTo(*windowSignUp);

    sf::RenderTarget* target = this->windowSignUp;
    draw(target);
    this->playButton.render(target);
    this->submitButton.render(target);
    this->windowSignUp->display();

}

SignUp::~SignUp(){
    delete this->nume;
    delete this->prenume;
}



[[maybe_unused]] SignUp::SignUp(const SignUp &other): font{other.font},mousePosition{other.mousePosition},
                                                      event{other.event}, player{other.player},  playButton{other.playButton},
                                                      submitButton{other.submitButton}
                                                      {
    windowSignUp=new sf::RenderWindow;
    nume = new PlayerInput;
    prenume=new PlayerInput;



}


SignUp& SignUp::operator=(const SignUp &other) {

    if(this==&other)
        return *this;

    font=other.font;
    submitButton=other.submitButton;
    mousePosition=other.mousePosition;
    windowSignUp=other.windowSignUp;
    event=other.event;
    nume=other.nume;
    prenume=other.prenume;
    player=other.player;
    playButton=other.playButton;
    return *this;

}


void SignUp::draw(sf::RenderTarget *target) {
    target->draw(this->boxName);
    target->draw(this->boxSurname);
}


void SignUp::checkButtonState() {

    if(submitButton.get_buttonState() && !pressedOnce) {
        Player tmp(this->prenume->get_text(), this->nume->get_text());
        this->player=tmp;
        pressedOnce=true;
        std::cout<<player.get_name()<<" "<<player.get_surname();
    }

}