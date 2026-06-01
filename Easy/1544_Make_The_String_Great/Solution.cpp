#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty()) {
                char top = st.top();

                if (abs(s[i] - top) == 32) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";

        while (!st.empty()) {
            char c = st.top();
            st.pop();
            ans =  c + ans;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.makeGood("leEeetcode") << endl;

    // test cases 2
    cout << solution.makeGood("abBAcC") << endl;

    // test cases 3
    cout << solution.makeGood("s") << endl;

    return 0;
}