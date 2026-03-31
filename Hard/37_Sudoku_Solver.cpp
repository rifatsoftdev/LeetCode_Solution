#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Sudoku Solver (Backtracking):
    1. Iterate through every cell in the 9x9 board.
    2. When an empty cell ('.') is found, try placing digits from '1' to '9'.
    3. For each digit, check if it is valid according to Sudoku rules:
        - The digit must not appear in the same row.
        - The digit must not appear in the same column.
        - The digit must not appear in the 3x3 sub-grid.
    4. If placing the digit is valid, recursively attempt to solve the rest of the board.
    5. If the board is solved successfully, return true.
    6. If no digit works, backtrack by resetting the cell to '.' and return false.
    7. The process continues until the entire board is filled.

Time Complexity: O(9^(n*n)) where n=9, though significantly reduced by pruning.
Space Complexity: O(n*n) for the recursion stack.
*/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;

                            if (solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solution.solveSudoku(board);
    printVec2D(board);
    
    return 0;
}