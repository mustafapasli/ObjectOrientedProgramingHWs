#include "Tsuro.h"
#include <random>
#include <cstdlib>
Tsuro::Tsuro() {

    winnerPlayer =0;
    numberOfPlayers = 2; // two palyers game
    width = 3;
    height = 3;
    playerNames = {'X','Y','Z','Q','R','S','T','V'};
    tsuroGrid.setHeight(height); // setting grid object height
    tsuroGrid.setWidth(width); //  setting grid object width
    numberOfRandomCards = calculateTotalCardsNumber(); // calculate random number of  card
    tsuroCards.resize(static_cast<unsigned long>(numberOfRandomCards)); // resize tsuro cards array

    for (int i = 0; i < numberOfRandomCards; ++i) { // generate random cards and fill array
        Card card;
        tsuroCards[i] = card;
    }

    tsuroPlayers.resize(static_cast<unsigned long>(numberOfPlayers)); // resize  tsuro players array and fill array
    for (int j = 0; j < numberOfPlayers; ++j) {
        Player player;
        tsuroPlayers[j] = player;
        tsuroPlayers[j].setPlayerName(playerNames[j]);

    }

    boardCards.resize(static_cast<unsigned long>(height)); // resize board cards array
    for (int k = 0; k < height; ++k) {
        boardCards[k].resize(static_cast<unsigned long>(width));
    }

    tsuroGrid.calculateGridSize();

    tsuroGrid.drawGridFrame();

    randomLocatePlayers();
    putPlayersToGrid();
}

Tsuro::Tsuro(int numberOfPlayer) {

    winnerPlayer =0;
    Tsuro::numberOfPlayers = numberOfPlayer;
    width = 3;
    height = 3;
    playerNames = {'X','Y','Z','Q','R','S','T','V'};
    tsuroGrid.setHeight(height); // setting grid object height
    tsuroGrid.setWidth(width); //  setting grid object width
    numberOfRandomCards = calculateTotalCardsNumber(); // calculate random number of  card
    tsuroCards.resize(static_cast<unsigned long>(numberOfRandomCards)); // resize tsuro cards array

    for (int i = 0; i < numberOfRandomCards; ++i) { // generate random cards and fill array
        Card card;
        tsuroCards[i] = card;
    }

    tsuroPlayers.resize(static_cast<unsigned long>(numberOfPlayers)); // resize  tsuro players array and fill array
    for (int j = 0; j < numberOfPlayers; ++j) {
        Player player;
        tsuroPlayers[j] = player;
        tsuroPlayers[j].setPlayerName(playerNames[j]);

    }

    boardCards.resize(static_cast<unsigned long>(height)); // resize board cards array
    for (int k = 0; k < height; ++k) {
        boardCards[k].resize(static_cast<unsigned long>(width));
    }

    tsuroGrid.calculateGridSize();

    tsuroGrid.drawGridFrame();

    randomLocatePlayers();
    putPlayersToGrid();

}

void Tsuro::displayCurrentBoard() {

    for (int i = 0; i < tsuroGrid.getGridHeight(); ++i) {
        for (int j = 0; j < tsuroGrid.getGridWidth(); ++j) {
            cout <<tsuroGrid.getGridInCell(i,j);
        }
        cout << endl;
    }

}

int Tsuro::calculateTotalCardsNumber() {

    int total = numberOfPlayers * 3;

    while(total < (height * width)){
        total *=2;
    }

    return total+1;
}

void Tsuro::randomLocatePlayers() {

    vector <vector <int> > startLocates; // keeps start locates on the board
    int numberOfStartLocates = (width+height)*4;
    startLocates.resize(static_cast<unsigned long>(numberOfStartLocates));
    for (int i = 0; i < numberOfStartLocates; ++i) { // resize  for x,y position
        startLocates[i].resize(2);
    }

    int x = 0; // first index of start locates

    for (int k = 0; k < tsuroGrid.getGridHeight(); ++k) {
        for (int i = 0; i < tsuroGrid.getGridWidth(); ++i) {
            if(tsuroGrid.getGridInCell(k,i) == 'o'){
                startLocates[x][0] = k;
                startLocates[x][1] = i;
                x++;

            }
        }
    }

    int randomLocateIndex;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int j = 0; j < numberOfPlayers; ++j) { // assigns random position to array
        randomLocateIndex = rand() % numberOfStartLocates;
        tsuroPlayers[j].setPlayerPositionY(startLocates[randomLocateIndex][0])  ;
        tsuroPlayers[j].setPlayerPositionX(startLocates[randomLocateIndex][1])  ;
        startLocates.erase(startLocates.begin()+randomLocateIndex);
        numberOfStartLocates--;
    }


}

