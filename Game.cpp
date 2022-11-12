//
// Created by smaranda on 10/23/2022.
//

#include "Game.h"
#include "SignUp.h"
#include "SFML/Graphics.hpp"

void Game::initWindow() {
    this->windowMenu = new sf::RenderWindow(sf::VideoMode(800,600), "Main Menu");

    //ce face asta this->windowMenu->create(sf::VideoMode({800, 700}), "MAIN windowMenu", sf::Style::Default);

    //this->windowMenu->setVerticalSyncEnabled(true);

    this->windowMenu->setFramerateLimit(60);

    this->windowMenu->setTitle("windowMenu");
    //colour = sf::Color(255, 100, 230, 255);

}


Game::~Game()
{
    delete this->windowMenu;
}


void Game::updateSFMLEvents() {


    while (this->windowMenu->pollEvent(event))
    {

        if (this->event.type == sf::Event::Closed)
            this->windowMenu->close();
        if (event.type == sf::Event::Resized) {
            std::cout << "New width: " << this->windowMenu->getSize().x << '\n'
                      << "New height: " << this->windowMenu->getSize().y << '\n';
        }
        if (event.type == sf::Event::KeyPressed)
        { std::cout << "Received key ";
            if(event.key.code == sf::Keyboard::Escape)
                this->windowMenu->close();
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                std::cout<<"Up key was pressed\n";
                menu->MoveUp();
                //if (event.key.code == sf::Keyboard::Enter)
                //sf::RenderWindow SignUp(sf::VideoMode(960, 720), "SIGNUP");
            }

            if (event.key.code == sf::Keyboard::Down)
            {
                std::cout<<"Down key was pressed\n";
                menu->MoveDown();
                //if (event.key.code == sf::Keyboard::Enter)
                //sf::RenderWindow Rules(sf::VideoMode(960, 720), "RULES");
            }

            if (event.key.code == sf::Keyboard::Enter)
            {
                int option = menu->MainMenuPressed();

                if(option==0)
                {
                        SignUp signUp;
                    while (signUp.getWindow()->isOpen()) {
                        signUp.SFMLevents();
                        signUp.render();

                    }

                }

                if(option==1) {


                    Rules gameRules;
                    while (gameRules.getWindow()->isOpen()) {
                        gameRules.SFMLevents();
                        gameRules.render();
                        //gameRules.draw();


                    }
                }

                if(option==2)
                    this->windowMenu->close();
                break;

            }
        }
    }

    menu->draw(*windowMenu);


}


Game::Game() {

    this->initWindow();
    this->menu = new Menu(*(this->windowMenu));
}



void Game::render() {


    sf::RectangleShape background;
    background.setSize(sf::Vector2f(960,720));
    sf::Texture MenuTexture;
    MenuTexture.loadFromFile("Jocul-Cuvintelor-Meniu.jpg");
    background.setTexture(&MenuTexture);


    this->windowMenu->clear();
    /// windowMenu.clear(sf::Color::Red);

    //render items

// using namespace std::chrono_literals;
// std::this_thread::sleep_for(8000ms);


//sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
//rectangle.setFillColor(sf::Color(150, 50, 250));
//window.draw(rectangle);


    this->windowMenu->draw(background);
    this->windowMenu->draw(text);
    menu->draw(*windowMenu);
    this->windowMenu->display();

}


void Game::update() {

    this->updateSFMLEvents();
}

void Game::start_game() {

    while(this->windowMenu->isOpen()) {

        this->update();
        this->render();

    }

}

