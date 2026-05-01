#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Detect Capital:
    1. Count the number of uppercase and lowercase letters in the word.
    2. The word is valid if:
        a. All letters are uppercase (capitalCount == n).
        b. All letters are lowercase (lowercaseCount == n).
        c. Only the first letter is uppercase and the rest are lowercase (capitalCount == 1 && isupper(word[0])).
    3. Return true if any of the above conditions are met, otherwise return false.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 0) return true;

        int capitalCount = 0;
        int lowercaseCount = 0;

        for (int i = 0; i < n; i++) {
            if (isupper(word[i])) {
                capitalCount++;
            } else {
                lowercaseCount++;
            }
        }

        if (capitalCount == n || lowercaseCount == n) {
            return true;
        }
        if (capitalCount == 1 && isupper(word[0])) {
            return true;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.detectCapitalUse("USA") << endl; // true
    cout << solution.detectCapitalUse("FlaG") << endl; // false
    cout << solution.detectCapitalUse("Leetcode") << endl; // true

    return 0;
}