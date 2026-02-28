#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimized approach:
1. Start from the least significant bit (LSB) of the binary string.
2. If the current bit is '0', it means we can simply divide by 2, which takes 1 step.
3. If the current bit is '1', we need to add 1 to make it even, which takes 2 steps (one for adding 1 and one for dividing by 2).
4. Keep track of any carry that may occur when adding 1 to a '1' bit, as it may affect the next bits.
5. Continue this process until we reach the most significant bit (MSB). If there is a carry left after processing all bits, it means we need one additional step to account for the final division by 2 after the last addition.

Time complexity: O(n), where n is the length of the binary string.
Space complexity: O(1), as we are using only a constant amount of extra space for the steps and carry variables.
*/

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }

        return steps + carry;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.numSteps("1101") << endl; // Output: 6
    cout << solution.numSteps("10") << endl;   // Output: 1
    cout << solution.numSteps("1") << endl;    // Output: 0
    
    return 0;
}