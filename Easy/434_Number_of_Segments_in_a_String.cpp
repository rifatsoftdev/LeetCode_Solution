#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Number of Segments in a String:
    1. A segment is defined as a contiguous sequence of non-space characters.
    2. Iterate through the string character by character.
    3. A new segment starts if the current character is not a space AND (it is the first character of the string OR the previous character was a space).
    4. Increment a counter whenever these conditions are met.
    5. Return the final count.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
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
    
    cout << solution.countSegments("Hello, my name is John") << endl;
    cout << solution.countSegments("Hello") << endl;

    return 0;
}