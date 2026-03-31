#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Complement of Base 10 Integer:
    1. The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
    2. To find the complement, first calculate the number of bits required to represent the number `n`.
    3. Create a bitmask of the same length consisting only of 1's.
    4. The result is the XOR of the original number `n` and the mask.

Time Complexity: O(log n) (where n is the input integer, as we iterate through its bits)
Space Complexity: O(1)
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int bits = 0;
        int temp = n;

        while (temp) {
            bits++;
            temp >>= 1;
        }

        int mask = (1 << bits) - 1;

        int result = n ^ mask;

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.bitwiseComplement(5) << endl; // Output: 2
    cout << solution.bitwiseComplement(7) << endl; // Output: 0

    return 0;
}