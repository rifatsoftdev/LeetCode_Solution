#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find the String with LCP:
    1. We are given an `n x n` matrix `lcp` where `lcp[i][j]` is the length of the longest common prefix between `s[i...n-1]` and `s[j...n-1]`.
    2. To reconstruct the string, we greedily assign characters 'a' through 'z'. For each unassigned index `i`, we assign the next available character and propagate it to all indices `j` where `lcp[i][j] > 0`.
    3. If we run out of characters (more than 26 groups) or cannot assign a character to every index, return an empty string.
    4. After constructing the string, we must validate it against the `lcp` matrix. We use dynamic programming logic: if `s[i] == s[j]`, then `lcp[i][j]` must be `1 + lcp[i+1][j+1]` (or 1 if at the end). If `s[i] != s[j]`, `lcp[i][j]` must be 0.
    5. If the constructed string satisfies all constraints in the `lcp` matrix, return it; otherwise, return "".

Time Complexity: O(n^2) to construct and validate the matrix.
Space Complexity: O(n) to store the resulting string.
*/

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> s(n, 0);

        int i = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            while (i < n && s[i] != 0) i++;
            if (i == n) break;

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = c;
                }
            }
        }

        for (char c : s) if (c == 0) return "";

        // validate
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i == n-1 || j == n-1) {
                        if (lcp[i][j] != 1) return "";
                    } else {
                        if (lcp[i][j] != lcp[i+1][j+1] + 1) return "";
                    }
                } else {
                    if (lcp[i][j] != 0) return "";
                }
            }
        }

        return string(s.begin(), s.end());
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<vector<int>> lcp1 = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    cout << solution.findTheString(lcp1) << endl;

    vector<vector<int>> lcp2 = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}};
    cout << solution.findTheString(lcp2) << endl;

    vector<vector<int>> lcp3 = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3}};
    cout << solution.findTheString(lcp3) << endl;

    return 0;
}