#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Length of Last Word:
    1. Start iterating from the end of the string to find the last word.
    2. Skip any trailing spaces at the end of the string.
    3. Once a non-space character is encountered, start counting the characters until another space or the beginning of the string is reached.
    4. Return the count, which represents the length of the last word.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as we only use a single counter variable.
*/

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