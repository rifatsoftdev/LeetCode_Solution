#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = ans[i + n] = nums[i];
        }

        return ans;
        
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 2, 1};
    vector<int> result1 = solution.getConcatenation(nums1);
    printVec(result1);
    
    // test cases 2
    vector<int> nums2 = {1, 3, 2, 1};
    vector<int> result2 = solution.getConcatenation(nums2);
    printVec(result2);

    return 0;
}