#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Add Binary:
    1. Initialize an empty string `result` and a `carry` variable set to 0.
    2. Use two pointers starting from the end of strings `a` and `b`.
    3. In each iteration, calculate the sum of the bits at the current positions and the `carry`.
    4. Append the result of `sum % 2` to the `result` string and update the `carry` to `sum / 2`.
    5. After the loop, reverse the `result` string and return it.

Time Complexity: O(max(N, M)), where N and M are the lengths of strings a and b.
Space Complexity: O(max(N, M)) to store the resulting binary string.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int n = a.size()-1;
        int m = b.size()-1;


        while (n >= 0 || m >= 0 || carry > 0) {
            int sum = carry;

            if (n >= 0) {
                sum += a[n] - '0';
                n--;
            }
            if (m >= 0) {
                sum += b[m] - '0';
                m--;
            }

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.addBinary("11", "1") << endl;
    cout << solution.addBinary("1010", "1011") << endl;

    return 0;
}