#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        double minimumNum = 50.0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            double ave = (nums[left] + nums[right]) / 2.0;
            minimumNum = min(minimumNum, ave);
            left++;
            right--;
        }

        return minimumNum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {7, 8, 3, 4, 15, 13, 4, 1};
    cout << solution.minimumAverage(nums1) << endl;
    
    // test cases 2
    vector<int> nums2 = {1, 9, 8, 3, 10, 5};
    cout << solution.minimumAverage(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {1, 2, 3, 7, 8, 9};
    cout << solution.minimumAverage(nums3) << endl;
    
    return 0;
}