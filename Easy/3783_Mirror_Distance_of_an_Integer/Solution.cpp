#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Mirror Distance of an Integer:
    1. The mirror distance of an integer is defined as the absolute difference between the integer and its reverse.
    2. Create a helper function `reverseInteger` that reverses the digits of the given number.
    3. Calculate the absolute difference between the original number `n` and its reversed version.
    4. Return the result.

Time Complexity: O(log10 n), as we iterate through the digits of the number.
Space Complexity: O(1).
*/

class Solution {
    int reverseInteger(int n) {
        int reversed = 0;
        while (n != 0) {
            int remainder = n % 10;
            reversed = reversed * 10 + remainder;
            n /= 10;
        }
        return reversed;
    }

public:
    int mirrorDistance(int n) {
        return abs(reverseInteger(n) - n);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.mirrorDistance(25) << endl;
    cout << solution.mirrorDistance(10) << endl;
    cout << solution.mirrorDistance(7) << endl;

    return 0;
}