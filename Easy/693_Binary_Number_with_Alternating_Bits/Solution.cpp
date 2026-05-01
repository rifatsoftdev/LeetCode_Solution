#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Binary Number with Alternating Bits:
    1. Convert the given integer n to its binary representation as a string.
    2. Iterate through the binary string and check if any two adjacent bits are the same.
    3. If any two adjacent bits are the same, return false.
    4. If the loop completes without finding any adjacent bits that are the same, return true.

Time Complexity: O(log n) - The time complexity is logarithmic because we are converting the integer to its binary representation, which takes O(log n) time, and then iterating through the binary string, which also takes O(log n) time.
Space Complexity: O(log n) - The space complexity is logarithmic because we are storing the binary representation of the integer as a string, which takes O(log n) space.
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while (n > 0) {
            s += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                return false;
            }
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.hasAlternatingBits(5) << endl; // Output: true
    cout << solution.hasAlternatingBits(7) << endl; // Output: false
    cout << solution.hasAlternatingBits(11) << endl; // Output: false

    return 0;
}