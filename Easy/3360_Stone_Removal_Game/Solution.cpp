#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool canAliceWin(int n) {
        bool Alice = true;
        int turn = 10;

        while (n >= turn) {
            n -= turn;
            turn--;
            Alice = !Alice;
        }

        return !Alice;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.canAliceWin(12) << endl;

    // test cases 2
    cout << solution.canAliceWin(1) << endl;

    return 0;
}