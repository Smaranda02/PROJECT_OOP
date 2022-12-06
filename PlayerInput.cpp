//
// Created by smaranda on 11/12/2022.
//

#include "PlayerInput.h"
#include "Exceptions.h"

PlayerInput::PlayerInput(int size, sf::Color color, bool sel) {
    hasLimit=false;
    if(size<0)
        throw eroare_constructor("dimesniune negativa");
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


void PlayerInput::setPosition(sf::Vector2f pos) {
    textbox.setPosition(pos);
}

/*
void PlayerInput::setLimit(bool ToF) {
    hasLimit= ToF;
}
*/


void PlayerInput::setFont(sf::Font &font) {
    textbox.setFont(font);
}

///to be continued
/*
void PlayerInput::setLimit(bool ToF, int lim) {
    hasLimit =ToF;
    limit = lim;
}
 */



void PlayerInput::setSelected(bool sel) {
     isSelected = sel;
     if(!sel) {
         std::string t =text.str();
         std::string newT ;
         for(int i=0; i < int(t.length()); i++)
             newT += t[i];
         textbox.setString(newT);
     }
}


/*
std::string PlayerInput::getText() {
    return text.str();
}
*/

void PlayerInput::typedOn(sf::Event input)
{
    if(isSelected) {
        auto charTyped = input.text.unicode;
        if(charTyped < 128) {
            if(hasLimit) {
                 if(int(text.str().length()) <= limit  )
                     inputLogic((charTyped));

                 else if(int(text.str().length()) > limit && charTyped == DELETE_KEY)
                    deleteLastChar();

                        }

            else {
                inputLogic(charTyped);
            }
        }

    }
}

void PlayerInput::drawTo(sf::RenderWindow &window){
    window.draw(textbox);
}



PlayerInput::~PlayerInput() { std::cout<<"Destructor for PlayerInput called"; }

PlayerInput::PlayerInput() {hasLimit=false; std::cout<<"Constructor called for PlayerInput";}

std::string& PlayerInput::get_text() {return (std::string &) textbox.getString(); }