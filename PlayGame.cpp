//
// Created by smaranda on 11/26/2022.
//

#include "PlayGame.h"
#include <iostream>
#include "Exceptions.h"
#include <fstream>
#include "Beginner.h"
//#include "Decorator.h"
#include <chrono>
#include <thread>


std::string toUpperCase(std::string s)
{
     int size=static_cast<int>(s.length());
    for(int i=0;i<size;i++)
        s[i]=static_cast<char>(toupper(s[i]));
    return s;
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

    std::ifstream file;
    file.open("wordList.txt");
    std::string line;

    while(file)
    {
        std::string key;
        std::string value;
        std::getline(file, line);
        unsigned int size=line.length();
        for(unsigned int i=0;i<size;i++)
            if(line[i]==' ')
            {
                 key = line.substr(0,i);
                 value = line.substr(i+1, size-1);
                break;
            }

        if(value.length()>38)
        {
            std::string space = " ";
            std::string copy=value.substr(38,value.length()-1);
            size_t found=copy.find(space);
            if(found != std::string::npos)
                value=value.substr(0,38+found)+"\n"+value.substr(38+found+1,value.length()-1);

        }
        this->wordList[key]=value;
    }



    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    if(!soundBuffer.loadFromFile("Sound.wav"))
    {
        std::cout<<"EROARE LA INCARCARE SUNET";
    }

    sound.setBuffer(soundBuffer);


    this->sendButton = SendAnswer(600,300,150,50, this->font, "Send Answer");
    playerInGame=player;

    if(playerInGame->get_level()==1)
    {
            unsigned int i=0;
            for(const auto &[key,value] : wordList) {
                definition word;
                word.key=key;
                word.value=value;
                queue.push(word);
                i++;
                std::cout<<word.key<<std::endl;
                if(i==wordList.size()/3) break;
            }
    }

    else if(playerInGame->get_level()==2)
    {
        unsigned int i=0;
        for(const auto &[key,value] : wordList) {
            if(i>=wordList.size()/3) {
                definition word;
                word.key = key;
                word.value = value;
                queue.push(word);
                i++;
                std::cout << word.key << std::endl;
                if(i==wordList.size()*2/3) break;
            }
            else i++;
        }
    }

    else {
        unsigned int i=0;
        for(const auto &[key,value] : wordList) {
            if(i>=wordList.size()*2/3) {
                definition word;
                word.key = key;
                word.value = value;
                queue.push(word);
                i++;
                std::cout << word.key << std::endl;
                if(i==wordList.size()) break;
            }
            else i++;
        }
    }



    this->shape.setPosition(sf::Vector2f(50, 100));
    this->shape.setSize(sf::Vector2f(700, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


    this->scoreBox.setPosition(sf::Vector2f(370, 450));
    this->scoreBox.setSize(sf::Vector2f(150, 50));
    this->scoreBox.setOutlineColor(sf::Color::Black);
    this->scoreBox.setOutlineThickness(2);
    this->scoreBox.setFillColor(sf::Color::Cyan);


    this->guessBox.setPosition(sf::Vector2f(170,300));
    this->guessBox.setSize(sf::Vector2f(350, 50));
    this->guessBox.setFillColor(sf::Color::Transparent);
    this->guessBox.setOutlineColor(sf::Color::Black);
    this->guessBox.setOutlineThickness(2);


    this->inputWord = new PlayerInput<double>(22, sf::Color::Red, false);
    this->inputWord->setFont(font);
    this->inputWord->setPosition(sf::Vector2f(170, 310));


    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);


    wordDef.setFont(font);
    wordDef.setOutlineColor(sf::Color::Black);
    wordDef.setOutlineThickness(2.f);
    wordDef.setFillColor(sf::Color::White);
    wordDef.setString("Definitia cuvantului");
    wordDef.setPosition(sf::Vector2f(300, 50));
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
    swap(playGame1.soundBuffer,playGame2.soundBuffer);
    swap(playGame1.sound,playGame2.sound);
    swap(playGame1.scoreBox,playGame2.scoreBox);


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
                if(queue.empty())
                {
                    if(wordsGuessed==0)
                    {
                        auto playingNow=std::dynamic_pointer_cast<Beginner>(playerInGame);

                        if(playingNow) {
                            std::cout << "Good cast\n";
                            std::cout<<playingNow->get_name()<<std::endl;

                        }

                        else {
                            std::cout << "Bad cast\n";
                            continue;
                        }


                        sf::RenderWindow sadPopUp(sf::VideoMode(600, 130), "Sad...");
                        sf::Event event3{};
                        sf::Text sad;
                        sad.setFont(font);
                        sad.setOutlineColor(sf::Color::Black);
                        sad.setOutlineThickness(3.f);
                        sad.setFillColor(sf::Color::Red);

                        sad.setString(playingNow->sadMessage());
                        sad.setPosition(sf::Vector2f(static_cast<float>(sadPopUp.getSize().x / 10.0),
                                                           static_cast<float>(sadPopUp.getSize().y / 2.0)));


                        sad.setCharacterSize(25);

                        while(sadPopUp.isOpen()) {
                            while(sadPopUp.pollEvent(event3))
                            {
                                if (event3.type == sf::Event::Closed)
                                    sadPopUp.close();

                                if (event3.type == sf::Event::KeyPressed) {
                                    if (event3.key.code == sf::Keyboard::Escape)
                                        sadPopUp.close();
                                }
                            }

                            sadPopUp.clear();
                            sadPopUp.draw(sad);
                            sadPopUp.display();
                        }

                    }

                    using namespace std::this_thread;     // sleep_for, sleep_until
                    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
                    using std::chrono::system_clock;
                    sleep_for(1.5s);
                    windowPlayGame.close();
                }
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
            }

            if (event.key.code == sf::Keyboard::Down) {
            }

        }

        if(this->guessBox.getGlobalBounds().contains(static_cast<sf::Vector2f>(this->mousePosition)))
        {

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout<<"OK";

                auto playingNow=std::dynamic_pointer_cast<Beginner>(playerInGame);
                if(playingNow) {
                    std::cout << "Good cast\n";
                    std::cout<<playingNow->get_name()<<std::endl;

                }
                else std::cout<<"Bad cast\n";

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

    sf::Text guess;
    guess.setFont(font);
    guess.setOutlineColor(sf::Color::Black);
    guess.setOutlineThickness(2.f);
    guess.setFillColor(sf::Color::White);
    guess.setString("GHICESTE :");
    guess.setPosition(sf::Vector2f(15, 310));
    guess.setCharacterSize(25);


    sf::Text score;
    score.setFont(font);
    score.setOutlineColor(sf::Color::Black);
    score.setOutlineThickness(2.f);
    score.setFillColor(sf::Color::White);
    score.setString("SCORUL TAU :");
    score.setPosition(sf::Vector2f(170, 460));
    score.setCharacterSize(25);



    text.setString(queue.front().value);
    text.setPosition(sf::Vector2f(70, 120));


    sf::Text scoreNumber;
    scoreNumber.setFont(font);
    scoreNumber.setOutlineColor(sf::Color::Black);
    scoreNumber.setOutlineThickness(2.f);
    scoreNumber.setFillColor(sf::Color::White);
    scoreNumber.setString(std::to_string(playerInGame->getScore()));
    scoreNumber.setPosition(sf::Vector2f(430, 460));
    scoreNumber.setCharacterSize(25);

    this->windowPlayGame.clear();
    sf::RenderTarget* target = &this->windowPlayGame;
    this->windowPlayGame.draw(background);
    this->windowPlayGame.draw(text);
    this->windowPlayGame.draw(shape);
    this->windowPlayGame.draw(scoreBox);
    this->windowPlayGame.draw(wordDef);
    this->windowPlayGame.draw(guess);
    this->windowPlayGame.draw(score);
    this->windowPlayGame.draw(scoreNumber);


    draw(target);
    this->windowPlayGame.draw(wordGuessed);
    this->sendButton.render(target);
    this->inputWord->drawTo(windowPlayGame);
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

    std::ifstream file;
    file.open("wordList.txt");
    std::string line;

    while(file)
    {
        std::string key;
        std::string value;
        std::getline(file, line);
        unsigned int size=line.length();
        for(unsigned int i=0;i<size;i++)
            if(line[i]==' ')
            {
                key = line.substr(0,i);
                value = line.substr(i+1, size-1);
                break;
            }

        this->wordList[key]=value;
    }


    if (!font.loadFromFile("arial.ttf")) { std::cout << "EROARE LA INCARACREA FONTULUI";
        throw eroare_font();
    }


    if(!soundBuffer.loadFromFile("Sound.wav"))
    {
        std::cout<<"EROARE LA INCARCARE SUNET";
    }

    sound.setBuffer(soundBuffer);


    this->sendButton = SendAnswer(600,300,150,50, this->font, "Send Answer");

    this->shape.setPosition(sf::Vector2f(50, 100));
    this->shape.setSize(sf::Vector2f(700, 100));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
    this->shape.setFillColor(sf::Color::Transparent);


    this->scoreBox.setPosition(sf::Vector2f(370, 450));
    this->scoreBox.setSize(sf::Vector2f(150, 50));
    this->scoreBox.setOutlineColor(sf::Color::Black);
    this->scoreBox.setOutlineThickness(2);
    this->scoreBox.setFillColor(sf::Color::Red);

    this->guessBox.setPosition(sf::Vector2f(170,300));
    this->guessBox.setSize(sf::Vector2f(350, 50));
    this->guessBox.setFillColor(sf::Color::Red);
    this->guessBox.setOutlineColor(sf::Color::Transparent);
    this->guessBox.setOutlineThickness(2);


    this->inputWord = new PlayerInput<double>(22, sf::Color::Red, false);
    this->inputWord->setFont(font);
    this->inputWord->setPosition(sf::Vector2f(170, 310));


    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.f);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);


    wordDef.setFont(font);
    wordDef.setOutlineColor(sf::Color::Black);
    wordDef.setOutlineThickness(2.f);
    wordDef.setFillColor(sf::Color::White);
    wordDef.setString("Definitia cuvantului");
    wordDef.setPosition(sf::Vector2f(300, 50));
    wordDef.setCharacterSize(25);


}

PlayGame::~PlayGame() {
    std::cout<<"Destructor for inputWord called";
    delete inputWord;
}



void PlayGame::checkInputWord( const std::string& index) {
    std::cout<<"Checking the word guessed\n";

    if(toUpperCase(inputWord->get_text()) == toUpperCase(index))
    {
        std::cout<<"THE WORD IS CORRECT\n";
        wordsGuessed++;
        sound.play();
        inputWord->deleteAll();
        if (this->playerInGame != nullptr) {
            this->playerInGame->updatePlayer();
            std::cout<<playerInGame->getScore();
        }
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
