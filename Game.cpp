//
// Created by smaranda on 10/23/2022.
//

#include "Game.h"


void Game::start_game() {

    sf::RectangleShape background;
    background.setSize(sf::Vector2f(960,720));
    sf::Texture MenuTexture;
    MenuTexture.loadFromFile("Jocul-Cuvintelor-Meniu.jpg");
    background.setTexture(&MenuTexture);



    MENU.create(sf::VideoMode({800, 700}), "MAIN MENU", sf::Style::Default);

    MENU.setVerticalSyncEnabled(true);

    MENU.setFramerateLimit(60);

    Menu menu(float(MENU.getSize().x), float(MENU.getSize().y));   //agregare

    while(MENU.isOpen()) {

        MENU.setTitle("MENU");
        colour = sf::Color(255, 0, 0, 255);

        while (MENU.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                MENU.close();
            if (event.type == sf::Event::Resized) {
                std::cout << "New width: " << MENU.getSize().x << '\n'
                          << "New height: " << MENU.getSize().y << '\n';
            }
            if (event.type == sf::Event::KeyPressed)
            { std::cout << "Received key ";
                if(event.key.code == sf::Keyboard::Escape)
                    MENU.close();
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    std::cout<<"Up key was pressed\n";
                    menu.MoveUp();
                    //if (event.key.code == sf::Keyboard::Enter)
                        //sf::RenderWindow SignUp(sf::VideoMode(960, 720), "SIGNUP");
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    std::cout<<"Down key was pressed\n";
                    menu.MoveDown();
                    //if (event.key.code == sf::Keyboard::Enter)
                        //sf::RenderWindow Rules(sf::VideoMode(960, 720), "RULES");
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
                    sf::RenderWindow SignUp(sf::VideoMode(960, 720), "SIGNUP");
                    sf::RenderWindow Rules(sf::VideoMode(960, 720), "RULES");

                    int option = menu.MainMenuPressed();
                    if(option==0)
                    {
                        while(SignUp.isOpen())
                        {
                            sf::Event firstEvent{} ;
                            while(SignUp.pollEvent((firstEvent)))
                            {
                                if(firstEvent.type==sf::Event::Closed)
                                {
                                    SignUp.close();
                                }
                                if(firstEvent.type == sf::Event::KeyPressed)
                                {
                                    if(firstEvent.key.code == sf::Keyboard::Escape)
                                        SignUp.close();
                                }
                            }
                            Rules.close();
                            SignUp.clear();
                            SignUp.display();

                        }
                    }

                    if(option==1)
                    {
                        while(Rules.isOpen())
                        {
                            sf::Event secondEvent{};
                            while(Rules.pollEvent((secondEvent)))
                            {
                                if(secondEvent.type==sf::Event::Closed)
                                {
                                    Rules.close();
                                }
                                if(secondEvent.type == sf::Event::KeyPressed)
                                {
                                    if(secondEvent.key.code == sf::Keyboard::Escape)
                                        Rules.close();
                                }
                            }
                            SignUp.close();
                            Rules.clear();
                            Rules.display();

                        }
                    }

                    if(option==2)
                        MENU.close();
                    break;

                }


            }
        }

        if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
            MENU.close();

// using namespace std::chrono_literals;
// std::this_thread::sleep_for(8000ms);

        MENU.clear(sf::Color::Red);
//sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
//rectangle.setFillColor(sf::Color(150, 50, 250));
//window.draw(rectangle);




// select the font
        text.setFont(font); // font is a sf::Font

// set the string to display
        text.setString("Hello world");

// set the character size
        text.setCharacterSize(100); // in pixels, not points!


        text.setFillColor(sf::Color::Black);

        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

// inside the main loop, between window.clear() and window.display()
        MENU.draw(background);
        MENU.draw(text);
        menu.draw(MENU);
        MENU.display();

    }

}