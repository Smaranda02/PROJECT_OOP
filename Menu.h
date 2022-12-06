//
// Created by smaranda on 10/23/2022.
//

#ifndef OOP_MENU_H
#define OOP_MENU_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Rules.h"
#include <string>
#include <vector>
#include <array>

class Menu {
private:

    std::array <sf::Text,2> options;
    //std::vector<std::string> menuText = {"SignUp", "Rules"};
    sf::Font font;
    int optionsSelected=0;

public:
    Menu()=default;
    //Menu(float width, float height);
    explicit Menu(const sf::RenderWindow& window);
    //void setter(int index, std::string& text);
    void draw( sf::RenderWindow &window );
    void MoveUp();
    void MoveDown();
    int MainMenuPressed() const;

   ~Menu()=default;


};


#endif //OOP_MENU_H
