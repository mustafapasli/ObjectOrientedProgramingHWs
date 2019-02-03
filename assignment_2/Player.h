#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Player{

public:

    Player();
    bool isOnBoard() const;

    char getPlayerName() const;

    int getNumberOfCards() const;

    void setOnBoard(bool onBoard);
    void setPlayerName(char playerName);
    void setNumberOfCards(int cardNumber);
    void setPlayerBackPort(int playerBackPort);
    void setPlayerPositionY(int playerPositionY);
    void setPlayerPositionX(int playerPositionX);

    int getPlayerBackPort() const;
    int getPlayerPositionX() const;
    int getPlayerPositionY() const;

    vector<Card> &getPlayersCard() ;

    Card& getPlayersCard(int index) ;

private:

    int playerPositionX;
    int playerPositionY;
    int numberOfCards;
    int playerBackPort; // port number under the player

    bool onBoard;

    char playerName;

    vector <Card> playersCard;// keeps three card

};

#endif //PLAYER_H
