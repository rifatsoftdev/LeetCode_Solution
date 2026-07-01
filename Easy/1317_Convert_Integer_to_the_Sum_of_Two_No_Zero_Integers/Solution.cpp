#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool noZero(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;

            if (noZero(a) && noZero(b))
                return {a, b};
        }

        return {};
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> result1 = solution.getNoZeroIntegers(2);
    printVec(result1);

    // test cases 2
    vector<int> result2 = solution.getNoZeroIntegers(11);
    printVec(result2);

    return 0;
}