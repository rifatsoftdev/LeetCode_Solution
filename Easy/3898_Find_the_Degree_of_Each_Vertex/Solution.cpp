#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> result;

        for (int i = 0; i < matrix.size(); i++) {
            int tmp = 0;

            for (int j = 0; j < matrix[i].size(); j++) {
                tmp += matrix[i][j];
            }

            result.push_back(tmp);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<vector<int>> matrix1 = {{0,1,1},{1,0,1},{1,1,0}};
    vector<int> result1 = solution.findDegrees(matrix1);
    printVec(result1);

    // test cases 2
    vector<vector<int>> matrix2 = {{0,1,0},{1,0,0},{0,0,0}};
    vector<int> result2 = solution.findDegrees(matrix2);
    printVec(result2);

    // test cases 2
    vector<vector<int>> matrix3 = {{0}};
    vector<int> result3 = solution.findDegrees(matrix3);
    printVec(result3);

    return 0;
}