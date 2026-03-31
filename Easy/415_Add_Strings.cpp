#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Add Strings:
    1. Initialize an empty string `result` to store the sum and a `carry` variable set to 0.
    2. Use two pointers starting from the end of `num1` and `num2`.
    3. In each step, add the digits pointed to by the pointers (if available) and the current `carry`.
    4. Update the `carry` for the next position and append the last digit of the sum to the `result`.
    5. After the loop, reverse the `result` string to get the correct order and return it.

Time Complexity: O(max(n, m)), where n and m are the lengths of the input strings.
Space Complexity: O(max(n, m)) to store the resulting string.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.addStrings("11", "123") << endl;
    cout << solution.addStrings("456", "77") << endl;
    cout << solution.addStrings("0", "0") << endl;

    return 0;
}