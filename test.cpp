#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "board.h"
#include "hint.h"


int main (int argc, char* argv[]) {

    try {
        unsigned int row, col;
        std::string line;
        std::cin >> row >> col;
    
        if (row > 10000 || row < 0 || col > 10000 || col < 0) {
            throw std::invalid_argument("Arguments negative or above 10000");
        }

        Board b(row, col);
        std::cin.ignore(); // flushes out cin of the '\n' character       
        for (auto i = 0U; i < row; ++i) {
            std::getline(std::cin, line);
            if (line.size() != col) {
                throw std::invalid_argument("size of column ain't right");// use better exception
            }
            for (auto j = 0U; j < col; ++j) {
                b.addTile(i, j, line[j]);
            }
        }
       
        Hint h(b); // construct a new hint with a board
        h.displayHint();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}
