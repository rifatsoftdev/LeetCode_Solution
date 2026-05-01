#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

N Queens II:
    1. Use backtracking to place queens row by row.
    2. For each row, try placing a queen in each column and check if it's a valid position.
    3. If valid, recursively move to the next row.
    4. If all queens are placed successfully, increment the count.
    5. Backtrack and try the next column.

Time Complexity: O(N!), where N is the size of the board. In the worst case, we try to place queens in all columns for each row.
Space Complexity: O(N^2) for the board representation, and O(N) for the recursion stack in the worst case.
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
    
    void backtrack(vector<string>& board, int row, int& count) {
        if (row == board.size()) {
            count++;
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1, count);
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, count);
        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.totalNQueens(4) << endl; // Output: 2
    cout << solution.totalNQueens(1) << endl; // Output: 1

    return 0;
}