#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Number of Steps to Reduce a Number to Zero:
    1. Initialize a `steps` counter to 0.
    2. While the number `num` is greater than 0:
        a. If `num` is even, divide it by 2.
        b. If `num` is odd, subtract 1 from it.
        c. Increment the `steps` counter after each operation.
    3. Return the total number of steps taken to reach zero.

Time Complexity: O(log n), as dividing by 2 reduces the number of bits in each step.
Space Complexity: O(1), as we only use a single integer variable for counting.
*/

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }

        return steps;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.numberOfSteps(14) << endl; // Output: 6
    cout << solution.numberOfSteps(8) << endl;  // Output: 4
    cout << solution.numberOfSteps(123) << endl; // Output: 12

    return 0;
}