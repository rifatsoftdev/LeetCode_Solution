#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse Integer:
    1. Initialize a variable `result` to store the reversed integer.
    2. Use a loop to extract digits from the input integer `x` until it becomes 0.
    3. In each iteration, pop the last digit of `x` and push it to `result`.
    4. Before pushing the digit, check for overflow/underflow conditions:
       - If `result` is greater than `INT_MAX / 10` or equal to `INT_MAX / 10` and the popped digit is greater than 7, return 0 (overflow).
       - If `result` is less than `INT_MIN / 10` or equal to `INT_MIN / 10` and the popped digit is less than -8, return 0 (underflow).
    5. Return the final reversed integer.
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
            
            result = result * 10 + pop;
        }
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.reverse(123) << endl;       // Output: 321
    cout << solution.reverse(-123) << endl;      // Output: -321
    cout << solution.reverse(120) << endl;       // Output: 21

    return 0;
}