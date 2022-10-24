#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Button.h"
// #include <chrono>
// #include <thread>


class Timer : public Button {

};


class Hint_Button : public Button {

};

class Answer_Button : public Button {

};



int main() {

    sf::RenderWindow MENU;
    MENU.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    MENU.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);


    Menu menu(MENU.getSize().x, MENU.getSize().y);


    sf::Text text;
    sf::Font font;
    /*if(!font.loadFromFile("\"C:\\Users\\smara\\Downloads\\Arial-Font\\arial 1.ttf\""))
    {
        std::cout<<"Eroare";
    }
*/


    while(MENU.isOpen()) {
        sf::Event event;
        sf::Color colour;
        MENU.setTitle("MENU");
        colour = sf::Color(255,0,0,255);


        while(MENU.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                MENU.close();
            else if(event.type ==sf::Event::Resized) {
                std::cout << "New width: " << MENU.getSize().x << '\n'
                          << "New height: " << MENU.getSize().y << '\n';
            }
            else if(event.type == sf::Event::KeyPressed)
            {std::cout << "Received key " << (event.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";}

            else if(event.type == sf::Event::KeyReleased)
                            {
                    if(event.key.code==sf::Keyboard::Up)
                        menu.MoveUp();

                    else if(event.key.code == sf::Keyboard::Down)
                        menu.MoveDown();

                    else if(event.key.code == sf::Keyboard::Enter)
                    {
                        sf::RenderWindow SignUp(sf::VideoMode(960,720),"SIGNUP");
                        sf::RenderWindow Rules(sf::VideoMode(960,720),"RULES");

                        //int x=menu
                    }



            }
        }
        // using namespace std::chrono_literals;
        // std::this_thread::sleep_for(8000ms);

        MENU.clear(sf::Color::Red);
        //sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        //rectangle.setFillColor(sf::Color(150, 50, 250));
        //window.draw(rectangle);

        menu.draw(MENU);

        ///am facut o linie
        /*sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(100.f, 500.f)),
                        sf::Vertex(sf::Vector2f(400.f, 500.f))
                };

        window.draw(line, 2, sf::Lines);
         */


// select the font
        text.setFont(font); // font is a sf::Font

// set the string to display
        text.setString("Hello world");

// set the character size
        text.setCharacterSize(100); // in pixels, not points!


        text.setFillColor(sf::Color::Black);

        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

// inside the main loop, between window.clear() and window.display()
        MENU.draw(text);

        MENU.display();
    }

    return 0;
}
