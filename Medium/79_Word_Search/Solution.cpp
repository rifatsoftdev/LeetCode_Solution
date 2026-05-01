#include <iostream>
#include <vector>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:


*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int col = board.size();
        int row = board[0].size();
        int wsize = word.size();

        for (int i = 0; i < wsize; i++) {
            
        }

    }
};


int main() {
    Solution solution;
    
    vector<vector<char>> board= {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";

    cout << solution.exist(board, word) << endl;

    return 0;
}
