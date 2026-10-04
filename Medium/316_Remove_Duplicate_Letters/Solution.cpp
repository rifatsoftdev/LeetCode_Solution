#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (stk.empty() || c > stk.top()) {
                stk.push(c);
            } else if (c < stk.top()) {
                while (!stk.empty() && c < stk.top()) {
                    stk.pop();
                }
                stk.push(c);
            }
        }

        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "bcabc";
    string result1 = solution.removeDuplicateLetters(s1);
    cout << result1 << endl; // Output: "abc"

    // test cases 2
    string s2 = "cbacdcbc";
    string result2 = solution.removeDuplicateLetters(s2);
    cout << result2 << endl; // Output: "acdb"

    return 0;
}