#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Valid Sudoku:
    1. Each row must contain the digits 1-9 without repetition.
    2. Each column must contain the digits 1-9 without repetition.
    3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Time Complexity: O(1) - The board size is fixed (9x9).
Space Complexity: O(1) - No additional space is used that scales with input size.
*/

class Solution {
    bool validSudoku(vector<vector<char>>& board, int i, int j) {
        char ch = board[i][j];
        
        for (int k = 0; k < 9; k++) {
            if (k != j && board[i][k] == ch) return false;
            if (k != i && board[k][j] == ch) return false;
        }
        
        int rowStart = 3 * (i / 3);
        int colStart = 3 * (j / 3);
        
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (rowStart + r == i && colStart + c == j) continue;
                if (board[rowStart + r][colStart + c] == ch) return false;
            }
        }
        
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!validSudoku(board, i, j)) return false;
                }
            }
        }

        return true;
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
    cout << solution.isValidSudoku(board) << endl;

    vector<vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << solution.isValidSudoku(board2) << endl;
    

    return 0;
}