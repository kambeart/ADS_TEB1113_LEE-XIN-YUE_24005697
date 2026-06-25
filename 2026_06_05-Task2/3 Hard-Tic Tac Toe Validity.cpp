#include <iostream>
using namespace std;

// This matrix is used to find indexes to check all
// possible winning triplets in board[0..8]
int win[8][3] = {{0, 1, 2}, // Check first row.
                {3, 4, 5}, // Check 2nd Row
                {6, 7, 8}, // Check 3rd Row
                {0, 3, 6}, // Check first column
                {1, 4, 7}, // Check 2nd Column
                {2, 5, 8}, // Check 3rd Column
                {0, 4, 8}, // Check Diagonal leftright
                {2, 4, 6}}; // Check Diagonal rightleft

// Returns true if character c wins
bool isCWin(char *board, char c)
{
    for (int i=0; i<8; i++)
        if (board[win[i][0]] == c && board[win[i][1]] == c && board[win[i][2]] == c )
            return true;
    return false;
}

// Returns true if given board is valid
bool isValid(char board[9])
{
    // count X and O
    int xcount = 0, ocount = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 'X') xcount++;
        if (board[i] == 'O') ocount++;
    }

    // move counts must be equal or X has one more
    if (!(xcount == ocount || xcount == ocount + 1))
        return false;

    bool xWins = isCWin(board, 'X');
    bool oWins = isCWin(board, 'O');

    // cannot win simultaneously
    if (xWins && oWins) return false;
    
    // If X wins, X must have exactly one more move
    if (xWins && xcount != ocount + 1) return false;
    
    // If O wins, counts must be equal
    if (oWins && xcount != ocount) return false;

    return true;
}

int main()
{
    char board[] = {'X', 'X', 'O',
                    'O', 'O', 'X',
                   'X', 'O', 'X'};
    if (isValid(board)) {
        cout << "Given board is valid";
    } else {
        cout << "Given board is not valid";
    }
    return 0;
}