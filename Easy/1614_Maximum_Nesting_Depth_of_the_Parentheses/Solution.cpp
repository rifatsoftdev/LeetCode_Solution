#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int o = 0;
        int c = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                o++;
            } if (s[i] == ')') {
                c++;
            }

            result = max(result, o - c);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << solution.maxDepth(s1) << endl;

    // test cases 2
    string s2 = "(1)+((2))+(((3)))";
    cout << solution.maxDepth(s2) << endl;

    // test cases 3
    string s3 = "()(())((()()))";
    cout << solution.maxDepth(s3) << endl;

    return 0;
}