//
// Created by smaranda on 1/22/2023.
//

#include "Factory.h"
#include "Beginner.h"
#include "Intermediate.h"
#include "Advanced.h"

std::shared_ptr<Player> Factory::createPlayer(int level, std::string prenume, std::string nume) {
        switch(level) {
            case 1: {
                return std::make_shared<Beginner>(prenume, nume);
            }
            case 2: {
                return std::make_shared<Intermediate>(prenume, nume);
            }
            default: {
                return std::make_shared<Advanced>(prenume, nume);
            }

        }
}