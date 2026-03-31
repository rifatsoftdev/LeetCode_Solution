#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256, 0);
        int first = 0, secend = 0, len = 0;

        while (secend < s.size()) {
            while (count[s[secend]]) {
                count[s[first]] = 0;
                first++;
            }

            count[s[secend]] = 1;
            len = max(len, secend-first+1);
            secend++;
        }

        return len;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;  // output 3
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;     // output 1
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;    // output 3

    return 0;
}