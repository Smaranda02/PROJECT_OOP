//
// Created by smaranda on 10/23/2022.
//

#include "Menu.h"
#include <iostream>
#include "Rules.h"


Menu::Menu(const sf::RenderWindow &windowMenu) {

        float width=float(windowMenu.getSize().x);
        float height=float(windowMenu.getSize().y);


        //this->gameRules = new Rules();



    if(!font.loadFromFile("arial.ttf"))
            std::cout<<"EROARE LA INCARACREA FONTULUI";

        options[0].setFont(font);
        options[0].setFillColor(sf::Color::Black);
        options[0].setString("SignUp");
        options[0].setPosition(sf::Vector2f(width/2,height / float(optionsNumber+1) ));

        options[1].setFont(font);
        options[1].setFillColor(sf::Color::Black);
        options[1].setString("Rules");
        options[1].setPosition(sf::Vector2f(width/2,height / float(optionsNumber +1 )* 2));

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


int Menu::MainMenuPressed() const{
    return optionsSelected;
}
