#ifndef HINT_H
#define HINT_H

#include "board.h"

class Hint {
    public:
        Hint(const Board &b);
        Hint();
        //~Hint();
        void displayHint();
    private:
        const Board &b_;
};

#endif
