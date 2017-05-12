#define BOARD_SIZE 9
#define NUM_OF_PUZZLES 3
class Board {
public:
    Board();
    void printBoard();
    void setBoard(int num);
    bool checkMove(int num, int x, int y);
    void setMove(int num, int x, int y);
    bool checkWin();
private:
    int board[BOARD_SIZE][BOARD_SIZE];

    

};

