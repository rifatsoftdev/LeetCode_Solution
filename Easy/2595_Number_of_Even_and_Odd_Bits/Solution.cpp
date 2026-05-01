#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Number of Even and Odd Bits:
    1. Convert the given number n to a 32-bit binary string.
    2. Initialize two counters, even and odd, to zero.
    3. Iterate through the binary string:
        a. If the current bit is '1':
            i. If the index of the bit is even, increment the even counter.
            ii. If the index of the bit is odd, increment the odd counter.
    4. Return a vector containing the odd and even counters in the format [odd, even].

Time Complexity: O(1) - The operations are constant time since we are dealing with a fixed 32-bit integer.
Space Complexity: O(1) - We are using a fixed amount of space for the binary string and counters.
*/

class Solution {
public:
    vector<int> evenOddBit(int n) {
        string s = bitset<32>(n).to_string();
        int even = 0, odd = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (i % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }

        return {odd, even};
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> result1 = solution.evenOddBit(50);
    printVec(result1);

    vector<int> result2 = solution.evenOddBit(2);
    printVec(result2);
    

    return 0;
}