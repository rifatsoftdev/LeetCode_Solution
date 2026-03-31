#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Convert to Base -2 (Negative Base Conversion):
    1. To convert a number to base -2, we repeatedly divide the number by -2 and keep track of the remainders.
    2. In standard division, the remainder can be negative (e.g., 3 / -2 = -1 with remainder 1, but 2 / -2 = -1 with remainder 0, and some implementations might give -1 / -2 = 0 with remainder -1).
    3. Since base digits must be 0 or 1, if we encounter a negative remainder, we adjust it by adding 2 to the remainder and adding 1 to the quotient (since $N = Q \cdot (-2) + R = (Q+1) \cdot (-2) + (R+2)$).
    4. Prepend each remainder to the result string until the quotient becomes zero.
    5. Base case: If the input is 0, return "0".

Time Complexity: O(log N)
Space Complexity: O(log N) to store the result string.
*/

class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";

        string result = "";
        while (N != 0) {
            int remainder = N % -2;
            N = N / -2;

            if (remainder < 0) {
                remainder += 2;
                N += 1;
            }

            result = char(remainder + '0') + result;
        }
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.baseNeg2(2) << endl;
    cout << solution.baseNeg2(3) << endl;
    cout << solution.baseNeg2(4) << endl;

    return 0;
}