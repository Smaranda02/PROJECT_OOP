//
// Created by smaranda on 1/22/2023.
//

#ifndef OOP_FACTORY_H
#define OOP_FACTORY_H
#include "Player.h"

class Factory {
public:
    static std::shared_ptr<Player> createPlayer(int level, std::string prenume, std::string nume) ;

};


#endif //OOP_FACTORY_H
