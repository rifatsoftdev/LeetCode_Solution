#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*' && st.size() != 0) {
                st.pop();
            } else if (s[i] != '*') {
                st.push(s[i]);
            }
        }
        
        string result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
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
    string s1 = "leet**cod*e";
    cout << solution.removeStars(s1) << endl;

    // test cases 2
    string s2 = "erase*****";
    cout << solution.removeStars(s2) << endl;

    return 0;
}