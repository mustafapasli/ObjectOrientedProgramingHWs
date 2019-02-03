#include "Grid.h"

Grid::Grid() {

    boardWidth = boardHeight = gridWidth = gridHeight = 0;

}

void Grid::calculateGridSize() {

    gridWidth = boardWidth * cardWidth + 4;
    gridHeight = boardHeight * cardHeight + 2;

    gridCells.resize(gridHeight);
    for (int i = 0; i < gridHeight; ++i) {
        gridCells[i].resize(gridWidth);
    }

}

void Grid::drawGridFrame() {

    vector<char> x = {'-','-','-','-','o','-','-','o','-','-','-','-',};
    vector<char> y = {'|','|','o','o','|','|'};

    for (int i = 0; i < gridCells.size(); ++i) {
        for (int j = 0; j < gridCells[i].size(); ++j) {
            gridCells[i][j] = ' ';
        }
    }

    int a = 2;

    for (int j = 0; j < boardWidth; ++j) {
        if(j==0){
            gridCells[0][0]= '-';
            gridCells[0][1]= '-';
        }
        for (int k = 0; k < cardWidth; ++k) {
            gridCells[0][a++] = x[k];
        }
        if(j==0){
            gridCells[0][gridWidth-2]= '-';
            gridCells[0][gridWidth-1]= '-';
        }
    }

    a = 2;

    for (int j = 0; j < boardWidth; ++j) {
        if(j==0){
            gridCells[gridHeight-1][0]= '-';
            gridCells[gridHeight-1][1]= '-';
        }
        for (int k = 0; k < cardWidth; ++k) {
            gridCells[gridHeight-1][a++] = x[k];
        }
        if(j==0){
            gridCells[gridHeight-1][gridWidth-2]= '-';
            gridCells[gridHeight-1][gridWidth-1]= '-';
        }
    }

    a = 1;

    for (int j = 0; j < boardHeight; ++j) {

        for (int k = 0; k < cardHeight; ++k) {
            gridCells[a++][0] = y[k];
        }
    }

    a = 1;

    for (int j = 0; j < boardHeight; ++j) {

        for (int k = 0; k < cardHeight; ++k) {
            gridCells[a++][gridWidth-1] = y[k];
        }
    }

    drawGridCardsPosition();

}

void Grid::drawGridCardsPosition() {

    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            gridCells[3+(i*cardHeight)][6+(j*cardWidth)] = toChar(i+1);
            gridCells[3+(i*cardHeight)][7+(j*cardWidth)] = 'x';
            gridCells[3+(i*cardHeight)][8+(j*cardWidth)] = toChar(j+1);
        }
    }
}

int Grid::getGridWidth() const {
    return gridWidth;
}

int Grid::getGridHeight() const {
    return gridHeight;
}

char Grid::getGridInCell(int yIndex, int xIndex) const {

    return gridCells[yIndex][xIndex];
}

void Grid::setGridInCell(int yIndex, int xIndex, char inCell) {
    gridCells[yIndex][xIndex] = inCell;
}
