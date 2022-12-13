//
// Created by smaranda on 11/26/2022.
//

#include "PlayGame.h"
#include "iostream"
#include "Exceptions.h"


void PlayGame::updatePlayer(){
    playerInGame->increment_score();
}

PlayGame::PlayGame() {
    this->windowPlayGame.create(sf::VideoMode(800, 600), "PlayGame");
    this->windowPlayGame.setVerticalSyncEnabled(true);
    this->windowPlayGame.setFramerateLimit(60);

    ///lvl1
    this->wordList["CASA"] = "LOCUINTA";
    this->wordList["Masa"]="Obiect pe care se asaza chestii";
    this->wordList["INEL"]="ACCESORIU PENTRU DEGET";
    this->wordList["Sneakersi"] ="Adidasi";
    this->wordList["Ghiozdan"]="Rucsac";
    ///lvl2
    this->wordList["SPOVEDANIE"]="MARTURISIRE A GRESELILOR FACUTE";
    this->wordList["ELICOPTER"]="DECOLEAZA SI ATEREIZEAZA FARA PISTA";
    this->wordList["MIRODENII"]="INGREDIENTE DE NATURA VEGETLA, AROMATE SAU PICANTE";
    this->wordList["ISCALI"]="A SCRIE NUMELE PE TEXTUL UNUI ACT OFICIAL";
    this->wordList["SUBORDONAT"]="CARE SE AFLA SUB AUTORITATEA SAUCONDUCEREA CUIVA";
    ///LVL3
    this->wordList["INGRAMADIT"]="CARE ESTE ADUNAT LAOLALTA IN NUMAR PREA MARE";
    this->wordList["CONJUNCTIE"]="PARTE DE VORBIRE CARE LEAGA 2 PROPOZITII SAU DOUA CUVINTE CU ACELASI ROL";
    this->wordList["RESPIRATIE"]="PRIMUL TIMP AL RESPIRATIEI";
    this->wordList["COMEDIANT"]="ACTOR SAU ACTRITA DE CIRC, DE BALCI";
    this->wordList["ONOMATOPEE"]="CUVANT CARE, PRIN ELEMENTELE LUI SONORE IMITA UN SUNET SAU ZGOMOT";


    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    this->sendButton = SendAnswer(600,400,150,50, this->font, "Send Answer");

    this->shape.setPosition(sf::Vector2f(160, 50));
    this->shape.setSize(sf::Vector2f(480, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


}



sf::RenderWindow& PlayGame::getWindow()
{ return this->windowPlayGame; }


void PlayGame::updateMousePosition() {
    this->mousePosition = sf::Mouse::getPosition(this->getWindow());
}



void PlayGame::updateSFMLEvents() {


    while (this->windowPlayGame.pollEvent(event)) {


        this->updateMousePosition();
        this->sendButton.update(static_cast<sf::Vector2f>(this->mousePosition));


        if (this->event.type == sf::Event::Closed)
            this->windowPlayGame.close();
        if (event.type == sf::Event::Resized) {
            std::cout << "New width: " << this->windowPlayGame.getSize().x << '\n'
                      << "New height: " << this->windowPlayGame.getSize().y << '\n';
        }
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "Received key ";
            if (event.key.code == sf::Keyboard::Escape)
                this->windowPlayGame.close();
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                std::cout << "Up key was pressed\n";
                //if (event.key.code == sf::Keyboard::Enter)
                //sf::RenderWindow SignUp(sf::VideoMode(960, 720), "SIGNUP");
            }

            if (event.key.code == sf::Keyboard::Down) {
                std::cout << "Down key was pressed\n";

            }


        }
    }
}




void PlayGame::render() {

    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::Yellow);

    if(!font.loadFromFile("arial.ttf"))
        std::cout<<"EROARE LA INCARACREA FONTULUI";


    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);


    text.setString(wordList["CASA"]);
    text.setPosition(sf::Vector2f(160, 50));


    sf::RenderTarget* target = &this->windowPlayGame;
    this->windowPlayGame.clear();
    this->windowPlayGame.draw(background);
    this->windowPlayGame.draw(text);
    this->windowPlayGame.draw(shape);
    this->sendButton.render(target);
    this->windowPlayGame.display();

}



void PlayGame::update() {

    this->updateSFMLEvents();
}



void PlayGame::playGame() {

    while(this->windowPlayGame.isOpen()) {

        this->update();
        this->render();

    }

}