//
// Created by smaranda on 12/6/2022.
//

#include "StartGameButton.h"
#include "PlayGame.h"

void StartGameButton::update(const sf::Vector2f mousePos)  {
    this->shape.setFillColor(this->idleColor);

    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        //Hover
        //this->buttonState=BTN_HOVER;
        this->shape.setFillColor(this->hoverColor);

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //this->buttonState=BTN_PRESSED;
            incrementPressed();
            PlayGame wordGame;
            wordGame.playGame();
        }

    }
}


std::shared_ptr<Button> StartGameButton::clone() const {
    return std::make_shared<StartGameButton>(*this);
}
