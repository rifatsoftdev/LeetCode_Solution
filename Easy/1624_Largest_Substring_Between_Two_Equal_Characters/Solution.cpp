#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxGap = -1;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && maxGap < j-i) {
                    maxGap = j-i-1;
                }
            }
        }

        return maxGap;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.maxLengthBetweenEqualCharacters("aa") << endl;     // 0

    // test cases 2
    cout << solution.maxLengthBetweenEqualCharacters("abca") << endl;   // 2

    // test cases 3
    cout << solution.maxLengthBetweenEqualCharacters("cbzxy") << endl;  // -1

    return 0;
}