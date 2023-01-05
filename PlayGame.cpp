//
// Created by smaranda on 11/26/2022.
//

#include "PlayGame.h"
#include "iostream"
#include "Exceptions.h"

/*
std::string& toUpperCase(std::string& s)
{
     int size=static_cast<int>(s.length());
    for(int i=0;i<size;i++)
        s[i]=static_cast<char>(toupper(s[i]));
    return s;
}
*/


void PlayGame::checkInputWord( std::string& index) {
    std::cout<<"Checking the word guessed\n";

    //if(toUpperCase(inputWord->get_text()) == toUpperCase(index))
    if(inputWord->get_text() == index) {
        std::cout<<"THE WORD IS CORRECT\n";
        if (this->playerInGame != nullptr)
            this->playerInGame->updatePlayer();
        sendPressed=4;
    }
    else {
        sendPressed++;
        sf::RenderWindow errorPopUp(sf::VideoMode(600, 130), "ERROR!");
        sf::Event event2{};
        sf::Text error;
        error.setFont(font);
        error.setOutlineColor(sf::Color::Black);
        error.setOutlineThickness(3.f);
        error.setFillColor(sf::Color::Red);
        if(sendPressed==4) {
            error.setString("YOU HAVE FAILED ALL 3 ATTEMPTS. THE WORD WAS ???");
            error.setPosition(sf::Vector2f(static_cast<float>(errorPopUp.getSize().x / 10.0),
                                           static_cast<float>(errorPopUp.getSize().y / 2.0)));
        }
        else {
            error.setString("WRONG WORD");
            error.setPosition(sf::Vector2f(static_cast<float>(errorPopUp.getSize().x / 3.0),
                                           static_cast<float>(errorPopUp.getSize().y / 2.0)));
        }

        error.setCharacterSize(25);

        while(errorPopUp.isOpen()) {
            while(errorPopUp.pollEvent(event2))
            {
                if (event2.type == sf::Event::Closed)
                    errorPopUp.close();

                if (event2.type == sf::Event::KeyPressed) {
                    if (event2.key.code == sf::Keyboard::Escape)
                        errorPopUp.close();
                }
            }

            errorPopUp.clear();
            errorPopUp.draw(error);
            errorPopUp.display();
        }
    }

}


/*
[[maybe_unused]] PlayGame& PlayGame::getGame() {
    return *this;
}
 */

