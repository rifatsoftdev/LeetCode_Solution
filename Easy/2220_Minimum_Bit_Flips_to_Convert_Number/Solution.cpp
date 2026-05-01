#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Bit Flips to Convert Number:
    1. A bit flip is changing a 0 to a 1 or a 1 to a 0 in the binary representation of a number.
    2. To find the minimum number of bit flips to convert `start` to `goal`, we need to count the number of positions where their binary representations differ.
    3. Convert both numbers into 32-bit binary strings using `bitset<32>`.
    4. Iterate through the strings and increment a counter whenever the characters at the same index are different (Hamming distance).
    5. Return the final count.

Time Complexity: O(1) because the number of bits is fixed at 32.
Space Complexity: O(1) as the space used for strings is constant.
*/

class Solution {
public:
    int minBitFlips(int x, int y) {
        string x_bin = bitset<32>(x).to_string();
        string y_bin = bitset<32>(y).to_string();
        int distance = 0;

        for (int i = 0; i < 32; i++) {
            if (x_bin[i] != y_bin[i]) {
                distance++;
            }
        }

        return distance;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    cout << solution.minBitFlips(10, 7) << endl; // Output: 3
    cout << solution.minBitFlips(3, 4) << endl;  // Output: 3

    return 0;
}