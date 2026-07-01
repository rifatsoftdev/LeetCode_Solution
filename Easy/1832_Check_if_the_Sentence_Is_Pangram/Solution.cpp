#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> ch;

        for (int i = 0; i < sentence.size(); i++) {
            if (ch[sentence[i]] == 0) ch[sentence[i]] = 1;
            else ch[sentence[i]]++;
        }

        return ch.size() == 26;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;

    // test cases 2
    cout << solution.checkIfPangram("leetcode") << endl;

    return 0;
}