//
// Created by smaranda on 12/27/2022.
//

#include "StartGameButton.h"
#include "PlayGame.h"

[[maybe_unused]] StartGameButton::StartGameButton(const  StartGameButton& other) : idleColor{other.idleColor}, hoverColor{other.idleColor},
                                       text{other.text}, font{other.font} , shape{other.shape}{}


void StartGameButton::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}


StartGameButton::StartGameButton(float x, float y, float width, float height, sf::Font& font, const std::string& text) :   font(font) {

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idleColor);
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(15);
    this->text.setPosition(
            this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f -
            this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f -
            this->text.getGlobalBounds().height / 2.f
    );
}


StartGameButton::~StartGameButton() { std::cout<<"Destructor for Button called"; }



int StartGameButton::update(const sf::Vector2f mousePos, const std::shared_ptr<Player>& player, bool playersEmpty)  {
    this->shape.setFillColor(this->idleColor);
    int pressed=0;
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        //Hover
        //this->buttonState=BTN_HOVER;
        this->shape.setFillColor(this->hoverColor);

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            pressed=1;
            if(!playersEmpty) {
                PlayGame wordGame(player);
                wordGame.playGame();
            }

            else {
                PlayGame wordGame;
                wordGame.playGame();
            }
        }

    }
    return pressed;
}
