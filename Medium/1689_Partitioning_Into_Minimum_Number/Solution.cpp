#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Partitioning Into Minimum Number Of Deci-Binary Numbers:
    1. A deci-binary number is a positive integer that consists of only the digits 0 and 1 and does not contain any leading zeros.
    2. Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

Time Complexity: O(N), where N is the length of the input string n.
Space Complexity: O(1), as we are using only a constant amount of extra space to store the answer and iterate through the string.
*/

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) ans = max(ans, c - '0');
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.minPartitions("32") << endl; // Output: 3
    cout << solution.minPartitions("82734") << endl; // Output: 8
    cout << solution.minPartitions("27346209830709182346") << endl; // Output: 9

    return 0;
}