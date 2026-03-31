#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Check if Strings Can be Made Equal With Operations II (Sorting Even and Odd Indices):
    1. The problem allows swapping characters at indices `i` and `j` if `abs(i - j) == 2`. This means characters at even indices can only be swapped with other characters at even indices, and characters at odd indices can only be swapped with other characters at odd indices.
    2. To determine if `s1` can be transformed into `s2`, we separate the characters of both strings into two groups: those at even positions and those at odd positions.
    3. If the multiset of characters at even positions in `s1` matches that of `s2`, and the multiset of characters at odd positions in `s1` matches that of `s2`, then the transformation is possible.
    4. We can verify this by sorting the characters in each group and comparing the resulting vectors.

Time Complexity: O(nlogn), where n is the length of the input strings `s1` and `s2`.
Space Complexity: O(n), where n is the length of the input strings `s1` and `s2` (for the additional vectors used to store characters at even and odd indices).
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> e1, o1, e2, o2;

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) e1.push_back(s1[i]), e2.push_back(s2[i]);
            else o1.push_back(s1[i]), o2.push_back(s2[i]);
        }

        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        
        return e1 == e2 && o1 == o2;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.checkStrings("abcdba", "cabdab") << endl; // true
    cout << solution.checkStrings("abe", "bea") << endl; // false

    return 0;
}