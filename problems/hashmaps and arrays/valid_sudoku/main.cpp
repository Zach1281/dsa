#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

/*
    -- VALID SUDOKU --
        determine if a 9x9 sudoku board is valid
        only the filled cells need to be validated according to the following rules:
            1. each row must contain the digits 1-9 without repetition
            2. each column must contain the digits 1-9 without repetition
            3. each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition
*/

bool isValidSudoku(vector<vector<char>> &);

int main()
{
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << "Is the board valid?" << endl;
    if (!isValidSudoku(board))
    {
        cout << "No it is not!" << endl;
        return 0;
    }
    cout << "Yes it is!" << endl;
    return 0;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    const int SIZE = board.size();
    unordered_map<char, int> rows;
    unordered_map<char, int> cols;
    map<pair<char, char>, int> squares;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            if (board[i][j])
        }
    }
}