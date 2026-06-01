#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> chars(word.begin(), word.end());
        int count = 0;

        for (char c : chars) {
            if (isupper(c) && chars.count(tolower(c))) {
                count++;
            }
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.numberOfSpecialChars("aaAbcBC") << endl;

    // test cases 2
    cout << solution.numberOfSpecialChars("abc") << endl;

    // test cases 3
    cout << solution.numberOfSpecialChars("abBCab") << endl;

    return 0;
}