//
// Created by smaranda on 12/3/2022.
//

#ifndef OOP_SUBMITBUTTON_H
#define OOP_SUBMITBUTTON_H
#include "Button.h"

class SubmitButton : public Button {
    bool isPressed=false;
public:
    SubmitButton()=default;
    SubmitButton(float x, float y, float width, float height, sf::Font& font, const std::string& text) : Button(x, y, width,  height, font, text) {}
    bool get_buttonState() const ;
    SubmitButton(const SubmitButton& other)=default;
    explicit SubmitButton(Button& button);
    int update( sf::Vector2f mousePos) override;
    std::shared_ptr<Button> clone() const override;
    SubmitButton& operator=(const SubmitButton& other)=default;
    void set_ButtonState();

protected:
    void afisare(std::ostream& os) const override;
};


#endif //OOP_SUBMITBUTTON_H