PlayGame::PlayGame(const std::shared_ptr<Player>& player) {
    this->windowPlayGame.create(sf::VideoMode(800, 600), "PlayGame");
    this->windowPlayGame.setVerticalSyncEnabled(true);
    this->windowPlayGame.setFramerateLimit(60);

    ///lvl1
    this->wordList["Avion"]="PLANOR CU MOTOR";
    this->wordList["Artemis"]="ZEITA RAZBOIULUI";
    this->wordList["Barca"]="MIJLOC DE TRANSPORT PE APA";
    this->wordList["CASA"] = "SINONIM CU LOCUINTA";
    this->wordList["Masa"]="Obiect pe care se asaza chestii";
    this->wordList["INEL"]="ACCESORIU PENTRU DEGET";
    this->wordList["Ghiozdan"]="SINONIM CU RUCSAC";
    ///lvl2
    this->wordList["SPOVEDANIE"]="MARTURISIRE A GRESELILOR FACUTE";
    this->wordList["ELICOPTER"]="DECOLEAZA SI ATEREIZEAZA FARA PISTA";
    this->wordList["MIRODENII"]="INGREDIENTE DE NATURA VEGETLA, AROMATE SAU PICANTE";
    this->wordList["ISCALI"]="A SCRIE NUMELE PE TEXTUL UNUI ACT OFICIAL";
    this->wordList["SUBORDONAT"]="CARE SE AFLA SUB AUTORITATEA SAUCONDUCEREA CUIVA";
    ///LVL3
    this->wordList["INGRAMADIT"]="CARE ESTE ADUNAT LAOLALTA IN NUMAR PREA MARE";
    this->wordList["CONJUNCTIE"]="PARTE DE VORBIRE CARE LEAGA 2 PROPOZITII SAU DOUA CUVINTE CU ACELASI ROL";
    this->wordList["INSPIRATIE"]="PRIMUL TIMP AL RESPIRATIEI";
    this->wordList["COMEDIANT"]="ACTOR SAU ACTRITA DE CIRC, DE BALCI";
    this->wordList["ONOMATOPEE"]="CUVANT CARE, PRIN ELEMENTELE LUI SONORE IMITA UN SUNET SAU ZGOMOT";


    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    this->sendButton = SendAnswer(600,300,150,50, this->font, "Send Answer");
    playerInGame=player;

    if(playerInGame->get_level()==1)
    {
            int i=0;
            for(const auto &[key,value] : wordList) {
                definition word;
                word.key=key;
                word.value=value;
                queue.push(word);
                i++;
                std::cout<<word.key<<std::endl;
                if(i==5) break;
            }
    }

    else if(playerInGame->get_level()==2)
    {
        int i=0;
        for(const auto &[key,value] : wordList) {
            if(i>=5) {
                definition word;
                word.key = key;
                word.value = value;
                queue.push(word);
                i++;
                std::cout << word.key << std::endl;
                if(i==10) break;
            }
        }
    }

    else {
        int i=0;
        for(const auto &[key,value] : wordList) {
            if(i>=10) {
                definition word;
                word.key = key;
                word.value = value;
                queue.push(word);
                i++;
                std::cout << word.key << std::endl;
                if(i==15) break;
            }
        }
    }



    this->shape.setPosition(sf::Vector2f(50, 100));
    this->shape.setSize(sf::Vector2f(700, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


    this->guessBox.setPosition(sf::Vector2f(150,300));
    this->guessBox.setSize(sf::Vector2f(350, 50));
    this->guessBox.setFillColor(sf::Color::Transparent);
    this->guessBox.setOutlineColor(sf::Color::Black);
    this->guessBox.setOutlineThickness(1);


    this->inputWord = new PlayerInput(15, sf::Color::Red, false);
    this->inputWord->setFont(font);
    this->inputWord->setPosition(sf::Vector2f(170, 400));


    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);


    wordDef.setFont(font);
    wordDef.setOutlineColor(sf::Color::White);
    wordDef.setOutlineThickness(1.f);
    wordDef.setFillColor(sf::Color::Red);
    wordDef.setString("Definitia cuvantului");
    wordDef.setPosition(sf::Vector2f(200, 50));
    wordDef.setCharacterSize(25);


}


void swap(PlayGame& playGame1, PlayGame& playGame2)
{
    using::std::swap;
    swap(playGame1.font, playGame2.font);
    swap(playGame1.text, playGame2.text);
    swap(playGame1.mousePosition, playGame2.mousePosition);
    ///swap(playGame1.windowPlayGame, playGame2.windowPlayGame); nici asta nu ma lasa auuuuu
    swap(playGame1.event, playGame2.event);
    swap(playGame1.inputWord, playGame2.inputWord);
    swap(playGame1.wordGuessed, playGame2.wordGuessed);
    swap(playGame1.sendButton, playGame2.sendButton);
    swap(playGame1.guessBox, playGame2.guessBox);
    swap(playGame1.shape, playGame2.shape);
    swap(playGame1.event, playGame2.event);
    swap(playGame1.wordList, playGame2.wordList);
    swap (playGame1.wordDef, playGame2.wordDef);

}



PlayGame &PlayGame::operator=(PlayGame other) {

    swap(*this,other);
    return *this;

}


[[maybe_unused]] PlayGame::PlayGame(const PlayGame &other) : event{other.event}, text{other.text},font{other.font}, shape{other.shape},
                                            guessBox{other.guessBox},wordList{other.wordList},sendButton{other.sendButton},
                                            mousePosition{other.mousePosition}, wordGuessed{other.wordGuessed}, playerInGame{other.playerInGame->clone()}
{
    ////nu ma lasa sa copiez windowPlayGame ce fac???
    inputWord=new PlayerInput(*other.inputWord);

}



sf::RenderWindow& PlayGame::getWindow() {
    return this->windowPlayGame;
}


void PlayGame::updateMousePosition() {
    this->mousePosition = sf::Mouse::getPosition(this->getWindow());
}



void PlayGame::updateSFMLEvents() {

    while (this->windowPlayGame.pollEvent(event)) {

        this->updateMousePosition();
        if(this->sendButton.update(static_cast<sf::Vector2f>(this->mousePosition))) {
            checkInputWord(queue.front().key);
            if(sendPressed==4) {
                queue.pop();
                sendPressed=0;
            }
        }


        if (this->event.type == sf::Event::Closed)
            this->windowPlayGame.close();
        if (event.type == sf::Event::Resized) {
            std::cout << "New width: " << this->windowPlayGame.getSize().x << '\n'
                      << "New height: " << this->windowPlayGame.getSize().y << '\n';
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                this->windowPlayGame.close();
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                std::cout << "Up key was pressed\n";
            }

            if (event.key.code == sf::Keyboard::Down) {
                std::cout << "Down key was pressed\n";
            }

        }

        if(this->guessBox.getGlobalBounds().contains(static_cast<sf::Vector2f>(this->mousePosition)))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout<<"OK";
                this->inputWord->setSelected(true);
            }
            if(event.type == sf::Event::TextEntered) {
                inputWord->typedOn(event);
            }
        }




    }
}



