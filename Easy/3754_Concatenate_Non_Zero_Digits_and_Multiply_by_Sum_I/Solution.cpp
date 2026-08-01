#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        vector<int> digits;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                sum += digit;
                digits.push_back(digit);
            }

            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        long long product = 0;

        for (int digit : digits) {
            product = product * 10 + digit;
        }

        return sum * product;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    int n1 = 10203004;
    cout << solution.sumAndMultiply(n1) << endl; // Output: 12340

    // test cases 2
    int n2 = 1000;
    cout << solution.sumAndMultiply(n2) << endl; // Output: 1

    return 0;
}