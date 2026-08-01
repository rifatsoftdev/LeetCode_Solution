#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;

        for (int i = 0; i < word.size(); i++) {
            ans += i / 8 + 1;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string word1 = "abcde";
    cout << solution.minimumPushes(word1) << endl;

    // test cases 2
    string word2 = "xycdefghij";
    cout << solution.minimumPushes(word2) << endl;

    return 0;
}