//
// Created by smaranda on 11/12/2022.
//

#ifndef OOP_PLAYERINPUT_H
#define OOP_PLAYERINPUT_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include <sstream>
#include <string>
#include "Exceptions.h"


#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

//https://www.youtube.com/watch?v=T31MoLJws4U

template <typename T>
class PlayerInput {
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit;
    T limit = 0;


    void inputLogic(auto charTyped) {

        if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
            text<< static_cast<char>(charTyped);

        else if (charTyped == DELETE_KEY)
        {
            if(text.str().length() > 0)
                deleteLastChar();
        }
        textbox.setString((text.str()));
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
    PlayerInput() { hasLimit=false; };
    ~PlayerInput()=default;
    PlayerInput(int size, sf::Color color, bool sel) {
        hasLimit= false;
        setLimit(true, 30);
        if(size<0)
            throw eroare_input("dimesniune negativa");
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;

        if(sel){
            textbox.setString("_");
        }

        else {
            textbox.setString("");
        }

    }


    PlayerInput(const PlayerInput& other) : textbox{other.textbox} ,
                                            isSelected{other.isSelected}, hasLimit{other.hasLimit}, limit{other.limit}{};
    void setFont(sf::Font &font) { textbox.setFont(font); }
    void setPosition(sf::Vector2f pos) { textbox.setPosition(pos); }
    std::string get_text() {  return  textbox.getString();  }
    void deleteAll() {
        text.str("");
        textbox.setString(text.str());
    }

    void setLimit(bool ToF, T lim) {
        hasLimit =ToF;
        limit = lim;
        if(lim<0)
            throw eroare_input("dimnesiune maxima negativa");
    }

    void setSelected(bool sel) {
        isSelected = sel;
        if(!sel) {
            std::string t =text.str();
            std::string newT ;
            for(char i : t)
                newT += i;
            textbox.setString(newT);
        }
    }
    void drawTo(sf::RenderWindow &window) {  window.draw(textbox);}
    void typedOn(sf::Event input) {
        if(isSelected) {
            auto charTyped = input.text.unicode;
            if(charTyped < 128) {
                if(hasLimit) {
                    if(int(text.str().length()) <= int(limit)  )
                        inputLogic((charTyped));

                    else if(int(text.str().length()) > (int)limit && charTyped == DELETE_KEY)
                        deleteLastChar();

                }

                else {
                    inputLogic(charTyped);
                }
            }

        }
    }

};


#endif //OOP_PLAYERINPUT_H
