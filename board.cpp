#include "board.h"

Board::Board() {

    // 0 = vide
    // 1 = mur
    // 2 = gum
    // 3 = super gum
    // 4 = mur du spawn fantome (agit soit comme vide soit comme mur)
    // 5 = Pac
    // 6 = Blinky le fantome rouge
    // 7 = Pinky  le fantome rose
    // 8 = Inky   le fantome bleu
    // 9 = Clyde  le fantome orange
}

int Board::getCell(int x, int y) {
    return board[y][x];
}

int Board::getGumsNumber() {
    if (this->nbGums <0) {
        countGums();
    }
    return this->nbGums;
}

int Board::getNbLines() {
    return this->nbLines;
}

int Board::getNbColumns() {
    return this->nbColumns;
}

bool Board::isWall(int x, int y) {
    return (board[x][y] == 1);
}

bool Board::isGhost(int x, int y) {
    return (board[x][y] > 5);
}

void Board::countGums() {
    this->nbGums =0;
    for (int i=0; i< nbLines; i++) {
        for (int j=0; i< nbColumns; j++) {
            if (board[i][j] == 3 || board[i][j] == 4) {
                this->nbGums++;
            }
        }
    }
}

void Board::newFruit() {
	// TODO - implement Board::newFruit
	throw "Not yet implemented";
}
