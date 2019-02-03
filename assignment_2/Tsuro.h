#ifndef TSURO_H
#define TSURO_H

#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Grid.h"

using namespace std;

class Tsuro{

public:

    Tsuro(); // constructor for 3x3 board and 2 players game
    explicit Tsuro(int numberOfPlayer); // constructor for 3x3 board game and takes parameter number of players

    int getWidth() const;
    int getHeight() const;
    int getNumberOfPlayers() const;
    int checkPlayersNumberOfCard(Player player,string line); // checks entered card number of user

    char getWinnerPlayer() const;

    void displayCurrentBoard();
    void giveCardToPlayer(int playerIndex); // gives 3 random cards to players
    void fillBoardCards(int cardY,int cardX,Card card); // takes card position and card and put in to boardCard array
    void erasePlayerCard(int cardIndex,int playerIndex); // removes played card from users deck
    void rotate(int playerIndex,int cardIndex, char rotation); // rotate card
    void putCardtoGridbyCardPosition(Card card,int cardY,int cardX); // puts card to board grid array by card position
    void checkCardEnvironment(int cardX,int cardY, int playerIndex); // check card port and path by players position

    bool lastPlayerOnTheBoard(); // if there is one player on the board returns true
    bool checkCardPosition(int cardY, char x ,int cardX,Player player); // checks entered card position from user

    vector<Player> &getTsuroPlayers() ;
    Card &getBoardCards(int yIndex,int xIndex) ;


private:


    static const int cardWidth = 12;
    static const int cardHeight = 6;
    static const int charToInt = 48;

    int width; // board width by card width
    int height; // board height by card height
    int numberOfPlayers;
    int numberOfRandomCards; // generated number of cards by board size and number of players
    int calculateTotalCardsNumber(); // calculates random number of cards by board size and number of players

    char winnerPlayer;

    Grid tsuroGrid; // keeps board grid cells
    vector <Card> tsuroCards; // keeps random generated cards
    vector <char> playerNames ;
    vector <Player> tsuroPlayers; // keeps players
    vector <vector <Card> > boardCards; // keeps played cards

    void putPlayersToGrid(); // put players into the edge of the board frame
    void randomLocatePlayers(); // gives random ports to the users
    void printPlayersCards(Player player); // print players card in deck
    void putCardtoGrid(Card card,int gridX,int gridY); // puts card to grid cells by position
    void findPortAndPath(int posX, int posY, int &path, int &port); // find port and port by the grid cells

};

#endif //TSURO_H
