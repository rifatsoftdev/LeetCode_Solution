#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Valid Parentheses:
    1. Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    2. An input string is valid if:
    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.

Time Complexity: O(N), where N is the length of the input string s.
Space Complexity: O(N), in the worst case, when all characters in the string are opening
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.size() % 2 == 1) return false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' ||s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                char c = st.top();

                if (
                    (c == '(' && s[i] == ')') ||
                    (c == '{' && s[i] == '}') ||
                    (c == '[' && s[i] == ']')
                ) {
                    st.pop();
                } else return false;
            }
        }

        if (st.empty()) return true;
        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.isValid("()") << endl; // Output: true
    cout << solution.isValid("()[]{}") << endl; // Output: true
    cout << solution.isValid("(]") << endl; // Output: false
    
    return 0;
}