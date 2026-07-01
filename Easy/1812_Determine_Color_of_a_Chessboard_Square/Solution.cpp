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
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string coordinates1 = "a1";
    bool result1 = solution.squareIsWhite(coordinates1);
    cout << (result1 ? "true" : "false") << endl;
    
    // test cases 2
    string coordinates2 = "h3";
    bool result2 = solution.squareIsWhite(coordinates2);
    cout << (result2 ? "true" : "false") << endl;

    // test cases 3
    string coordinates3 = "c7";
    bool result3 = solution.squareIsWhite(coordinates3);
    cout << (result3 ? "true" : "false") << endl;

    return 0;
}