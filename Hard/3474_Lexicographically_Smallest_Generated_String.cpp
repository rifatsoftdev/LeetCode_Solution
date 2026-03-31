#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

*/

class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            // The substring must equal t
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a';
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            // Find the last undecided position
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') {
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}