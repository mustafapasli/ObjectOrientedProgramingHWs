#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

using namespace std;

class Grid{

public:

    Grid();

    int getGridWidth() const;
    int getGridHeight() const;

    void drawGridFrame();
    void calculateGridSize();
    void drawGridCardsPosition();
    void setWidth(int width){ boardWidth = width; }
    void setHeight(int height){ boardHeight = height; }
    void setGridInCell(int yIndex,int xIndex,char inCell);

    char getGridInCell(int yIndex,int xIndex) const ;
    char toChar(int number) const { return static_cast<char>(number + 48); }

private:

    int boardWidth;
    int boardHeight;
    int gridWidth;
    int gridHeight;
    static const int cardWidth = 12;
    static  const int cardHeight = 6;

    vector<vector<char> > gridCells;

} ;

#endif //GRID_H
