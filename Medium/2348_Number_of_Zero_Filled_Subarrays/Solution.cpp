#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long zeroSubarray = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                for (int j = 1; j < cnt + 1; j++) zeroSubarray += j;
                cnt = 0;
            }
        }

        for (int j = 1; j < cnt + 1; j++) {
            zeroSubarray += j;
        }

        return zeroSubarray;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,3,0,0,2,0,0,4};
    cout << solution.zeroFilledSubarray(nums1) << endl;
    
    // test cases 2
    vector<int> nums2 = {0,0,0,2,0,0};
    cout << solution.zeroFilledSubarray(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {2,10,2019};
    cout << solution.zeroFilledSubarray(nums3) << endl;

    return 0;
}