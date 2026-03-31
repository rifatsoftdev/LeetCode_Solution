#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Count Sorted Vowel Strings (Combinatorics):
    1. This problem is equivalent to finding the number of ways to choose $n$ items from 5 types (a, e, i, o, u) with replacement, where the order doesn't matter (since they must be sorted).
    2. This is a "Stars and Bars" combinatorics problem. The formula for choosing $r$ elements from $n$ types with replacement is $\binom{n + r - 1}{r}$.
    3. Here, $n$ is the number of types (5 vowels) and $r$ is the length of the string ($n$).
    4. The formula becomes $\binom{5 + n - 1}{n} = \binom{n + 4}{n} = \binom{n + 4}{4}$.
    5. $\binom{n + 4}{4} = \frac{(n+4) \times (n+3) \times (n+2) \times (n+1)}{4 \times 3 \times 2 \times 1}$.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4) * (n+3) * (n+2) * (n+1) / 24;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.countVowelStrings(1) << endl;
    cout << solution.countVowelStrings(2) << endl;
    cout << solution.countVowelStrings(33) << endl;
    
    return 0;
}