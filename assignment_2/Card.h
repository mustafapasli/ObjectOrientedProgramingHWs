#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>

using namespace std;

class Card{

public:

    Card();

    bool isOnBoard() const;

    void rotateLeft();
    void rotateRight();
    void displayCard() const;
    void convertCardtoArray(); // convert card to 6x12 arrays
    void setOnBoard(bool onBoard);
    void setArrayCard(const vector <vector <char> > &arrayCard);

    const vector< vector< char> > & getArrayCard() const;

private:

    int cardWidth;
    int cardHeight;
    int random(int port) const; // returns random number for port number

    bool onBoard;

    void generateRandomCard(); // generate random port and path number

    char toChar(int number) const { return static_cast<char>(number + 48); }

    vector <int> cardPort;
    vector <int> cardPath;
    vector <vector <char> > arrayCard;

};


#endif //CARD_H
