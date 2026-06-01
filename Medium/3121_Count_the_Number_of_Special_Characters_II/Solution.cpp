#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } 
            else {
                if (firstUpper[c - 'A'] == -1) {
                    firstUpper[c - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
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
    cout << solution.numberOfSpecialChars("AbBCab") << endl;

    return 0;
}