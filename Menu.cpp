//
// Created by smaranda on 10/23/2022.
//

#include "Menu.h"
#include <iostream>
#include "Rules.h"

    Menu::Menu(float width, float height)
    {
if(!font.loadFromFile("arial.ttf"))
    std::cout<<"EROARE LA INCARACREA FONTULUI";

options[0].setFont(font);
options[0].setFillColor(sf::Color::Yellow);
options[0].setString("SignUp");
options[0].setPosition(sf::Vector2f(width/2,height / (optionsNumber+1) ));

options[1].setFont(font);
options[1].setFillColor(sf::Color::Yellow);
options[1].setString("Rules");
options[1].setPosition(sf::Vector2f(width/2,height / (optionsNumber +1 )* 2));

optionsSelected=0;

}


void Menu::draw( sf::RenderWindow &window )
{
    for (int i=0;i<optionsNumber;i++)
        window.draw(options[i]);
}



void Menu::MoveDown() {
    if(optionsSelected + 1 <= optionsNumber)
    {
        options[optionsSelected].setFillColor(sf::Color::Black);

        optionsSelected++;
        if(optionsSelected == optionsNumber+1) {
            optionsSelected=0;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }
    //else optionsSelected=0;

}

void Menu::MoveUp() {
    if(optionsSelected - 1 >=0)
    {
        options[optionsSelected].setFillColor(sf::Color::Black);

        optionsSelected--;
        if(optionsSelected == -1) {
            optionsSelected=2;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }

    //else optionsSelected=optionsNumber-1;
}

void Menu::RenderRules(sf::RenderWindow RULES_PAGE)
{
    RULES_PAGE.create(sf::VideoMode({800, 700}), "GAME_RULES", sf::Style::Default);

    RULES_PAGE.setVerticalSyncEnabled(true);

    RULES_PAGE.setFramerateLimit(60);


}


int Menu::MainMenuPressed() {
    return optionsSelected;
}
