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
        options[0].setOutlineColor(sf::Color::Black);
        options[0].setOutlineThickness(2.f);
        options[0].setFillColor(sf::Color::White);
        options[0].setString("SignUp");
        options[0].setPosition(sf::Vector2f(width/2,height / float(options.size()+1) ));

        options[1].setFont(font);
        options[1].setOutlineColor(sf::Color::Black);
        options[1].setOutlineThickness(2.f);
        options[1].setFillColor(sf::Color::White);
        options[1].setString("Rules");
        options[1].setPosition(sf::Vector2f(width/2,height / float(options.size() +1 )* 2));

        ///work in progress
        /*for(int i=0;i<optionsSelected;i++)
            setter(i,menuText[i]);*/

        optionsSelected=0;


    }



    ///to be continued
    /*
void Menu::setter(int index, std::string& text) {

    options[index].setFont(font);
    options[index].setFillColor(sf::Color::Black);
    options[index].setString(text);
    //options[index].setPosition(sf::Vector2f(width/2,height / float(optionsNumber+1) ));

}
     */



void Menu::draw( sf::RenderWindow &window )
{
    for (const auto & option : options)
        window.draw(option);
}



void Menu::MoveDown() {
    if(optionsSelected + 1 <= int(options.size()))
    {
        options[optionsSelected].setFillColor(sf::Color::White);

        optionsSelected++;
        if(optionsSelected == int(options.size())) {
            optionsSelected=0;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }


}

void Menu::MoveUp() {
    //if(optionsSelected - 1 >=0)
    {
        options[optionsSelected].setFillColor(sf::Color::White);

        optionsSelected--;
        if(optionsSelected == -1) {
            optionsSelected=static_cast<int>(options.size()-1);
            //optionsSelected = 1;
        }

        options[optionsSelected].setFillColor(sf::Color::Blue);
    }

}


int Menu::MainMenuPressed() const{
    return optionsSelected;
}
