#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool judgeSquareSum(long long c) {
        long long left = 0, right = static_cast<int>(sqrt(c));

        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) return true;
            if (sum < c) left++;
            else right--;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.judgeSquareSum(5) << endl;   // Output: True
    
    // test cases 2
    cout << solution.judgeSquareSum(3) << endl;   // Output: False

    return 0;
}