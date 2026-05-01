#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Minimum Changes To Make Alternating Binary String:
    1. Iterate through the string and count the number of changes needed to make the string alternate starting with '0' (i.e., "010101...").
    2. The number of changes needed to make the string alternate starting with '1' (i.e., "101010...") can be calculated as `n - count`, where `n` is the length of the string.
    3. Return the minimum of the two counts.

Time Complexity: O(n) (where n is the length of the string)
Space Complexity: O(1) (only a few variables are used for counting)

Note: This approach efficiently counts the number of changes needed for both alternating patterns in a single pass through the string, making it optimal for this problem.
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != (i % 2 + '0')) {
                count++;
            }
        }

        return min(count, n - count);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.minOperations("0100") << endl; // Output: 1
    cout << solution.minOperations("10") << endl;   // Output: 0
    cout << solution.minOperations("1111") << endl;  // Output: 2

    return 0;
}