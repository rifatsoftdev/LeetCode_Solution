#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;

        int maxLength = 0;
        int lastInvalidIndex = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    lastInvalidIndex = i;
                } else {
                    st.pop();
                    int currentLength = st.empty() ? (i - lastInvalidIndex) : (i - st.top());
                    maxLength = max(maxLength, currentLength);
                }
            }
        }

        return maxLength;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "(()";
    cout << solution.longestValidParentheses(s1) << endl; // Output: 2

    // test cases 2
    string s2 = ")()())";
    cout << solution.longestValidParentheses(s2) << endl; // Output: 4

    // test cases 3
    string s3 = "";
    cout << solution.longestValidParentheses(s3) << endl; // Output: 0

    return 0;
}