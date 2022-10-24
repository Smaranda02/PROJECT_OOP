//
// Created by smaranda on 10/23/2022.
//

#include "Menu.h"
#include <iostream>
    Menu::Menu(float width, float height) {
if(!font.loadFromFile("arial.ttf"))
    std::cout<<"NU";
//handle error
options[0].setFont(font);
options->setFillColor(sf::Color::Yellow);
options[0].setString("SignUp");
options[0].setPosition(sf::Vector2f(width/2,height / optionsNumber ));

options[1].setFont(font);
options->setFillColor(sf::Color::Yellow);
options[1].setString("Rules");
options[1].setPosition(sf::Vector2f(width/2,height / optionsNumber * 2));

optionsSelected=-1;

}

//Menu::~Menu();

void Menu::draw( sf::RenderWindow &window )
{
    for (int i=0;i<optionsNumber;i++)
        window.draw(options[i]);
}

void Menu::MoveDown() {
    if(optionsSelected + 1 <= optionsNumber)
    {
        options[optionsSelected].setFillColor(sf::Color::White);

        optionsSelected++;
        if(optionsSelected == 4) {
            optionsSelected=0;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }

}

void Menu::MoveUp() {
    if(optionsSelected - 1 >=0)
    {
        options[optionsSelected].setFillColor(sf::Color::White);

        optionsSelected--;
        if(optionsSelected == -1) {
            optionsSelected=2;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }
}
