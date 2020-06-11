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

bool Board::isWall(int x, int y) {
    return (board[y][x] == 1);
}

bool Board::isGum(int x, int y) {
    return (board[y][x] == 2);
}

bool Board::isSuperGum(int x, int y) {
    return (board[y][x] == 3);
}

bool Board::isPlayer(int x, int y) {
    return (board[y][x] == 5);
}

bool Board::isGhost(int x, int y) {
    return (board[y][x] > 5);
}

bool Board::isBlinky(int x, int y) {
    return (board[y][x] == 6);
}

bool Board::isPinky(int x, int y) {
    return (board[y][x] == 7);
}

bool Board::isInky(int x, int y) {
    return (board[y][x] == 8);
}

bool Board::isClyde(int x, int y) {
    return (board[y][x] == 9);
}

bool Board::isIntersection(int x, int y) {
    for (int i=0; i<34; i++) {
        if (intersections[i][0] == x && intersections[i][1] == y)
            return true;
    }
    return false;
}
