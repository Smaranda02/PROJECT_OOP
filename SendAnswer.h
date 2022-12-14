//
// Created by smaranda on 12/11/2022.
//

#ifndef OOP_SENDANSWER_H
#define OOP_SENDANSWER_H
#include "Button.h"
#include "Player.h"

class SendAnswer : public Button {

    using Button::Button;



public:
    SendAnswer()=default;
    SendAnswer(float x, float y, float width, float height, sf::Font& font, const std::string& text);
    int update(sf::Vector2f mousePos) override;
    std::shared_ptr<Button> clone() const override;

};


#endif //OOP_SENDANSWER_H
