#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        int cnt = 0;
        vector<int> digits;

        while (n != 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        for (int i : digits) {
            if (cnt % 2 == 0) {
                ans += i;
            } else {
                ans -= i;
            }
            cnt++;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.alternateDigitSum(521) << endl;

    // test cases 2
    cout << solution.alternateDigitSum(111) << endl;

    // test cases 3
    cout << solution.alternateDigitSum(886996) << endl;
    
    return 0;
}