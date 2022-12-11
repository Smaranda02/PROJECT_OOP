//
// Created by smaranda on 11/26/2022.
//

#include "PlayGame.h"
#include "iostream"
#include "Exceptions.h"

PlayGame::PlayGame() {
    this->windowPlayGame.create(sf::VideoMode(800, 600), "PlayGame");
    this->windowPlayGame.setVerticalSyncEnabled(true);
    this->windowPlayGame.setFramerateLimit(60);

    this->wordList.insert(std::pair<std::string, std::string>("CASA", "LOCUINTA"));
    this->wordList.insert(std::pair<std::string, std::string>("Masa", "Obiect"));


    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    this->shape.setPosition(sf::Vector2f(160, 50));
    this->shape.setSize(sf::Vector2f(480, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


}



void PlayGame::updateSFMLEvents() {


    while (this->windowPlayGame.pollEvent(event)) {

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

    float width=float(windowPlayGame.getSize().x);
    float height=float(windowPlayGame.getSize().y);

    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);
    text.setString("HELLO");
    text.setPosition(sf::Vector2f(width/2,height / 2 ));

    this->windowPlayGame.clear();
    this->windowPlayGame.draw(background);
    this->windowPlayGame.draw(text);
    this->windowPlayGame.draw(shape);
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