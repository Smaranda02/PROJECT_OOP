//
// Created by smaranda on 11/11/2022.
//

#include "SignUp.h"
#include "Exceptions.h"
//#include "Player/Player.h"
//#include "Player/Intermediate.h"
//#include "Player/Beginner.h"
//#include "Player/Advanced.h"
#include "Player.h"
#include "Beginner.h"
#include "Intermediate.h"
#include "Advanced.h"
#include "PlayerInput.h"
//#include "TemplateNewPlayer.h"
#include "StartGameButton.h"

/*
std::vector<std::shared_ptr<Player>> SignUp::get_players(){
    return this->players;
}
*/

PlayerInput& SignUp::get_name() {return *(this->prenume); }
PlayerInput& SignUp::get_surname() {return *(this->nume); }


SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);

    try {
        this->nume = new PlayerInput(15, sf::Color::White, false);
        this->prenume = new PlayerInput(15, sf::Color::White, false);
    } catch(const eroare_input& err){
        std::cout<<err.what()<<"\n";
    }

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


    this->playButton =   StartGameButton(600,400,150,50, this->font, "Start Game");
    this->submitButton = SubmitButton(600,300,150,50, this->font, "Submit");


    this->nume->setFont(font);
    this->nume->setPosition(sf::Vector2f(100, 300));
    this->prenume->setFont(font);
    this->prenume->setPosition(sf::Vector2f(100, 200));



    textPrenume.setFont(font);
    textPrenume.setOutlineColor(sf::Color::Black);
    textPrenume.setOutlineThickness(1.f);
    textPrenume.setFillColor(sf::Color::White);
    textPrenume.setString("Name");
    textPrenume.setPosition(sf::Vector2f(25, 200));
    textPrenume.setCharacterSize(18); // in pixels, not points!


    textNume.setFont(font);
    textNume.setOutlineColor(sf::Color::Black);
    textNume.setOutlineThickness(1.f);
    textNume.setFillColor(sf::Color::White);
    textNume.setString("Surname");
    textNume.setPosition(sf::Vector2f(25, 300));
    textNume.setCharacterSize(18); // in pixels, not points!

}


sf::RenderWindow* SignUp::getWindow(){
    return this->windowSignUp;
}



void SignUp::updateMousePosition() {
    this->mousePosition = sf::Mouse::getPosition(*this->getWindow());
}



void SignUp::SFMLevents() {

        while (this->windowSignUp->pollEvent(event)) {

            this->updateMousePosition();
            this->submitButton.update(static_cast<sf::Vector2f>(this->mousePosition));

            bool playersEmpty=false;
            if(players.empty())
                playersEmpty=true;

            ///is StartGame is pressed
            if(this->playButton.update(static_cast<sf::Vector2f>(this->mousePosition), players.back(), playersEmpty))
            {
                nume->deleteAll();
                prenume->deleteAll();
                pressedOnce=false;
                submitButton.set_ButtonState();
            }

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
                    this->prenume->setSelected(true);
                    }
                if(event.type == sf::Event::TextEntered)
                    prenume->typedOn(event);

                this->nume->setSelected(false);
            }


            if(this->boxSurname.getGlobalBounds().contains(static_cast<sf::Vector2f>(this->mousePosition)))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::cout<<"OK";
                    this->nume->setSelected(true);
                }

                if(event.type == sf::Event::TextEntered)
                    nume->typedOn(event);

                this->prenume->setSelected(false);

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
    this->windowSignUp->draw(textPrenume);
    this->windowSignUp->draw(textNume);
    this->playButton.render(target);
    this->submitButton.render(target);
    this->windowSignUp->display();

}



void SignUp::draw(sf::RenderTarget *target) {
    target->draw(this->boxName);
    target->draw(this->boxSurname);
}


SignUp::~SignUp(){
    delete this->nume;
    delete this->prenume;
}



[[maybe_unused]] SignUp::SignUp(const SignUp &other): textPrenume{other.textPrenume}, textNume{other.textNume}, font{other.font},mousePosition{other.mousePosition},
                                                      event{other.event},  playButton{other.playButton},
                                                      submitButton{other.submitButton} {

    this->players = *new std::vector<std::shared_ptr<Player>>;
    for(auto const &i: other.players)
        this->players.push_back(i->clone());

    windowSignUp=new sf::RenderWindow;
   nume = new PlayerInput(*other.nume);
   prenume=new PlayerInput(*other.prenume);
}



void swap(SignUp& signUp1, SignUp& signUp2)
{
    using::std::swap;
    swap(signUp1.font, signUp2.font);
    swap(signUp1.submitButton, signUp2.submitButton);
    swap(signUp1.mousePosition,signUp2.mousePosition);
    swap(signUp1.windowSignUp,signUp2.windowSignUp);
    swap(signUp1.event,signUp2.event);
    swap(signUp1.nume, signUp2.nume);
    swap(signUp1.prenume,signUp2.prenume);
    swap(signUp1.playButton,signUp2.playButton);
    swap(signUp1.boxSurname,signUp2.boxSurname);
    swap(signUp1.boxName,signUp2.boxName);

}


SignUp& SignUp::operator=(SignUp other) {

    swap(*this,other);
    return *this;

}



void SignUp::checkButtonState() {

    if(submitButton.get_buttonState() && !pressedOnce) {

        bool gasit=false;
       for(auto& player : players)
            if( player->get_name() == this->prenume->get_text() && player->get_surname()==this->nume->get_text()) {
                gasit=true;
                std::cout<<"TE CUNOSC DE UNDEVA\n";


                 if (player->get_level() == 1) {
                     std::cout<<"NIVELUL E 1\n";
                     std::shared_ptr<Intermediate>in = std::make_shared<Intermediate>(this->prenume->get_text(), this->nume->get_text());
                     this->players.push_back(std::shared_ptr<Intermediate>(in));
                     //std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();
                }

                 else if (player->get_level() == 2) {
                     std::cout<<"NIVELUL E 2\n";
                     std::shared_ptr<Advanced> ad = std::make_shared<Advanced>(this->prenume->get_text(), this->nume->get_text());
                    this->players.push_back(std::shared_ptr<Advanced>(ad));
                    //std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();
                }



                ///nu mai adaug si asta cred
                 else if (player->get_level() == 3) {
                     std::shared_ptr<Advanced> ad = std::make_shared<Advanced>(this->prenume->get_text(), this->nume->get_text());
                     this->players.push_back(std::shared_ptr<Advanced>(ad));
                     //std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();
                 }


                players.erase(std::remove(players.begin(), players.end(), player), players.end()); ///il sterg din vector si il reintroduc cu nivelul corect
                break;
            }

       if(gasit==0)
       {
           prenume->get_text();
           nume->get_text();
           std::shared_ptr<Beginner> be = std::make_shared<Beginner>(this->prenume->get_text(), this->nume->get_text());
           this->players.push_back(std::shared_ptr<Beginner>(be));
           //std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname()<<std::endl;

       }

        pressedOnce=true;
        //std::cout<< players[players.size()-1]->get_name()<<" "<<players[players.size()-1]->get_surname();
    }

}