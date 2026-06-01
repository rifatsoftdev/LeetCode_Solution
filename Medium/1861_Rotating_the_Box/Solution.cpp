#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        // Step 2: Simulate gravity on the rotated box
        for (int col = 0; col < m; ++col) {
            int emptyRow = n - 1;

            for (int row = n - 1; row >= 0; --row) {
                if (rotatedBox[row][col] == '*') {
                    emptyRow = row - 1;
                } 
                else if (rotatedBox[row][col] == '#') {
                    if (emptyRow > row) {
                        swap(rotatedBox[row][col], rotatedBox[emptyRow][col]);
                    }
                    emptyRow--;
                }
            }
        }

        return rotatedBox;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<vector<char>> boxGrid1 = {{'#','.','#'}};
    vector<vector<char>> result1 = solution.rotateTheBox(boxGrid1);
    printVec2D(result1); // Expected: [['.'], ['#'], ['#']]

    // test cases 2
    vector<vector<char>> boxGrid2 = {{'#','.','#','*','.','#'}};
    vector<vector<char>> result2 = solution.rotateTheBox(boxGrid2);
    printVec2D(result2); // Expected: [['.'], ['#'], ['#'], ['*'], ['.'], ['#']]


    vector<vector<char>> boxGrid3 = {{'#','#','*','.','*','.'},
                                     {'#','#','#','*','.','.'},
                                     {'#','#','#','.','#','.'}};
    vector<vector<char>> result3 = solution.rotateTheBox(boxGrid3);
    printVec2D(result3); // Expected: [['.'], ['#'], ['#'], ['#'], ['#'], ['#']],
             //           [['.'], ['#'], ['#'], ['*'], ['.'], ['.']],
             //           [['.'], ['*'], ['*'], ['.'], ['*'], ['.']]

    return 0;
}