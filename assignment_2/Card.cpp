#include "Card.h"

Card::Card() {

    onBoard = false;
    cardWidth = 12;
    cardHeight = 6;
    cardPort = {1,2,3,4,5,6,7,8};
    cardPath = {0,0,0,0,0,0,0,0};

    arrayCard.resize(cardHeight);
    for (int i = 0; i < cardHeight; ++i) {
        arrayCard[i].resize(cardWidth);
    }

    generateRandomCard();

    convertCardtoArray();

}

int Card::random(int port) const {

    int randomNumber = (rand() % 8 )+ 1;

    while(port == randomNumber){
        randomNumber = (rand() % 8 )+ 1;
    }

    return randomNumber;
}

void Card::generateRandomCard() {

    int randomNumber;
    int flag = 0;

    for (int j = 0; j < 8; ++j) {

        flag = 0;

        if(cardPath[j] == 0) {
            randomNumber = random(j + 1);


            for (int i = 1; i < 8; ++i) {
                if (cardPath[i] == randomNumber) {
                    flag = -1;
                    break;
                }

            }
            if (flag == 0) {
                cardPath[j] = randomNumber;
                cardPath[randomNumber - 1] = j+1;
            } else
                j--;
        }

    }

    convertCardtoArray();

}

void Card::displayCard() const{

    for (int i = 0; i < cardHeight; ++i) {
        for (int j = 0; j < cardWidth; ++j) {
            cout << arrayCard[i][j] ;
        }
        cout << endl;
    }

}

void Card::rotateRight() {

    int temp1 = 0,temp2 = 0;

    temp1 = cardPort[6];
    temp2 = cardPort[7];

    for (int k = 5; k > -1; --k) {
        cardPort[k+2] = cardPort[k];
    }

    cardPort[0] = temp1;
    cardPort[1] = temp2;

    temp1 = cardPath[6];
    temp2 = cardPath[7];

    for (int k = 5; k > -1; --k) {
        cardPath[k+2] = cardPath[k];
    }

    cardPath[0] = temp1;
    cardPath[1] = temp2;


    convertCardtoArray();

}

void Card::rotateLeft() {

    int temp1 = 0,temp2 = 0;

    temp1 = cardPort[0];
    temp2 = cardPort[1];

    for (int k = 0; k < 6; ++k) {
        cardPort[k] = cardPort[k+2];
    }

    cardPort[6] = temp1;
    cardPort[7] = temp2;

    temp1 = cardPath[0];
    temp2 = cardPath[1];

    for (int k = 0; k < 6; ++k) {
        cardPath[k] = cardPath[k+2];
    }

    cardPath[6] = temp1;
    cardPath[7] = temp2;

    convertCardtoArray();

}

void Card::convertCardtoArray() {

    arrayCard[0] = {'.','.','.','.',toChar(cardPort[0]),'.','.',toChar(cardPort[1]),'.','.','.','.'};
    arrayCard[1] = {':',' ',' ',' ',toChar(cardPath[0]),' ',' ',toChar(cardPath[1]),' ',' ',' ',':'};
    arrayCard[2] = {toChar(cardPort[7]),' ',' ',' ',toChar(cardPath[7]),' ',' ',toChar(cardPath[2]),' ',' ',' ',toChar(cardPort[2])};
    arrayCard[3] = {toChar(cardPort[6]),' ',' ',' ',toChar(cardPath[6]),' ',' ',toChar(cardPath[3]),' ',' ',' ',toChar(cardPort[3])};
    arrayCard[4] = {':',' ',' ',' ',toChar(cardPath[5]),' ',' ',toChar(cardPath[4]),' ',' ',' ',':'};
    arrayCard[5] = {'.','.','.','.',toChar(cardPort[5]),'.','.',toChar(cardPort[4]),'.','.','.','.'};

}

const vector<vector<char>> &Card::getArrayCard() const {
    return arrayCard;
}

bool Card::isOnBoard() const {
    return onBoard;
}

void Card::setOnBoard(bool onBoard) {
    Card::onBoard = onBoard;
}

void Card::setArrayCard(const vector<vector<char>> &arrayCard) {
    Card::arrayCard = arrayCard;
}

