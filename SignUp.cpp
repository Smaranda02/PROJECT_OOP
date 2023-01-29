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
//#include "Beginner.h"
//#include "Intermediate.h"
//#include "Advanced.h"
#include "PlayerInput.h"
//#include "StartGameButton.h"
#include "Factory.h"

/*
std::vector<std::shared_ptr<Player>> SignUp::get_players(){
    return this->players;
}
*/

/*
template <class T>
void f(T object){
        std::shared_ptr<T>in = std::make_shared<T>(this->prenume->get_text(), this->nume->get_text());
        tmp_players.push_back(std::shared_ptr<Intermediate>(in));
        std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();

    }
*/

template class PlayerInput<int>;

bool SignUp::checkMaxPlayers() {
    if(players.size()<=maxPlayers)
        return true;
    return false;
}



PlayerInput<short>& SignUp::get_name() {return *(this->prenume); }
PlayerInput<int>& SignUp::get_surname() {return *(this->nume); }


SignUp::SignUp() {

    this->windowSignUp = new sf::RenderWindow(sf::VideoMode(800,600), "SignUp Window");

    float width = float(windowSignUp->getSize().x);
    float height = float(windowSignUp->getSize().y);

    try {
        this->nume = new PlayerInput<int>(15, sf::Color::White, false);
        this->prenume = new PlayerInput<short>(15, sf::Color::White, false);
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


    this->playButton  =  StartGameButton(600,400,150,50, this->font, "Start Game");
    this->submitButton = Decorator(600,300,150,50, this->font, "Submit");


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
            this->submitButton.getSubmitButton().update(static_cast<sf::Vector2f>(this->mousePosition));

            bool playersEmpty=false;
            if(players.empty())
                playersEmpty=true;

            ///if StartGame is pressed
            if(this->playButton.update(static_cast<sf::Vector2f>(this->mousePosition), players.back(), playersEmpty))
            {
                nume->deleteAll();
                prenume->deleteAll();
                pressedOnce=false;
                submitButton.getSubmitButton().set_ButtonState();
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

    sf::Text title;

    title.setFont(font);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1.f);
    title.setFillColor(sf::Color::White);
    title.setString("                                             SIGN UP FORM \n"
                    "                   PLEASE ENTER YOUR NAME AND SURNAME");
    title.setPosition(sf::Vector2f(25, 50));
    title.setCharacterSize(25); // in pixels, not points!

    this->windowSignUp->clear();
    this->nume->drawTo(*windowSignUp);
    this->prenume->drawTo(*windowSignUp);


    sf::RenderTarget* target = this->windowSignUp;
    draw(target);
    this->windowSignUp->draw(textPrenume);
    this->windowSignUp->draw(textNume);
    this->windowSignUp->draw(title);
    this->playButton.render(target);
    this->submitButton.getSubmitButton().render(target);
    this->windowSignUp->draw(this->submitButton.getSprite());
    this->windowSignUp->draw(this->submitButton.getText());
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
                                                      event{other.event},playButton{other.playButton},
                                                      submitButton{other.submitButton} {

    this->players = *new std::vector<std::shared_ptr<Player>>;
    for (auto const &i: other.players) { this->players.push_back(i->clone()); }

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

    if(submitButton.getSubmitButton().get_buttonState() && !pressedOnce) {

        bool gasit=false;
        auto tmp_players = players;


        for(auto& player : players)
            if( player->get_name() == this->prenume->get_text() && player->get_surname()==this->nume->get_text()) {
                gasit=true;


                 if (player->get_level() == 1) {
                     /*
                     std::shared_ptr<Intermediate>in = std::make_shared<Intermediate>(this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Intermediate>(in));
                      */

                     std::shared_ptr<Player> in= Factory::createPlayer(2, this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Player>(in));

                     std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();
                }

                 else if (player->get_level() == 2) {
                     /*
                     std::shared_ptr<Advanced> ad = std::make_shared<Advanced>(this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Advanced>(ad));
                      */

                     std::shared_ptr<Player> ad= Factory::createPlayer(3, this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Player>(ad));

                     std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();
                }



                ///nu mai adaug si asta cred
                 else if (player->get_level() == 3) {

                     /*
                     std::shared_ptr<Advanced> ad = std::make_shared<Advanced>(this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Advanced>(ad));
                      */

                     std::shared_ptr<Player> ad= Factory::createPlayer(3, this->prenume->get_text(), this->nume->get_text());
                     tmp_players.push_back(std::shared_ptr<Player>(ad));

                     std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname();

                 }

                tmp_players.erase(std::remove(tmp_players.begin(), tmp_players.end(), player), tmp_players.end()); ///il sterg din vector si il reintroduc cu nivelul corect

                break;
            }
        std::cout << "--------\n";
        for(auto& player : tmp_players)
            std::cout<< player->get_name()<<" "<<player->get_surname() << " " << player->get_level() << "\n";
        std::cout << "--------\n";
        players = tmp_players;

       if(gasit==0)
       {
           if(checkMaxPlayers()) {
               prenume->get_text();
               nume->get_text();


               std::shared_ptr<Player> b= Factory::createPlayer(1, this->prenume->get_text(), this->nume->get_text());
               this->players.push_back(std::shared_ptr<Player>(b));

//
//               std::shared_ptr<Beginner> be = std::make_shared<Beginner>(this->prenume->get_text(),
//                                                                         this->nume->get_text());
//               this->players.push_back(std::shared_ptr<Beginner>(be));




               //std::cout<< players.back()->get_name()<<" "<<players.back()->get_surname()<<std::endl;
           }

           else throw eroare_jucatori();

       }

        pressedOnce=true;
        //std::cout<< players[players.size()-1]->get_name()<<" "<<players[players.size()-1]->get_surname();
    }

}