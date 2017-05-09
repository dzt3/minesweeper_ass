#ifndef BOARD_H
#define BOARD_H
/*
 * Definition for the Board class
 */
class Board {
    public:
        Board(unsigned int row, unsigned int col);
        ~Board();

        void addTile(int row, int col, char c);
        char getTile(unsigned int x, unsigned int y) const;
        unsigned int getRowSize() const;
        unsigned int getColSize() const;
        void displayBoard() const;
    private:
        char **table;
        unsigned int row;
        unsigned int col;

};

#endif
