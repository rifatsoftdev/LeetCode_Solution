#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse Bits:
    1. Convert the 32-bit unsigned integer to its binary string representation using `bitset<32>`.
    2. Reverse the binary string to flip the order of bits.
    3. Convert the reversed binary string back into an unsigned long integer.

Time Complexity: O(1), as the number of bits is fixed at 32.
Space Complexity: O(1), as the string and bitset use a constant amount of space.
*/

class Solution {
public:
    int reverseBits(int n) {
        string s = bitset<32>(n).to_string();
        reverse(s.begin(), s.end());
        return bitset<32>(s).to_ulong();
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout <<solution.reverseBits(43261596) << endl;
    cout <<solution.reverseBits(2147483644) << endl;

    return 0;
}