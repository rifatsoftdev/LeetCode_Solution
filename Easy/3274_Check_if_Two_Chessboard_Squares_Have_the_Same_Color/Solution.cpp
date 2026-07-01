#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = coordinates[0] - '0';
        int col = coordinates[1] - 'a';

        return (row + col) % 2 == 0;
    }

    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return squareIsWhite(coordinate1) == squareIsWhite(coordinate2);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string coordinate1_1 = "a1", coordinate1_2 = "c3";
    bool result1 = solution.checkTwoChessboards(coordinate1_1, coordinate1_2);
    cout << (result1 ? "true" : "false") << endl;
    
    // test cases 2
    string coordinate2_1 = "a1", coordinate2_2 = "h3";
    bool result2 = solution.checkTwoChessboards(coordinate2_1, coordinate2_2);
    cout << (result2 ? "true" : "false") << endl;

    return 0;
}