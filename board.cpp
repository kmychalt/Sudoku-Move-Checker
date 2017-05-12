using namespace std;

#include "board.h"
#include <iostream>
#include <list>

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i == 0)
            cout << "  0  1  2  3  4  5  6  7  8" << endl;
        if (i % 3 == 0)
            cout << "  ------------------------- " << endl;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 0)
                cout << i << " ";
            if (j % 3 == 0)
                cout << "| ";
            if (board[i][j] == 0)
                cout << "  ";
            else 
                cout << board[i][j] << " ";
            if (j == BOARD_SIZE - 1)
                cout << "| ";
        }
        cout << endl;
    }
    cout << "  ------------------------- " << endl;
    cout << endl;
}

void Board::setBoard(int num) {
    int i = 0;
    int newBoard0[BOARD_SIZE * BOARD_SIZE] = {0, 0, 0, 0, 0, 0, 9, 4, 0,
                0, 1, 9, 4, 7, 2, 8, 0, 0,
                2, 0, 4, 0, 0, 0, 0, 7, 5,
                0, 0, 2, 0, 4, 0, 0, 8, 0,
                7, 5, 3, 0, 0, 0, 6, 9, 4,
                0, 8, 0, 0, 9, 0, 5, 0, 0,
                8, 2, 0, 0, 0, 0, 3, 0, 7,
                0, 0, 7, 6, 3, 8, 2, 5, 0,
                0, 3, 5, 0, 0, 0, 0, 0, 0};
    int newBoard1[BOARD_SIZE * BOARD_SIZE] = {6, 0, 8, 4, 0, 0, 3, 0, 7,
                7, 0, 0, 9, 0, 1, 0, 8, 6,
                0, 3, 0, 0, 7, 6, 0, 2, 0,
                0, 0, 0, 0, 0, 0, 8, 5, 1,
                0, 0, 6, 0, 0, 0, 7, 0, 0,
                4, 8, 3, 0, 0, 0, 0, 0, 0,
                0, 1, 0, 7, 4, 0, 0, 9, 0,
                9, 4, 0, 6, 0, 5, 0, 0, 8,
                3, 0, 5, 0, 0, 9, 2, 0, 4};
    int newBoard2[BOARD_SIZE * BOARD_SIZE] = {0, 2, 0, 0, 0, 0, 0, 0, 4,
                0, 0, 8, 0, 2, 4, 6, 0, 0,
                0, 7, 3, 0, 6, 1, 8, 0, 5,
                0, 0, 6, 0, 4, 0, 0, 0, 0,
                0, 1, 4, 0, 7, 0, 9, 3, 0,
                0, 0, 0, 0, 5, 0, 4, 0, 0,
                8, 0, 1, 5, 9, 0, 2, 6, 0,
                0, 0, 5, 2, 3, 0, 1, 0, 0,
                3, 0, 0, 0, 0, 0, 0, 9, 0};
    switch (num) {
        case 0:
            i = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    board[j][k] = newBoard0[i];
                    i++;
                }
            }
            break;
        case 1:
            i = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    board[j][k] = newBoard1[i];
                    i++;
                }
            }
            break;
        case 2:
            i = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    board[j][k] = newBoard2[i];
                    i++;
                }
            }
            break;
    }

}

bool Board::checkMove(int num, int x, int y) {
    //check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][y] == num)
            return false;
    }
    
    //check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[x][i] == num)
            return false;
    }
 
    //check box
    //find x parameters
    int xmin, xmax, ymin, ymax = 0;
    if (x >= 0 && x <= 2) {
        xmin = 0;
        xmax = 2;
    }
    else if (x >= 3 && x <= 5) {
        xmin = 3;
        xmax = 5;
    }
    else {
        xmin = 6;
        xmax = 8;
    }
    //find y parameters
    if (y >= 0 && y <= 2) {
        ymin = 0;
        ymax = 2;
    }
    else if (y >= 3 && y <= 5) {
        ymin = 3;
        ymax = 5;
    }
    else {
        ymin = 6;
        ymax = 8;
    }
    //check box with parameters for number match
    for (int i = xmin; i <= xmax; i++) {
        for (int j = ymin; j <= ymax; j++) {
            if (board[i][j] == num)
                return false;
        }
    }
    
    return true;
}

void Board::setMove(int num, int x, int y) {
    board[x][y] = num;
}

bool Board::checkWin() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;   
}