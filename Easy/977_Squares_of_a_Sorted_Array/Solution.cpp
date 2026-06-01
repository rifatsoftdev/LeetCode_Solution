#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int fast = 0;
        int last = n - 1;
        int idx = n - 1;
        vector<int> result(n);

        while (fast <= last) {
            int fast_sq = nums[fast] * nums[fast];
            int last_sq = nums[last] * nums[last];
            
            if (fast_sq < last_sq) {
                result[idx] = last_sq;
                last--;
            } else {
                result[idx] = fast_sq;
                fast++;
            }
            idx--;
        }
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> ans1 = solution.sortedSquares(nums1);
    printVec(ans1);

    // test cases 2
    vector<int> nums2 = {-7,-3,2,3,11};
    vector<int> ans2 = solution.sortedSquares(nums2);
    printVec(ans2);

    return 0;
}