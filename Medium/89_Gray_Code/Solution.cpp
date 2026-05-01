#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Gray Code (Bit Manipulation):
    1. A Gray code is a binary numeral system where two successive values differ in only one bit.
    2. The n-bit Gray code sequence can be generated using the formula: G(i) = i ^ (i >> 1).
    3. Iterate from 0 to 2^n - 1 and apply the formula to each index to get the sequence.

Time Complexity: O(2^n)
Space Complexity: O(1) (excluding the output vector)
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        
        for (int i = 0; i < (1 << n); i++) {
            res.push_back(i ^ (i >> 1));
        }

        return res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> res1 = solution.grayCode(2);
    printVec(res1);

    vector<int> res2 = solution.grayCode(1);
    printVec(res2);

    return 0;
}