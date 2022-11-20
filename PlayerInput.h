//
// Created by smaranda on 11/12/2022.
//

#ifndef OOP_PLAYERINPUT_H
#define OOP_PLAYERINPUT_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

//https://www.youtube.com/watch?v=T31MoLJws4U



class PlayerInput {
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit = 0;

    void inputLogic(auto charTyped) {

        if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
            text<< static_cast<char>(charTyped);

        else if (charTyped == DELETE_KEY)
        {
            if(text.str().length() > 0)
                deleteLastChar();
        }
        textbox.setString((text.str() + "_"));
    }


    void deleteLastChar(){
        std::string t =text.str();
        std::string newT ;
        for(int i=0; i < int(t.length())-1; i++)
            newT += t[i];

        text.str("");
        text<<newT;

        textbox.setString(text.str());
    }

public:
    PlayerInput();
    ~PlayerInput();
    PlayerInput(int size, sf::Color color, bool sel);
    void setFont(sf::Font &font);
    void setPosition(sf::Vector2f pos);
    //void setLimit(bool ToF);
    //void setLimit(bool ToF, int lim);
    //void setSelected(bool sel);
    //std::string getText();
    void drawTo(sf::RenderWindow &window);
    void typedOn(sf::Event input);

};


#endif //OOP_PLAYERINPUT_H
