#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Set Mismatch (In-place Marking):
    1. Iterate through the array and use the absolute value of each element as an index.
    2. For each element, negate the value at the corresponding index (`abs(nums[i]) - 1`).
    3. If the value at that index is already negative, it means the current number is the duplicate. Store it as the first result.
    4. After the first pass, iterate through the array again. The index that contains a positive value indicates the missing number (index + 1).

Time Complexity: O(n)
Space Complexity: O(1) (modifying the input array in-place)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                result[0] = idx + 1;
            } else {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,2,2,4};
    vector<int> result1 = solution.findErrorNums(nums1);
    printVec(result1);
    
    vector<int> nums2 = {1,1};
    vector<int> result2 = solution.findErrorNums(nums2);
    printVec(result2);

    return 0;
}