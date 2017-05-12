#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

bool validBoard(int boardNum) {
    if (boardNum > 0 || boardNum < NUM_OF_PUZZLES)
        return true;
    else return false;
}

int main(int argc, char** argv) {
    bool checkMove = false;
    bool chooseBoard = false;
    bool solved = false;
    int boardNum = 0;
    int x = 0;
    int y = 0;
    int num = 0;
    Board b;
    
    cout << "Welcome to Sudoku!" << endl;
    cout << "We have this many puzzles to choose from: " << NUM_OF_PUZZLES << endl;
    cout << "Please pick which board you would like to play today:" << endl;
    cin >> boardNum;
    
    chooseBoard = validBoard(boardNum);
    while (!chooseBoard) {
        cout << "That is not a valid board. Please choose a valid board. " << endl;
        cin >> boardNum;
        chooseBoard = validBoard(boardNum);
    }
    
    b.setBoard(boardNum);
    b.printBoard();
    
    while (!solved) {
        cout << "Please choose the row and the column that you would like to enter: " << endl;
        cin >> x;
        cin >> y;
        
        cout << "And what number :" << endl;
        cin >> num;
        
        checkMove = b.checkMove(num, x, y);
        if (checkMove) {
            b.setMove(num, x, y);
            b.printBoard();
        }
        else 
            cout << "That was not a valid move. " << endl;
        
        if (b.checkWin())
            solved = true;
    }
    
    cout << "Congrats! You solved the puzzle. " << endl;
    
    return 0;
}

