#include "Player.h"

Player::Player() {

    playersCard.resize(3);
    playerName = ' ';
    playerPositionX = playerPositionY = numberOfCards = playerBackPort = 0;
    onBoard = true;

}

void Player::setNumberOfCards(int cardNumber) {
    numberOfCards = cardNumber;

}

bool Player::isOnBoard() const {
    return onBoard;
}

void Player::setOnBoard(bool onBoard) {
    Player::onBoard = onBoard;
}

char Player::getPlayerName() const {
    return playerName;
}

void Player::setPlayerName(char playerName) {
    Player::playerName = playerName;
}

Card& Player::getPlayersCard(int index) {
    return playersCard[index];
}

vector<Card> &Player::getPlayersCard() {
    return playersCard;
}

void Player::setPlayerPositionX(int playerPositionX) {
    Player::playerPositionX = playerPositionX;
}

void Player::setPlayerPositionY(int playerPositionY) {
    Player::playerPositionY = playerPositionY;
}

int Player::getPlayerPositionX() const {
    return playerPositionX;
}

int Player::getPlayerPositionY() const {
    return playerPositionY;
}

void Player::setPlayerBackPort(int playerBackPort) {
    Player::playerBackPort = playerBackPort;
}

int Player::getNumberOfCards() const {
    return numberOfCards;
}

int Player::getPlayerBackPort() const {
    return playerBackPort;
}


