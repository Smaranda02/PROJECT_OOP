#include "Game.h"
// #include <chrono>
// #include <thread>


int main() {

//am in SignUp.cpp in constructor facut throw, iar blocul de try catch este in Game.cpp
//variabila statica este in Button si se numeste pressedNumber si este apelata functie de incrementare a varbilei in clasele derivate din Button
//am folosit functia virtuala pura in Player, pe care am suprascris o in Beginnner, Intermediate, Advanced
//am folosit smart pointers in SignUp la vectorul de pointeri Player
//throw in PlayerInput in functia setLimit
//try catch in SingUp.cpp in constructor
//2 functii virtuale pure in clasa Player

   auto& game=Game::get_game();
   game.start_game();

   //constr copiere sign up
   //schimb tipul returnat in sign up inde updataez lista de player ca sa scap de functia aia statica





















    return 0;
}



