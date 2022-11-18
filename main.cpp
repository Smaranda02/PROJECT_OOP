#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "Menu.h"
#include "Button.h"
#include "Game.h"
// #include <chrono>
// #include <thread>


int main() {

    //https://dafontonline.com/arial-font-free-download/


class eroare_aplicatie : public std::runtime_error{
    using std::runtime_error::runtime_error;
};

    Game game;
    game.start_game();

    return 0;
}
