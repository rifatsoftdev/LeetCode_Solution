#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Operations to Equalize Binary String (Greedy / Mathematical):
    1. The goal is to make all characters in a binary string equal to '1' using operations of length `k`.
    2. We count the number of zeros in the string. If there are no zeros, 0 operations are needed.
    3. We consider the constraints imposed by the operation length `k` and the remaining length `base = len - k`.
    4. We calculate the minimum number of operations required for both odd and even scenarios based on the parity of the zeros and the operation length.
    5. The result is the minimum valid number of operations, or -1 if it's impossible to equalize the string.

Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1).
*/

class Solution {
public:
    int minOperations(string s, int k) {
        int zero = 0;
        int len = s.length();

        for (int i = 0; i < len; i++)
            zero += ~s[i] & 1;

        if (!zero)
            return 0;

        if (len == k)
            return ((zero == len) << 1) - 1;

        int base = len - k;

        int odd = max(
            (zero + k - 1) / k,
            (len - zero + base - 1) / base
        );

        odd += ~odd & 1;

        int even = max(
            (zero + k - 1) / k,
            (zero + base - 1) / base
        );

        even += even & 1;

        int res = INT_MAX;

        if ((k & 1) == (zero & 1))
            res = min(res, odd);

        if (~zero & 1)
            res = min(res, even);

        return res == INT_MAX ? -1 : res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.minOperations("110", 1) << endl; // 1
    cout << solution.minOperations("0101", 3) << endl; // 2
    cout << solution.minOperations("101", 2) << endl; // -1

    return 0;
}