void PlayGame::draw(sf::RenderTarget *target) {
    target->draw(this->guessBox);
}


void PlayGame::render() {

    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::Yellow);

    text.setString(queue.front().value);
    text.setPosition(sf::Vector2f(70, 120));

    this->windowPlayGame.clear();
    this->inputWord->drawTo(windowPlayGame);
    sf::RenderTarget* target = &this->windowPlayGame;
    this->windowPlayGame.draw(background);
    this->windowPlayGame.draw(text);
    this->windowPlayGame.draw(shape);
    this->windowPlayGame.draw(wordDef);
    draw(target);
    this->windowPlayGame.draw(wordGuessed);
    this->sendButton.render(target);
    this->windowPlayGame.display();


    /*
    float maxLength = 200; ///cati pixeli sa ocupe pe ecran maxim
    unsigned int wordLetters = this->currentWord.length();
    unsigned int nrLines=0;
    float x_coordinate=0;
    float spacing=10;
    float length_line = (maxLength - (wordLetters-1)*spacing ) / wordLetters;

    while(nrLines<wordLetters) {

        //windowPlayGame.draw();

        x_coordinate+=spacing;
        nrLines++;
    }

*/



}



void PlayGame::playGame() {

    while(this->windowPlayGame.isOpen()) {

        this->updateSFMLEvents();
        this->render();
    }

}


PlayGame::PlayGame() {
    this->windowPlayGame.create(sf::VideoMode(800, 600), "PlayGame");
    this->windowPlayGame.setVerticalSyncEnabled(true);
    this->windowPlayGame.setFramerateLimit(60);

    ///lvl1
    this->wordList["Avion"]="PLANOR CU MOTOR";
    this->wordList["Artemis"]="ZEITA RAZBOIULUI";
    this->wordList["Barca"]="MIJLOC DE TRANSPORT PE APA";
    this->wordList["CASA"] = "SINONIM CU LOCUINTA";
    this->wordList["Masa"]="Obiect pe care se asaza chestii";
    this->wordList["INEL"]="ACCESORIU PENTRU DEGET";
    this->wordList["Ghiozdan"]="SINONIM CU RUCSAC";
    ///lvl2
    this->wordList["SPOVEDANIE"]="MARTURISIRE A GRESELILOR FACUTE";
    this->wordList["ELICOPTER"]="DECOLEAZA SI ATEREIZEAZA FARA PISTA";
    this->wordList["MIRODENII"]="INGREDIENTE DE NATURA VEGETLA, AROMATE SAU PICANTE";
    this->wordList["ISCALI"]="A SCRIE NUMELE PE TEXTUL UNUI ACT OFICIAL";
    this->wordList["SUBORDONAT"]="CARE SE AFLA SUB AUTORITATEA SAUCONDUCEREA CUIVA";
    ///LVL3
    this->wordList["INGRAMADIT"]="CARE ESTE ADUNAT LAOLALTA IN NUMAR PREA MARE";
    this->wordList["CONJUNCTIE"]="PARTE DE VORBIRE CARE LEAGA 2 PROPOZITII SAU DOUA CUVINTE CU ACELASI ROL";
    this->wordList["INSPIRATIE"]="PRIMUL TIMP AL RESPIRATIEI";
    this->wordList["COMEDIANT"]="ACTOR SAU ACTRITA DE CIRC, DE BALCI";
    this->wordList["ONOMATOPEE"]="CUVANT CARE, PRIN ELEMENTELE LUI SONORE IMITA UN SUNET SAU ZGOMOT";


    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    this->sendButton = SendAnswer(600,300,150,50, this->font, "Send Answer");

    this->shape.setPosition(sf::Vector2f(50, 100));
    this->shape.setSize(sf::Vector2f(700, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


    this->guessBox.setPosition(sf::Vector2f(150,300));
    this->guessBox.setSize(sf::Vector2f(350, 50));
    this->guessBox.setFillColor(sf::Color::Transparent);
    this->guessBox.setOutlineColor(sf::Color::Black);
    this->guessBox.setOutlineThickness(1);


    this->inputWord = new PlayerInput(25, sf::Color::Red, false);
    this->inputWord->setFont(font);
    this->inputWord->setPosition(sf::Vector2f(150, 400));


    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);

    wordDef.setFont(font);
    wordDef.setOutlineColor(sf::Color::White);
    wordDef.setOutlineThickness(1.f);
    wordDef.setFillColor(sf::Color::Red);
    wordDef.setString("Definitia cuvantului");
    wordDef.setPosition(sf::Vector2f(200, 50));
    wordDef.setCharacterSize(25);


}

PlayGame::~PlayGame() {
    std::cout<<"Destructor for inputWord called";
    delete inputWord;
}
