#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Convert a Number to Hexadecimal:
    1. If the input number is 0, return "0".
    2. Treat the input as an unsigned 32-bit integer to handle negative numbers (two's complement).
    3. Repeatedly take the remainder of the number when divided by 16 to find the hexadecimal digit.
    4. Map the remainder (0-15) to its corresponding hexadecimal character ('0'-'9', 'a'-'f').
    5. Prepend the character to the result string and divide the number by 16.
    6. Continue until the number becomes 0.

Time Complexity: O(log16 n), which is at most 8 iterations for a 32-bit integer.
Space Complexity: O(1) (ignoring the space for the output string).
*/

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num;
        string hex = "0123456789abcdef";
        string result = "";

        while (n > 0) {
            result = hex[n % 16] + result;
            n /= 16;
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.toHex(26) << endl;
    cout << solution.toHex(-1) << endl;

    return 0;
}