void Tsuro::putPlayersToGrid() {

    for (int i = 0; i < numberOfPlayers; ++i) { // puts players to grid frame by random position

        tsuroGrid.setGridInCell(tsuroPlayers[i].getPlayerPositionY(),tsuroPlayers[i].getPlayerPositionX(),tsuroPlayers[i].getPlayerName());

    }

}

void Tsuro::putCardtoGrid(Card card, int gridX, int gridY) {

    for (int i = 0; i < cardHeight; ++i) {
        for (int j = 0; j < cardWidth; ++j) {
            tsuroGrid.setGridInCell(gridY+i,gridX+j, card.getArrayCard()[i][j]);
        }
    }

}

vector<Player> &Tsuro::getTsuroPlayers()  {
    return tsuroPlayers;
}

void Tsuro::giveCardToPlayer(int playerIndex) {

    if(tsuroPlayers[playerIndex].getNumberOfCards() == 0){ // give random 3 cards to player

        for (int i = 0; i < 3; ++i) {
            tsuroPlayers[playerIndex].getPlayersCard().resize(3);
            tsuroPlayers[playerIndex].getPlayersCard(i).setArrayCard(tsuroCards.back().getArrayCard());
            tsuroPlayers[playerIndex].setNumberOfCards(tsuroPlayers[playerIndex].getNumberOfCards()+1);
            tsuroPlayers[playerIndex].getPlayersCard(i).rotateRight();
            tsuroPlayers[playerIndex].getPlayersCard(i).rotateLeft();
            tsuroCards.pop_back();

        }

    }


    printPlayersCards(tsuroPlayers[playerIndex]);

}

void Tsuro::printPlayersCards(Player player) {

    for (int j = 0; j < cardHeight; ++j) { // prints three cards to screen
        for (int i = 0; i < player.getNumberOfCards(); ++i) {
            for (int k = 0; k < cardWidth; ++k) {
                cout << player.getPlayersCard(i).getArrayCard()[j][k];
            }
            cout << "  ";
        }
        cout << endl;
    }

}

void Tsuro::putCardtoGridbyCardPosition(Card card, int cardY, int cardX) {
    // paste cards to board
    int X = 2 + (cardX-1)* cardWidth;
    int Y = 1 + (cardY-1)* cardHeight;

    card.setOnBoard(true);

    putCardtoGrid(card,X,Y);

}

void Tsuro::erasePlayerCard(int cardIndex, int playerIndex) {

    tsuroPlayers[playerIndex].getPlayersCard().erase(tsuroPlayers[playerIndex].getPlayersCard().begin()+cardIndex);
    tsuroPlayers[playerIndex].setNumberOfCards(tsuroPlayers[playerIndex].getNumberOfCards()-1);
    if(tsuroPlayers[playerIndex].getNumberOfCards() == 0 ){
        tsuroPlayers[playerIndex].getPlayersCard().resize(3);
    }

}

bool Tsuro::checkCardPosition(int cardY, char x, int cardX, Player player) {

    int X = (cardX-1)* cardWidth;
    int Y = (cardY-1)* cardHeight;

    if(x != 'x'){
        return false;
    }

    if(cardX < 0 || cardX > width){
        return false;
    }

    if(cardY < 0 || cardY > height){
        return false;
    }

    if(tsuroGrid.getGridInCell(Y+1,X+2) == '.'){
        return false;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 16; ++j) {
            if(tsuroGrid.getGridInCell(Y+i,X+j) == player.getPlayerName()){
                return true;
            }
        }
    }

    return false;
}

