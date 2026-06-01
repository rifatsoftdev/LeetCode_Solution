#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            string rotate = s.substr(i) + s.substr(0, i);

            if (rotate == goal) return true;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "abcde", goal1 = "cdeab";
    cout << solution.rotateString(s1, goal1) << endl;

    // test cases 2
    string s2 = "abcde", goal2 = "abced";
    cout << solution.rotateString(s2, goal2) << endl;

    return 0;
}