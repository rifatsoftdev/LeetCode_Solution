#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

N Queens:
    1. Place queens one by one in different columns, starting from the leftmost column.
    2. When we place a queen in a column, we check for clashes with already placed queens. 
       In the current column, we need to check only upper side for attacking queens
    3. If we find a row for the current column, we mark this row and column as part of solution and recursively check for next column.
    4. If we do not find a row for the current column, we backtrack and return false.

Time complexity: O(N!)
Space complexity: O(N^2) for the board, O(N) for the recursion stack
*/

class Solution {
    bool isValid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(res, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<string>> res1 = solution.solveNQueens(4);
    printVec2D(res1);

    vector<vector<string>> res2 = solution.solveNQueens(1);
    printVec2D(res2);

    return 0;
}