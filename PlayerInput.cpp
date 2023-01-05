//
// Created by smaranda on 11/12/2022.
//

#include "PlayerInput.h"
#include "Exceptions.h"
//#include "utility" //pentru swap


PlayerInput::PlayerInput(const PlayerInput &other) : textbox{other.textbox} ,
              isSelected{other.isSelected}, hasLimit{other.hasLimit}, limit{other.limit}{}


PlayerInput::PlayerInput(int size, sf::Color color, bool sel) {
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


void PlayerInput::setPosition(sf::Vector2f pos) {
    textbox.setPosition(pos);
}



void PlayerInput::setFont(sf::Font &font) {
    textbox.setFont(font);
}


void PlayerInput::setLimit(bool ToF, int lim) {
    hasLimit =ToF;
    limit = lim;
    if(lim<0)
        throw eroare_input("dimnesiune maxima negativa");
}


void PlayerInput::setSelected(bool sel) {
     isSelected = sel;
     if(!sel) {
         std::string t =text.str();
         std::string newT ;
         for(char i : t)
             newT += i;
         textbox.setString(newT);
     }
}

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

 std::string& PlayerInput::get_text() {
    std::cout<< textbox.getString().toAnsiString();
    return (std::string &) textbox.getString();
}