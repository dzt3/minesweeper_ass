#include <iostream>
#include "hint.h"

// Hint constructor
Hint::Hint(const Board &b) : b_(b) {}

// Delegating contructor, makes a 0 by 0 size board by default
Hint::Hint() : Hint(Board(0,0)) {}

//~Hint::Hint() {}

void Hint::displayHint() {
    unsigned int row = b_.getRowSize();
    unsigned int col = b_.getColSize();

    for (auto i = 0U; i < row; ++i) {
        for (auto j = 0U; j < col; ++j) {
            //b_.getTile(i,j);
            unsigned int tileCount{0}; // intialise in loop scope?
            if (b_.getTile(i, j) == '.') {
                if (i == 0 && j == 0) { // on the first row, first column (corner)
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j+1) == '*') ++tileCount;
                } else if (i == 0 && j != col - 1) { // on first row, any column in between
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j+1) == '*') ++tileCount;
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j-1) == '*') ++tileCount;
                } else if (i == 0 && j == col - 1) { // on the first row, last column (corner)
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j-1) == '*') ++tileCount;
                } else if (i == row - 1 && j == 0) { // on last row, first column (corner)
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i-1, j+1) == '*') ++tileCount;
                } else if (i == row - 1 && j != col -1) { // on last row, any column inbetween
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i-1, j+1) == '*') ++tileCount;
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i-1, j-1) == '*') ++tileCount;
                } else if (i == row - 1 && j == col - 1) { // on last row, last col (corner)
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i-1, j-1) == '*') ++tileCount;
                } else if (i != row - 1 && j == 0) { // on any row in between, first col
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i-1, j+1) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j+1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                } else if (i != row - 1 && j == col - 1) { // on any row in between, last col
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i-1, j-1) == '*') ++tileCount;
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j-1) == '*') ++tileCount;
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                } else { // surrounding 8 squares can be viewed
                    if (b_.getTile(i, j-1) == '*') ++tileCount;
                    if (b_.getTile(i, j+1) == '*') ++tileCount;
                    if (b_.getTile(i-1, j) == '*') ++tileCount;
                    if (b_.getTile(i+1, j) == '*') ++tileCount;
                    if (b_.getTile(i-1, j-1) == '*') ++tileCount; // top diagonal left
                    if (b_.getTile(i+1, j+1) == '*') ++tileCount; // bottom diagonal right
                    if (b_.getTile(i+1, j-1) == '*') ++tileCount; // bottom diaognal left
                    if (b_.getTile(i-1, j+1) == '*') ++tileCount; // top diagonal right
                }
                std::cout << tileCount;
            } else {
                std::cout << b_.getTile(i,j);
            } 
        }
        std::cout << std::endl;
    }
}



