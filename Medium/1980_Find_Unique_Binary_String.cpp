#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find Unique Binary String (Hash Set & Bit Manipulation):
    1. Convert all given binary strings into their decimal integer representations and store them in a hash set for O(1) lookup.
    2. Since there are `n` strings of length `n`, and there are 2^n possible binary strings, there must be at least one string missing (as 2^n > n for n >= 1).
    3. Iterate through all possible integers from 0 to 2^n - 1.
    4. For the first integer not found in the set, convert it back into a binary string of length `n`.
    5. Return the resulting binary string.

Time Complexity: O(n^2) - Converting strings to integers takes O(n^2), and the search/conversion takes O(n^2) in the worst case.
Space Complexity: O(n) - To store the integers in the hash set.
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int bn = nums.size();
        unordered_set<int> seen;

        for (int i = 0; i < bn; i++) {
            seen.insert(stoi(nums[i], nullptr, 2));
        }

        for (int i = 0; i <= (1 << bn) - 1; i++) {
            if (seen.find(i) == seen.end()) {
                string res = "";
                for (int j = bn - 1; j >= 0; j--) {
                    res += ((i >> j) & 1) ? '1' : '0';
                }
                return res;
            }
        }
        
        return "";
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<string> nums3 = {"111","011","001"};
    cout << solution.findDifferentBinaryString(nums3) << endl;

    return 0;
}