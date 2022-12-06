//
// Created by smaranda on 12/6/2022.
//

#ifndef OOP_STARTGAMEBUTTON_H
#define OOP_STARTGAMEBUTTON_H

#include "Button.h"

class StartGameButton : public Button {

public:
    StartGameButton()=default;
    StartGameButton(float x, float y, float width, float height, sf::Font *font, const std::string& text) : Button(x, y, width,  height, font, text) {}
  void update(sf::Vector2f mousePos) override;
  std::shared_ptr<Button> clone() const override;

};


#endif //OOP_STARTGAMEBUTTON_H
