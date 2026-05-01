#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Check if Strings Can be Made Equal With Operations I:
    1. You are given two strings s1 and s2, both of length 4.
    2. You can swap characters at indices i and j if j - i = 2.
    3. This means you can swap s1[0] with s1[2] and s1[1] with s1[3].
    4. To check if s1 can be made equal to s2, check if the characters at even indices {0, 2} in s1 can match those in s2 (either in the same order or swapped).
    5. Similarly, check if the characters at odd indices {1, 3} in s1 can match those in s2.
    6. If both conditions are met, return true. Otherwise, return false.

Time Complexity: O(1) - We are only comparing 4 characters.
Space Complexity: O(1) - We are using a constant amount of space.
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool swapeven = s1[0] == s2[2] && s1[2] == s2[0];
        bool sameeven = s1[0] == s2[0] && s1[2] == s2[2];

        bool swapodd = s1[1] == s2[3] && s1[3] == s2[1];
        bool sameodd = s1[1] == s2[1] && s1[3] == s2[3];

        return ((swapeven || sameeven) && (swapodd || sameodd));
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.canBeEqual("abcd", "cdab") << endl;
    cout << solution.canBeEqual("abcd", "dacb") << endl;

    return 0;
}