#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Sum of Two Integers (Bit Manipulation):
    1. Use XOR (^) to find the sum of two bits without considering the carry.
    2. Use AND (&) followed by a left shift (<< 1) to find the carry bits.
    3. Repeat the process until there is no carry left (b becomes 0).
    4. This approach simulates binary addition at the hardware level.

Time Complexity: O(1) because the number of bits is fixed (e.g., 32-bit integers).
Space Complexity: O(1).
*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.getSum(1,2) << endl;
    cout << solution.getSum(2,3) << endl;

    return 0;
}