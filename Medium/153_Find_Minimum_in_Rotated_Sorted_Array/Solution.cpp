#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,4,5,1,2};
    cout << solution.findMin(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << solution.findMin(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {11,13,15,17};
    cout << solution.findMin(nums3) << endl;

    return 0;
}