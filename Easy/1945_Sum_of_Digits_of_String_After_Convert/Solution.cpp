#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int getLucky(string s, int k) {
        string numStr;

        for (char c : s) {
            numStr += to_string(c - 'a' + 1);
        }

        for (int i = 0; i < k; i++) {
            int total = 0;

            for (char ch : numStr) {
                total += (ch - '0');
            }

            numStr = to_string(total);
        }
        
        return stoi(numStr);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.getLucky("iiii", 1) << endl;

    // test cases 2
    cout << solution.getLucky("leetcode", 2) << endl;

    // test cases 3
    cout << solution.getLucky("zbax", 2) << endl;

    return 0;
}