int Tsuro::checkPlayersNumberOfCard(Player player, string line) {

    int cardNumber;

    if(line.size() != 1){
        return -1;
    }

    cardNumber = line[0]-charToInt;

    if(cardNumber<1 || cardNumber > player.getPlayersCard().size()){
        return -1;
    }

    return cardNumber;
}

void Tsuro::checkCardEnvironment(int cardX, int cardY,int playerIndex) {

    int posX = 0; // player's x positions on grid
    int posY = 0; // player's y positions on grid

    int port;
    int path;

    int boardX = 2 + (cardX-1) * cardWidth; // card's x positions on grid
    int boardY = 1 + (cardY-1) * cardHeight; // card's x positions on grid

    for (int i = 0; i < 8; ++i) { // checks card environments for there is player
        for (int j = 0; j < 18; ++j) {

            // if there is assign the positions
            if(tsuroGrid.getGridInCell(boardY-1+i,boardX-3+j) == tsuroPlayers[playerIndex].getPlayerName() && (((i==0 ||i==8-1)||(j<3))||(j>14))){
                posX = boardX-3+j;
                posY = boardY-1+i;
                // if player is on the frame , puts players position 'o'
                if(posX == 0 || posY == 0 || posY == tsuroGrid.getGridHeight() -1|| posX == tsuroGrid.getGridWidth()-1) {
                    tsuroGrid.setGridInCell(posY,posX,'o');
                } else { // is not on the frame put previous port number to  players positions
                    tsuroGrid.setGridInCell(posY,posX, static_cast<char>(tsuroPlayers[playerIndex].getPlayerBackPort() + charToInt));
                }
            }
        }
    }

    findPortAndPath(posX,posY,path,port);

    for (int m = 0; m < 6; ++m) { // if there is a another players on the port
        if(playerNames[m] == port){
            cout << "Collide players !" << endl;
        }
    }

    // char to int

    port = port - charToInt;
    path = path - charToInt;



    if(path > 0 && path < 9) // if there isn't player in this position
        tsuroPlayers[playerIndex].setPlayerBackPort(path) ;

    for (int k = 0; k < cardHeight; ++k) { // finding card port for players port
        for (int i = 0; i < cardWidth; ++i) {
            if(tsuroGrid.getGridInCell(boardY+k,boardX+i) == path+charToInt && ((k==0||k==5)||(i==0||i==11))){
                tsuroGrid.setGridInCell(boardY+k,boardX+i,tsuroPlayers[playerIndex].getPlayerName());
                // if player port is near the frame
                if(boardY+k == 1 || boardY+k == tsuroGrid.getGridHeight()-2 || boardX+i == 2 || boardX+i == tsuroGrid.getGridWidth()-3){
                    displayCurrentBoard();
                    cout << "Player " << tsuroPlayers[playerIndex].getPlayerName() << " lost!" << endl;
                    tsuroGrid.setGridInCell(boardY+k,boardX+i, static_cast<char>(tsuroPlayers[playerIndex].getPlayerBackPort() + charToInt));
                    tsuroPlayers[playerIndex].setOnBoard(false);
                }
            }

        }
    }

    // than players move, put the previous port value

    for (int l = 2; l < tsuroGrid.getGridWidth(); ++l) {
        if(tsuroGrid.getGridInCell(1,l) == tsuroPlayers[playerIndex].getPlayerName()){
            tsuroGrid.setGridInCell(1,l,static_cast<char>(path + charToInt));
            tsuroGrid.setGridInCell(0,l, tsuroPlayers[playerIndex].getPlayerName());
        }
    }
    for (int l = 2; l < tsuroGrid.getGridWidth(); ++l) {
        if(tsuroGrid.getGridInCell(tsuroGrid.getGridHeight()-2, l) == tsuroPlayers[playerIndex].getPlayerName()){
            tsuroGrid.setGridInCell(tsuroGrid.getGridHeight()-2,l,static_cast<char>(path + charToInt));
            tsuroGrid.setGridInCell(tsuroGrid.getGridHeight()-1,l,tsuroPlayers[playerIndex].getPlayerName());
        }
    }

    for (int l = 2; l < tsuroGrid.getGridHeight(); ++l) {
        if(tsuroGrid.getGridInCell(l,2) == tsuroPlayers[playerIndex].getPlayerName()){
            tsuroGrid.setGridInCell(l,2,static_cast<char>(path + charToInt));
            tsuroGrid.setGridInCell(l,0,tsuroPlayers[playerIndex].getPlayerName());
        }
    }

    for (int l = 2; l < tsuroGrid.getGridHeight(); ++l) {
        if(tsuroGrid.getGridInCell(l,tsuroGrid.getGridWidth()-3) == tsuroPlayers[playerIndex].getPlayerName()){
            tsuroGrid.setGridInCell(l,tsuroGrid.getGridWidth()-3,static_cast<char>(path + charToInt));
            tsuroGrid.setGridInCell(l,tsuroGrid.getGridWidth()-1,tsuroPlayers[playerIndex].getPlayerName());
        }
    }

}

