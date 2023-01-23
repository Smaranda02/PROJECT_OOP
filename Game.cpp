//
// Created by smaranda on 10/23/2022.
//

#include "Game.h"
#include "SignUp.h"
#include <SFML/Graphics.hpp>
#include "Exceptions.h"


Game& Game::get_game() {
    static Game game;
    return game;
}


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
        {
            if(event.key.code == sf::Keyboard::Escape)
                this->windowMenu->close();
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                menu->MoveUp();

            }

            if (event.key.code == sf::Keyboard::Down)
            {
                menu->MoveDown();
            }

            if (event.key.code == sf::Keyboard::Enter)
            {
                int option = menu->MainMenuPressed();

                if(option==0)
                {

                        try {
                            SignUp signUp;
                            while (signUp.getWindow()->isOpen()) {
                                signUp.SFMLevents();
                                signUp.render();
                            }
                        } catch (const eroare_input& err){
                            std::cout<<err.what()<<"\n";
                        }
                        catch(const eroare_jucatori& err) {
                            std::cout<<err.what()<<" \n";
                        }
                        catch (const eroare_aplicatie& err) {
                            std::cout << err.what() << "\n";
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

    this->windowMenu= nullptr;
    this->initWindow();
    this->menu = new Menu(*(this->windowMenu));
    //throw eroare_input
}


void Game::render() {


    sf::RectangleShape background;
    background.setSize(sf::Vector2f(800,600));
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


void Game::start_game() {

    while(this->windowMenu->isOpen()) {

        this->updateSFMLEvents();
        this->render();

    }

}

