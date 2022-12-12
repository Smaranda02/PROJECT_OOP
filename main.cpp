#include "Game.h"
// #include <chrono>
// #include <thread>


int main() {

//am in signUp in constructor facut throw, iar blocul de try catch este in Game.cpp
//variabila statica este in Button si se numeste pressedNumber si este apelata functie de incrementare a varbilei in clasele derivate din Button
//am folosit functia virtuala pura in Player, pe care am suprascriso o in Beginnner, Intermediate, Advanced
//am folosit smart pointers in SignUp la vectorul de pointeri Player


    Game game;
    game.start_game();

    return 0;
}



