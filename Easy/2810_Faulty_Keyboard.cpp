#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Faulty Keyboard:
    1. Initialize an empty string res to store the final result.
    2. Iterate through each character c in the input string s:
        a. If c is 'i', reverse the string res.
        b. Otherwise, append c to the end of res.
    3. After processing all characters, return the resulting string res.

Time Complexity: O(n^2), where n is the length of the string, because each 'i' triggers a reverse operation which takes O(n).
Space Complexity: O(n) to store the resulting string.
*/

class Solution {
public:
    string finalString(string s) {
        string res = "";
        for (char c : s) {
            if (c == 'i') {
                reverse(res.begin(), res.end());
            } else {
                res += c;
            }
        }
        return res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.finalString("string") << endl;
    cout << solution.finalString("poiinter") << endl;

    return 0;
}