void Tsuro::fillBoardCards(int cardY, int cardX, Card card) {

    card.setOnBoard(true);
    boardCards[cardY-1][cardX-1] = card;

}

bool Tsuro::lastPlayerOnTheBoard() {

    int flag = 0;
    char player = 0;

    for (int i = 1; i < tsuroGrid.getGridHeight()-2; ++i) {
        for (int j = 2; j < tsuroGrid.getGridWidth()-3; ++j) {
            for (int k = 0; k < 6; ++k) {
                if(tsuroGrid.getGridInCell(i,j) == playerNames[k]){
                    flag++;
                    player = playerNames[k];
                }
            }
        }
    }

    if(flag == 1){
        winnerPlayer = player;
        return true;
    }

    return false;
}

void Tsuro::rotate(int playerIndex, int cardIndex, char rotation) {

    if(rotation == 'L') {
        tsuroPlayers[playerIndex].getPlayersCard(cardIndex).rotateLeft();
    }
    if(rotation == 'R') {
        tsuroPlayers[playerIndex].getPlayersCard(cardIndex).rotateRight();
    }


}

int Tsuro::getNumberOfPlayers() const {
    return numberOfPlayers;
}

int Tsuro::getWidth() const {
    return width;
}

int Tsuro::getHeight() const {
    return height;
}

char Tsuro::getWinnerPlayer() const {
    return winnerPlayer;
}

void Tsuro::findPortAndPath(const int posX, const int posY, int &path, int &port) {

    if(posY == tsuroGrid.getGridHeight()-1){
        port = tsuroGrid.getGridInCell(posY-1,posX);
        path = tsuroGrid.getGridInCell(posY-2,posX);
    }
    else if(posY == 0){
        port = tsuroGrid.getGridInCell(posY+1,posX);
        path = tsuroGrid.getGridInCell(posY+2,posX);
    }
    else if(posX == tsuroGrid.getGridWidth()-1){
        port = tsuroGrid.getGridInCell(posY,posX-2);
        path = tsuroGrid.getGridInCell(posY,posX-6);
    }
    else if(posX == 0){
        port = tsuroGrid.getGridInCell(posY,posX+2);
        path = tsuroGrid.getGridInCell(posY,posX+6);
    }
    else if(posY%cardHeight==0){
        port = tsuroGrid.getGridInCell(posY+1,posX);
        path = tsuroGrid.getGridInCell(posY+2,posX);
    }
    else if(posY%cardHeight==1){
        port = tsuroGrid.getGridInCell(posY-1,posX);
        path = tsuroGrid.getGridInCell(posY-2,posX);
    }
    else if((posX-1)%cardWidth == 0){
        port = tsuroGrid.getGridInCell(posY,posX+1);
        path = tsuroGrid.getGridInCell(posY,posX+5);
    }
    else if((posX-1)%cardWidth == 1){
        port = tsuroGrid.getGridInCell(posY,posX-1);
        path = tsuroGrid.getGridInCell(posY,posX-5);
    }

}

Card &Tsuro::getBoardCards(int yIndex,int xIndex)  {
    return boardCards[yIndex][xIndex];
}

