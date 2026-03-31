#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

The Happy String (Backtracking/DFS):
    1. A happy string is a string that consists only of 'a', 'b', and 'c' and does not have any two consecutive characters that are the same.
    2. We can use a backtracking approach to generate happy strings in lexicographical order.
    3. At each step, we try adding 'a', 'b', and 'c' to the current string, ensuring the new character is different from the last character added.
    4. We maintain a counter `k`. Every time we reach a string of length `n`, we decrement `k`.
    5. When `k` reaches zero, the current string is the $k$-th lexicographical happy string.
    6. If we finish the search and `k` is still greater than zero, return an empty string.

Time Complexity: O(3 * 2^(n-1)), as each position (except the first) has at most 2 choices.
Space Complexity: O(n) for the recursion stack.
*/

class Solution {
public:
    string ans = "";
    int k;

    void dfs(string s, int n) {
        if (s.size() == n) {
            k--;
            if (k == 0) ans = s;
            return;
        }

        for (char c : {'a','b','c'}) {
            if (!s.empty() && s.back() == c) continue;
            dfs(s + c, n);
            if (!ans.empty()) return;
        }
    }

    string getHappyString(int n, int k) {
        this->k = k;
        dfs("", n);
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.getHappyString(1, 3) << endl; // Output: "c"
    cout << solution.getHappyString(1, 4) << endl; // Output: ""
    cout << solution.getHappyString(3, 9) << endl; // Output: "cab"

    return 0;
}