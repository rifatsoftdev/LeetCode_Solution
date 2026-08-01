#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (count == 0) {
                    continue;
                } else {
                    break;
                }
            } else {
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
    
    cout << solution.lengthOfLastWord("Hello World") << endl;
    cout << solution.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << solution.lengthOfLastWord("luffy is still joyboy") << endl;

    return 0;
}