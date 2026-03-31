#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Split a String in Balanced Strings:
    1. Initialize a `balance` counter to 0 and an `ans` counter to 0.
    2. Iterate through each character in the string:
        a. If the character is 'R', increment `balance`.
        b. If the character is 'L', decrement `balance`.
        c. If `balance` reaches 0, it means a balanced substring has been found, so increment `ans`.
    3. Return the total count of balanced substrings.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as we only use a few integer variables.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int ans = 0;

        for(char c : s){
            if(c == 'R') balance++;
            else balance--;

            if(balance == 0) ans++;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.balancedStringSplit("RLRRLLRLRL") << endl;
    cout << solution.balancedStringSplit("RLRRRLLRLL") << endl;
    cout << solution.balancedStringSplit("LLLLRRRR") << endl;

    return 0;
}