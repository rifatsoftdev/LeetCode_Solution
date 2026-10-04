#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;

        for (int i = 0; i < s.size(); i++) {
            int rev = 26 - (s[i] - 'a' + 1) + 1;
            degree += (rev * (i + 1));
        }

        return degree;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "abc";
    int result1 = solution.reverseDegree(s1);
    cout << result1 << endl;

    // test cases 2
    string s2 = "zaza";
    int result2 = solution.reverseDegree(s2);
    cout << result2 << endl;

    return 0;
}