#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;

        while (n != 0) {
            int d = n % 10;
            ans += d;
            n /= 10;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.digitFrequencyScore(122) << endl;

    // test cases 2
    cout << solution.digitFrequencyScore(101) << endl;

    return 0;
}