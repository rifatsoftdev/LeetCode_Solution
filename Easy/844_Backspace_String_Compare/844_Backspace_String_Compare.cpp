#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Backspace String Compare:
    1. Use two stacks to process strings `s` and `t` respectively.
    2. Iterate through each string: if the character is not '#', push it onto the stack; if it is '#', pop the top element from the stack (if the stack is not empty).
    3. After processing both strings, compare the two stacks.
    4. If the stacks are equal, the strings are equal after backspacing; otherwise, they are not.

Time Complexity: O(n + m), where n and m are the lengths of strings s and t.
Space Complexity: O(n + m) to store the characters in the stacks.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for (char c : s) {
            if (c == '#') {
                if (!st1.empty()) st1.pop();
            } else {
                st1.push(c);
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(c);
            }
        }

        return st1 == st2;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    string s1 = "ab#c", t1 = "ad#c";
    cout << solution.backspaceCompare(s1, t1) << endl;

    string s2 = "ab##", t2 = "c#d#";
    cout << solution.backspaceCompare(s2, t2) << endl;

    string s3 = "a#c", t3 = "b";
    cout << solution.backspaceCompare(s3, t3) << endl;

    return 0;
}