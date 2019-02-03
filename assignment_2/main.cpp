#include <iostream>
#include "Tsuro.h"

using namespace std;

// takes a line and checks the number between 2 and 8
int checkNumberOfPlayer(string line);

int main() {

    char rotationChar[1]; //keeps rotation char for kart rotate
    char sSelectedCard[1]; // keeps player selected card
    char sNumberOfPlayer[1]; // string number of players
    char selectedPosition[3]; // keeps card position on the board

    int x,y; // keeps card coordinate
    int selectedCard; // selected players card number
    int numberOfPlayer; // keeps number of players
    // taking number of players from the user
    cout << "Enter number of player between 2-8>" << endl;
    cin >> sNumberOfPlayer;
    numberOfPlayer = checkNumberOfPlayer(sNumberOfPlayer);
    // control loop number of players
    while(numberOfPlayer == -1){
        cout << "Invalid number!" << endl;
        cout << "Enter number of player between 2-8>" << endl ;
        cin >> sNumberOfPlayer;
        numberOfPlayer = checkNumberOfPlayer(sNumberOfPlayer);
    }
    // new tsuro object with numberOfplayers
    Tsuro game1(numberOfPlayer);
    game1.displayCurrentBoard(); // printing first board to screen

    for (int i = 0; i < game1.getWidth()*game1.getHeight()/2+1; ++i) { // loop for game cycle numbers iteration
        for (int j = 0; j < game1.getNumberOfPlayers(); ++j) { // loop for players orders

            if(game1.getTsuroPlayers()[j].isOnBoard()) { // checking players is on the board

                if(game1.lastPlayerOnTheBoard() && i > 0 ){ // checking is there last players on the board
                    cout << "Winner player is " <<game1.getWinnerPlayer() << " !"<<endl;
                    return 0;
                }
                // taking selected kard number from the user
                cout << "Player " << game1.getTsuroPlayers()[j].getPlayerName() << "'s turn>" << endl;
                cout << "Player " << game1.getTsuroPlayers()[j].getPlayerName() << "'s cards>" << endl;

                game1.giveCardToPlayer(j); // giving 3 cards to players

                cout << "Select a card>" << endl;
                cin >>  sSelectedCard;
                selectedCard = game1.checkPlayersNumberOfCard(game1.getTsuroPlayers()[j], sSelectedCard);
                while (selectedCard == -1) { // control selecting card number
                    cout << "Invalid card number!" << endl;
                    cout << "Select a card>" << endl;
                    cin >> sSelectedCard;
                    selectedCard = game1.checkPlayersNumberOfCard(game1.getTsuroPlayers()[j], sSelectedCard);

                }
                // taking rotation info from the user
                game1.getTsuroPlayers()[j].getPlayersCard(selectedCard - 1).displayCard();
                cout << "Enter a char for rotate(R,L) or next(N)>" << endl;
                cin >> rotationChar;

                while(rotationChar[0] != 'N' ){ // control rotation char
                    if(rotationChar[0] == 'R'){
                        game1.rotate(j,selectedCard - 1,'R');
                        game1.getTsuroPlayers()[j].getPlayersCard(selectedCard - 1).displayCard();
                    }
                    if(rotationChar[0] == 'L'){
                        game1.rotate(j,selectedCard-1,'L');
                        game1.getTsuroPlayers()[j].getPlayersCard(selectedCard - 1).displayCard();
                    }

                    cout << "Enter a char for rotate(R,L) or next(N)>" << endl;
                    cin >> rotationChar;
                }
                // taking card position info from the user
                cout << "Enter a position>" << endl;

                cin >> selectedPosition;

                y = selectedPosition[0] - 48;
                x = selectedPosition[2] - 48;

                while (!game1.checkCardPosition(y, selectedPosition[1], x, game1.getTsuroPlayers()[j])) { // control

                    cout << "Invalid position!" << endl;
                    cout << "Player " << game1.getTsuroPlayers()[j].getPlayerName() << "'s turn." << endl;
                    cout << "Enter a position>" << endl;

                    cin >> selectedPosition;

                    y = selectedPosition[0] - 48;
                    x = selectedPosition[2] - 48;

                }
                // puts card to board
                game1.putCardtoGridbyCardPosition(game1.getTsuroPlayers()[j].getPlayersCard(selectedCard - 1), y, x);
                // puts card info to 2d card array for checking players position and moving them
                game1.fillBoardCards(y, x, game1.getTsuroPlayers()[j].getPlayersCard(selectedCard - 1));

                for (int n = 0; n < game1.getNumberOfPlayers() ; ++n) { // loop for checking every players position for added card
                    for (int m = 0; m < game1.getHeight()*game1.getWidth() ; ++m) { // max move numbers players on the board
                        for (int l = 0; l < game1.getHeight() ; ++l) { // checking every card for every players
                            for (int k = 0; k < game1.getWidth() ; ++k) {
                                if (game1.getBoardCards(l,k).isOnBoard()) { // if cards on the board
                                    game1.checkCardEnvironment(k + 1, l + 1, (j + n) % numberOfPlayer);
                                    // check card environment according to players position
                                }
                            }
                        }
                    }
                }

                game1.erasePlayerCard(selectedCard-1, j); //erasing played card

                game1.displayCurrentBoard(); // displaying changing board

            }
        }
    }

    if(game1.getWinnerPlayer() == 0){ // if nobody won the game

        cout << "Nobody won the game!" << endl;
    }

    return 0;
}


int checkNumberOfPlayer(string line) {

    int number;

    if(line.size() != 1){
        return -1;
    }

    number = line[0]-48;

    if(number < 2 || number > 8)
        return -1;

    return number;
}