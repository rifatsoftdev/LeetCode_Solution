#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string processStr(string s) {
        string result;

        for (char c : s) {
            if (c == '*') {
                // Remove the last character
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                // Duplicate
                if (!result.empty()) {
                    result += result;
                }
            } else if (c == '%') {
                // Reverse
                reverse(result.begin(), result.end());
            } else {
                // Append
                result += c;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "a#b%*";
    cout << solution.processStr(s1) << endl;

    // test cases 2
    string s2 = "z*#";
    cout << solution.processStr(s2) << endl;

    return 0;
}