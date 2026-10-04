#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countCommas(int n) {
        int ans = n - 999;

        if (ans < 0) {
            return 0;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    int n1 = 1002;
    int result1 = solution.countCommas(n1);
    cout << result1 << endl;

    // test cases 2
    int n2 = 999;
    int result2 = solution.countCommas(n2);
    cout << result2 << endl;

    return 0;
}