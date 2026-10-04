#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long i = 1000; i <= n; i *= 1000) {
            ans += (n - i + 1);
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    long long n1 = 1002;
    long long result1 = solution.countCommas(n1);
    cout << result1 << endl;

    // test cases 2
    long long n2 = 998;
    long long result2 = solution.countCommas(n2);
    cout << result2 << endl;

    return 0;
}