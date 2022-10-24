//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_MENU_H
#define OOP_MENU_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu {
private:
    //Button SignUp;
    //Button Rules;
    sf::Text options[2];
    sf::Font font;
    int optionsNumber=2;
    int optionsSelected;

public:
    Menu()=default;
    Menu(float width, float height);

    void draw( sf::RenderWindow &window );
    void MoveUp();
    void MoveDown();
    void MainMenuPressed();

   // ~Menu();


};


#endif //OOP_MENU_H
