#include <iostream>
#include "board.h"

//Board constructors here
Board::Board(unsigned int row, unsigned int col) {
    this->row = row;
    this->col = col;
    table = new char*[row];

    for (auto i = 0U; i < row; ++i) {
        table[i] = new char[col];
    }
}

// got to write a destructor since I used pointers.
Board::~Board() {
    for (auto i = 0U; i < this->row; ++i) {
        delete[] table[i];
    } 
    delete[] table;
}

/*
 * Member functions of Board class
 */

void Board::addTile(int row, int col, char c) {
    table[row][col] = c;
}

char Board::getTile(unsigned int x, unsigned int y) const {
    return table[x][y];
}

unsigned int Board::getRowSize() const {
    return row;    
}

unsigned int Board::getColSize() const {
    return col;
}

void Board::displayBoard() const {
    for (auto i = 0U; i < row; ++i) {
        for (auto j = 0U; j < col ; ++j) {
            std::cout << table[i][j];
        }
        std::cout << std::endl;
    }
}
