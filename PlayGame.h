//
// Created by smaranda on 11/26/2022.
//

#ifndef OOP_PLAYGAME_H
#define OOP_PLAYGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "SendAnswer.h"
//#include "Player/Player.h"
//#include "Player/Beginner.h"
//#include "Player/Intermediate.h"
//#include "Player/Advanced.h"
#include "Player.h"
#include "Beginner.h"
#include "Intermediate.h"
#include "Advanced.h"
#include "PlayerInput.h"
#include <queue>

class PlayGame {
private:

     struct definition{
        std::string key;
        std::string value;
    };

    sf::RenderWindow windowPlayGame;
    sf::Event event{};
    sf::Text text;
    sf::Font font;
    int sendPressed=0;
    sf::RectangleShape shape;
    sf::RectangleShape guessBox;
    //std::string currentWord;
    std::map<std::string, std::string> wordList;
    SendAnswer sendButton;
    sf::Vector2i mousePosition;
    PlayerInput* inputWord;
    sf::Text wordGuessed;
    sf::Text wordDef;
    std::shared_ptr<Player> playerInGame = nullptr ;
    std::queue<definition> queue;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

public:
    PlayGame();

    [[maybe_unused]] PlayGame(const PlayGame& other);
    PlayGame& operator=(PlayGame other);
    explicit PlayGame(const std::shared_ptr <Player>& player);
    void updateSFMLEvents();
    void render();
    void playGame();
    //void draw(sf::RenderTarget* target);
    void updateMousePosition();
    sf::RenderWindow& getWindow();
    ~PlayGame();
    friend void swap(PlayGame& playGame1, PlayGame& playGame2);
    void checkInputWord( std::string& index);
    //[[maybe_unused]]PlayGame& getGame();
    void draw(sf::RenderTarget* target);


};


#endif //OOP_PLAYGAME_H
