#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;

            if (charCount[c] == 2) {
                return c;
            }
        }

        return '\0';
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "abccbaacz";
    cout << solution.repeatedCharacter(s1) << endl;

    // test cases 2
    string s2 = "abcdd";
    cout << solution.repeatedCharacter(s2) << endl;

    return 0;
}