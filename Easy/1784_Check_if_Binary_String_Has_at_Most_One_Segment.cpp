#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Check One Segment:
    1. Initialize a count variable to keep track of the number of segments of '1's.
    2. Iterate through the string:
        a. If the current character is '1', increment the count and skip all subsequent '1's until you encounter a '0' or reach the end of the string.
    3. After the loop, check if the count is equal to 1. If it is, return true; otherwise, return false.

Time Complexity: O(n), where n is the length of the input string.
Space Complexity: O(1), as we are using only a constant amount of extra space for the count variable.

Note: This solution efficiently checks for the presence of at most one segment of '1's in the binary string by counting the segments and ensuring that they are contiguous.
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
                while (i < n && s[i] == '1') {
                    i++;
                }
            }
        }
        return count == 1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.checkOnesSegment("1001") << endl; // false
    cout << solution.checkOnesSegment("110") << endl; // true

    return 0;
}