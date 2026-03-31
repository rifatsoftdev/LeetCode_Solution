#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Number Complement:
    1. Find the number of bits in the binary representation of the given integer `n`.
    2. Create a bitmask of the same length consisting only of '1's. This can be done by shifting 1 left by the number of bits and subtracting 1.
    3. Perform an XOR operation between the original number `n` and the mask. This flips all the bits of `n`, effectively producing its complement.
    4. Return the resulting integer.

Time Complexity: O(log n), where n is the input integer (proportional to the number of bits).
Space Complexity: O(1), as we only use a few variables for the calculation.
*/

class Solution {
public:
    int findComplement(int n) {
        if (n == 0) return 1;

        int bits = 0;
        int temp = n;

        while (temp) {
            bits++;
            temp >>= 1;
        }

        long long mask = (1LL << bits) - 1;

        int result = n ^ mask;

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.findComplement(5) << endl;
    cout << solution.findComplement(1) << endl;
    cout << solution.findComplement(2147483647) << endl;

    return 0;
}